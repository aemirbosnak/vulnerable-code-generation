//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateFortune(int num);

int main(void)
{
    // Seed the random number generator
    srand(time(NULL));
    
    int num;
    
    // Ask the user for their question
    printf("Welcome to the Automated Fortune Teller! Please ask a yes or no question:\n");
    scanf("%d", &num);
    
    // Generate the fortune
    generateFortune(num);
    
    return 0;
}

void generateFortune(int num)
{
    int randNum = rand() % 10 + 1;
    
    if (num == 42)
    {
        printf("That is the answer to life, the universe, and everything.\n");
        printf("Your fortune is uncertain.");
    }
    else if (randNum == 1)
    {
        printf("It is certain.\n");
    }
    else if (randNum == 2)
    {
        printf("It is decidedly so.\n");
    }
    else if (randNum == 3)
    {
        printf("Without a doubt.\n");
    }
    else if (randNum == 4)
    {
        printf("Yes - definitely.\n");
    }
    else if (randNum == 5)
    {
        printf("You may rely on it.\n");
    }
    else if (randNum == 6)
    {
        printf("As I see it, yes.\n");
    }
    else if (randNum == 7)
    {
        printf("Most likely.\n");
    }
    else if (randNum == 8)
    {
        printf("Outlook good.\n");
    }
    else if (randNum == 9)
    {
        printf("Yes.\n");
    }
    else // randNum == 10
    {
        printf("Don't count on it.\n");
    }
}