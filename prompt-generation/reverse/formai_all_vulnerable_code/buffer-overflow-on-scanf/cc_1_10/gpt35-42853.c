//FormAI DATASET v1.0 Category: Smart home automation ; Style: Cyberpunk
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

// Initialize random seed
void init_random_seed() {
    srand(time(NULL));
}

// Function to check if a given probability is true
bool prob_true(float prob) {
    return ((float) rand() / (float) RAND_MAX) <= prob;
}

// Function to generate a random smart home event
void generate_event() {
    int rand_num = rand() % 4;
    char* event;
    switch (rand_num) {
        case 0:
            event = "The lights in the living room turned on.";
            break;
        case 1:
            event = "The temperature in the bedroom increased.";
            break;
        case 2:
            event = "The security system detected movement outside the house.";
            break;
        case 3:
            event = "The voice assistant was activated in the kitchen.";
    }
    printf("%s\n", event);
}

int main() {
    init_random_seed();

    int hour = 0;
    int minutes = 0;
    float prob_event = 0.5;

    printf("Welcome to your CyberPunk Smart Home Automation System!\n");
    printf("You can control every aspect of your house with just a few commands.\n");
    printf("Let's get started.\n\n");

    while (true) {
        printf("It is currently %02d:%02d.\n", hour, minutes);
        printf("What would you like to do? Enter a command (or type 'help' for a list of commands): ");

        char command[20];
        scanf("%s", command);

        if (strcmp(command, "help") == 0) {
            printf("\nAvailable commands:\n");
            printf("\t- 'view time' to see the current time.\n");
            printf("\t- 'set time' to set the current time. Format is HH:MM.\n");
            printf("\t- 'view probability' to see the current event probability.\n");
            printf("\t- 'set probability' to set the event probability. Format is 0.00 - 1.00.\n");
            printf("\t- 'simulate' to simulate a random event happening.\n");
            printf("\t- 'exit' to exit the program.\n");
        } else if (strcmp(command, "view time") == 0) {
            printf("The current time is %02d:%02d.\n", hour, minutes);
        } else if (strcmp(command, "set time") == 0) {
            int new_hour, new_minutes;
            scanf("%d:%d", &new_hour, &new_minutes);
            if (new_hour < 0 || new_hour > 23 || new_minutes < 0 || new_minutes > 59) {
                printf("Invalid time.\n");
            } else {
                hour = new_hour;
                minutes = new_minutes;
                printf("The time has been set to %02d:%02d.\n", hour, minutes);
            }
        } else if (strcmp(command, "view probability") == 0) {
            printf("The current event probability is %.2f.\n", prob_event);
        } else if (strcmp(command, "set probability") == 0) {
            float new_prob;
            scanf("%f", &new_prob);
            if (new_prob < 0 || new_prob > 1) {
                printf("Invalid probability.\n");
            } else {
                prob_event = new_prob;
                printf("The event probability has been set to %.2f.\n", prob_event);
            }
        } else if (strcmp(command, "simulate") == 0) {
            if (prob_true(prob_event)) {
                generate_event();
            } else {
                printf("No event happened.\n");
            }
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting program...\n");
            break;
        } else {
            printf("Invalid command. Type 'help' for available commands.\n");
        }
        printf("\n");
    }

    return 0;
}