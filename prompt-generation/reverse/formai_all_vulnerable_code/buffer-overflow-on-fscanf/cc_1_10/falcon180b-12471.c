//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LENGTH 20

char words[MAX_WORDS][MAX_WORD_LENGTH];
int num_words;

void load_words() {
    FILE *file;
    char word[MAX_WORD_LENGTH];
    int i = 0;

    file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error loading words.\n");
        exit(1);
    }

    while (fscanf(file, "%s", word)!= EOF) {
        strcpy(words[i], word);
        i++;
    }

    fclose(file);
    num_words = i;
}

int main() {
    load_words();

    int score = 0;
    int correct_words = 0;
    int incorrect_words = 0;
    int total_words = 0;
    int start_time, end_time;

    srand(time(NULL));
    int rand_index = rand() % num_words;

    printf("Welcome to the Typing Speed Test!\n");
    printf("You will have 60 seconds to type as many words as possible.\n");
    printf("Press enter to begin...\n");
    getchar();

    start_time = clock();

    while (clock() - start_time < 60000) {
        int word_index = rand() % num_words;
        int word_length = strlen(words[word_index]);
        char *word = words[word_index];

        printf("%s", word);

        char input[MAX_WORD_LENGTH];
        fgets(input, MAX_WORD_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';

        total_words++;

        if (strcmp(input, word) == 0) {
            correct_words++;
        } else {
            incorrect_words++;
        }

        rand_index = (rand_index + 1) % num_words;
    }

    end_time = clock();
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    score = (int)((double)correct_words / total_words * 100);

    printf("\nTest complete!\n");
    printf("You typed %d words in %.2f seconds.\n", total_words, elapsed_time);
    printf("Your score is %d%% correct.\n", score);

    return 0;
}