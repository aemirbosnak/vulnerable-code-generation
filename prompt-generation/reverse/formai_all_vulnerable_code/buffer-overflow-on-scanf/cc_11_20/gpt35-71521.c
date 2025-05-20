//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    srand(time(NULL));
    char name[20];
    printf("Welcome to the Haunted House Simulator! \n");
    printf("What is your name, traveler? Enter it below: ");
    scanf("%s", name);
    printf("Greetings, %s! \n", name);
    printf("You have arrived at the entrance of the Haunted House. \n");
    printf("Would you like to enter? (y/n) ");
    char answer1[2];
    scanf("%s", answer1);
    if(strcmp(answer1, "y") == 0) {
        printf("You enter the dark and eerie mansion. \n");
    } else if(strcmp(answer1, "n") == 0) {
        printf("You choose to flee the premises. Better luck next time! \n");
        return 0;
    } else {
        printf("Invalid input. Please try again. \n");
        return 0;
    }
    printf("You hear strange noises coming from a room nearby. \n");
    printf("Would you like to investigate? (y/n) ");
    char answer2[2];
    scanf("%s", answer2);
    if(strcmp(answer2, "y") == 0) {
        printf("You enter the room and find a mysterious key. \n");
        printf("Would you like to take it? (y/n) ");
        char answer3[2];
        scanf("%s", answer3);
        if(strcmp(answer3, "y") == 0) {
            printf("You take the key and continue on your journey. \n");
        } else if(strcmp(answer3, "n") == 0) {
            printf("You choose to leave the key behind. \n");
        } else {
            printf("Invalid input. Please try again. \n");
            return 0;
        }
    } else if(strcmp(answer2, "n") == 0) {
        printf("You decide to avoid the noise and continue exploring. \n");
    } else {
        printf("Invalid input. Please try again. \n");
        return 0;
    }
    printf("As you walk down the hallway, you see a shadowy figure in the distance. \n");
    printf("Do you approach them? (y/n) ");
    char answer4[2];
    scanf("%s", answer4);
    if(strcmp(answer4, "y") == 0) {
        printf("You realize the shadowy figure is a ghost and attempt to run away. \n");
        int random_num = rand() % 2 + 1;
        if(random_num == 1) {
            printf("You escape the ghost's wrath and continue on your journey. \n");
        } else if(random_num == 2) {
            printf("The ghost catches up to you and drags you into its lair. \n");
            printf("Game over! \n");
            return 0;
        }
    } else if(strcmp(answer4, "n") == 0) {
        printf("You choose to avoid the shadowy figure and continue exploring. \n");
    } else {
        printf("Invalid input. Please try again. \n");
        return 0;
    }
    printf("You reach a dead end, but notice a crack in the wall. \n");
    printf("Would you like to investigate further? (y/n) ");
    char answer5[2];
    scanf("%s", answer5);
    if(strcmp(answer5, "y") == 0) {
        printf("You discover a secret room and find a map of the mansion. \n");
        printf("Congratulations, you have successfully completed the Haunted House Simulator! \n");
    } else if(strcmp(answer5, "n") == 0) {
        printf("You choose to leave the dead end and continue exploring. \n");
    } else {
        printf("Invalid input. Please try again. \n");
        return 0;
    }

    return 0;
}