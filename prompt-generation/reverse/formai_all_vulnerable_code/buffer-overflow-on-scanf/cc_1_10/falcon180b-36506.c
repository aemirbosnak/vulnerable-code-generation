//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the menu
void print_menu() {
    printf("Welcome to the Haunted House!\n");
    printf("1. Enter the house\n");
    printf("2. Exit\n");
    printf("Enter your choice: ");
}

// Function to generate random events
void generate_event() {
    int event = rand() % 4;

    switch (event) {
        case 0:
            printf("You hear a strange noise.\n");
            break;
        case 1:
            printf("You feel a cold breeze.\n");
            break;
        case 2:
            printf("You see a ghostly figure.\n");
            break;
        case 3:
            printf("You feel like you're being watched.\n");
            break;
    }
}

// Function to simulate the haunted house
void haunted_house() {
    int choice, event_count = 0;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        if (choice == 1) {
            printf("You enter the haunted house...\n");

            while (event_count < 5) {
                generate_event();
                event_count++;
            }

            printf("You made it out alive!\n");
        } else if (choice == 2) {
            printf("Thanks for visiting the Haunted House!\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
}

int main() {
    srand(time(NULL));
    haunted_house();

    return 0;
}