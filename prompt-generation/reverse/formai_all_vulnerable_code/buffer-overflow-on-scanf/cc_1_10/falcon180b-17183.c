//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_THREADS 5
#define MAX_FILE_SIZE 10000000

typedef struct {
    char file_name[100];
    char file_path[200];
    int file_size;
    int thread_id;
} file_info;

void *thread_func(void *arg) {
    file_info *file_data = (file_info *) arg;
    char command[50] = "rsync -avz ";
    strcat(command, file_data->file_path);
    strcat(command, " user@remote_server:/remote/path/");
    system(command);
    return NULL;
}

int main() {
    int num_files = 0, i;
    file_info files[MAX_THREADS];

    printf("Enter the number of files to synchronize: ");
    scanf("%d", &num_files);

    for (i = 0; i < num_files; i++) {
        printf("Enter the name of file %d: ", i+1);
        scanf("%s", files[i].file_name);
        strcpy(files[i].file_path, "/local/path/");
        strcat(files[i].file_path, files[i].file_name);
        struct stat st;
        stat(files[i].file_path, &st);
        files[i].file_size = st.st_size;
        files[i].thread_id = i;
    }

    pthread_t threads[MAX_THREADS];

    for (i = 0; i < num_files; i++) {
        pthread_create(&threads[i], NULL, thread_func, &files[i]);
    }

    for (i = 0; i < num_files; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}