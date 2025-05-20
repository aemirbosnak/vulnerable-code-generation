//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to Grateful Typing Speed Test!\n");
    printf("You will be given a random sentence to type.\n");
    printf("Press enter to start...\n");
    getchar();
    
    const char* sentenceList[5] = {"The quick brown fox jumps over the lazy dog.",
                                   "I am the walrus, coo coo ca choo.",
                                   "The sunflower is my favorite flower.",
                                   "Programming is fun and challenging at the same time.",
                                   "Life is like a box of chocolates, you never know what you're going to get."};
    srand(time(NULL));
    int randomIndex = rand() % 5;
    const char* sentence = sentenceList[randomIndex];
    
    printf("Type this sentence: \"%s\"\n", sentence);
    time_t start = time(NULL);
    char input[100];
    fgets(input, 100, stdin);
    time_t end = time(NULL);
    double duration = difftime(end, start);
    
    int errors = 0;
    int i = 0;
    while (sentence[i] != '\0' && input[i] != '\0')
    {
        if (sentence[i] != input[i])
        {
            errors++;
        }
        i++;
    }
    printf("\n");
    if (errors == 0)
    {
        printf("Congratulations! You typed the sentence correctly!\n");
        printf("Your typing speed is: %.2f characters per second.\n", (double)i / duration);
    }
    else
    {
        printf("Oops! You made %d error(s).\n", errors);
        printf("Your typing speed is: %.2f characters per second.\n", (double)i / duration);
    }

    return 0;
}