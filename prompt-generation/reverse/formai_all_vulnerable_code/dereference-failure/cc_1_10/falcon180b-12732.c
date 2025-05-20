//Falcon-180B DATASET v1.0 Category: File system simulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_FILES 1000
#define MAX_FILE_SIZE 1024
#define NUM_SERVERS 5

struct file {
    int id;
    char name[32];
    int size;
    int num_servers;
    int server_ids[NUM_SERVERS];
};

struct server {
    int id;
    int num_files;
    struct file *files;
};

void *server_thread(void *arg);

int main(int argc, char *argv[]) {
    pthread_t server_threads[NUM_SERVERS];
    struct server servers[NUM_SERVERS];
    int i;

    for (i = 0; i < NUM_SERVERS; i++) {
        servers[i].id = i;
        servers[i].num_files = 0;
        servers[i].files = (struct file *) malloc(MAX_FILES * sizeof(struct file));
        memset(servers[i].files, 0, MAX_FILES * sizeof(struct file));

        pthread_create(&server_threads[i], NULL, server_thread, &servers[i]);
    }

    while (1) {
        sleep(1);
    }

    return 0;
}

void *server_thread(void *arg) {
    struct server *server = (struct server *) arg;
    int i;

    for (i = 0; i < MAX_FILES; i++) {
        server->files[i].id = i;
        strcpy(server->files[i].name, "file");
        server->files[i].size = rand() % MAX_FILE_SIZE;
        server->files[i].num_servers = rand() % NUM_SERVERS;

        int j;
        for (j = 0; j < NUM_SERVERS; j++) {
            if (j!= server->id) {
                server->files[i].server_ids[j] = 1;
            }
        }
    }

    while (1) {
        sleep(1);
    }

    return NULL;
}