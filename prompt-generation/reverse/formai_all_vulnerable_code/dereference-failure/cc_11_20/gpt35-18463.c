//FormAI DATASET v1.0 Category: System boot optimizer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 10000

int main(int argc, char** argv) {
    char* input_file_path = NULL;
    char* output_file_path = NULL;
    int verbose = 0;    // Default to minimal output
    int randomize = 0;  // Default to sorting lines alphabetically

    // Parse command line arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-i") == 0) {
            input_file_path = argv[++i];
        } else if (strcmp(argv[i], "-o") == 0) {
            output_file_path = argv[++i];
        } else if (strcmp(argv[i], "-v") == 0) {
            verbose = 1;
        } else if (strcmp(argv[i], "-r") == 0) {
            randomize = 1;
        } else {
            fprintf(stderr, "Unknown option: %s\n", argv[i]);
            return 1;
        }
    }

    // Open input file
    FILE* input_file = stdin;
    if (input_file_path != NULL) {
        input_file = fopen(input_file_path, "r");
        if (input_file == NULL) {
            perror("Failed to open input file");
            return 1;
        }
    }

    // Read all lines from input file
    char** lines = malloc(MAX_NUM_LINES * sizeof(char*));
    int num_lines = 0;
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL) {
        // Remove trailing newline character
        line[strcspn(line, "\n")] = '\0';

        // Allocate memory for line and copy it
        char* copy = malloc(strlen(line) + 1);
        strcpy(copy, line);

        lines[num_lines++] = copy;
        if (num_lines == MAX_NUM_LINES) {
            fprintf(stderr, "Maximum number of lines exceeded\n");
            return 1;
        }
    }

    // Close input file
    if (input_file != stdin) {
        fclose(input_file);
    }

    // Sort or randomize the lines
    if (!randomize) {
        qsort(lines, num_lines, sizeof(char*), strcmp);
    } else {
        srand(time(NULL));
        for (int i = 0; i < num_lines; i++) {
            // Swap line i with a random line
            int j = rand() % num_lines;
            char* tmp = lines[i];
            lines[i] = lines[j];
            lines[j] = tmp;
        }
    }

    // Open output file
    FILE* output_file = stdout;
    if (output_file_path != NULL) {
        output_file = fopen(output_file_path, "w");
        if (output_file == NULL) {
            perror("Failed to open output file");
            return 1;
        }
    }

    // Write lines to output file
    for (int i = 0; i < num_lines; i++) {
        if (verbose) {
            printf("%s\n", lines[i]);
        }
        fprintf(output_file, "%s\n", lines[i]);
    }

    // Close output file
    if (output_file != stdout) {
        fclose(output_file);
    }

    // Free memory allocated for lines
    for (int i = 0; i < num_lines; i++) {
        free(lines[i]);
    }
    free(lines);

    return 0;
}