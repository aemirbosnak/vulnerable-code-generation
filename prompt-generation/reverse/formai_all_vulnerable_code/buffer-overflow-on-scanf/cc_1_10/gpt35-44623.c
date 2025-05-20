//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void start_game();
void display_introduction();
void display_options();
void play_game(int option);
void display_win_message();
void display_lose_message();

int main()
{
    start_game();
    return 0;
}

void start_game()
{
    display_introduction();
    display_options();

    int option;
    scanf("%d", &option);
    play_game(option);
}

void display_introduction()
{
    printf("Welcome to the future!\n");
    printf("In this world, you are a time traveler who has been sent to the year 2045 to save humanity from the brink of extinction.\n");
    printf("You have been equipped with a time machine and a mission to find the lost cure to a deadly virus that has wiped out 90 percent of the population.\n");
    printf("Good luck, time traveler!\n\n");
}

void display_options()
{
    printf("Select an option below:\n");
    printf("1. Travel to the year 2075\n");
    printf("2. Travel to the year 2100\n");
    printf("3. Travel to the year 2200\n");
}

void play_game(int option)
{
    switch (option)
    {
        case 1:
            printf("\nYou have arrived in the year 2075!\n");
            printf("You search the archives and discover the virus was caused by a rogue AI named Zephyr.\n");
            printf("You must find and destroy Zephyr to save humanity!\n\n");
            display_win_message();
            break;

        case 2:
            printf("\nYou have arrived in the year 2100!\n");
            printf("You discover that the virus was actually a bioweapon created by a terrorist group.\n");
            printf("You must navigate through their stronghold and find the cure to the virus to save humanity!\n\n");
            display_win_message();
            break;

        case 3:
            printf("\nYou have arrived in the year 2200!\n");
            printf("You find a post-apocalyptic world devoid of humanity.\n");
            printf("You must find the last remaining human survivor and the cure to the virus to save humanity!\n\n");
            display_lose_message();
            break;

        default:
            printf("\nInvalid option selected. Please try again.\n\n");
            start_game();
            break;
    }
}

void display_win_message()
{
    printf("Congratulations! You have saved humanity and prevented the virus from wiping out the remaining population. You are a hero!\n\n");
}

void display_lose_message()
{
    printf("Sorry, you were unable to find the last remaining human survivor and the cure to the virus. Humanity is doomed to extinction.\n\n");
}