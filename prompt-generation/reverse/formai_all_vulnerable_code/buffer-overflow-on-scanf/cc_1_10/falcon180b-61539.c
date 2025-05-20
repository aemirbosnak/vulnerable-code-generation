//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_BACKUPS 10
#define MAX_THREADS 5

typedef struct {
    char filename[100];
    int fileid;
} BackupFile;

BackupFile backupFiles[MAX_BACKUPS];
int numBackups = 0;

void *backupThread(void *arg) {
    char *filename = (char *) arg;
    int fileid = numBackups;

    printf("Starting backup of %s (file ID %d)\n", filename, fileid);
    fflush(stdout);

    // Simulate backup process
    sleep(2);

    printf("Backup of %s (file ID %d) completed\n", filename, fileid);
    fflush(stdout);

    pthread_exit(0);
}

int main() {
    pthread_t threads[MAX_THREADS];
    int i, rc;

    for (i = 0; i < MAX_BACKUPS; i++) {
        printf("Enter filename for backup %d: ", i+1);
        scanf("%s", backupFiles[i].filename);
        backupFiles[i].fileid = i+1;
        numBackups++;
    }

    for (i = 0; i < numBackups; i++) {
        rc = pthread_create(&threads[i], NULL, backupThread, (void *) backupFiles[i].filename);
        if (rc) {
            printf("Error creating thread %d: %s\n", i+1, strerror(rc));
            exit(1);
        }
    }

    for (i = 0; i < numBackups; i++) {
        rc = pthread_join(threads[i], NULL);
        if (rc) {
            printf("Error joining thread %d: %s\n", i+1, strerror(rc));
            exit(1);
        }
    }

    printf("All backups completed\n");
    return 0;
}