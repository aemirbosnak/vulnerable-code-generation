//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 1000

struct WordCount {
    char word[MAX_WORD_LENGTH];
    int count;
};

int main() {
    char input_file[100];
    char output_file[100];
    char line[1000];
    FILE *input_fp, *output_fp;
    int num_words = 0;
    struct WordCount word_count[MAX_NUM_WORDS];

    // Read input file name
    printf("Enter the name of the input file: ");
    scanf("%s", input_file);

    // Read output file name
    printf("Enter the name of the output file: ");
    scanf("%s", output_file);

    // Open input file
    input_fp = fopen(input_file, "r");
    if (input_fp == NULL) {
        printf("Error: Could not open input file.\n");
        exit(1);
    }

    // Open output file
    output_fp = fopen(output_file, "w");
    if (output_fp == NULL) {
        printf("Error: Could not open output file.\n");
        exit(1);
    }

    // Read input file and count words
    while (fgets(line, sizeof(line), input_fp)!= NULL) {
        // Convert line to lowercase
        int i = 0;
        while (line[i]!= '\0') {
            line[i] = tolower(line[i]);
            i++;
        }

        // Split line into words
        char *word = strtok(line, ",.!?;:");
        while (word!= NULL) {
            // Check if word is already in word count array
            int j = 0;
            while (j < num_words && strcmp(word_count[j].word, word)!= 0) {
                j++;
            }

            // Increment word count if word is found
            if (j < num_words) {
                word_count[j].count++;
            } else {
                // Add new word to word count array
                if (num_words >= MAX_NUM_WORDS) {
                    printf("Error: Maximum number of words exceeded.\n");
                    exit(1);
                }
                strcpy(word_count[num_words].word, word);
                word_count[num_words].count = 1;
                num_words++;
            }

            word = strtok(NULL, ",.!?;:");
        }
    }

    // Write output file
    for (int i = 0; i < num_words; i++) {
        fprintf(output_fp, "%s: %d\n", word_count[i].word, word_count[i].count);
    }

    // Close files
    fclose(input_fp);
    fclose(output_fp);

    return 0;
}