//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

struct word {
    char word[MAX_WORD_LEN];
    int is_correct;
};

int main() {
    FILE *input_file, *output_file;
    char line[1000];
    char word[MAX_WORD_LEN];
    struct word words[MAX_WORDS];
    int num_words = 0;

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
        char *token = strtok(line, ",.?!;:");
        while (token!= NULL) {
            strcpy(word, token);
            int is_correct = 1;

            for (int i = 0; i < strlen(word); i++) {
                if (!isalpha(word[i])) {
                    is_correct = 0;
                    break;
                }
            }

            if (is_correct) {
                for (int i = 0; i < num_words; i++) {
                    if (strcmp(words[i].word, word) == 0) {
                        is_correct = 0;
                        break;
                    }
                }
            }

            if (is_correct) {
                strcpy(words[num_words].word, word);
                words[num_words].is_correct = 1;
                num_words++;
            } else {
                strcpy(words[num_words].word, word);
                words[num_words].is_correct = 0;
                num_words++;
            }

            token = strtok(NULL, ",.?!;:");
        }
    }

    fclose(input_file);
    fclose(output_file);

    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    for (int i = 0; i < num_words; i++) {
        if (words[i].is_correct) {
            fprintf(output_file, "%s ", words[i].word);
        } else {
            fprintf(output_file, "%s ", words[i].word);
        }
    }

    fclose(output_file);

    printf("Spell checking complete!\n");

    return 0;
}