//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKEN_LEN 64
#define MAX_LINE_LEN 1024

// Function to extract metadata from a C file
void extract_metadata(FILE *fp, char *filename) {
    int line_num = 0;
    char line[MAX_LINE_LEN];
    char token[MAX_TOKEN_LEN];
    char *p = NULL;

    // Extract file name
    strcpy(token, filename);
    p = strrchr(token, '/');
    if (p!= NULL) {
        *p = '\0';
    }
    printf("File name: %s\n", token);

    // Extract line count
    rewind(fp);
    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        line_num++;
    }
    printf("Line count: %d\n", line_num);

    // Extract function count
    rewind(fp);
    int func_count = 0;
    while (fgets(line, MAX_LINE_LEN, fp)!= NULL) {
        if (strstr(line, "{")!= NULL) {
            func_count++;
        }
    }
    printf("Function count: %d\n", func_count);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Unable to open file '%s'\n", argv[1]);
        return 1;
    }

    extract_metadata(fp, argv[1]);

    fclose(fp);
    return 0;
}