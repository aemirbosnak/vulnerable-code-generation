//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function Prototypes
void intro();
void game();
void start();
void end();

int main() {
    srand(time(NULL));
    int choice;
    while(1) {
        system("clear");
        intro();
        printf("Enter your choice:\n1. Start Game\n2. Quit\n");
        scanf("%d", &choice);
        if(choice == 1) {
            game();
        } else if(choice == 2) {
            end();
            break;
        } else {
            printf("Invalid choice!\n");
        }
    }
    return 0;
}

void intro() {
    printf("****************************************\n");
    printf("*                                      *\n");
    printf("*           WELCOME TO THE GAME         *\n");
    printf("*                                      *\n");
    printf("****************************************\n");
    printf("\n");
}

void game() {
    int x = rand() % 3 + 1; // Generating random number between 1 and 3
    if(x == 1) {
        printf("You found a treasure!\n");
    } else if(x == 2) {
        printf("You encountered a monster!\n");
    } else {
        printf("You reached the end of the game!\n");
    }
}

void start() {
    printf("The game has started...\n");
    printf("Press any key to continue...\n");
    getchar();
}

void end() {
    printf("The game has ended...\n");
    printf("Press any key to exit...\n");
    getchar();
}