//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intro();
void play();
void endGame();
void shapeShift();

int main() {
    srand(time(0));
    intro();
    play();
    endGame();
    return 0;
}

void intro() {
    printf("Welcome to the Shape Shifting Space Adventure!\n");
    printf("You are a space explorer with the ability to shape shift into different forms.\n");
    printf("Your mission is to navigate through space and defeat the evil space villains.\n");
    printf("Are you ready for the challenge?\n");
    getchar();
}

void play() {
    int choice;
    while(1) {
        system("CLS");
        printf("You are currently in the form of: ");
        if(rand() % 2 == 0) {
            printf("Human\n");
        } else {
            printf("Alien\n");
        }
        printf("What would you like to do?\n");
        printf("1. Shape shift\n");
        printf("2. Attack\n");
        printf("3. Defend\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                shapeShift();
                break;
            case 2:
                printf("You attack with full force!\n");
                break;
            case 3:
                printf("You defend yourself with all your might!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
        getchar();
    }
}

void endGame() {
    printf("Congratulations! You have completed the Shape Shifting Space Adventure!\n");
    printf("Thank you for playing.\n");
}

void shapeShift() {
    int form;
    system("CLS");
    printf("You are currently in the form of: ");
    if(rand() % 2 == 0) {
        printf("Human\n");
    } else {
        printf("Alien\n");
    }
    printf("What form would you like to shape shift into?\n");
    printf("1. Cat\n");
    printf("2. Bird\n");
    scanf("%d", &form);
    switch(form) {
        case 1:
            printf("You have shape shifted into a cat!\n");
            break;
        case 2:
            printf("You have shape shifted into a bird!\n");
            break;
        default:
            printf("Invalid choice.\n");
    }
    getchar();
}