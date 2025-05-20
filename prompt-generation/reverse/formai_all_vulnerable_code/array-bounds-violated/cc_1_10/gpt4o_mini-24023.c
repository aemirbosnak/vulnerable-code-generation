//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

void convert_to_uppercase(const char *input_file, const char *output_file) {
    FILE *input_fp = fopen(input_file, "r");
    if (input_fp == NULL) {
        perror("Error opening input file");
        exit(1);
    }

    FILE *output_fp = fopen(output_file, "w");
    if (output_fp == NULL) {
        perror("Error opening output file");
        fclose(input_fp);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    int word_count = 0;

    while (fgets(line, sizeof(line), input_fp) != NULL) {
        for (int i = 0; line[i] != '\0'; i++) {
            line[i] = toupper(line[i]);
            if (isspace(line[i-1]) && !isspace(line[i])) {
                word_count++; // Count words based on spaces
            }
        }
        fputs(line, output_fp);
    }

    // If the last line has no newline, check if there's a word
    if (strlen(line) > 0 && !isspace(line[strlen(line) - 1])) {
        word_count++;
    }

    // Happy message at the end
    printf("🎉 Hooray! You've turned %d words into uppercase! 🎉\n", word_count);

    fclose(input_fp);
    fclose(output_fp);
}

int main() {
    char input_file[100];
    char output_file[100];

    printf("✨ Welcome to the Text Transforming Program! ✨\n");
    
    printf("Please enter the name of the input file: ");
    scanf("%99s", input_file);
    
    printf("Please enter the name of the output file: ");
    scanf("%99s", output_file);

    convert_to_uppercase(input_file, output_file);

    printf("🌟 Transformation complete! Check '%s' for your uppercased wonders! 🌟\n", output_file);
    return 0;
}