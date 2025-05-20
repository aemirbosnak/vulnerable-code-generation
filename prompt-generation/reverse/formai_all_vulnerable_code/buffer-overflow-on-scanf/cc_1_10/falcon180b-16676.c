//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intro();
void game();
void end();

int main() {
    srand(time(NULL));
    int choice;

    intro();

    do {
        game();

        printf("Do you want to play again? (y/n): ");
        scanf("%d", &choice);
    } while (choice == 'y' || choice == 'Y');

    end();

    return 0;
}

void intro() {
    printf("Welcome to the Text-Based Adventure Game!\n");
    printf("In this game, you will explore a mysterious world filled with danger and treasure.\n");
    printf("Are you ready to begin your adventure? (y/n): ");
    char response;
    scanf("%c", &response);

    if (response!= 'y' && response!= 'Y') {
        printf("Exiting game...\n");
        exit(0);
    }
}

void game() {
    int room = rand() % 5;
    switch (room) {
        case 0:
            printf("You are in a dark, damp dungeon. There is a door to the east.\n");
            break;
        case 1:
            printf("You are in a lush, green forest. There is a path to the west.\n");
            break;
        case 2:
            printf("You are in a fiery, red desert. There is a cave to the south.\n");
            break;
        case 3:
            printf("You are in a snowy, white tundra. There is an igloo to the north.\n");
            break;
        case 4:
            printf("You are in a grand, golden palace. There is a throne to the east.\n");
            break;
    }

    char direction;
    printf("Which way do you want to go? (w/e/s/n): ");
    scanf("%c", &direction);

    switch (direction) {
        case 'w':
        case 'W':
            if (room == 0 || room == 1 || room == 3) {
                printf("You can't go that way.\n");
            } else {
                room--;
            }
            break;
        case 'e':
        case 'E':
            if (room == 0 || room == 2 || room == 4) {
                printf("You can't go that way.\n");
            } else {
                room++;
            }
            break;
        case's':
        case 'S':
            if (room == 1 || room == 3 || room == 4) {
                printf("You can't go that way.\n");
            } else {
                room += 2;
            }
            break;
        case 'n':
        case 'N':
            if (room == 0 || room == 1 || room == 2) {
                printf("You can't go that way.\n");
            } else {
                room -= 2;
            }
            break;
        default:
            printf("Invalid direction.\n");
    }

    switch (room) {
        case 0:
            printf("You found a treasure chest! You gained 100 gold!\n");
            break;
        case 1:
            printf("You found a friendly unicorn. It will help you on your journey.\n");
            break;
        case 2:
            printf("You found a magical amulet. It will protect you from harm.\n");
            break;
        case 3:
            printf("You found a hidden cave. It leads to a secret area!\n");
            break;
        case 4:
            printf("You met the king. He rewarded you with 500 gold!\n");
            break;
    }
}

void end() {
    printf("Thanks for playing the Text-Based Adventure Game!\n");
}