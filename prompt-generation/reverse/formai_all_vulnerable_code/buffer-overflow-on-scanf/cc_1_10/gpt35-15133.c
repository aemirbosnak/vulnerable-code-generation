//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the Typing Speed Test!\n");
    printf("You will be presented with a list of words to type as quickly and accurately as possible!\n");
    printf("Press enter to start the test...\n");
    getchar();
    srand(time(0));//Seed for random word selection
    
    char *words[] = {"hello", "world", "programming", "language", "computer", "science", 
                    "algorithm", "database", "network", "design", "testing", "debugging", 
                    "software", "hardware", "developer", "interface", "internet", "security", 
                    "memory", "storage", "server", "client", "application", "mobile", "frontend", 
                    "backend", "configuration", "installation", "documentation", "support"};
    int totalWords = sizeof(words)/sizeof(char *);
    int count = 0;
    int mistakes = 0;
    clock_t start_time, end_time;
    double elapsed_time;
    
    printf("Type the following words:\n");
    printf("-------------------------------------\n");
    
    while(count < 10) //We will select 10 random words from list
    {
        int randomIndex = rand() % totalWords;
        printf("%s ", words[randomIndex]);
        char inputWord[50];
        scanf("%s", inputWord);
        if(strcmp(inputWord, words[randomIndex]) == 0)
        {
            printf("Correct!\n");
        }
        else
        {
            printf("Incorrect!\n");
            mistakes++;
        }
        count++;
    }
    
    end_time = clock();
    elapsed_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("--------------------------------------\n");
    printf("Test complete!\n");
    printf("Total time: %.2f seconds\n", elapsed_time);
    printf("Total mistakes: %d\n", mistakes);
    printf("Your typing speed is: %.2f WPM (Words Per Minute)\n", 10/(elapsed_time/60));
    
    return 0;
}