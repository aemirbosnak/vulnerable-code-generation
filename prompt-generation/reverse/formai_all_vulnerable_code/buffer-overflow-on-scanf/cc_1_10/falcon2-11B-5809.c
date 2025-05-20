//Falcon2-11B DATASET v1.0 Category: Educational ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

void goNorth() {
    printf("You go north.\n");
}

void goSouth() {
    printf("You go south.\n");
}

void goEast() {
    printf("You go east.\n");
}

void goWest() {
    printf("You go west.\n");
}

void printRoom() {
    printf("You are in a dark room with four doors.\n");
    printf("One leads north, one leads south, one leads east, and one leads west.\n");
}

int main() {
    printRoom();

    int choice;
    while (1) {
        printf("Which direction would you like to go? (N/S/E/W): ");
        scanf("%d", &choice);

        switch (choice) {
            case 'N':
                goNorth();
                break;
            case 'S':
                goSouth();
                break;
            case 'E':
                goEast();
                break;
            case 'W':
                goWest();
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}