//Falcon-180B DATASET v1.0 Category: Error handling ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file, *output_file;
    char input_line[MAX_LINE_LENGTH], output_line[MAX_LINE_LENGTH];
    int input_line_num = 0, output_line_num = 0;

    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        perror(argv[1]);
        return 1;
    }

    output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        perror(argv[2]);
        return 1;
    }

    while (fgets(input_line, MAX_LINE_LENGTH, input_file)!= NULL) {
        input_line_num++;
        if (strlen(input_line) == 0) {
            // skip empty lines
            continue;
        }
        if (input_line[strlen(input_line) - 1] == '\n') {
            // remove newline character from the end of the line
            input_line[strlen(input_line) - 1] = '\0';
        }
        char *token = strtok(input_line, " ");
        while (token!= NULL) {
            if (strlen(token) == 0) {
                // skip empty tokens
                continue;
            }
            if (strlen(output_line) + strlen(token) + 1 >= MAX_LINE_LENGTH) {
                // output line is too long, write to file and start a new line
                fputs(output_line, output_file);
                output_line_num++;
                output_line[0] = '\0';
            }
            strcat(output_line, token);
            strcat(output_line, " ");
            token = strtok(NULL, " ");
        }
        if (strlen(output_line) > 0) {
            // write last line to file
            fputs(output_line, output_file);
            output_line_num++;
            output_line[0] = '\0';
        }
    }

    fclose(input_file);
    fclose(output_file);

    printf("Processed %d lines from %s to %s\n", input_line_num, argv[1], argv[2]);

    return 0;
}