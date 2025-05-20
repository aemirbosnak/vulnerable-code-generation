//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BAGS 100
#define MAX_NAME_LEN 50

typedef struct {
    int id;
    char owner[MAX_NAME_LEN];
    char status[MAX_NAME_LEN];
} Baggage;

Baggage baggageCollection[MAX_BAGS];
int bagCount = 0;

void addBaggage(int id, const char *owner) {
    if (bagCount < MAX_BAGS) {
        baggageCollection[bagCount].id = id;
        strncpy(baggageCollection[bagCount].owner, owner, MAX_NAME_LEN);
        strcpy(baggageCollection[bagCount].status, "Checked In");
        bagCount++;
        printf("Baggage %d added for %s.\n", id, owner);
    } else {
        printf("Baggage storage is full!\n");
    }
}

void processBaggage(int id) {
    for (int i = 0; i < bagCount; i++) {
        if (baggageCollection[i].id == id) {
            if (strcmp(baggageCollection[i].status, "Checked In") == 0) {
                strcpy(baggageCollection[i].status, "In Transit");
                printf("Baggage %d is now In Transit.\n", id);
            } else if (strcmp(baggageCollection[i].status, "In Transit") == 0) {
                strcpy(baggageCollection[i].status, "At Arrival");
                printf("Baggage %d has arrived.\n", id);
            } else {
                printf("Baggage %d has already arrived.\n", id);
            }
            return;
        }
    }
    printf("Baggage ID %d not found!\n", id);
}

void displayBaggageStatus() {
    printf("\nCurrent Baggage Status:\n");
    for (int i = 0; i < bagCount; i++) {
        printf("ID: %d, Owner: %s, Status: %s\n", baggageCollection[i].id, baggageCollection[i].owner, baggageCollection[i].status);
    }
}

int main() {
    int choice, id;
    char owner[MAX_NAME_LEN];

    while (1) {
        printf("\n--- Airport Baggage Handling System ---\n");
        printf("1. Add Baggage\n");
        printf("2. Process Baggage\n");
        printf("3. Display Baggage Status\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Baggage ID: ");
                scanf("%d", &id);
                printf("Enter Owner Name: ");
                scanf("%s", owner);
                addBaggage(id, owner);
                break;

            case 2:
                printf("Enter Baggage ID to process: ");
                scanf("%d", &id);
                processBaggage(id);
                break;

            case 3:
                displayBaggageStatus();
                break;

            case 4:
                printf("Exiting the program. Thank you!\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
        sleep(1); // Pause for 1 second before displaying the menu again
    }

    return 0;
}