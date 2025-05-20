//Falcon2-11B DATASET v1.0 Category: Periodic Table Quiz ; Style: asynchronous
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Function to print the periodic table
void printPeriodicTable() {
    printf("Periodic Table:\n");
    for (int i = 1; i <= 118; i++) {
        if (i % 4 == 0 && i!= 118) {
            printf(" ");
        }
        printf("%3d %-8s\n", i, " ");
    }
}

// Function to generate random element name
char* generateRandomElementName() {
    srand(time(NULL));
    char* elementName = malloc(sizeof(char) * 5);
    int randomElement = rand() % 118;
    switch (randomElement) {
        case 1:
            strcpy(elementName, "Hydrogen");
            break;
        case 2:
            strcpy(elementName, "Helium");
            break;
        case 3:
            strcpy(elementName, "Lithium");
            break;
        case 4:
            strcpy(elementName, "Beryllium");
            break;
        //... (other elements)
        case 118:
            strcpy(elementName, "Oganesson");
            break;
        default:
            break;
    }
    return elementName;
}

// Function to get user's guess
char getUserGuess() {
    char elementName[5];
    printf("Guess the element name (or 'q' to quit): ");
    scanf("%s", elementName);
    if (strcmp(elementName, "q") == 0) {
        return 'q';
    } else {
        return elementName[0];
    }
}

// Function to check user's guess
int checkUserGuess(char* elementName) {
    if (strcmp(elementName, "q") == 0) {
        return 0;
    } else {
        for (int i = 1; i <= 118; i++) {
            if (strcmp(elementName, " ") == 0) {
                printf("Invalid element name.\n");
                return 1;
            } else if (strcmp(elementName, " ")!= 0) {
                if (strcmp(elementName, " ") == 0) {
                    printf("Invalid element name.\n");
                    return 1;
                }
            }
        }
        return 0;
    }
}

// Main function
int main() {
    int numElements = 0;
    int numQuits = 0;
    char userGuess;
    printf("Welcome to the C Periodic Table Quiz!\n");
    printf("Enter '1' to start the quiz.\n");
    scanf("%d", &numElements);
    if (numElements == 1) {
        while (numQuits < numElements) {
            userGuess = getUserGuess();
            if (userGuess == 'q') {
                numQuits++;
            } else {
                char* elementName = generateRandomElementName();
                int result = checkUserGuess(elementName);
                if (result == 0) {
                    printf("Correct!\n");
                } else {
                    printf("Incorrect. The correct element is: %s.\n", elementName);
                }
            }
        }
    }
    printf("Thanks for playing!\n");
    return 0;
}