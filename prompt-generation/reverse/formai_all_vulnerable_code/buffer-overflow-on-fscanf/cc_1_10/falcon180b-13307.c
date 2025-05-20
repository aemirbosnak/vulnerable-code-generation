//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WORD_LIST_SIZE 1000
#define WORD_LENGTH_MIN 4
#define WORD_LENGTH_MAX 10

char *word_list[WORD_LIST_SIZE];
int word_count = 0;

void load_words(char *filename)
{
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    char word[WORD_LENGTH_MAX + 1];
    while (fscanf(file, "%s", word)!= EOF) {
        if (strlen(word) >= WORD_LENGTH_MIN && strlen(word) <= WORD_LENGTH_MAX) {
            word_list[word_count++] = strdup(word);
        }
    }

    fclose(file);
}

int main()
{
    srand(time(NULL));

    load_words("words.txt");

    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given words to type. Type as many words as you can in 60 seconds.\n");
    printf("Press Enter to begin...\n");

    char input[WORD_LENGTH_MAX + 1];
    fgets(input, sizeof(input), stdin);

    int score = 0;
    int correct_words = 0;
    int incorrect_words = 0;

    time_t start_time = time(NULL);
    time_t end_time = start_time + 60;

    while (difftime(time(NULL), end_time) > 0) {
        int index = rand() % word_count;
        char *word = word_list[index];

        printf("%s\n", word);
        fgets(input, sizeof(input), stdin);

        if (strcmp(input, word) == 0) {
            score += strlen(word);
            correct_words++;
        } else {
            incorrect_words++;
        }
    }

    printf("\nTime's up!\n");
    printf("You typed %d words correctly and %d words incorrectly.\n", correct_words, incorrect_words);
    printf("Your final score is %d points.\n", score);

    return 0;
}