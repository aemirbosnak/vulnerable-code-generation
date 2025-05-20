//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print menu
void printMenu() {
    printf("\n");
    printf("   1. Start Adventure\n");
    printf("   2. Quit\n");
    printf("\n");
    printf("Select an option: ");
}

// Function to print game over message
void gameOver() {
    printf("\n");
    printf("Game Over!\n");
    printf("Thanks for playing!\n");
}

// Function to print victory message
void victory() {
    printf("\n");
    printf("Congratulations! You have won!\n");
    printf("Thanks for playing!\n");
}

// Function to print room description
void describeRoom(int room) {
    switch(room) {
        case 1:
            printf("\n");
            printf("You are in a dark, damp dungeon. The walls are made of stone and the floor is covered in moss.\n");
            printf("There is a door to the east.\n");
            break;
        case 2:
            printf("\n");
            printf("You are in a large, open field. The sun is shining and the grass is green.\n");
            printf("There is a path leading north.\n");
            break;
        case 3:
            printf("\n");
            printf("You are in a small, cozy room. There is a fireplace with a roaring fire and a comfortable chair.\n");
            printf("There is a door to the south.\n");
            break;
        case 4:
            printf("\n");
            printf("You are in a dark, spooky forest. The trees are tall and the leaves are falling.\n");
            printf("There is a path leading west.\n");
            break;
        case 5:
            printf("\n");
            printf("You are in a large, grand hall. There are chandeliers hanging from the ceiling and paintings on the walls.\n");
            printf("There is a door to the north.\n");
            break;
        case 6:
            printf("\n");
            printf("You are in a small, cramped room. There is a table with a key on it.\n");
            printf("There is a door to the east.\n");
            break;
    }
}

// Function to move between rooms
void move(int *room, int direction) {
    switch(direction) {
        case 1:
            (*room)++;
            break;
        case 2:
            (*room)--;
            break;
        case 3:
            (*room)++;
            break;
        case 4:
            (*room)--;
            break;
    }
}

// Function to check for victory
int checkVictory(int room) {
    if(room == 6) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    srand(time(0));
    int room = 1;
    int choice;
    
    while(1) {
        printMenu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                describeRoom(room);
                break;
            case 2:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
        
        if(checkVictory(room)) {
            victory();
            exit(0);
        }
    }
    
    return 0;
}