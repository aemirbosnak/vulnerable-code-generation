//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_THREADS 10
#define MAX_FILES 1000

typedef struct {
    char path[1024];
    struct stat stat_buf;
} file_info;

file_info files[MAX_FILES];
int num_files = 0;

void *thread_func(void *arg) {
    DIR *dir;
    struct dirent *dent;
    char path[1024];

    strcpy(path, (char *) arg);
    strcat(path, "/*");

    dir = opendir(path);

    if (dir!= NULL) {
        while ((dent = readdir(dir))!= NULL) {
            if (dent->d_type == DT_REG) {
                sprintf(files[num_files].path, "%s/%s", path, dent->d_name);
                if (stat(files[num_files].path, &files[num_files].stat_buf) == 0) {
                    num_files++;
                }
            }
        }

        closedir(dir);
    }

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    int i, rc;
    char path[1024];

    printf("Enter the directory path: ");
    scanf("%s", path);

    num_files = 0;

    for (i = 0; i < MAX_THREADS && num_files < MAX_FILES; i++) {
        sprintf(path, "%s/%d", path, i);
        rc = pthread_create(&threads[i], NULL, thread_func, (void *) path);

        if (rc) {
            printf("Error: unable to create thread, %d\n", rc);
            exit(-1);
        }
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Total number of files: %d\n", num_files);

    return 0;
}