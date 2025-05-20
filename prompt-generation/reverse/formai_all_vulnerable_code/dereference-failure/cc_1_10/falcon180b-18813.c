//Falcon-180B DATASET v1.0 Category: Error handling ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_ERROR_MESSAGE_LENGTH 256

typedef struct {
    char *message;
    char *filename;
    int line_number;
} Error;

int main(int argc, char **argv) {
    FILE *fp;
    char *filename = argv[1];
    char line[MAX_LINE_LENGTH];
    char *token;
    Error error;
    int line_number = 1;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file %s: %s\n", filename, strerror(errno));
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        token = strtok(line, " \t\n");
        while (token!= NULL) {
            if (strlen(token) > 0 && token[0] == '#') {
                // skip comment lines
                break;
            }
            if (strlen(token) > 0 && token[0] == '@') {
                // parse error message
                error.message = strdup(token + 1);
                error.filename = strdup(filename);
                error.line_number = line_number;
                printf("Error: %s\n", error.message);
                exit(1);
            }
            token = strtok(NULL, " \t\n");
        }
        line_number++;
    }

    fclose(fp);
    return 0;
}