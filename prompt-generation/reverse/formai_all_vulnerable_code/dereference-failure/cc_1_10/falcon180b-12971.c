//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORDS 5000
#define MAX_WORD_LENGTH 20

struct word {
    char word[MAX_WORD_LENGTH];
    int count;
};

int main() {
    FILE *input_file, *output_file;
    char line[1000];
    struct word words[MAX_WORDS];
    int num_words = 0;
    int i, j;

    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error opening input file.\n");
        exit(1);
    }

    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), input_file)!= NULL) {
        for (i = 0; i < strlen(line); i++) {
            if (isalpha(line[i])) {
                for (j = 0; j < num_words; j++) {
                    if (strcmp(words[j].word, line) == 0) {
                        words[j].count++;
                        break;
                    }
                }
                if (j == num_words) {
                    strcpy(words[num_words].word, line);
                    words[num_words].count = 1;
                    num_words++;
                }
            }
        }
    }

    for (i = 0; i < num_words; i++) {
        fprintf(output_file, "%s %d\n", words[i].word, words[i].count);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}