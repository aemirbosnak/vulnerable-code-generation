//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define NUM_OF_WORDS 10

int main()
{
    char words[NUM_OF_WORDS][20] = {"puzzling", "juxtaposition", "obfuscate", "esoteric", 
                                    "ennui", "plethora", "quintessential", "ephemeral",
                                    "ubiquitous", "labyrinthine"};
    int correct_words = 0, words_typed = 0;
    clock_t start_time, end_time;
    double time_taken;

    printf("Welcome to the Typing Test!\n\n");

    printf("You will be given a list of %d words to type out as fast and accurately as you can.\n", NUM_OF_WORDS);
    printf("Ready? Press any key to begin.\n\n");
    getchar();

    srand(time(NULL));
    for (int i = 0; i < NUM_OF_WORDS; i++) {
        printf("%s ", words[i]);
    }

    printf("\n\n");

    start_time = clock();

    while (words_typed < NUM_OF_WORDS) {
        char input[20];
        printf("Type the word: %s\n", words[words_typed]);
        scanf("%s", input);
        if (strcmp(input, words[words_typed]) == 0) {
            correct_words++;
            printf("Correct!\n\n");
        } else {
            printf("Incorrect.\n\n");
        }
        words_typed++;
    }

    end_time = clock();
    time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("You typed %d out of %d words correctly. \n", correct_words, NUM_OF_WORDS);
    printf("It took you %.2lf seconds to type all the words.\n", time_taken);

    double typed_per_min = (double)(correct_words) / (time_taken / 60);
    printf("That's equivalent to %.2lf words per minute!\n", typed_per_min);

    printf("\nThanks for playing!");

    return 0;
}