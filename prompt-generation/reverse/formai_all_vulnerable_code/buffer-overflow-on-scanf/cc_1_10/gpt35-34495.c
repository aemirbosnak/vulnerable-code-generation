//FormAI DATASET v1.0 Category: File Synchronizer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#define MAX_FILE_SIZE 1024

typedef struct {
    char filename[50];
    char data[MAX_FILE_SIZE];
    time_t timestamp;
} file_data;

typedef struct {
    file_data file;
    int replica_count;
    int replicated[10];
} replica_data;

replica_data replica_table[50];
int num_files = 0;

void sendFileData(int node_id, file_data file) {
    // Simulate sending file data to another node
}

void syncFile(int node_id, int file_index) {
    file_data file = replica_table[file_index].file;

    for (int i = 0; i < replica_table[file_index].replica_count; i++) {
        int replica_node_id = replica_table[file_index].replicated[i];

        if (replica_node_id != node_id) {
            sendFileData(replica_node_id, file);
        }
    }
}

void addReplica(int file_index, int node_id) {
    replica_table[file_index].replicated[replica_table[file_index].replica_count] = node_id;
    replica_table[file_index].replica_count++;
}

int getFileIndex(char* filename) {
    for (int i = 0; i < num_files; i++) {
        if (strcmp(replica_table[i].file.filename, filename) == 0) {
            return i;
        }
    }

    return -1;
}

void* nodeThread(void* arg) {
    int node_id = *(int*) arg;

    while (1) {
        int choice;

        printf("\nNode %d: Choose an option:\n", node_id);
        printf("1. Add a file\n");
        printf("2. Sync a file\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        if (choice == 1) {
            printf("\nNode %d: Enter filename: ", node_id);
            char filename[50];
            scanf("%s", filename);

            int file_index = getFileIndex(filename);
            if (file_index != -1) {
                printf("\nNode %d: File already exists\n", node_id);
                continue;
            }

            file_data file;
            strcpy(file.filename, filename);
            printf("\nNode %d: Enter file data: ", node_id);
            scanf("%s", file.data);
            file.timestamp = time(NULL);

            replica_table[num_files].file = file;
            replica_table[num_files].replica_count = 0;

            addReplica(num_files, node_id);

            num_files++;

            printf("\nNode %d: File added successfully\n", node_id);
        }
        else if (choice == 2) {
            printf("\nNode %d: Enter filename: ", node_id);
            char filename[50];
            scanf("%s", filename);

            int file_index = getFileIndex(filename);
            if (file_index == -1) {
                printf("\nNode %d: File not found\n", node_id);
                continue;
            }

            syncFile(node_id, file_index);

            printf("\nNode %d: File synced successfully\n", node_id);
        }
        else if (choice == 3) {
            pthread_exit(NULL);
        }
    }
}

int main() {
    int num_nodes;

    printf("Enter number of nodes: ");
    scanf("%d", &num_nodes);

    pthread_t threads[num_nodes];
    int node_ids[num_nodes];

    for (int i = 0; i < num_nodes; i++) {
        node_ids[i] = i + 1;
        pthread_create(&threads[i], NULL, nodeThread, &node_ids[i]);
    }

    for (int i = 0; i < num_nodes; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}