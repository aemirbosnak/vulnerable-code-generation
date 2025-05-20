//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Global variables
int level = 1;
int score = 0;
int target = 0;

// Function prototypes
void displayHeader();
void displayInstruction();
void displayLevel();
void generateTarget();
int calculatePoints(int guess);

int main()
{
    srand(time(0)); // Seed random function with current time
    displayHeader();
    displayInstruction();
    while(1)
    {
        displayLevel();
        generateTarget();        
        int guess;
        printf("Enter your guess between 1 and %d: ", level*10);
        scanf("%d", &guess);
        int points = calculatePoints(guess);
        score += points;
        if(score < 0)
            score = 0;
        printf("You scored %d points in this round.\n", points);
        printf("Your total score is %d\n", score);
    }
    return 0;
}

void displayHeader()
{
    printf("\n********** Welcome to the Guessing Game **********\n\n");
}

void displayInstruction()
{
    printf("Instructions:\n");
    printf("1. You have to guess a number between 1 and (level x 10)\n");
    printf("2. You will score 10 points more than the difference between your guess and the target.\n");
    printf("3. If your guess is more than 3 away from the target, you will lose 5 points.\n");
    printf("4. If your guess is more than 5 away from the target, you will lose 10 points.\n");
    printf("5. If your guess is more than 8 away from the target, you will lose 15 points.\n\n");
}

void displayLevel()
{
    printf("\n********** LEVEL %d **********\n\n", level);
}

void generateTarget()
{
    target = rand() % (level * 10) + 1;
    printf("Guess the number between 1 and %d: ", level*10);
}

int calculatePoints(int guess)
{
    int difference = abs(target - guess);
    if(difference <= 3)
        return 10 + (3 - difference);
    else if(difference > 3 && difference <= 5)
        return 5 + (3 - (difference-3));
    else if(difference > 5 && difference <= 8)
        return (3 - (difference-5));
    else
        return -15;
}