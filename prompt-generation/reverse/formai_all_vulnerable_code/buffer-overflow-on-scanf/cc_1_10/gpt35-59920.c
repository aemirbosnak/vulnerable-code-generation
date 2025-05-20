//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#define MAX_WORD_LEN 20
#define MAX_TIME 60

char words[MAX_WORD_LEN][MAX_WORD_LEN]={"apple","banana","chocolate","dinosaur","elephant","fireworks",
                    "galaxy","hamburger","icecream","jungle","koala","lemon",
                    "mountain","notebook","olympics","pencil","rectangle","strawberry",
                    "telephone","umbrella","victory","watermelon","xylophone","yellowstone",
                    "zeppelin"};

void instructions()
{
    printf("Welcome to the Typing Speed Test\n");
    printf("You will have %d seconds to type as many words as possible\n", MAX_TIME);
    printf("Ready or not - here we go!\n");
}

int main()
{
    instructions();

    time_t start, end;
    int correct = 0, wrong = 0, total_words = 0;
    double elapsed_time;

    // Seed the random number generator
    srand(time(NULL));

    start = time(NULL);

    while (1)
    {
        // Choose a random word from the list
        int word_index = rand() % MAX_WORD_LEN;
        printf("%s\n", words[word_index]);

        // User input
        char user_input[MAX_WORD_LEN];
        scanf("%s", user_input);
        total_words++;

        // Check if the word matches
        if (strcmp(user_input, words[word_index]) == 0)
        {
            correct++;
        }
        else
        {
            wrong++;
        }

        // Check if time is up
        end = time(NULL);
        elapsed_time = difftime(end, start);
        if (elapsed_time >= MAX_TIME)
        {
            break;
        }
    }

    printf("\n\nResult:\n");
    printf("Total words: %d\n", total_words);
    printf("Correct: %d\n", correct);
    printf("Wrong: %d\n", wrong);
    printf("Time: %.2f seconds\n", elapsed_time);
    printf("Typing speed: %.2f words per minute\n", total_words / (elapsed_time / 60.0));

    return 0;
}