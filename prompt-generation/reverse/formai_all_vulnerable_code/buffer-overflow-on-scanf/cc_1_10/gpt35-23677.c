//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    printf("\n Claude Shannon's Typing Speed Test\n\n"); 
    printf("Instructions:\n");
    printf("1. Type the words displayed on the screen as fast as you can\n");
    printf("2. Press 'Enter' to move on to the next word\n");
    printf("3. At the end of the test, you will be shown your typing speed\n\n");
    
    char words[10][20] = {"technique", "bureaucracy", "information", "phenomenon", "technology", "philosophy", "development", "intelligence", "advantage", "knowledge"};
    
    int num_words = 10;
    int i = 0;
    int errors = 0;
    int total_time = 0;
    char user_input[20];
    clock_t start, end;
    
    srand(time(NULL));
    
    while(i < num_words)
    {
        printf("%s ", words[i]);
        start = clock();
        scanf("%s", user_input);
        end = clock();
        
        if(strcmp(user_input, words[i]) != 0)
        {
            errors++;
        }
        
        total_time += end - start;
        
        i++;
    }
    
    int typing_speed = (num_words * 60) / (total_time / CLOCKS_PER_SEC);
    
    printf("\n\nCongratulations! You completed the test.\n");
    printf("Your typing speed is %d words per minute.\n", typing_speed);
    
    if(errors == 0)
    {
        printf("You made no errors. Great job!\n");
    }
    else
    {
        printf("You made %d error(s).\n", errors);
    }
    
    return 0;
}