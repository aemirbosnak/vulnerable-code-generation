//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_FILES 100
#define MAX_FILE_NAME 50

typedef struct {
    char name[MAX_FILE_NAME];
    int size;
    int is_deleted;
} File;

File files[MAX_FILES];
int num_files = 0;

void create_file(char *name, int size) {
    if (num_files >= MAX_FILES) {
        printf("Error: Maximum number of files reached\n");
        return;
    }

    strcpy(files[num_files].name, name);
    files[num_files].size = size;
    files[num_files].is_deleted = 0;

    num_files++;
}

void delete_file(char *name) {
    int i;

    for (i = 0; i < num_files; i++) {
        if (strcmp(files[i].name, name) == 0 &&!files[i].is_deleted) {
            files[i].is_deleted = 1;
            break;
        }
    }
}

void list_files() {
    int i;

    for (i = 0; i < num_files; i++) {
        if (!files[i].is_deleted) {
            printf("%s (%d bytes)\n", files[i].name, files[i].size);
        }
    }
}

void *thread_create_file(void *arg) {
    char name[MAX_FILE_NAME];
    int size;

    scanf("%s %d", name, &size);
    create_file(name, size);

    pthread_exit(NULL);
}

void *thread_delete_file(void *arg) {
    char name[MAX_FILE_NAME];

    scanf("%s", name);
    delete_file(name);

    pthread_exit(NULL);
}

void *thread_list_files(void *arg) {
    list_files();

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[3];

    pthread_create(&threads[0], NULL, thread_create_file, NULL);
    pthread_create(&threads[1], NULL, thread_delete_file, NULL);
    pthread_create(&threads[2], NULL, thread_list_files, NULL);

    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}