//Falcon2-11B DATASET v1.0 Category: Periodic Table Quiz ; Style: complete
#include <stdio.h>

// Define the structure for elements of the periodic table
struct Element {
    char symbol[3];
    int atomicNumber;
    int massNumber;
};

// Print an element in a formatted way
void printElement(const struct Element *elem) {
    printf("%c %d %d\n", elem->symbol, elem->atomicNumber, elem->massNumber);
}

// Ask user for an element and return its index in the array
int getElementIndex(struct Element elements[], int numElements, char *symbol) {
    for (int i = 0; i < numElements; i++) {
        if (strcmp(elements[i].symbol, symbol) == 0) {
            return i;
        }
    }
    return -1;
}

// Main function
int main() {

    // Create an array of elements
    struct Element elements[] = {
        {"H", 1, 1},
        {"He", 2, 4},
        //... add more elements here...
    };

    // Number of elements in the array
    int numElements = sizeof(elements) / sizeof(elements[0]);

    // Print all elements
    for (int i = 0; i < numElements; i++) {
        printElement(&elements[i]);
    }

    // Ask user to guess an element
    char guess[3];
    printf("Guess an element: ");
    scanf("%s", guess);

    // Check if the guess matches any element
    int index = getElementIndex(elements, numElements, guess);
    if (index!= -1) {
        printf("Correct!\n");
    } else {
        printf("Incorrect.\n");
    }

    // Ask user if they want to try again or exit
    char choice;
    while (choice!= 'e') {
        printf("Do you want to try again (y/n)? ");
        scanf(" %c", &choice);
        if (choice == 'y') {
            // Reset variables and continue quiz
            printf("Guess an element: ");
            scanf("%s", guess);
            index = getElementIndex(elements, numElements, guess);
            if (index!= -1) {
                printf("Correct!\n");
            } else {
                printf("Incorrect.\n");
            }
        } else {
            printf("Thanks for playing!\n");
            return 0;
        }
    }

    return 0;
}