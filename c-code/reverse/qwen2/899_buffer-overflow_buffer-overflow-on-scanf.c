#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    int choice;

    printf("Welcome to the Adventure Game!\n");
    printf("You find yourself at a fork in the road.\n");
    printf("1. Go left\n2. Go right\nChoose your path (1/2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("\nYou chose to go left.\n");
        printf("A bear appears! What do you do?\n");
        printf("1. Fight the bear\n2. Run away\nChoose an action (1/2): ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("\nYou bravely fought the bear and won!\n");
        } else if (choice == 2) {
            printf("\nYou ran away safely.\n");
        } else {
            printf("\nInvalid choice. You get lost.\n");
        }
    } else if (choice == 2) {
        printf("\nYou chose to go right.\n");
        printf("You find a treasure chest! What do you do?\n");
        printf("1. Open the chest\n2. Leave it closed\nChoose an action (1/2): ");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("\nYou opened the chest and found gold!\n");
        } else if (choice == 2) {
            printf("\nYou decided to leave the chest alone.\n");
        } else {
            printf("\nInvalid choice. You miss out on the treasure.\n");
        }
    } else {
        printf("\nInvalid choice. The path splits again.\n");
    }

    return 0;
}
