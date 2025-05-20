//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int roll;
    int health = 100;
    int score = 0;
    char name[20];

    printf("Welcome to the Haunted House!\n");
    printf("What is your name? ");
    scanf("%s", name);

    srand(time(NULL));
    roll = rand() % 6 + 1;

    while (health > 0 && score < 10) {
        printf("\nYou are in a room with %d doors.\n", roll);
        printf("Which door do you choose? ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("You enter the first room and find a treasure chest!\n");
            score++;
        } else if (choice == 2) {
            printf("You enter the second room and find a friendly ghost.\n");
        } else if (choice == 3) {
            printf("You enter the third room and find a secret passage.\n");
        } else if (choice == 4) {
            printf("You enter the fourth room and find a pile of gold!\n");
            score++;
        } else if (choice == 5) {
            printf("You enter the fifth room and find a magic potion.\n");
            health += 50;
        } else {
            printf("You enter the sixth room and find a monster!\n");
            health -= 25;
        }

        roll = rand() % 6 + 1;
    }

    if (score >= 10) {
        printf("\nCongratulations, %s! You have escaped the haunted house with a score of %d!\n", name, score);
    } else {
        printf("\nSorry, %s. You did not escape the haunted house.\n", name);
    }

    return 0;
}