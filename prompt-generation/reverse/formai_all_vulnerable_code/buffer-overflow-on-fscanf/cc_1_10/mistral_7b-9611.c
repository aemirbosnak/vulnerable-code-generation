//MISTRAL-7B DATASET v1.0 Category: Sentiment analysis tool ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define WORD_LENGTH 50
#define DICTIONARY_SIZE 100

typedef struct {
    char word[WORD_LENGTH];
    int score;
} Word;

Word dictionary[DICTIONARY_SIZE];
int num_words;

void load_dictionary() {
    FILE *fp = fopen("romantic_words.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not open dictionary file.\n");
        exit(1);
    }

    num_words = 0;
    while (fscanf(fp, "%s %d", dictionary[num_words].word, &dictionary[num_words].score) != EOF) {
        num_words++;
    }

    fclose(fp);
}

int main() {
    char input[1000];
    int total_score = 0;
    int num_words_in_input = 0;

    load_dictionary();

    printf("Enter a romantic message: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    char *token = strtok(input, " ");
    while (token != NULL) {
        int i;
        int found = 0;

        for (i = 0; i < num_words; i++) {
            if (strcasecmp(token, dictionary[i].word) == 0) {
                total_score += dictionary[i].score;
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Warning: Unknown word '%s'. Please add it to the dictionary.\n", token);
        }

        token = strtok(NULL, " ");
        num_words_in_input++;
    }

    printf("The romantic message contains %d words.\n", num_words_in_input);
    printf("The score of the message is: %d\n", total_score);

    return 0;
}