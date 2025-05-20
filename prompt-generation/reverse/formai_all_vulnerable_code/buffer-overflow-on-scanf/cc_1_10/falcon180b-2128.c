//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_ELEMENTS 100

struct element {
    char *tag;
    char *content;
    int length;
};

int main(int argc, char **argv) {
    FILE *input_file = NULL;
    FILE *output_file = NULL;
    char input_filename[100];
    char output_filename[100];
    char line[MAX_LINE_LENGTH];
    char *delimiter = " ";
    char *token = NULL;
    int line_number = 0;
    int num_elements = 0;
    struct element elements[MAX_ELEMENTS];

    printf("Enter the input filename: ");
    scanf("%s", input_filename);
    printf("Enter the output filename: ");
    scanf("%s", output_filename);

    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, input_file)!= NULL) {
        line_number++;
        token = strtok(line, delimiter);
        while (token!= NULL) {
            if (num_elements == MAX_ELEMENTS) {
                printf("Error: Maximum number of elements reached.\n");
                exit(1);
            }

            int length = strlen(token);
            elements[num_elements].tag = malloc(length + 1);
            strcpy(elements[num_elements].tag, token);
            elements[num_elements].content = malloc(length + 1);
            strcpy(elements[num_elements].content, token);
            elements[num_elements].length = length;

            num_elements++;

            token = strtok(NULL, delimiter);
        }
    }

    fclose(input_file);
    fclose(output_file);

    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    for (int i = 0; i < num_elements; i++) {
        fprintf(output_file, "%s", elements[i].tag);
        fprintf(output_file, "%s", elements[i].content);
        fprintf(output_file, "\n");
    }

    fclose(output_file);

    printf("HTML beautification completed successfully.\n");

    return 0;
}