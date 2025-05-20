//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define CHAR_SET "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789.,!?@#$%^&*()_+-=[]{};:<>/|\\"

int main() {
    char input_file[100];
    char output_file[100];
    char line[MAX_WIDTH];
    char *word;
    FILE *input_fp, *output_fp;
    int width = 0, height = 0, i, j, letter_count = 0;
    int font_size = 8; // Default font size
    int max_letters = MAX_WIDTH / (int)strlen("M"); // Maximum number of letters per line

    printf("Enter the name of the input file: ");
    scanf("%s", input_file);
    printf("Enter the name of the output file: ");
    scanf("%s", output_file);

    input_fp = fopen(input_file, "r");
    if (input_fp == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    output_fp = fopen(output_file, "w");
    if (output_fp == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    while (fgets(line, MAX_WIDTH, input_fp)!= NULL) {
        width = 0;
        height += 2; // Add 2 for line spacing
        letter_count = 0;
        for (i = 0; i < strlen(line); i++) {
            if (isalpha(line[i])) {
                width++;
                letter_count++;
            }
        }
        if (width > max_letters) {
            printf("Warning: Line exceeds maximum width. Truncating.\n");
            width = max_letters;
        }
        for (i = 0; i < strlen(line); i++) {
            if (isalpha(line[i])) {
                word = &line[i];
                while (isalpha(*word)) {
                    fprintf(output_fp, "%c", toupper(*word));
                    word++;
                }
            } else {
                fprintf(output_fp, "%c", line[i]);
            }
        }
        fprintf(output_fp, "\n");
    }

    fclose(input_fp);
    fclose(output_fp);

    printf("ASCII art generated successfully in %s.\n", output_file);

    return 0;
}