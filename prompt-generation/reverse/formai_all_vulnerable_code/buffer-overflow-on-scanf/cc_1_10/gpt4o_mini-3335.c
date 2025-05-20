//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BAGS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char owner[MAX_NAME_LENGTH];
    int bag_id;
    int checked_in;
} Baggage;

Baggage baggage_list[MAX_BAGS];
int baggage_count = 0;

void check_in_bag() {
    if (baggage_count >= MAX_BAGS) {
        printf("All baggage slots are full!\n");
        return;
    }
    Baggage new_bag;
    printf("Enter your name: ");
    scanf("%s", new_bag.owner);
    new_bag.bag_id = baggage_count + 1; // Simple ID assignment
    new_bag.checked_in = 1;
    
    baggage_list[baggage_count] = new_bag;
    baggage_count++;

    printf("Bag checked in successfully! Your Bag ID is: %d\n", new_bag.bag_id);
}

void transport_bag(int bag_id) {
    if (bag_id > baggage_count || bag_id <= 0) {
        printf("Invalid Bag ID!\n");
        return;
    }

    Baggage *bag = &baggage_list[bag_id - 1];
    if (!bag->checked_in) {
        printf("This bag has not been checked in!\n");
        return;
    }

    printf("Transporting bag ID %d of %s...\n", bag->bag_id, bag->owner);
    // Simulating random outcomes: lost or delivered
    srand(time(NULL));
    int outcome = rand() % 2; // 0: lost, 1: delivered
    
    if (outcome == 0) {
        printf("Oh no! Bag ID %d is lost!\n", bag->bag_id);
        bag->checked_in = 0; // Mark as lost
    } else {
        printf("Bag ID %d successfully delivered to the terminal!\n", bag->bag_id);
        bag->checked_in = 0; // Mark as delivered
    }
}

void display_baggage_status() {
    printf("\nCurrent Baggage Status:\n");
    for (int i = 0; i < baggage_count; i++) {
        Baggage bag = baggage_list[i];
        printf("Bag ID: %d | Owner: %s | Status: %s\n", 
               bag.bag_id, 
               bag.owner, 
               bag.checked_in ? "Checked In" : "Handled");
    }
    printf("\n");
}

int main() {
    int choice;
    printf("Welcome to the Lively Airport Baggage Handling System!\n");
    
    do {
        printf("Choose an option:\n");
        printf("1. Check in a bag\n");
        printf("2. Transport a bag by ID\n");
        printf("3. Display baggage status\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                check_in_bag();
                break;
            case 2: {
                int bag_id;
                printf("Enter Bag ID to transport: ");
                scanf("%d", &bag_id);
                transport_bag(bag_id);
                break;
            }
            case 3:
                display_baggage_status();
                break;
            case 4:
                printf("Exiting the system. Safe travels!\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    } while (choice != 4);

    return 0;
}