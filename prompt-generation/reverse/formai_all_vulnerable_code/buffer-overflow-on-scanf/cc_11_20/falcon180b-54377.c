//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

struct word_count {
    char word[MAX_WORD_LENGTH + 1];
    int count;
};

int main() {
    FILE *input_file, *output_file;
    char input_filename[MAX_WORD_LENGTH + 1];
    char output_filename[MAX_WORD_LENGTH + 1];
    struct word_count words[MAX_WORDS];
    int num_words = 0;
    int i, j;
    char ch;

    // Get input file name from user
    printf("Enter the name of the input file: ");
    scanf("%s", input_filename);

    // Open input file
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // Read words from input file
    while ((ch = fgetc(input_file))!= EOF) {
        if (isalnum(ch)) {
            words[num_words].word[0] = tolower(ch);
            words[num_words].count = 1;
            num_words++;
        } else if (num_words > 0) {
            words[num_words - 1].count++;
        }
    }

    // Close input file
    fclose(input_file);

    // Calculate word frequencies
    for (i = 0; i < num_words; i++) {
        for (j = i + 1; j < num_words; j++) {
            if (strcmp(words[i].word, words[j].word) == 0) {
                words[i].count += words[j].count;
                words[j].count = 0;
            }
        }
    }

    // Get output file name from user
    printf("Enter the name of the output file: ");
    scanf("%s", output_filename);

    // Open output file
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    // Write word frequencies to output file
    for (i = 0; i < num_words; i++) {
        if (words[i].count > 0) {
            fprintf(output_file, "%s: %d\n", words[i].word, words[i].count);
        }
    }

    // Close output file
    fclose(output_file);

    return 0;
}