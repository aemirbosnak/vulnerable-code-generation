//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_WORDS 100
#define WORD_LENGTH 30
#define BUFFER_SIZE 1024
#define NUM_ROUNDS 5

typedef struct {
    char word[WORD_LENGTH];
    int is_typed;
} Word;

void generate_words(Word words[MAX_WORDS]) {
    FILE *file = fopen("dictionary.txt", "r");
    int index = 0;

    if (file != NULL) {
        char line[BUFFER_SIZE];
        while (fgets(line, BUFFER_SIZE, file)) {
            if (strlen(line) > WORD_LENGTH) continue;
            strcpy(words[index].word, line);
            words[index].is_typed = 0;
            index++;
        }
        fclose(file);
    }
}

void print_word(Word word) {
    printf(" %s", word.word);
}

int main() {
    srand(time(NULL));
    Word words[MAX_WORDS];
    generate_words(words);

    int round, correct_count = 0;
    for (round = 0; round < NUM_ROUNDS; round++) {
        int random_index = rand() % MAX_WORDS;
        Word current_word = words[random_index];
        printf("\nRound %d: ", round + 1);

        fflush(stdout);
        scanf("%s", current_word.word);
        fflush(stdin);

        if (strcmp(current_word.word, words[random_index].word) == 0) {
            printf("Correct!\n");
            correct_count++;
        } else {
            printf("Incorrect. The correct word was: ");
            print_word(words[random_index]);
        }

        words[random_index].is_typed = 1;
    }

    printf("\nTotal correct words: %d", correct_count);
    return 0;
}