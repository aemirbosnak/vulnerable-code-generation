//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    srand(time(NULL));
    printf("Welcome to the Enchanted Forest!\n");
    printf("You are a brave adventurer on a quest to find the magical artifact.\n");
    printf("Which path will you take?\n");
    printf("1. The path to the left\n");
    printf("2. The path to the right\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("You take the path to the left and come across a sparkling river.\n");
        printf("Do you want to cross the river?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("You wade through the river and reach the other side.\n");
            printf("You see a cave in the distance.\n");
            printf("Do you want to enter the cave?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            scanf("%d", &choice);

            if (choice == 1) {
                printf("You enter the cave and find the magical artifact!\n");
                printf("Congratulations, you have completed your quest!\n");
            } else {
                printf("You decide not to enter the cave and continue on your journey.\n");
            }
        } else {
            printf("You decide not to cross the river and continue on your journey.\n");
        }
    } else if (choice == 2) {
        printf("You take the path to the right and come across a wise old owl.\n");
        printf("The owl asks you a riddle:\n");
        printf("What is always in front of you but can't be seen?\n");
        printf("Do you know the answer?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("You answer correctly and the owl rewards you with a magical potion.\n");
            printf("Do you want to drink the potion?\n");
            printf("1. Yes\n");
            printf("2. No\n");
            scanf("%d", &choice);

            if (choice == 1) {
                printf("You drink the potion and gain the power of flight!\n");
                printf("You soar through the air and find the magical artifact!\n");
                printf("Congratulations, you have completed your quest!\n");
            } else {
                printf("You decide not to drink the potion and continue on your journey.\n");
            }
        } else {
            printf("You answer incorrectly and the owl flies away.\n");
            printf("You continue on your journey.\n");
        }
    } else {
        printf("Invalid choice.\n");
        return 1;
    }

    return 0;
}