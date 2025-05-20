//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WORDS_COUNT 10
#define MAX_WORD_LENGTH 20
#define LINE_LENGTH 80

void print_random_words(char words[][MAX_WORD_LENGTH], int count) {
    int i;
    for (i = 0; i < count; i++) {
        printf("%s ", words[rand() % count]);
        if ((i + 1) % LINE_LENGTH == 0) {
            printf("\n");
        }
    }
    printf("\nReady? Press Enter to start...\n");
    getchar();
    system("clear"); // or cls on Windows
}

int main() {
    srand(time(NULL));
    char words[WORDS_COUNT][MAX_WORD_LENGTH];
    int i, j;

    for (i = 0; i < WORDS_COUNT; i++) {
        scanf("%s", words[i]);
    }

    print_random_words(words, WORDS_COUNT);

    clock_t start = clock();
    char user_input[LINE_LENGTH];
    int correct_count = 0;

    for (i = 0; i < WORDS_COUNT; i++) {
        printf("%s ", words[i]);
        fgets(user_input, LINE_LENGTH, stdin);
        user_input[strlen(user_input) - 1] = '\0';

        if (strcmp(words[i], user_input) == 0) {
            correct_count++;
        }
    }

    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    double wpm = (double)correct_count * WORDS_COUNT * 60 / time_spent;

    printf("You typed %d words correctly in %.2f seconds.\n", correct_count, time_spent);
    printf("Your typing speed is %.2f wpm.\n", wpm);

    return 0;
}