//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Variables
    int choice, luckyNumber;
    char name[20];
    // Seed the random number generator with current time
    srand(time(0));
    // Welcome message
    printf("Welcome to the Haunted House Simulator!\n");
    // Get user's name
    printf("What is your name? ");
    scanf("%s", name);
    getchar(); // Clear input buffer
    // Instructions
    printf("Hello, %s! You are about to enter the haunted house.\n", name);
    printf("Inside the house, you will encounter spooky creatures and terrifying situations.\n");
    printf("But don't worry, you can survive if you make the right choices.\n");
    // Enter the house or not?
    printf("Do you want to enter the house? (1=yes, 0=no) ");
    scanf("%d", &choice);
    getchar(); // Clear input buffer
    if (choice == 0) {
        printf("Goodbye, %s! See you next time.\n", name);
        return 0;
    }
    // Lucky number
    luckyNumber = rand() % 10 + 1;
    printf("Before entering the house, guess a number between 1 and 10. This could be your lucky number.\n");
    printf("What is your guess? ");
    scanf("%d", &choice);
    getchar(); // Clear input buffer
    if (choice == luckyNumber) {
        printf("Congratulations, %s! Your guess was correct.\n", name);
    } else {
        printf("Sorry, %s. Your guess was wrong. Your lucky number was %d.\n", name, luckyNumber);
    }
    // First room
    printf("You enter the house and find yourself in a dimly lit room.\n");
    printf("You see two doors, one on the left and one on the right.\n");
    printf("Which door do you choose? (1=left, 2=right) ");
    scanf("%d", &choice);
    getchar(); // Clear input buffer
    if (choice == 1) {
        printf("You open the door on the left.\n");
        printf("You see a ghostly figure float by and disappear.\n");
    } else {
        printf("You open the door on the right.\n");
        printf("You hear a loud scream and a door slams shut behind you.\n");
        printf("You are trapped!\n");
        printf("But wait, there is a key on the floor.\n");
        printf("You pick up the key and use it to open the door.\n");
    }
    // Second room
    printf("You enter another room. It's dark and you can barely see anything.\n");
    printf("You hear footsteps approaching.\n");
    printf("What do you do? (1=hide, 2=run away, 3=confront) ");
    scanf("%d", &choice);
    getchar(); // Clear input buffer
    if (choice == 1) {
        printf("You hide behind the door.\n");
        printf("The footsteps stop and you hear the door creak open.\n");
        printf("A figure looks around, but doesn't see you.\n");
        printf("You wait for a few minutes and then cautiously leave the room.\n");
    } else if (choice == 2) {
        printf("You run away as fast as you can.\n");
        printf("You hear the footsteps chasing you, but you manage to escape.\n");
    } else {
        printf("You confront the figure.\n");
        printf("It turns out to be a friendly ghost who offers to guide you out of the house.\n");
        printf("You decide to follow the ghost to safety.\n");
    }
    // Final message
    printf("Congratulations, %s! You have escaped from the haunted house.\n", name);
    printf("Thanks for playing the Haunted House Simulator.\n");
    return 0;
}