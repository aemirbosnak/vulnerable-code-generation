//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void playGame(int difficulty)
{
    int codeA = rand() % difficulty + difficulty;
    int codeB = rand() % difficulty + difficulty;
    int codeC = rand() % difficulty + difficulty;
    
    int codeSum = codeA + codeB + codeC;
    int codeProduct = codeA * codeB * codeC;
    
    printf("\n");
    printf("You are now on level %d.\n", difficulty);
    printf("You need to enter three codes to get to the next level.\n");
    printf("The codes add up to: %d\n", codeSum);
    printf("The codes multiply to: %d\n", codeProduct);
    
    int guessA, guessB, guessC;
    printf("Enter your guess for Code A: ");
    scanf("%d", &guessA);
    printf("Enter your guess for Code B: ");
    scanf("%d", &guessB);
    printf("Enter your guess for Code C: ");
    scanf("%d", &guessC);
    
    int guessSum = guessA + guessB + guessC;
    int guessProduct = guessA * guessB * guessC;
    
    if (guessSum==codeSum && guessProduct==codeProduct)
    {
        printf("Success! You have unlocked the next level.\n");
        playGame(difficulty + 1);
    } 
    else
    {
        printf("Oops! You entered the wrong codes. Game over.\n");
        printf("You made it to level %d. Better luck next time.\n", difficulty);
    }
}

int main()
{
    srand(time(NULL));
    int levelDifficulty = 1;
    
    printf("*** WELCOME TO SPACE ADVENTURE ***\n\n");
    printf("You are stranded aboard a spacecraft and your only hope is to unlock\n");
    printf("the codes to the next level. You have to do this before the spacecraft\n");
    printf("crashes.\n");
    printf("You have to enter the codes correctly to go to the next level.\n");
    printf("Be careful! You only have 3 chances before the spacecraft crashes.\n");
    
    playGame(levelDifficulty);

    return 0;
}