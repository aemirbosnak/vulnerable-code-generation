//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

typedef struct {
    char word[MAX_WORD_LEN+1];
    int count;
} WordCount;

int compare_word_counts(const void *a, const void *b) {
    const WordCount *wc1 = a;
    const WordCount *wc2 = b;
    return wc2->count - wc1->count;
}

int main() {
    char input_file[100];
    char output_file[100];
    FILE *input, *output;
    char word[MAX_WORD_LEN+1];
    WordCount words[MAX_WORDS];
    int num_words = 0;
    int i, j, k;
    char *token;

    // get input and output file names
    printf("Enter input file name: ");
    scanf("%s", input_file);
    printf("Enter output file name: ");
    scanf("%s", output_file);

    // open input file
    input = fopen(input_file, "r");
    if (input == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    // read words from input file
    while (fscanf(input, "%s", word)!= EOF) {
        if (num_words >= MAX_WORDS) {
            printf("Error: too many words.\n");
            exit(1);
        }
        words[num_words].word[0] = tolower(word[0]);
        strcpy(words[num_words].word+1, word+1);
        words[num_words].count = 1;
        num_words++;
    }

    // sort words by count
    qsort(words, num_words, sizeof(WordCount), compare_word_counts);

    // write output to file
    output = fopen(output_file, "w");
    if (output == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }
    for (i = 0; i < num_words; i++) {
        fprintf(output, "%s %d\n", words[i].word, words[i].count);
    }

    // close input and output files
    fclose(input);
    fclose(output);

    return 0;
}