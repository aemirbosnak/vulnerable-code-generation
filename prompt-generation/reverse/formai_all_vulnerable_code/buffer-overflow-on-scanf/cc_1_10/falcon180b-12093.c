//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_FILE_NAME 1024
#define MAX_DIR_NAME 1024

typedef struct {
    char dir_path[MAX_DIR_NAME];
    FILE *file;
} dir_t;

typedef struct {
    pthread_t thread_id;
    dir_t *dir;
} thread_data_t;

void *scan_dir(void *data) {
    thread_data_t *thread_data = (thread_data_t *) data;
    dir_t *dir = thread_data->dir;
    DIR *dp;
    struct dirent *dirp;
    char path[MAX_DIR_NAME + MAX_FILE_NAME];

    dp = opendir(dir->dir_path);

    if (dp == NULL) {
        printf("Error opening directory %s\n", dir->dir_path);
        return NULL;
    }

    while ((dirp = readdir(dp))!= NULL) {
        strcpy(path, dir->dir_path);
        strcat(path, "/");
        strcat(path, dirp->d_name);

        if (dirp->d_type == DT_DIR) {
            if (mkdir(path, 0755) == -1) {
                printf("Error creating directory %s\n", path);
            }
        } else {
            FILE *file = fopen(path, "w");

            if (file == NULL) {
                printf("Error creating file %s\n", path);
            } else {
                fclose(file);
            }
        }
    }

    closedir(dp);
    return NULL;
}

int main() {
    int i, num_threads;
    pthread_t threads[MAX_THREADS];
    dir_t dirs[MAX_THREADS];

    printf("Enter number of threads: ");
    scanf("%d", &num_threads);

    for (i = 0; i < num_threads; i++) {
        printf("Enter directory path for thread %d: ", i + 1);
        scanf("%s", dirs[i].dir_path);

        dirs[i].file = fopen(dirs[i].dir_path, "r");

        if (dirs[i].file == NULL) {
            printf("Error opening directory %s\n", dirs[i].dir_path);
            exit(1);
        }

        thread_data_t thread_data;
        thread_data.dir = &dirs[i];
        pthread_create(&threads[i], NULL, scan_dir, &thread_data);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}