//FormAI DATASET v1.0 Category: Smart home automation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Global variables to store status of different devices
bool lights = false;
bool ac = false;
bool tv = false;
bool lock = true;

// Function to toggle state of a device
void toggleDevice(char device) {
    switch (device) {
        case 'L':
            lights = !lights;
            printf("Lights turned %s\n", lights ? "on" : "off");
            break;
        case 'A':
            ac = !ac;
            printf("AC turned %s\n", ac ? "on" : "off");
            break;
        case 'T':
            tv = !tv;
            printf("TV turned %s\n", tv ? "on" : "off");
            break;
        case 'D':
            lock = !lock;
            printf("Door lock %s\n", lock ? "locked" : "unlocked");
            break;
        default:
            printf("Invalid device\n");
            break;
    }
}

int main() {
    // Welcome message
    printf("Welcome to Smart Home Automation\n");

    // Menu
    printf("\nMENU:\n");
    printf("L - Toggle Lights\n");
    printf("A - Toggle AC\n");
    printf("T - Toggle TV\n");
    printf("D - Toggle Door Lock\n");
    printf("Q - Quit Program\n");

    // User input loop
    char choice;
    do {
        printf("\nEnter your choice: ");
        scanf(" %c", &choice);
        
        switch (choice) {
            case 'L': case 'A': case 'T': case 'D':
                toggleDevice(choice);
                break;
            case 'Q':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    } while (choice != 'Q');

    return 0;
}