//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void start();
void main_menu();
void game();
void end();

int main() {
    srand(time(NULL));
    int choice;
    while(1) {
        system("clear");
        printf("Welcome to the Text-Based Adventure Game!\n");
        start();
        main_menu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                game();
                break;
            case 2:
                end();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void start() {
    printf("\n");
    printf("You wake up in a dark room with no memory of how you got there.\n");
    printf("The only thing you have is a flashlight and a note that says:\n");
    printf("\n");
    printf("'Find the key to escape this place'\n");
    printf("\n");
}

void main_menu() {
    printf("\n");
    printf("What would you like to do?\n");
    printf("1. Continue the game\n");
    printf("2. Quit\n");
}

void game() {
    char choice;
    int room = 1;
    while(1) {
        system("clear");
        printf("\n");
        printf("You are in room %d.\n", room);
        printf("\n");
        printf("What would you like to do?\n");
        printf("1. Look around\n");
        printf("2. Use flashlight\n");
        printf("3. Read note\n");
        scanf(" %c", &choice);
        switch(choice) {
            case '1':
                printf("\n");
                printf("You look around the room and find a key!\n");
                printf("\n");
                room++;
                break;
            case '2':
                printf("\n");
                printf("You turn on your flashlight and see a door.\n");
                printf("\n");
                room++;
                break;
            case '3':
                printf("\n");
                printf("The note says:\n");
                printf("\n");
                printf("'The key is hidden in the darkness'\n");
                printf("\n");
                break;
            default:
                printf("\n");
                printf("Invalid choice. Please try again.\n");
        }
    }
    printf("\n");
    printf("Congratulations! You have escaped the room.\n");
}

void end() {
    printf("\n");
    printf("Thanks for playing the Text-Based Adventure Game!\n");
}