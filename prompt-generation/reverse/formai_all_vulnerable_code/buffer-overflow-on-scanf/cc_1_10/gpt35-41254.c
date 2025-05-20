//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    char name[20];
    char choice[80];
    int ammo = 10;
    int food = 5;
    int water = 3;

    printf("Welcome to the post-apocalyptic world!\n");
    printf("What is your name?\n");
    scanf("%s", name);
    printf("Hello %s! You are one of the few human survivors left on earth after the catastrophic event.\n", name);
    printf("You find yourself in a deserted city, scavenging for food and supplies to stay alive.\n");

    printf("\nYou have:\n%d ammo\n%d food\n%d water\n", ammo, food, water);

    while (1) {
        printf("What would you like to do?\n");
        printf("1. Look for supplies\n");
        printf("2. Rest\n");
        printf("3. Leave the city\n");

        scanf("%s", choice);

        if (strcmp(choice, "1") == 0) {
            printf("You search the city for supplies...\n");
            ammo += 2;
            food += 1;
            water += 1;
            printf("You found 2 ammo, 1 food and 1 water!\n");
            printf("You now have:\n%d ammo\n%d food\n%d water\n", ammo, food, water);
        }
        else if (strcmp(choice, "2") == 0) {
            printf("You take a break from your journey...\n");
            food--;
            printf("You ate 1 food!\n");
            printf("You now have:\n%d ammo\n%d food\n%d water\n", ammo, food, water);
        }
        else if (strcmp(choice, "3") == 0) {
            if (ammo >= 5 && food >= 3 && water >= 2) {
                printf("You leave the city and head towards the next town...\n");
                printf("Congratulations! You have survived the post-apocalyptic world!\n");
                break;
            }
            else {
                printf("You don't have enough supplies to leave the city. You need at least:\n5 ammo\n3 food\n2 water\n");
            }
        }
        else {
            printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}