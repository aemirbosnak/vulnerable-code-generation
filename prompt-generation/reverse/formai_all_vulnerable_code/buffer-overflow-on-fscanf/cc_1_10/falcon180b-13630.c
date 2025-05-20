//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 10

char *words[MAX_WORDS];
int word_lengths[MAX_WORDS];
int num_words;

void load_words() {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: could not open words.txt\n");
        exit(1);
    }

    char word[MAX_WORD_LENGTH + 1] = { 0 };
    int i = 0;
    while (fscanf(file, "%s", word)!= EOF) {
        words[i] = strdup(word);
        word_lengths[i] = strlen(word);
        i++;
        if (i == MAX_WORDS) {
            break;
        }
    }
    num_words = i;

    fclose(file);
}

void test_typing_speed() {
    int correct = 0;
    int incorrect = 0;
    int total = 0;
    int score = 0;

    srand(time(NULL));
    int word_index = rand() % num_words;

    printf("You will be typing the following words:\n");
    for (int i = 0; i < num_words; i++) {
        printf("%d. %s\n", i + 1, words[i]);
    }

    printf("Press enter to begin...\n");
    getchar();

    for (int i = 0; i < 60; i++) {
        int word_to_type_index = rand() % num_words;
        char *word_to_type = words[word_to_type_index];
        int word_to_type_length = word_lengths[word_to_type_index];

        printf("Type the following word: ");
        for (int j = 0; j < word_to_type_length; j++) {
            printf("_");
        }
        printf("\n");

        char input[MAX_WORD_LENGTH + 1] = { 0 };
        fgets(input, MAX_WORD_LENGTH + 1, stdin);

        int input_length = strlen(input);
        if (input_length!= word_to_type_length) {
            printf("Incorrect\n");
            incorrect++;
        } else if (strcmp(input, word_to_type)!= 0) {
            printf("Incorrect\n");
            incorrect++;
        } else {
            printf("Correct\n");
            correct++;
        }

        total++;
    }

    score = (correct * 100) / total;

    printf("Your score is: %d%%\n", score);
}

int main() {
    load_words();
    test_typing_speed();

    return 0;
}