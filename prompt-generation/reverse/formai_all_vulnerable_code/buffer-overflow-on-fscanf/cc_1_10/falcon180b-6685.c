//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 100

typedef struct {
    char word[MAX_WORD_LEN];
    char translation[MAX_WORD_LEN];
} word_t;

int main() {
    FILE *dict_file;
    word_t words[MAX_WORDS];
    int num_words = 0;

    dict_file = fopen("dictionary.txt", "r");
    if (dict_file == NULL) {
        printf("Error: could not open dictionary file.\n");
        return 1;
    }

    while (fscanf(dict_file, "%s %s", words[num_words].word, words[num_words].translation)!= EOF) {
        num_words++;
        if (num_words >= MAX_WORDS) {
            printf("Error: dictionary is too large.\n");
            fclose(dict_file);
            return 2;
        }
    }

    fclose(dict_file);

    char input_buffer[MAX_WORD_LEN];
    char output_buffer[MAX_WORD_LEN];

    while (1) {
        printf("Enter a phrase to translate (or type 'quit' to exit):\n");
        fgets(input_buffer, MAX_WORD_LEN, stdin);

        if (strcmp(input_buffer, "quit") == 0) {
            break;
        }

        char *token = strtok(input_buffer, " ");
        while (token!= NULL) {
            int i;
            for (i = 0; i < num_words; i++) {
                if (strcmp(token, words[i].word) == 0) {
                    strcpy(output_buffer, words[i].translation);
                    break;
                }
            }

            if (i == num_words) {
                strcpy(output_buffer, "unknown");
            }

            printf("%s -> %s\n", token, output_buffer);

            token = strtok(NULL, " ");
        }
    }

    return 0;
}