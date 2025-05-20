//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// -------- GLOABL VARIABLES --------
char game_show_name[] = "The Dicey Dilemma!";
int player_guess = 0;
int dice1 = 0, dice2 = 0;
int sum = 0;
int game_over = 0;

// -------- FUNCTION PROTOTYPES --------
void roll_the_dice(void);
void player_turn(void);
void check_answers(void);

// -------- MAIN FUNCTION --------
int main(void)
{
    printf("---- %s ----\n", game_show_name);
    printf("Welcome, Contestant! Let's roll some dice and test your luck!\n");
    srand(time(NULL)); // Seed random number generator with current time

    while (!game_over)
    {
        roll_the_dice(); // Host rolls the dice
        player_turn(); // Player makes a guess
        check_answers(); // Check if the player's guess is correct
    }

    printf("---- GAME OVER ----\n");
    printf("Thanks for playing, Contestant! Come back soon!\n");
    return 0;
}

// -------- ROLL THE DICE FUNCTION --------
void roll_the_dice(void)
{
    printf("\nHost rolls the dice...\n");
    dice1 = rand() % 6 + 1; // Roll dice 1
    dice2 = rand() % 6 + 1; // Roll dice 2
    sum = dice1 + dice2; // Calculate sum of dice

    printf("Host rolled a %d and a %d. The total sum is: %d.\n", dice1, dice2, sum);
}

// -------- PLAYER TURN FUNCTION --------
void player_turn(void)
{
    printf("\nPlayer, it's your turn! Guess the sum of the dice:\n");
    scanf("%d", &player_guess);
}

// -------- CHECK ANSWERS FUNCTION --------
void check_answers(void)
{
    if (player_guess > sum)
    {
        printf("Sorry, your guess is too high. Try again!\n");
        player_turn();
    }
    else if (player_guess < sum)
    {
        printf("Sorry, your guess is too low. Try again!\n");
        player_turn();
    }
    else
    {
        printf("Congratulations! You guessed the correct sum: %d!\n", sum);
        game_over = 1;
    }
}