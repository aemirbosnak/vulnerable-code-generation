//Falcon-180B DATASET v1.0 Category: File handling ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 100

void read_file(FILE* file, char* line) {
    char* buffer = malloc(MAX_LINE_LENGTH * sizeof(char));
    if (buffer == NULL) {
        printf("Error: Could not allocate memory for buffer.\n");
        exit(1);
    }

    fgets(buffer, MAX_LINE_LENGTH, file);
    strcpy(line, buffer);

    free(buffer);
}

void write_file(FILE* file, char* line) {
    fprintf(file, "%s", line);
}

int main() {
    FILE* input_file = fopen("input.txt", "r");
    FILE* output_file = fopen("output.txt", "w");

    if (input_file == NULL || output_file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    char line;
    while (fscanf(input_file, "%c", &line)!= EOF) {
        if (line == '\n') {
            write_file(output_file, "\n");
        } else {
            char* new_line = malloc(MAX_LINE_LENGTH * sizeof(char));
            if (new_line == NULL) {
                printf("Error: Could not allocate memory for line.\n");
                exit(1);
            }

            strcpy(new_line, "");
            int i = 0;

            while (i < MAX_LINE_LENGTH && fscanf(input_file, "%c", &line)!= EOF) {
                strcat(new_line, line);
                i++;
            }

            write_file(output_file, new_line);

            free(new_line);
        }
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}