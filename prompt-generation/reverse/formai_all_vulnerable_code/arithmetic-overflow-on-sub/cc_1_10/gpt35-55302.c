//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#define MAX 1000

int main()
{
    srand(time(0));
    char input_buffer[MAX], output_buffer[MAX];
    int i, j, mistakes = 0, time_taken;
    clock_t start, end;
    
    printf("Welcome to the Typing Speed Test!\n");
    printf("Type the following sentence as fast as possible and press Enter:\n");
    printf("The quick brown fox jumps over the lazy dog.\n");
    
    gets(input_buffer);     //gets function to read input string
    start = clock();        //start timer
    
    //Loop to copy string to output buffer and check for mistakes
    for(i=0, j=0; input_buffer[i]!= '\0'; i++)
    {
        if(isalpha(input_buffer[i]))
        {
            output_buffer[j] = input_buffer[i];
            j++;
        }
        else if(input_buffer[i] == ' ')
        {
            output_buffer[j] = ' ';
            j++;
        }
        else
        {
            mistakes++;
        }
    }
    output_buffer[j] = '\0';
    
    end = clock();          //end timer
    
    time_taken = (end-start)/CLOCKS_PER_SEC; 
    
    printf("\n\n");
    
    //Print results and message depending on performance
    if(mistakes != 0)
    {
        printf("You made %d mistake(s).\n", mistakes);
        printf("Your typed sentence: %s\n", output_buffer);
    }
    else
    {
        printf("Congratulations! You typed the sentence correctly.\n");
    }
    
    printf("Time taken: %d seconds\n", time_taken);
    
    if(time_taken <= 5)
    {
        printf("You're really fast! But are you sure you didn't cheat?\n");
    }
    else if(time_taken > 5 && time_taken <= 10)
    {
        printf("Not bad, but you could do better. Keep practicing!\n");
    }
    else
    {
        printf("You need to improve your typing speed. Keep practicing and you'll get there.\n");
    }
    
    //Extra paranoid message at the end
    printf("Be careful, someone may be watching you type right now...\n");

    return 0;
}