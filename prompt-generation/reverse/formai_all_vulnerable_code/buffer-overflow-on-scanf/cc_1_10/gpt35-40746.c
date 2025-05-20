//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: happy
// This program is a Typing Speed Test that will make you happy!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    int words_per_minute, total_words, correct_words, incorrect_words;
    char input[100];
    char word[10][50] = {"happy", "joy", "smiling", "fun", "laugh", "amazing", "love", "exciting", "silly", "happiness"};
    
    printf("Welcome to the Happy Typing Speed Test!\n\n");
    printf("In this test, you will be given 10 random happy words to type in 1 minute.\n\n");
    printf("Press ENTER to start the test!\n");
    getchar();
    
    srand(time(NULL));
    
    time_t start = time(NULL);
    time_t end = start + 60;
    
    total_words = correct_words = incorrect_words = 0;
    
    while (time(NULL) <= end)
    {
        int index = rand() % 10;
        
        printf("\nType the word: %s\n", word[index]);
        scanf("%s", input);
        total_words++;
        
        if (strcmp(input, word[index]) == 0)
        {
            printf("Correct!\n");
            correct_words++;
        }
        else
        {
            printf("Incorrect!\n");
            incorrect_words++;
        }
    }
    time_t time_taken = end - start;
    words_per_minute = (total_words * 60) / time_taken;
    
    printf("\n\nTime taken: %ld seconds\n", time_taken);
    printf("Total words: %d\n", total_words);
    printf("Correct words: %d\n", correct_words);
    printf("Incorrect words: %d\n", incorrect_words);
    printf("Words per minute: %d\n", words_per_minute);
    
    if (words_per_minute >= 50)
    {
        printf("Congratulations! You are a happy and fast typer!\n");
    }
    else
    {
        printf("Keep practicing and you will soon be a happy and fast typer!\n");
    }
    
    return 0;
}