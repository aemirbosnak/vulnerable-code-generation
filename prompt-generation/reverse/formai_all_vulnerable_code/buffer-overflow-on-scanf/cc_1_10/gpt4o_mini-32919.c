//GPT-4o-mini DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_THEORIES 10
#define MAX_DESCRIPTORS 5
#define BUFFER_SIZE 256

char *theories[MAX_THEORIES] = {
    "The AI overlords have been manipulating stock markets.",
    "Neon signs are embedded with mind-control technology.",
    "Corporate megacities are actually spaceships disguised as urban areas.",
    "Virtual reality is a trap to keep us from realizing the real world is dying.",
    "Cybernetic enhancements are a way to harvest human organs.",
    "Hacker collectives are working with rogue AI to combat the corporations.",
    "Holographic advertisements are spying on your desires.",
    "Underground communities are building their own city using nanite technology.",
    "5G towers emit signals that can control our thoughts.",
    "The government has turned the moon into a surveillance base."
};

char *descriptors[MAX_DESCRIPTORS] = {
    "They discovered this when they hacked into the mainframe.",
    "A whistleblower revealed documents that confirmed this.",
    "It was leaked in a forgotten chatroom on the dark web.",
    "Street kids say they found a blueprint showing this scheme.",
    "Witnesses claim they saw drones conducting secret scans."
};

void generateTheory() {
    srand(time(0)); // Seed the random number generator
    int theory_index = rand() % MAX_THEORIES; // Randomly select a theory
    int descriptor_index = rand() % MAX_DESCRIPTORS; // Randomly select a descriptor

    char output[BUFFER_SIZE];
    snprintf(output, BUFFER_SIZE, "Theory: \"%s\"\nDescriptor: \"%s\"\n", theories[theory_index], descriptors[descriptor_index]);
    printf("%s", output);
}

void displayMenu() {
    printf("=== Cyberpunk Conspiracy Theory Generator ===\n");
    printf("1. Generate a new theory\n");
    printf("2. Exit\n");
    printf("=============================================\n");
}

int main() {
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            generateTheory();
        } else if (choice != 2) {
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 2);

    printf("Stay vigilant, the Matrix is watching!\n");
    return 0;
}