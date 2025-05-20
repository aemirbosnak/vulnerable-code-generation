//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <libgen.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_LINE_LENGTH 256

typedef struct {
    char *filename;
    char *author;
    char *title;
} Metadata;

Metadata *extractMetadata(char *filename) {
    FILE *fp;
    Metadata *metadata = malloc(sizeof(Metadata));
    char line[MAX_LINE_LENGTH];
    char *token;
    int inTitle = 0;

    metadata->filename = strdup(filename);
    metadata->author = NULL;
    metadata->title = NULL;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        if (strstr(line, "Author:")!= NULL) {
            token = strtok(line, " ");
            while (token!= NULL && strcmp(token, "Author:")!= 0) {
                token = strtok(NULL, " ");
            }
            metadata->author = strdup(token + 8);
        } else if (strstr(line, "Title:")!= NULL) {
            inTitle = 1;
            token = strtok(line, " ");
            while (token!= NULL && strcmp(token, "Title:")!= 0) {
                if (inTitle) {
                    metadata->title = realloc(metadata->title, strlen(metadata->title) + strlen(token) + 2);
                    strcat(metadata->title, " ");
                    strcat(metadata->title, token);
                }
                token = strtok(NULL, " ");
            }
        }
    }

    fclose(fp);

    return metadata;
}

void printMetadata(Metadata *metadata) {
    if (metadata->author!= NULL) {
        printf("Author: %s\n", metadata->author);
    }
    if (metadata->title!= NULL) {
        printf("Title: %s\n", metadata->title);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return 1;
    }

    Metadata *metadata = extractMetadata(argv[1]);
    printMetadata(metadata);

    free(metadata->filename);
    free(metadata->author);
    free(metadata->title);
    free(metadata);

    return 0;
}