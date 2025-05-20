//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BAGS 100
#define MAX_NAME_LEN 30

typedef struct {
    char owner[MAX_NAME_LEN];
    int weight; // in kilograms
    int flightNumber;
    int isLoaded; // 0 for not loaded, 1 for loaded
} Bag;

Bag baggage[MAX_BAGS];
int bagCount = 0;

// Function Prototypes
void checkInBag();
void loadBags();
void displayBags();
void deliverBags();

int main() {
    srand(time(0)); // For random values
    int choice;

    printf("Welcome to the Airport Baggage Handling System! 🌟\n");

    do {
        printf("\nPlease choose an option:\n");
        printf("1. Check in a bag 🎒\n");
        printf("2. Load bags onto the plane ✈️\n");
        printf("3. Display all bags 📋\n");
        printf("4. Deliver bags to the flight 📦\n");
        printf("5. Exit the program ❌\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkInBag();
                break;
            case 2:
                loadBags();
                break;
            case 3:
                displayBags();
                break;
            case 4:
                deliverBags();
                break;
            case 5:
                printf("Thank you for using the baggage handling system! Have a great day! 😊\n");
                break;
            default:
                printf("Oops! That choice is not available. Please try again! 🚫\n");
        }
    } while (choice != 5);

    return 0;
}

void checkInBag() {
    if (bagCount >= MAX_BAGS) {
        printf("The baggage area is full! Can't check in more bags. 😢\n");
        return;
    }

    printf("Please enter the owner's name: ");
    scanf("%s", baggage[bagCount].owner);
    printf("Enter the weight of the bag (kg): ");
    scanf("%d", &baggage[bagCount].weight);
    printf("Enter the flight number: ");
    scanf("%d", &baggage[bagCount].flightNumber);

    baggage[bagCount].isLoaded = 0; // Not loaded yet
    bagCount++;

    printf("Bag checked in successfully! 🎉\n");
}

void loadBags() {
    printf("Loading bags onto the planes... 🚚\n");

    for (int i = 0; i < bagCount; i++) {
        if (!baggage[i].isLoaded) {
            baggage[i].isLoaded = 1; // Mark as loaded
            printf("Loading bag for %s (Flight %d, Weight: %d kg) ✅\n", 
                    baggage[i].owner, baggage[i].flightNumber, baggage[i].weight);
        }
    }
    printf("All bags loaded! 🎊\n");
}

void displayBags() {
    if (bagCount == 0) {
        printf("No bags to display! 👜\n");
        return;
    }

    printf("\nDisplaying all bags: 📦\n");
    for (int i = 0; i < bagCount; i++) {
        printf("Owner: %s, Weight: %d kg, Flight: %d, Loaded: %s\n",
               baggage[i].owner, baggage[i].weight, baggage[i].flightNumber, 
               (baggage[i].isLoaded ? "Yes" : "No"));
    }
}

void deliverBags() {
    printf("Delivering bags to the respective flights... 📬\n");
    
    for (int i = 0; i < bagCount; i++) {
        if (baggage[i].isLoaded) {
            printf("Delivering bag for %s (Flight %d) to the luggage claim area... 🛄\n", 
                   baggage[i].owner, baggage[i].flightNumber);
            baggage[i].isLoaded = 0; // Mark as not loaded anymore
        }
    }
    printf("All bags delivered! Have a pleasant flight! ✈️😄\n");
}