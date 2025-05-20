//FormAI DATASET v1.0 Category: HTML beautifier ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 10000

void beautify_html(char *input_file_path, char *output_file_path);

int main() {
    char input_file_path[100], output_file_path[100];
    printf("Enter the path of input file: ");
    scanf("%s", input_file_path);
    printf("Enter the path of output file: ");
    scanf("%s", output_file_path);
    beautify_html(input_file_path, output_file_path);
    return 0;
}

void beautify_html(char *input_file_path, char *output_file_path) {
    FILE *input_file = fopen(input_file_path, "r"), *output_file = fopen(output_file_path, "w");
    if (input_file == NULL || output_file == NULL) {
        printf("Error opening input/output file!");
        exit(0);
    }

    char input[MAX_SIZE];
    int tabs = 0;
    while (fgets(input, MAX_SIZE, input_file) != NULL) {
        int len = strlen(input);
        char prev = '\0';
        for (int i = 0; i < len; i++) {
            if (input[i] == '<') {
                if (prev == '\n') {
                    for (int j = 0; j < tabs; j++) {
                        fprintf(output_file, "\t");
                    }
                }
                fprintf(output_file, "<");
                if (i+1 < len && input[i+1] == '/') {
                    tabs--;
                } else {
                    tabs++;
                }
            } else if (input[i] == '>') {
                fprintf(output_file, ">\n");
            } else {
                fprintf(output_file, "%c", input[i]);
            }
            prev = input[i];
        }
    }

    fclose(input_file);
    fclose(output_file);
    printf("HTML file beautified successfully!");
}