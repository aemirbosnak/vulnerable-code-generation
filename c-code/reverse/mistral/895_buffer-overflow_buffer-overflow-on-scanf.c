#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 20

void hauntedHouse(char name[]) {
    char choice;
    int ghostEncounter = 0;

    printf("Welcome to the Haunted House, %s!\n", name);
    printf("Do you dare enter? (y/n)\n");
    scanf(" %c", &choice);

    if (choice == 'y') {
        printf("You enter the house...\n");
        printf("You see a door to your left and a staircase to your right.\n");
        printf("Where do you go? (l/r)\n");
        scanf(" %c", &choice);

        if (choice == 'l') {
            printf("You find a closet full of old clothes.\n");
            printf("You leave the house unscathed.\n");
        } else if (choice == 'r') {
            printf("You hear a strange noise...\n");
            printf("A ghost appears!\n");
            ghostEncounter = 1;
        } else {
            printf("Invalid input. Please try again.\n");
        }

        if (ghostEncounter) {
            printf("You've encountered a ghost! Game over.\n");
        } else {
            printf("You've successfully escaped the haunted house!\n");
        }
    } else {
        printf("You've chosen to leave. Better safe than sorry!\n");
    }
}

int main() {
    char name[MAX_NAME_LENGTH];
    printf("What is your name?\n");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';

    hauntedHouse(name);

    return 0;
}
