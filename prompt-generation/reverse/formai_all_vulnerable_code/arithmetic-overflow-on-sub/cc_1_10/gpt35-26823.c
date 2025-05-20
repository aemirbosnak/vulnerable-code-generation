//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MIN_WORD_LENGTH 3
#define MAX_WORD_LENGTH 15
#define NUM_WORDS 10
#define DELAY 3000

int main()
{
    char* words[] = {"apple", "banana", "cherry", "dog", "elephant", "flower",
                     "grape", "house", "igloo", "jellyfish"};
    int num_correct = 0;
    float elapsed_time = 0;

    srand(time(NULL));
    printf("Welcome to the Typing Speed Test!\n\n");
    printf("You will be given 10 random words to type as quickly and accurately as possible.\n");
    printf("Press 'Enter' to begin.\n");
    getchar();

    for (int i = 0; i < NUM_WORDS; i++) {
        char* word = words[rand() % NUM_WORDS];
        int len = strlen(word);
        if (len < MIN_WORD_LENGTH || len > MAX_WORD_LENGTH) continue;
        printf("Type the word: %s\n", word);
        fflush(stdout);
        clock_t start_time = clock();
        char input[MAX_WORD_LENGTH+1];
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0'; // remove trailing newline
        clock_t end_time = clock();
        elapsed_time += ((float) (end_time - start_time)) / CLOCKS_PER_SEC;
        if (strcmp(word, input) == 0) num_correct++;
        if (i < NUM_WORDS-1) {
            printf("Next word will appear in %d seconds...\n", DELAY/1000);
            fflush(stdout);
            for (int j = DELAY; j > 0; j -= 1000) {
                printf("%d... ", j/1000);
                fflush(stdout);
                sleep(1);
            }
            printf("\n");
        }
    }

    printf("\nYou typed %d out of %d words correctly in %.1f seconds.\n", num_correct, NUM_WORDS, elapsed_time);
    printf("Your average typing speed was %.1f words per minute.\n", num_correct / (elapsed_time / 60));
    printf("Thank you for taking the Typing Speed Test!\n");

    return 0;
}