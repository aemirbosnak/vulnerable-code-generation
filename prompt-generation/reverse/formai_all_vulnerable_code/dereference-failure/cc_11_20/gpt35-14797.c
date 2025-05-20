//FormAI DATASET v1.0 Category: Text processing ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

int main(int argc, char *argv[]) {

    char *filename = NULL;
    char *prefix = NULL;
    char *suffix = NULL;

    printf("Welcome to the Text Processor Program!\n");

    // Parsing command line arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--filename") == 0 || strcmp(argv[i], "-f") == 0) {
            i++;
            if (i < argc) {
                filename = argv[i];
            }
        } else if (strcmp(argv[i], "--prefix") == 0 || strcmp(argv[i], "-p") == 0) {
            i++;
            if (i < argc) {
                prefix = argv[i];
            }
        } else if (strcmp(argv[i], "--suffix") == 0 || strcmp(argv[i], "-s") == 0) {
            i++;
            if (i < argc) {
                suffix = argv[i];
            }
        }
    }

    printf("Configuring the Text Processor Program...\n");
    printf("Selected File: %s\n", filename);
    printf("Prefix: %s\n", prefix);
    printf("Suffix: %s\n", suffix);

    // Reading the input file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    int line_number = 1;
    char line[MAX_LINE_LENGTH];
    printf("Starting text processing...\n");

    // Processing each line of the input file
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        if (prefix) {
            printf("%s ", prefix);
        }
        printf("%d: %s", line_number, line);
        if (suffix) {
            printf("%s", suffix);
        }
        line_number++;
    }

    printf("Text processing completed successfully!\n");

    fclose(file);
    return 0;
}