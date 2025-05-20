//Falcon2-11B DATASET v1.0 Category: Smart home light control ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

int main() {
    char command[100];
    int light_level;

    printf("Welcome, noble guest! What is thy bidding?\n");
    scanf("%s", command);

    if (strcmp(command, "turn on") == 0) {
        printf("The torches are lit! The hall is now bathed in a warm glow.\n");
        light_level = 100;
    } else if (strcmp(command, "turn off") == 0) {
        printf("The torches are extinguished! The hall is now shrouded in darkness.\n");
        light_level = 0;
    } else {
        printf("I do not understand thy command, noble guest.\n");
        printf("Please choose from the following options:\n");
        printf("1. Turn on\n");
        printf("2. Turn off\n");
        printf("3. Exit\n");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            printf("The torches are lit! The hall is now bathed in a warm glow.\n");
            light_level = 100;
        } else if (choice == 2) {
            printf("The torches are extinguished! The hall is now shrouded in darkness.\n");
            light_level = 0;
        } else if (choice == 3) {
            printf("Fare thee well, noble guest.\n");
            exit(0);
        } else {
            printf("I do not understand thy command, noble guest.\n");
        }
    }

    if (light_level > 50) {
        printf("The torches are ablaze! The hall is now bathed in a warm, fiery glow.\n");
    } else if (light_level > 25) {
        printf("The torches are flickering! The hall is now bathed in a warm, flickering glow.\n");
    } else {
        printf("The torches are barely glowing! The hall is now bathed in a dim, flickering glow.\n");
    }

    printf("The %d-level lighting has been set.\n", light_level);
    printf("May thy journey through the castle be well-lit and safe.\n");
    return 0;
}