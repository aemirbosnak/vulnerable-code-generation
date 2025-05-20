//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Typing Speed Test!\n\n");
    printf("You will be presented with a series of random words to type. Your score will be based on the time taken to type all the words correctly.\n\n");

    char words[10][20] = {"hello", "world", "computer", "program", "keyboard", "monitor", "mouse", "software", "hardware", "internet"};

    srand(time(0));

    int randomIndex;
    int numWords = 10;
    int i, j;
    int score = 0;

    printf("Type the following words as fast as you can:\n");

    for(i = 0; i < numWords; i++)
    {
        randomIndex = rand() % numWords;
        printf("%d. %s\n", i+1, words[randomIndex]);
    }

    printf("\nType the words now:\n");

    time_t startTime, endTime;

    startTime = time(0);

    for(i = 0; i < numWords; i++)
    {
        char userWord[20];
        scanf("%s", userWord);

        for(j = 0; j < 20; j++)
        {
            if(userWord[j] != words[i][j])
            {
                printf("Incorrect word! Please try again.\n");
                i--;
                break;
            }
            if(j == 19)
            {
                printf("Correct word!\n");
                score++;
            }
        }
    }

    endTime = time(0);

    printf("\nYour score is %d and it took you %d seconds!\n", score, endTime-startTime);

    return 0;
}