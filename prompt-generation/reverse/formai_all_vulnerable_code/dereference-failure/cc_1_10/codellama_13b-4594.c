//Code Llama-13B DATASET v1.0 Category: Metadata Extractor ; Style: scalable
/*
 * A scalable C metadata extractor example program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 256
#define MAX_KEYWORD_LEN 32
#define MAX_FILE_LEN 1024

typedef struct {
    char filename[MAX_FILENAME_LEN];
    char keyword[MAX_KEYWORD_LEN];
    char content[MAX_FILE_LEN];
} FileInfo;

void extractMetadata(FileInfo *file_info, char *keyword) {
    char *file_content = file_info->content;
    char *match = strstr(file_content, keyword);
    if (match != NULL) {
        char *metadata = strtok(match, " ");
        strcpy(file_info->keyword, metadata);
    }
}

int main(int argc, char *argv[]) {
    FileInfo *file_info = malloc(sizeof(FileInfo));
    char filename[MAX_FILENAME_LEN];
    char keyword[MAX_KEYWORD_LEN];
    char file_content[MAX_FILE_LEN];

    strcpy(filename, argv[1]);
    strcpy(keyword, argv[2]);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        return 1;
    }

    fread(file_content, sizeof(char), MAX_FILE_LEN, fp);
    fclose(fp);

    strcpy(file_info->filename, filename);
    strcpy(file_info->keyword, keyword);
    strcpy(file_info->content, file_content);

    extractMetadata(file_info, keyword);

    printf("Metadata for file %s:\n", file_info->filename);
    printf("Keyword: %s\n", file_info->keyword);
    printf("Content: %s\n", file_info->content);

    free(file_info);
    return 0;
}