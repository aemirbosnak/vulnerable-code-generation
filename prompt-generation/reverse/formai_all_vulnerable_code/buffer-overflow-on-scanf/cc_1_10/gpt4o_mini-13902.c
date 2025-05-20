//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BAGGAGE 100
#define MAX_NAME 50

typedef enum {
    CHECKED_IN,
    LOADING,
    IN_TRANSIT,
    ARRIVED,
    LOST
} BaggageStatus;

typedef struct {
    int id;
    char owner[MAX_NAME];
    BaggageStatus status;
} Baggage;

Baggage baggageList[MAX_BAGGAGE];
int baggageCount = 0;

void checkInBaggage() {
    if (baggageCount >= MAX_BAGGAGE) {
        printf("Baggage limit reached! Cannot check in more baggage.\n");
        return;
    }
    Baggage newBaggage;
    newBaggage.id = baggageCount + 1; // Simple ID generation
    printf("Enter owner's name: ");
    scanf("%s", newBaggage.owner);
    newBaggage.status = CHECKED_IN;

    baggageList[baggageCount++] = newBaggage;
    printf("Baggage checked in successfully! ID: %d\n", newBaggage.id);
}

void updateBaggageStatus(int id, BaggageStatus status) {
    for (int i = 0; i < baggageCount; i++) {
        if (baggageList[i].id == id) {
            baggageList[i].status = status;
            printf("Baggage ID %d status updated to %d.\n", id, status);
            return;
        }
    }
    printf("Baggage ID %d not found!\n", id);
}

void simulateBaggageProcess() {
    srand(time(0)); // Seed for randomness
    for (int i = 0; i < baggageCount; i++) {
        if (baggageList[i].status == CHECKED_IN) {
            updateBaggageStatus(baggageList[i].id, LOADING);
            updateBaggageStatus(baggageList[i].id, IN_TRANSIT);
            if (rand() % 10 < 3) { // 30% chance of being lost
                updateBaggageStatus(baggageList[i].id, LOST);
            } else {
                updateBaggageStatus(baggageList[i].id, ARRIVED);
            }
        }
    }
}

void displayBaggageStatus() {
    printf("\nCurrent baggage status:\n");
    for (int i = 0; i < baggageCount; i++) {
        printf("Baggage ID: %d | Owner: %s | Status: %d\n", baggageList[i].id, baggageList[i].owner, baggageList[i].status);
    }
}

int main() {
    int choice;

    do {
        printf("\n===== Airport Baggage Handling System =====\n");
        printf("1. Check in Baggage\n");
        printf("2. Simulate Baggage Process\n");
        printf("3. Display Baggage Status\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkInBaggage();
                break;
            case 2:
                simulateBaggageProcess();
                break;
            case 3:
                displayBaggageStatus();
                break;
            case 4:
                printf("Exiting the program. Thank you!\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    } while (choice != 4);

    return 0;
}