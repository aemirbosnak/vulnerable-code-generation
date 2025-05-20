//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: decentralized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE_LEN 1024
#define MAX_WORD_LEN 64
#define MAX_FILE_NAME_LEN 256
#define MAX_KEYWORDS 10
#define MAX_KEYWORD_LEN 64

typedef struct {
    char file_name[MAX_FILE_NAME_LEN];
    char keywords[MAX_KEYWORDS][MAX_KEYWORD_LEN];
    int num_keywords;
} Metadata;

void read_file(FILE* fp, char* line) {
    char c;
    int len = 0;

    while ((c = fgetc(fp))!= EOF) {
        if (len >= MAX_LINE_LEN) {
            fprintf(stderr, "Line too long: %s", line);
            exit(1);
        }
        if (isalnum(c)) {
            line[len++] = tolower(c);
        }
    }
    line[len] = '\0';
}

void extract_metadata(char* line, Metadata* metadata) {
    char* word;
    int i = 0;
    char* delimiters = " \t\n\r\f";

    word = strtok(line, delimiters);
    while (word!= NULL) {
        if (i >= MAX_KEYWORDS) {
            fprintf(stderr, "Too many keywords: %s", word);
            exit(1);
        }
        strcpy(metadata->keywords[i], word);
        i++;
        word = strtok(NULL, delimiters);
    }
    metadata->num_keywords = i;
}

void write_metadata(FILE* fp, Metadata* metadata) {
    int i;

    fprintf(fp, "File: %s\n", metadata->file_name);
    fprintf(fp, "Keywords:\n");
    for (i = 0; i < metadata->num_keywords; i++) {
        fprintf(fp, "  %s\n", metadata->keywords[i]);
    }
}

int main(int argc, char** argv) {
    FILE* fp;
    char line[MAX_LINE_LEN];
    Metadata metadata;
    char file_name[MAX_FILE_NAME_LEN];

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    strcpy(file_name, argv[1]);
    fp = fopen(file_name, "r");

    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", file_name);
        return 1;
    }

    metadata.num_keywords = 0;
    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        extract_metadata(line, &metadata);
    }

    write_metadata(stdout, &metadata);

    fclose(fp);
    return 0;
}