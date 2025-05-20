//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_FILES 10
#define BUFFER_SIZE 256
#define THREAD_COUNT 5

typedef struct {
    char filename[20];
    char data[BUFFER_SIZE];
} FileOperation;

FileOperation fileOps[THREAD_COUNT];

pthread_mutex_t lock;

void* write_file(void* arg) {
    FileOperation* fileOp = (FileOperation*)arg;
    pthread_mutex_lock(&lock);
    FILE* file = fopen(fileOp->filename, "a");
    if (file) {
        fprintf(file, "%s\n", fileOp->data);
        fclose(file);
        printf("Written to file %s: %s\n", fileOp->filename, fileOp->data);
    } else {
        perror("Error writing to file");
    }
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* read_file(void* arg) {
    FileOperation* fileOp = (FileOperation*)arg;
    pthread_mutex_lock(&lock);
    char buffer[BUFFER_SIZE];
    FILE* file = fopen(fileOp->filename, "r");
    if (file) {
        printf("Contents of %s:\n", fileOp->filename);
        while (fgets(buffer, BUFFER_SIZE, file)) {
            printf("%s", buffer);
        }
        fclose(file);
    } else {
        perror("Error reading file");
    }
    pthread_mutex_unlock(&lock);
    return NULL;
}

void* delete_file(void* arg) {
    FileOperation* fileOp = (FileOperation*)arg;
    pthread_mutex_lock(&lock);
    if (remove(fileOp->filename) == 0) {
        printf("Deleted file: %s\n", fileOp->filename);
    } else {
        perror("Error deleting file");
    }
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t threads[THREAD_COUNT];
    char command[20], filename[20], data[BUFFER_SIZE];
    int thread_index = 0;

    pthread_mutex_init(&lock, NULL);

    while (1) {
        printf("Enter command (write/read/delete/exit): ");
        scanf("%s", command);

        if (strcmp(command, "exit") == 0) {
            break;
        }

        printf("Enter filename: ");
        scanf("%s", filename);
        strcpy(fileOps[thread_index].filename, filename);

        if (strcmp(command, "write") == 0) {
            printf("Enter data to write: ");
            scanf(" %[^\n]", data);
            strcpy(fileOps[thread_index].data, data);
            pthread_create(&threads[thread_index], NULL, write_file, (void*)&fileOps[thread_index]);
        } 
        else if (strcmp(command, "read") == 0) {
            pthread_create(&threads[thread_index], NULL, read_file, (void*)&fileOps[thread_index]);
        } 
        else if (strcmp(command, "delete") == 0) {
            pthread_create(&threads[thread_index], NULL, delete_file, (void*)&fileOps[thread_index]);
        } 
        else {
            printf("Invalid command\n");
            continue;
        }

        pthread_join(threads[thread_index], NULL);
        thread_index = (thread_index + 1) % THREAD_COUNT;
        
        if(thread_index >= THREAD_COUNT){
            thread_index = 0; // Reset index to prevent overflow
        }
    }

    pthread_mutex_destroy(&lock);
    return 0;
}