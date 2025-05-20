//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    char input_file[MAX_LINE_LENGTH] = {0};
    char output_file[MAX_LINE_LENGTH] = {0};
    strncpy(input_file, argv[1], MAX_LINE_LENGTH - 1);
    strncpy(output_file, argv[2], MAX_LINE_LENGTH - 1);

    FILE *input_fp = fopen(input_file, "r");
    if (input_fp == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE *output_fp = fopen(output_file, "w");
    if (output_fp == NULL) {
        printf("Error opening output file.\n");
        fclose(input_fp);
        return 1;
    }

    char line[MAX_LINE_LENGTH] = {0};
    while (fgets(line, MAX_LINE_LENGTH, input_fp)!= NULL) {
        int line_length = strlen(line);
        if (line[line_length - 1] == '\n') {
            line[line_length - 1] = '\0';
        }

        char *token = strtok(line, " ");
        while (token!= NULL) {
            fprintf(output_fp, "%s\n", token);
            token = strtok(NULL, " ");
        }
    }

    fclose(input_fp);
    fclose(output_fp);
    return 0;
}