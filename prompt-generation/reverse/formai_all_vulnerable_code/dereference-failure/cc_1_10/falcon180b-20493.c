//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 20

typedef struct {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
} word_pair;

int main() {
    // Load dictionary
    FILE *dict_file = fopen("dictionary.txt", "r");
    if (dict_file == NULL) {
        printf("Error: Unable to open dictionary file.\n");
        return 1;
    }

    word_pair *dict = malloc(MAX_WORDS * sizeof(word_pair));
    int num_words = 0;

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, dict_file)!= NULL) {
        line[strcspn(line, "\n")] = '\0'; // Remove newline character
        if (strlen(line) == 0) {
            continue;
        }

        char *token = strtok(line, " ");
        if (token == NULL) {
            continue;
        }

        strcpy(dict[num_words].english, token);
        strcpy(dict[num_words].alien, "");
        num_words++;
    }

    fclose(dict_file);

    // Translate input
    char input_line[MAX_WORD_LENGTH];
    printf("Enter text to translate:\n");
    fgets(input_line, MAX_WORD_LENGTH, stdin);
    input_line[strcspn(input_line, "\n")] = '\0'; // Remove newline character

    char *token = strtok(input_line, " ");
    while (token!= NULL) {
        int i;
        for (i = 0; i < num_words; i++) {
            if (strcmp(dict[i].english, token) == 0) {
                printf("%s ", dict[i].alien);
                break;
            }
        }

        if (i == num_words) {
            printf("%s ", token);
        }

        token = strtok(NULL, " ");
    }

    printf("\n");
    return 0;
}