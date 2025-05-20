//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function declarations
int generateRandomCase(char *caseName);
void printCaseDetails(char *caseName, int caseNumber);
void investigateCase(char *caseName, int caseNumber);

int main() {
    srand(time(0)); // Seed the random number generator with current time

    int numberOfCases;
    printf("Enter the number of cases you want to generate: ");
    scanf("%d", &numberOfCases);

    for (int i = 1; i <= numberOfCases; i++) {
        char caseName[20];
        sprintf(caseName, "Case %d", i);
        generateRandomCase(caseName);
        printCaseDetails(caseName, i);
        investigateCase(caseName, i);
    }

    return 0;
}

// Function to generate a random case name and number
int generateRandomCase(char *caseName) {
    int randomNumber = rand() % 3; // Generate a random number between 0 and 2

    switch (randomNumber) {
        case 0:
            strcpy(caseName, "The Mystery of the Missing Diamond");
            break;
        case 1:
            strcpy(caseName, "The Adventure of the Secret Code");
            break;
        case 2:
            strcpy(caseName, "The Enigma of the Haunted Mansion");
            break;
        default:
            printf("Error: Invalid case number.\n");
            exit(1);
    }

    return randomNumber;
}

// Function to print case details
void printCaseDetails(char *caseName, int caseNumber) {
    printf("\n\nCase %d: %s\n", caseNumber, caseName);
}

// Function to investigate the case
void investigateCase(char *caseName, int caseNumber) {
    int randomNumber = generateRandomCase(caseName);

    switch (randomNumber) {
        case 0:
            printf("\nYou are tasked with solving the mystery of the missing diamond.\n");
            printf("The diamond was last seen at a gala event attended by several wealthy individuals.\n");
            printf("You must interview each suspect and gather clues to determine who stole the diamond.\n");
            break;
        case 1:
            printf("\nYour mission is to decode a secret message left behind by an anonymous source.\n");
            printf("The message contains vital information that could prevent a catastrophic event.\n");
            printf("Use your skills in cryptography to unravel the mystery and save the day.\n");
            break;
        case 2:
            printf("\nRumors of paranormal activity have surrounded the old mansion on the hill for years.\n");
            printf("As Sherlock Holmes, you must investigate these claims and uncover the truth behind them.\n");
            printf("Explore the mansion, gather evidence, and solve puzzles to get to the bottom of this enigma.\n");
            break;
        default:
            printf("Error: Invalid case number.\n");
            exit(1);
    }
}