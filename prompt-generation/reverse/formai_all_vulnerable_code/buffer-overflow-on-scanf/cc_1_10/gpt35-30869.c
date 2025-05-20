//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); //seed for random number generator
    
    //initialize variables
    int guess;
    int num = rand() % 100 + 1; //generate random number between 1-100
    int attempts = 0;
    
    //game loop
    while (attempts < 10)
    {
        printf("Guess the number between 1-100: ");
        scanf("%d", &guess);
        
        if (guess < 1 || guess > 100) //validation check
        {
            printf("Invalid input. Please enter a number between 1-100.\n");
            continue;
        }
        
        attempts++;
        
        if (guess == num)
        {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
            break;
        }
        else if (guess < num)
        {
            printf("Too low. ");
        }
        else
        {
            printf("Too high. ");
        }
        
        printf("Attempts left: %d\n", 10 - attempts);
    }
    
    if (attempts == 10) //if 10 attempts are completed and number is not guessed
    {
        printf("Sorry, you couldn't guess the number. The number was %d.\n", num);
    }
    
    return 0;
}