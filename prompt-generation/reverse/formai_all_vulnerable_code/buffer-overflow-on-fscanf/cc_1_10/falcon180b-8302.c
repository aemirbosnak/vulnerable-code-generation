//Falcon-180B DATASET v1.0 Category: Alien Language Translator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000 //maximum number of words in the dictionary
#define MAX_WORD_LENGTH 20 //maximum length of a word

typedef struct {
    char english[MAX_WORD_LENGTH];
    char alien[MAX_WORD_LENGTH];
} word_t;

void load_dictionary(word_t dictionary[MAX_WORDS]) {
    FILE *file = fopen("dictionary.txt", "r");
    if (file == NULL) {
        printf("Error loading dictionary.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s %s\n", dictionary[count].english, dictionary[count].alien)!= EOF) {
        count++;
        if (count >= MAX_WORDS) {
            printf("Dictionary too large.\n");
            exit(1);
        }
    }

    fclose(file);
}

int main() {
    word_t dictionary[MAX_WORDS];
    load_dictionary(dictionary);

    char input[MAX_WORD_LENGTH];
    printf("Enter a sentence to translate:\n");
    fgets(input, MAX_WORD_LENGTH, stdin);

    char output[MAX_WORD_LENGTH];
    int output_length = 0;

    char *word = strtok(input, " ");
    while (word!= NULL) {
        int i;
        for (i = 0; i < MAX_WORDS; i++) {
            if (strcmp(word, dictionary[i].english) == 0) {
                strcpy(output + output_length, dictionary[i].alien);
                output_length += strlen(dictionary[i].alien);
                break;
            }
        }

        if (i == MAX_WORDS) {
            printf("Unknown word: %s\n", word);
        }

        word = strtok(NULL, " ");
    }

    printf("Alien translation: %s\n", output);

    return 0;
}