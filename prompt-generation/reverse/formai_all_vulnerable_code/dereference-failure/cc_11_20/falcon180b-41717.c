//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_SIZE 1024

typedef struct {
    char *name;
    int line_number;
    int num_occurrences;
} Function;

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s [input_file] [output_file]\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    int num_functions = 0;
    Function functions[100]; // arbitrary limit

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, input_file)!= NULL) {
        int i;
        for (i = 0; i < strlen(line); i++) {
            if (isalpha(line[i])) {
                int j;
                for (j = i + 1; j < strlen(line); j++) {
                    if (!isalpha(line[j])) {
                        break;
                    }
                }
                int line_number = atoi(line + i + 1);
                char *name = malloc(j - i + 1);
                strncpy(name, line + i + 1, j - i);
                name[j - i] = '\0';
                functions[num_functions].name = name;
                functions[num_functions].line_number = line_number;
                functions[num_functions].num_occurrences = 1;
                num_functions++;
            }
        }
    }

    fclose(input_file);
    fclose(output_file);

    for (int i = 0; i < num_functions; i++) {
        for (int j = i + 1; j < num_functions; j++) {
            if (strcmp(functions[i].name, functions[j].name) == 0) {
                if (functions[i].line_number > functions[j].line_number) {
                    functions[i].line_number = functions[j].line_number;
                }
            }
        }
    }

    for (int i = 0; i < num_functions; i++) {
        fprintf(output_file, "%s%d\n", functions[i].name, functions[i].line_number);
    }

    fclose(output_file);

    return 0;
}