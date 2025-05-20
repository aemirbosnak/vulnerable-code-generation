//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    char name[20];
    int age;
    int gender;
    int scared;

    printf("Welcome to the Haunted House!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("How old are you? ");
    scanf("%d", &age);
    printf("Are you male or female? (1 for male, 2 for female) ");
    scanf("%d", &gender);

    srand(time(NULL));
    int random_number = rand() % 2;

    if (random_number == 0) {
        printf("You are male.\n");
    } else {
        printf("You are female.\n");
    }

    printf("You are %d years old.\n", age);

    int rand_scared = rand() % 2;

    if (rand_scared == 0) {
        printf("You are not scared.\n");
    } else {
        printf("You are scared.\n");
    }

    int choice_1 = rand() % 2;
    int choice_2 = rand() % 2;
    int choice_3 = rand() % 2;

    printf("You have three choices:\n");
    printf("1. Go through the haunted maze\n");
    printf("2. Go through the haunted forest\n");
    printf("3. Go through the haunted house\n");

    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("You have chosen the haunted maze.\n");
            printf("You feel the walls closing in on you.\n");
            printf("You hear screams and moans.\n");
            printf("You see ghosts and goblins.\n");
            printf("You feel cold chills running down your spine.\n");
            break;
        case 2:
            printf("You have chosen the haunted forest.\n");
            printf("You feel the wind blowing through your hair.\n");
            printf("You hear the rustling of leaves.\n");
            printf("You see glowing eyes in the darkness.\n");
            printf("You feel a sense of dread and foreboding.\n");
            break;
        case 3:
            printf("You have chosen the haunted house.\n");
            printf("You feel the floorboards creaking under your feet.\n");
            printf("You hear doors slamming shut.\n");
            printf("You see ghostly apparitions.\n");
            printf("You feel a presence watching you.\n");
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}