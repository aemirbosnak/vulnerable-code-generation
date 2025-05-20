//LLAMA2-13B DATASET v1.0 Category: Game ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_GUESTS 10

// Global variables
char *guestNames[MAX_GUESTS];
int numGuests = 0;

// Function prototypes
void printWelcomeMessage();
void printFarewellMessage();
void addGuest(char *name);
void removeGuest(int index);
void printGuestList();

int main() {
    // Welcome message
    printWelcomeMessage();

    // Ask user for number of guests
    printf("Enter number of guests: ");
    int numGuests = getUserInput();

    // Create an array to store guest names
    guestNames[0] = malloc(MAX_NAME_LENGTH * sizeof(char));

    // Loop to read guest names
    for (int i = 0; i < numGuests; i++) {
        printf("Guest %d's name: ", i + 1);
        scanf("%19s", guestNames[i]);
    }

    // Add guests to the list
    for (int i = 0; i < numGuests; i++) {
        addGuest(guestNames[i]);
    }

    // Loop to print guest list
    for (int i = 0; i < numGuests; i++) {
        printGuestList();
    }

    // Remove a guest
    removeGuest(getRandomIndex());

    // Print farewell message
    printFarewellMessage();

    return 0;
}

// Function to print a welcome message
void printWelcomeMessage() {
    printf("Welcome to the party! \n");
}

// Function to print a farewell message
void printFarewellMessage() {
    printf("Goodbye, party people! \n");
}

// Function to add a guest to the list
void addGuest(char *name) {
    // Check if the name is too long
    if (strlen(name) > MAX_NAME_LENGTH) {
        printf("Sorry, names cannot be longer than %d characters.\n", MAX_NAME_LENGTH);
        return;
    }

    // Check if the name is already in the list
    for (int i = 0; i < numGuests; i++) {
        if (strcmp(guestNames[i], name) == 0) {
            printf("Sorry, %s is already a guest.\n", name);
            return;
        }
    }

    // Add the name to the list
    guestNames[numGuests] = name;
    numGuests++;
}

// Function to remove a guest from the list
void removeGuest(int index) {
    // Check if the index is valid
    if (index < 0 || index >= numGuests) {
        printf("Sorry, invalid index.\n");
        return;
    }

    // Remove the name from the list
    guestNames[index] = NULL;
    numGuests--;
}

// Function to print the guest list
void printGuestList() {
    for (int i = 0; i < numGuests; i++) {
        if (guestNames[i] != NULL) {
            printf("%d. %s\n", i + 1, guestNames[i]);
        }
    }
}

// Function to get user input
int getUserInput() {
    char input[20];
    printf("Enter a number: ");
    fgets(input, 20, stdin);
    int userInput;
    sscanf(input, "%d", &userInput);
    return userInput;
}

// Function to get a random index
int getRandomIndex() {
    int index = rand() % numGuests;
    return index;
}