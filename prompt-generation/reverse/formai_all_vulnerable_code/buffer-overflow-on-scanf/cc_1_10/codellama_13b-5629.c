//Code Llama-13B DATASET v1.0 Category: File system simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define BLOCK_SIZE 1024
#define FILE_SIZE 4096

typedef struct {
    char name[100];
    uint32_t size;
    uint32_t offset;
} File;

typedef struct {
    char name[100];
    uint32_t size;
    uint32_t offset;
    uint32_t inode;
} Directory;

typedef struct {
    char name[100];
    uint32_t size;
    uint32_t offset;
    uint32_t inode;
    uint32_t link_count;
} Link;

int main() {
    char filename[100];
    char filedata[FILE_SIZE];
    char directory[100];
    char linkname[100];
    char linktarget[100];
    uint32_t file_size;
    uint32_t directory_size;
    uint32_t link_size;

    // Initialize file system
    FILE *fs = fopen("file.sys", "w+");
    fseek(fs, 0, SEEK_SET);

    // Create file
    printf("Enter file name: ");
    scanf("%s", filename);
    printf("Enter file data: ");
    scanf("%s", filedata);
    file_size = strlen(filedata);
    fwrite(filedata, sizeof(char), file_size, fs);

    // Create directory
    printf("Enter directory name: ");
    scanf("%s", directory);
    directory_size = strlen(directory);
    fwrite(directory, sizeof(char), directory_size, fs);

    // Create link
    printf("Enter link name: ");
    scanf("%s", linkname);
    printf("Enter link target: ");
    scanf("%s", linktarget);
    link_size = strlen(linktarget);
    fwrite(linktarget, sizeof(char), link_size, fs);

    // Read file
    fseek(fs, 0, SEEK_SET);
    fread(filedata, sizeof(char), file_size, fs);
    printf("File data: %s\n", filedata);

    // Read directory
    fseek(fs, file_size, SEEK_SET);
    fread(directory, sizeof(char), directory_size, fs);
    printf("Directory: %s\n", directory);

    // Read link
    fseek(fs, file_size + directory_size, SEEK_SET);
    fread(linktarget, sizeof(char), link_size, fs);
    printf("Link target: %s\n", linktarget);

    fclose(fs);
    return 0;
}