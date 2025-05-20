//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000
#define BLOCK_SIZE 512

typedef struct {
    char filename[100];
    int size;
    int num_blocks;
    int start_block;
} FileInfo;

typedef struct {
    int block_num;
    int next_block;
} Block;

Block* free_list;
int num_free_blocks;

void init() {
    free_list = (Block*)malloc(sizeof(Block) * MAX_FILE_SIZE);
    num_free_blocks = MAX_FILE_SIZE;
    for (int i = 0; i < MAX_FILE_SIZE; i++) {
        free_list[i].block_num = i;
        free_list[i].next_block = -1;
    }
}

int get_free_block() {
    if (num_free_blocks == 0) {
        printf("No free blocks left!\n");
        exit(1);
    }
    int block_num = free_list[--num_free_blocks].block_num;
    return block_num;
}

void add_free_block(int block_num) {
    free_list[num_free_blocks++].block_num = block_num;
}

void delete_file(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File not found!\n");
        exit(1);
    }
    fclose(fp);
    remove(filename);
}

int main() {
    init();
    char command[100];
    while (1) {
        printf("Enter command: ");
        scanf("%s", command);
        if (strcmp(command, "create") == 0) {
            char filename[100];
            printf("Enter filename: ");
            scanf("%s", filename);
            FILE* fp = fopen(filename, "w");
            if (fp == NULL) {
                printf("File creation failed!\n");
            } else {
                fclose(fp);
            }
        } else if (strcmp(command, "delete") == 0) {
            char filename[100];
            printf("Enter filename: ");
            scanf("%s", filename);
            delete_file(filename);
        } else if (strcmp(command, "recover") == 0) {
            char filename[100];
            printf("Enter filename: ");
            scanf("%s", filename);
            FILE* fp = fopen(filename, "r");
            if (fp == NULL) {
                printf("File not found!\n");
            } else {
                fclose(fp);
            }
        } else {
            printf("Invalid command!\n");
        }
    }
    return 0;
}