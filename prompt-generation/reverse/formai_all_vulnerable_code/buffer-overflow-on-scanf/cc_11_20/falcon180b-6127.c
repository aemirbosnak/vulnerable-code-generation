//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 20

struct word {
    char word[MAX_WORD_LENGTH];
    int count;
};

int main() {
    char input_file[MAX_WORD_LENGTH];
    char output_file[MAX_WORD_LENGTH];
    char line[MAX_WORD_LENGTH];
    FILE *fp_in, *fp_out;
    struct word words[MAX_WORDS];
    int num_words = 0;
    int i, j, k;
    
    // Prompt user for input file name
    printf("Enter input file name: ");
    scanf("%s", input_file);
    
    // Prompt user for output file name
    printf("Enter output file name: ");
    scanf("%s", output_file);
    
    // Open input file
    fp_in = fopen(input_file, "r");
    if (fp_in == NULL) {
        printf("Error: cannot open input file.\n");
        exit(1);
    }
    
    // Open output file
    fp_out = fopen(output_file, "w");
    if (fp_out == NULL) {
        printf("Error: cannot open output file.\n");
        exit(1);
    }
    
    // Read input file and count words
    while (fgets(line, MAX_WORD_LENGTH, fp_in)!= NULL) {
        for (i = 0; i < strlen(line); i++) {
            if (isalpha(line[i])) {
                // Check if word already exists in array
                for (j = 0; j < num_words; j++) {
                    if (strcmp(words[j].word, line) == 0) {
                        // Increment count for existing word
                        words[j].count++;
                        break;
                    }
                }
                // Add new word to array if it doesn't already exist
                if (j == num_words) {
                    strcpy(words[num_words].word, line);
                    words[num_words].count = 1;
                    num_words++;
                }
            }
        }
    }
    
    // Sort words by frequency
    for (i = 0; i < num_words - 1; i++) {
        for (j = i + 1; j < num_words; j++) {
            if (words[i].count < words[j].count) {
                // Swap words and their counts
                struct word temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
    
    // Write output file
    for (i = 0; i < num_words; i++) {
        fprintf(fp_out, "%s %d\n", words[i].word, words[i].count);
    }
    
    // Close files
    fclose(fp_in);
    fclose(fp_out);
    
    return 0;
}