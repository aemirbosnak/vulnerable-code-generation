//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to get user input */
int getUserInput() {
    int input;
    printf("\nEnter a choice: ");
    scanf("%d", &input);
    return input;
}

/* Function to get a random number */
int getRandomNumber() {
    srand(time(0));
    return rand() % 3 + 1;
}

int main() {
    int choice, randomNumber;
    printf("Welcome to the Text-Based Adventure Game!\n");

    /* Introduction */
    printf("\nYou are on a mission to save the princess from the evil dragon.\n");
    printf("You have to cross a dangerous forest, cross a river and climb a mountain to reach the castle where the dragon lives.\n");
    printf("Choose wisely to avoid danger and successfully complete your mission.\n");

    /* Forest */
    printf("\nYou are now in the forest. There are two paths ahead.\n");
    printf("1. Turn left\n");
    printf("2. Turn right\n");

    choice = getUserInput();

    if (choice == 1) {
        printf("\nYou encounter a pack of wolves. You have to fight them off.\n");
        printf("1. Use sword\n");
        printf("2. Use bow and arrow\n");

        choice = getUserInput();
        randomNumber = getRandomNumber(); // 1, 2 or 3

        if (choice == 1 && randomNumber == 1) {
            printf("\nYou successfully defeated the wolves with your sword.\n");
        }
        else if (choice == 2 && randomNumber == 2) {
            printf("\nYou successfully defeated the wolves with your bow and arrow.\n");
        }
        else {
            printf("\nThe wolves have overpowered you. Game over!\n");
            exit(0);
        }
    }
    else {
        printf("\nYou encounter a river. You have to cross it.\n");
        printf("1. Swim across\n");
        printf("2. Build a raft\n");

        choice = getUserInput();
        randomNumber = getRandomNumber(); // 1, 2 or 3

        if (choice == 1 && randomNumber == 1) {
            printf("\nYou swim across the river successfully.\n");
        }
        else if (choice == 2 && randomNumber == 2) {
            printf("\nYou build a sturdy raft and cross the river successfully.\n");
        }
        else {
            printf("\nThe river is too dangerous. You drown. Game over!\n");
            exit(0);
        }
    }

    /* Mountain */
    printf("\nYou have successfully crossed the forest and the river. Now you have to climb the mountain to reach the castle.\n");
    printf("1. Use the path\n");
    printf("2. Climb the rocks\n");

    choice = getUserInput();
    randomNumber = getRandomNumber(); // 1, 2 or 3

    if (choice == 1 && randomNumber == 1) {
        printf("\nYou reach the castle using the path, but the dragon sees you coming and attacks you. You have to fight it off.\n");
        printf("1. Use sword\n");
        printf("2. Use bow and arrow\n");

        choice = getUserInput();
        randomNumber = getRandomNumber(); // 1, 2 or 3

        if (choice == 1 && randomNumber == 1) {
            printf("\nYou have successfully defeated the dragon with your sword. You have saved the princess and completed your mission. Congratulations!\n");
        }
        else if (choice == 2 && randomNumber == 2) {
            printf("\nYou have successfully defeated the dragon with your bow and arrow. You have saved the princess and completed your mission. Congratulations!\n");
        }
        else {
            printf("\nThe dragon has defeated you. Game over!\n");
            exit(0);
        }
    }
    else if(choice == 2 && randomNumber == 2) {
        printf("\nYou try to climb the rocks, but they are too steep and you fall and die. Game over!\n");
        exit(0);
    }
    else {
        printf("\nThe path is too dangerous. You fall and die. Game over!\n");
        exit(0);
    }

    return 0;
}