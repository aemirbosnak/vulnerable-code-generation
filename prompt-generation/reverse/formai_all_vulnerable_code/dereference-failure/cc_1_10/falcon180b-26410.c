//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 20

typedef struct {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    char line[100];
    char word[MAX_WORD_LEN];
    WordCount words[MAX_WORDS];
    int num_words = 0;
    int i, j;

    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: Could not open output file.\n");
        fclose(input_file);
        return 1;
    }

    while (fgets(line, sizeof(line), input_file)!= NULL) {
        for (i = 0; i < strlen(line); i++) {
            if (isalpha(line[i])) {
                strncpy(word, &line[i], MAX_WORD_LEN);
                word[strcspn(word, ".,!?;:\"'")] = '\0';
                for (j = 0; j < num_words; j++) {
                    if (strcmp(word, words[j].word) == 0) {
                        words[j].count++;
                        break;
                    }
                }
                if (j == num_words) {
                    strcpy(words[num_words].word, word);
                    words[num_words].count = 1;
                    num_words++;
                }
            }
        }
    }

    fprintf(output_file, "Word\tCount\n");
    for (i = 0; i < num_words; i++) {
        fprintf(output_file, "%s\t%d\n", words[i].word, words[i].count);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}