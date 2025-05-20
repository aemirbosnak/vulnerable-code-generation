//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

#define MAX_LINE_SIZE 1024
#define MAX_FILE_NAME_SIZE 256
#define MAX_COMMAND_LINE_SIZE 256
#define MAX_METADATA_SIZE 4096

typedef struct {
    char file_name[MAX_FILE_NAME_SIZE];
    char command_line[MAX_COMMAND_LINE_SIZE];
    char metadata[MAX_METADATA_SIZE];
} FileMetadata;

int get_file_metadata(const char *file_path, FileMetadata *metadata) {
    FILE *fp = fopen(file_path, "r");
    if (fp == NULL) {
        return -1;
    }
    char line[MAX_LINE_SIZE];
    fgets(line, MAX_LINE_SIZE, fp);
    sscanf(line, "%s", metadata->file_name);
    metadata->command_line[0] = '\0';
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        if (strncmp(line, "CommandLine:", 11) == 0) {
            strncat(metadata->command_line, line + 11, MAX_COMMAND_LINE_SIZE - strlen(metadata->command_line) - 1);
        } else if (strncmp(line, "Metadata:", 9) == 0) {
            strncat(metadata->metadata, line + 9, MAX_METADATA_SIZE - strlen(metadata->metadata) - 1);
        }
    }
    fclose(fp);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        return -1;
    }
    char file_path[MAX_FILE_NAME_SIZE];
    strncpy(file_path, argv[1], MAX_FILE_NAME_SIZE - 1);
    FileMetadata metadata;
    if (get_file_metadata(file_path, &metadata) == -1) {
        fprintf(stderr, "Error: Failed to get file metadata\n");
        return -1;
    }
    printf("File name: %s\n", metadata.file_name);
    printf("Command line: %s\n", metadata.command_line);
    printf("Metadata: %s\n", metadata.metadata);
    return 0;
}