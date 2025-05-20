//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_FILES 100000

typedef struct {
    char path[1024];
    size_t size;
} file_t;

file_t files[MAX_FILES];
int file_count = 0;

void *thread_func(void *arg) {
    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir((char *) arg))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_REG) {
                if (file_count >= MAX_FILES) {
                    break;
                }

                snprintf(files[file_count].path, sizeof(files[file_count].path), "%s/%s", (char *) arg, ent->d_name);
                files[file_count].size = ent->d_reclen;
                file_count++;
            }
        }

        closedir(dir);
    }

    return NULL;
}

void analyze_disk_space() {
    char path[1024];
    size_t total_size = 0;

    printf("Enter directory path: ");
    scanf("%s", path);

    pthread_t threads[MAX_THREADS];
    int i = 0;

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, path);
    }

    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Total files: %d\n", file_count);
    printf("Total disk space used: %zu bytes\n", total_size);
}

int main() {
    analyze_disk_space();

    return 0;
}