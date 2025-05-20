//Falcon-180B DATASET v1.0 Category: Typing Speed Test ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_WORDS 100
#define MAX_WORD_LEN 20
#define MAX_TEST_TIME 60

typedef struct {
    char word[MAX_WORD_LEN];
    int length;
} Word;

Word words[MAX_WORDS];

void generate_words() {
    FILE *file = fopen("words.txt", "r");
    if (file == NULL) {
        printf("Error: words.txt not found.\n");
        exit(1);
    }

    int count = 0;
    while (fscanf(file, "%s", words[count].word)!= EOF && count < MAX_WORDS) {
        words[count].length = strlen(words[count].word);
        count++;
    }

    fclose(file);
}

int main() {
    srand(time(NULL));

    generate_words();

    int score = 0;
    int correct = 0;
    int incorrect = 0;
    int time_left = MAX_TEST_TIME;

    printf("Welcome to the Typing Speed Test!\n");
    printf("You will have %d seconds to type as many words as possible.\n", MAX_TEST_TIME);
    printf("Press enter to begin...\n");
    getchar();

    while (time_left > 0 && score < MAX_WORDS) {
        int word_index = rand() % MAX_WORDS;
        Word word = words[word_index];

        printf("%s ", word.word);

        char input[MAX_WORD_LEN];
        fgets(input, sizeof(input), stdin);

        int input_length = strlen(input);
        if (input_length == word.length && strcasecmp(input, word.word) == 0) {
            correct++;
            score++;
        } else {
            incorrect++;
        }

        time_left--;
    }

    printf("\nTest complete.\n");
    printf("Score: %d\n", score);
    printf("Correct: %d\n", correct);
    printf("Incorrect: %d\n", incorrect);

    return 0;
}