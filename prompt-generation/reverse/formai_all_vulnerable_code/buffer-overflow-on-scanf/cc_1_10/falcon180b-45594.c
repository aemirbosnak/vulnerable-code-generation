//Falcon-180B DATASET v1.0 Category: Data mining ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 50

struct word_count {
    char word[MAX_WORD_LEN];
    int count;
};

int main() {
    FILE *input_file;
    char filename[MAX_WORD_LEN];
    char line[MAX_WORD_LEN];
    int num_words;
    struct word_count counts[MAX_WORDS];
    int i;

    // Get filename from user
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open input file
    input_file = fopen(filename, "r");
    if (input_file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read file line by line and count words
    num_words = 0;
    while (fgets(line, MAX_WORD_LEN, input_file)!= NULL) {
        char *word = strtok(line, " \t\n\r");
        while (word!= NULL) {
            if (num_words >= MAX_WORDS) {
                printf("Too many words in file.\n");
                exit(1);
            }
            strcpy(counts[num_words].word, word);
            counts[num_words].count = 1;
            num_words++;
            word = strtok(NULL, " \t\n\r");
        }
    }

    // Sort words alphabetically
    for (i = 0; i < num_words - 1; i++) {
        int j;
        for (j = i + 1; j < num_words; j++) {
            if (strcmp(counts[i].word, counts[j].word) > 0) {
                struct word_count temp = counts[i];
                counts[i] = counts[j];
                counts[j] = temp;
            }
        }
    }

    // Print word counts
    printf("Word counts:\n");
    for (i = 0; i < num_words; i++) {
        printf("%s: %d\n", counts[i].word, counts[i].count);
    }

    // Close input file
    fclose(input_file);

    return 0;
}