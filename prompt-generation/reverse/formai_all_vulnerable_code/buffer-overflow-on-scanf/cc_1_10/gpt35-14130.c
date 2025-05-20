//FormAI DATASET v1.0 Category: File system simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_NUM_FILES 100

typedef struct {
    char name[MAX_FILENAME_LENGTH];
    int start_block;
    int end_block;
    int size;
} File;

File files[MAX_NUM_FILES];
int total_files = 0;

void create_file(char *name, int size) {
    if (total_files == MAX_NUM_FILES) {
        printf("Error: Maximum number of files reached!\n");
        return;
    }
    int num_blocks = size / 512;
    if (size % 512 != 0) {
        num_blocks++;
    }
    if (num_blocks > 10) {
        printf("Error: File size too large!\n");
        return;
    }
    int free_block = -1;
    int consecutive_blocks = 0;
    for (int i = 0; i < 100; i++) {
        if (consecutive_blocks == num_blocks) {
            break;
        }
        if (free_block == -1 && files[i].name[0] == '\0') {
            free_block = i;
        } else if (free_block != -1 && files[i].name[0] == '\0') {
            consecutive_blocks++;
        } else {
            free_block = -1;
            consecutive_blocks = 0;
        }
    }
    if (consecutive_blocks < num_blocks) {
        printf("Error: Not enough free space!\n");
        return;
    }
    int cur_block = free_block;
    for (int i = 0; i < num_blocks; i++) {
        files[cur_block].name[0] = '*';
        if (i == 0) {
            strcpy(files[cur_block].name + 1, name);
        }
        files[cur_block].start_block = free_block;
        files[cur_block].size = size;
        if (i == num_blocks - 1) {
            files[cur_block].end_block = -1;
        } else {
            cur_block++;
            while (files[cur_block].name[0] != '\0') {
                cur_block++;
            }
            files[cur_block-1].end_block = cur_block;
        }
    }
    total_files++;
    printf("File %s created!\n", name);
}

void delete_file(char *name) {
    int file_index = -1;
    for (int i = 0; i < total_files; i++) {
        if (strcmp(files[i].name + 1, name) == 0) {
            file_index = i;
            break;
        }
    }
    if (file_index == -1) {
        printf("Error: File not found!\n");
        return;
    }
    int cur_block = files[file_index].start_block;
    while (1) {
        int next_block = files[cur_block].end_block;
        files[cur_block].name[0] = '\0';
        files[cur_block].start_block = -1;
        files[cur_block].end_block = -1;
        files[cur_block].size = -1;
        if (next_block == -1) {
            break;
        }
        cur_block = next_block;
    }
    total_files--;
    printf("File %s deleted!\n", name);
}

void list_files() {
    printf("Total Files: %d\n", total_files);
    for (int i = 0; i < total_files; i++) {
        printf("%s (%d bytes)\n", files[i].name + 1, files[i].size);
    }
}

int main() {
    char command[100];
    while (1) {
        printf("> ");
        scanf("%s", command);
        if (strcmp(command, "create") == 0) {
            char name[MAX_FILENAME_LENGTH];
            int size;
            scanf("%s %d", name, &size);
            create_file(name, size);
        } else if (strcmp(command, "delete") == 0) {
            char name[MAX_FILENAME_LENGTH];
            scanf("%s", name);
            delete_file(name);
        } else if (strcmp(command, "list") == 0) {
            list_files();
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command!\n");
        }
    }
    return 0;
}