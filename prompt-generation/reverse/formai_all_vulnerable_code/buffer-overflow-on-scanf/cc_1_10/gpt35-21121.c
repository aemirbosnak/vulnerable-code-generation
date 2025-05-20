//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    char randomWords[10][50] = {"apple", "banana", "cat", "dog", "elephant", "fridge", "guitar", "happiness", "island", "jazz"};
    int randomIndex, numOfWords = 0, correctCount = 0, wrongCount = 0;
    char input[50], exitInput[5];
    time_t startTime, endTime;

    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be given a series of 10 random words to type.\n");
    printf("Press any key to start the test...\n");
    getchar();

    srand(time(NULL));
    for(int i = 0; i < 10; i++)
    {
        randomIndex = rand() % 10; // generating random index to select random word from above array
        printf("Word %d: %s\n", i+1, randomWords[randomIndex]);
        scanf("%s", input);
        if(strcmp(randomWords[randomIndex], input) == 0)
        {
            correctCount++;
        }
        else
        {
            wrongCount++;
        }
        numOfWords++;
    }

    time(&endTime);
    printf("\n\nYou have completed the test!\n");
    printf("You typed %d correct words and %d wrong words out of %d words.\n", correctCount, wrongCount, numOfWords);
    printf("Your typing speed is %.2f words per minute.\n", ((float)correctCount / (endTime - startTime)) * 60);

    printf("\n\nPress 'exit' to quit the program.\n");
    scanf("%s", exitInput);
    if(strcmp(exitInput, "exit") == 0)
    {
        return 0;
    }
    else
    {
        printf("Invalid input, program will now exit.\n");
        return 1;
    }
}