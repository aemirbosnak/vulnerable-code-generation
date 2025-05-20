//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#define BLOCK_SIZE 512

struct inode {
    uint16_t mode;
    uint16_t nlinks;
    uint32_t uid;
    uint32_t gid;
    uint32_t size;
    uint32_t blocks[10];
};

struct directory_entry {
    uint32_t inode;
    char name[256];
};

struct file_system {
    struct inode inodes[1024];
    struct directory_entry directory[1024];
    uint8_t blocks[1024][BLOCK_SIZE];
};

struct file_system fs;

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file-system-image>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    fread(&fs, sizeof(fs), 1, file);
    fclose(file);

    char command[256];
    while (true) {
        printf("> ");
        fgets(command, sizeof(command), stdin);
        command[strlen(command) - 1] = '\0';

        if (strcmp(command, "ls") == 0) {
            for (int i = 0; i < 1024; i++) {
                if (fs.directory[i].inode != 0) {
                    printf("%s\n", fs.directory[i].name);
                }
            }
        } else if (strcmp(command, "cat") == 0) {
            char filename[256];
            printf("Enter filename: ");
            fgets(filename, sizeof(filename), stdin);
            filename[strlen(filename) - 1] = '\0';

            int inode = 0;
            for (int i = 0; i < 1024; i++) {
                if (strcmp(fs.directory[i].name, filename) == 0) {
                    inode = fs.directory[i].inode;
                    break;
                }
            }

            if (inode == 0) {
                printf("File not found\n");
                continue;
            }

            struct inode *node = &fs.inodes[inode];
            for (int i = 0; i < 10; i++) {
                if (node->blocks[i] != 0) {
                    printf("%s", fs.blocks[node->blocks[i]]);
                }
            }
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Unknown command\n");
        }
    }

    return EXIT_SUCCESS;
}