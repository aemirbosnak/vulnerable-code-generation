//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char name[50];
    int age, choice;

    printf("Welcome adventurer! What is your name?\n");
    scanf("%s", name);

    printf("Hello %s! How old are you?\n", name);
    scanf("%d", &age);

    printf("Great! Let's begin our adventure, %s.\n", name);
    printf("You are on a quest to find the missing treasure of the ancient kingdom.\n");
    printf("As you embark on your journey, you come across a fork in the road. Which path do you choose?\n");
    printf("1. The dark and ominous path to the left.\n");
    printf("2. The flower-filled path to the right.\n");
    printf("3. You can't decide and stay put.\n");

    scanf("%d", &choice);

    if (choice == 1) {
        printf("You chose the dark path. As you walk down the path, you feel an eerie presence around you.\n");
        printf("You soon find yourself in a dark cave with a dimly lit torch ahead of you.\n");
        printf("Do you approach the torch?\n");
        printf("1. Yes\n");
        printf("2. No\n");

        scanf("%d", &choice);

        if (choice == 1) {
            printf("You approach the torch and pick it up. Suddenly, the walls around you begin to move.\n");
            printf("You become trapped in the cave and are never seen again.\n");
            printf("GAME OVER!\n");
            exit(0);
        } else if (choice == 2) {
            printf("You ignore the torch and continue down the dark path.\n");
            printf("You eventually stumble upon a hidden room filled with treasure!\n");
            printf("CONGRATULATIONS! YOU WIN!\n");
            exit(0);
        } else {
            printf("Invalid input. Please try again.\n");
            exit(0);
        }
    } else if (choice == 2) {
        printf("You chose the flower-filled path. As you walk down the path, you admire the beautiful scenery around you.\n");
        printf("You eventually come across a serenity garden with a small pond.\n");
        printf("Do you take a break and rest by the pond?\n");
        printf("1. Yes\n");
        printf("2. No\n");

        scanf("%d", &choice);

        if (choice == 1) {
            printf("You rest by the pond and take a drink from the clear water. Suddenly, you feel ill.\n");
            printf("You realize too late that the water was poisoned and you die.\n");
            printf("GAME OVER!\n");
            exit(0);
        } else if (choice == 2) {
            printf("You ignore the pond and continue down the path.\n");
            printf("You eventually come across a hidden room filled with treasure!\n");
            printf("CONGRATULATIONS! YOU WIN!\n");
            exit(0);
        } else {
            printf("Invalid input. Please try again.\n");
            exit(0);
        }
    } else if (choice == 3) {
        printf("You stay in the same spot and try to decide which path to take.\n");
        printf("Suddenly, a group of bandits appear and attack you!\n");
        printf("You defend yourself but are eventually outnumbered.\n");
        printf("You die in battle.\n");
        printf("GAME OVER!\n");
        exit(0);
    } else {
        printf("Invalid input. Please try again.\n");
        exit(0);
    }

    return 0;
}