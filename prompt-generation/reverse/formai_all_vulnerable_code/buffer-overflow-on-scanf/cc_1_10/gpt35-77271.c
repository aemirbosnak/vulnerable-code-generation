//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * This is a text-based adventure game that takes place in a romantic setting.
 * The goal is for the player to win the heart of their love interest through
 * a series of challenges and obstacles.
 */

int main() {
    srand(time(NULL)); // Seed the random number generator

    // Introduction and initial setup
    printf("Welcome to Love Adventure!\n");
    printf("What is your name?\n");
    char player_name[20];
    scanf("%s", player_name);

    printf("\nWho is your love interest?\n");
    char love_interest[20];
    scanf("%s", love_interest);

    printf("\nYou are on a date with %s. You both decide to take a romantic walk in the park.\n\n", love_interest);

    // First challenge: a chance encounter with a stray cat
    printf("As you walk hand in hand, you come across a stray cat.\n");
    printf("What do you do?\n");
    printf("1. Ignore it and keep walking.\n");
    printf("2. Approach the cat and try to pet it.\n");
    printf("3. Give the cat some food.\n");

    int choice_1;
    scanf("%d", &choice_1);

    switch (choice_1) {
        case 1:
            printf("\n%s seems disappointed that you didn't show any compassion towards the cat.\n", love_interest);
            break;
        case 2:
            printf("\n%s is impressed by your kindness towards animals.\n", love_interest);
            break;
        case 3:
            printf("\n%s is touched by your generosity towards the cat.\n", love_interest);
            break;
        default:
            printf("\n%s is confused by your indecisiveness.\n", love_interest);
            break;
    }

    // Second challenge: an unexpected rainstorm
    printf("\nJust as you continue your walk, the sky suddenly darkens and it starts to rain heavily.\n");
    printf("What do you do?\n");
    printf("1. Make a run for the nearest shelter.\n");
    printf("2. Offer your jacket to %s.\n", love_interest);
    printf("3. Stand in the rain and dance together.\n");

    int choice_2;
    scanf("%d", &choice_2);

    switch (choice_2) {
        case 1:
            printf("\n%s is grateful that you're looking out for their safety.\n", love_interest);
            break;
        case 2:
            printf("\n%s is touched by your chivalry and thoughtfulness.\n", love_interest);
            break;
        case 3:
            printf("\n%s is thrilled by your spontaneity and sense of adventure.\n", love_interest);
            break;
        default:
            printf("\n%s is confused by your lack of action in a difficult situation.\n", love_interest);
            break;
    }

    // Final challenge: a surprise proposal
    printf("\nAfter the rain clears, you find yourselves at a romantic gazebo.\n");
    printf("The atmosphere is perfect for what you've been planning all along.\n");
    printf("What do you say to %s?\n", love_interest);
    printf("1. Will you marry me?\n");
    printf("2. I really like you.\n");
    printf("3. Do you want to go out again sometime?\n");

    int choice_3;
    scanf("%d", &choice_3);

    switch (choice_3) {
        case 1:
            printf("\n%s is overjoyed and says YES!\n", love_interest);
            break;
        case 2:
            printf("\n%s is happy, but not quite sure what to make of your statement.\n", love_interest);
            break;
        case 3:
            printf("\n%s smiles and agrees that it would be lovely to see each other again.\n", love_interest);
            break;
        default:
            printf("\n%s is taken aback by your strange phrasing.\n", love_interest);
            break;
    }

    // Ending
    printf("\nCongratulations, %s! You have successfully won %s's heart.\n", player_name, love_interest);
    printf("Thanks for playing Love Adventure!\n");

    return 0;
}