//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 1024
#define SYNC_MODE_COPY 1
#define SYNC_MODE_DELETE 2
#define SYNC_MODE_RENAME 3

typedef struct {
    char source_file_name[MAX_FILE_NAME_LENGTH];
    char dest_file_name[MAX_FILE_NAME_LENGTH];
    int sync_mode;
} FileSyncItem;

int main() {
    FILE *file;
    char line[1024];
    int num_items = 0;
    FileSyncItem items[100];

    file = fopen("sync.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open sync.txt\n");
        return 1;
    }

    while (fgets(line, sizeof(line), file)!= NULL) {
        if (num_items >= 100) {
            printf("Error: Too many items in sync.txt\n");
            fclose(file);
            return 1;
        }

        char *token = strtok(line, ",");
        strcpy(items[num_items].source_file_name, token);

        token = strtok(NULL, ",");
        strcpy(items[num_items].dest_file_name, token);

        token = strtok(NULL, ",");
        items[num_items].sync_mode = atoi(token);

        num_items++;
    }

    fclose(file);

    for (int i = 0; i < num_items; i++) {
        if (items[i].sync_mode == SYNC_MODE_COPY) {
            printf("Copying %s to %s\n", items[i].source_file_name, items[i].dest_file_name);
        } else if (items[i].sync_mode == SYNC_MODE_DELETE) {
            printf("Deleting %s\n", items[i].dest_file_name);
        } else if (items[i].sync_mode == SYNC_MODE_RENAME) {
            printf("Renaming %s to %s\n", items[i].source_file_name, items[i].dest_file_name);
        }
    }

    return 0;
}