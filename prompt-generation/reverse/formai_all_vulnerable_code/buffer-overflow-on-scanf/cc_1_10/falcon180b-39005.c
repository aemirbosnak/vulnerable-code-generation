//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intro();
void create_character();
void play_game();

int main() {
    srand(time(0));
    intro();
    create_character();
    play_game();
    return 0;
}

void intro() {
    printf("Welcome to the year 3019.\n");
    printf("You are a space adventurer on a mission to explore the universe.\n");
    printf("Create your character and begin your journey.\n\n");
}

void create_character() {
    int gender;
    char name[20];

    printf("What is your name? ");
    scanf("%s", name);

    printf("What is your gender? (0 for male, 1 for female) ");
    scanf("%d", &gender);

    if (gender == 0)
        printf("You are a male space adventurer named %s.\n\n", name);
    else
        printf("You are a female space adventurer named %s.\n\n", name);
}

void play_game() {
    int choice, random_event;

    while (1) {
        printf("You are currently in space.\n");
        printf("What would you like to do?\n");
        printf("1. Explore a planet.\n2. Battle an alien.\n3. Repair your ship.\n4. Continue flying.\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You land on a nearby planet.\n");
                random_event = rand() % 2;
                if (random_event == 0)
                    printf("You discover a valuable resource!\n");
                else
                    printf("You encounter a dangerous creature!\n");
                break;
            case 2:
                printf("You engage in battle with an alien spacecraft.\n");
                random_event = rand() % 2;
                if (random_event == 0)
                    printf("You win the battle and gain valuable loot!\n");
                else
                    printf("You lose the battle and suffer damage to your ship.\n");
                break;
            case 3:
                printf("You repair your ship.\n");
                break;
            case 4:
                printf("You continue flying through space.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

        printf("\nDo you want to continue playing? (y/n) ");
        char cont;
        scanf(" %c", &cont);

        if (cont == 'n')
            break;
    }

    printf("\nThanks for playing!\n");
}