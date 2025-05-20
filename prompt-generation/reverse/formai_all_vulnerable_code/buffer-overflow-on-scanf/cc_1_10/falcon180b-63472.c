//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <dirent.h>
#include <sys/statvfs.h>
#include <string.h>

#define MAX_THREADS 10
#define MAX_FILE_NAME_LENGTH 256

typedef struct {
    char dir_path[MAX_FILE_NAME_LENGTH];
    int thread_id;
} thread_data_t;

void *analyze_dir(void *arg) {
    thread_data_t *data = (thread_data_t *) arg;
    DIR *dir;
    struct dirent *ent;
    struct statvfs buf;
    char path[MAX_FILE_NAME_LENGTH];

    if ((dir = opendir(data->dir_path))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR) {
                strcat(path, data->dir_path);
                strcat(path, "/");
                strcat(path, ent->d_name);
                if (statvfs(path, &buf) == 0) {
                    printf("Thread %d: Directory %s has size %ld bytes\n", data->thread_id, ent->d_name, buf.f_bsize * buf.f_blocks);
                }
            }
        }
        closedir(dir);
    } else {
        perror("");
    }

    return NULL;
}

int main() {
    pthread_t threads[MAX_THREADS];
    thread_data_t data[MAX_THREADS];
    int i, num_threads;
    char dir_path[MAX_FILE_NAME_LENGTH];

    printf("Enter directory path: ");
    scanf("%s", dir_path);

    num_threads = 1;
    for (i = 0; i < MAX_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, analyze_dir, &data[i])!= 0) {
            printf("Error creating thread %d\n", i);
            break;
        }
        num_threads++;
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}