//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BAGS 100
#define DESTINATION_LENGTH 20
#define BAG_STATUS_LENGTH 30

typedef struct {
    int id;
    char destination[DESTINATION_LENGTH];
    char status[BAG_STATUS_LENGTH];
} Bag;

Bag bags[MAX_BAGS];
int bag_count = 0;

void check_in_bag(int id, const char* destination) {
    if (bag_count < MAX_BAGS) {
        bags[bag_count].id = id;
        strncpy(bags[bag_count].destination, destination, DESTINATION_LENGTH);
        strncpy(bags[bag_count].status, "Checked In", BAG_STATUS_LENGTH);
        bag_count++;
        printf("Bag ID %d checked in to %s\n", id, destination);
    } else {
        printf("Bag check-in failed: Maximum capacity reached.\n");
    }
}

void sort_bags() {
    for (int i = 0; i < bag_count - 1; i++) {
        for (int j = i + 1; j < bag_count; j++) {
            if (strcmp(bags[i].destination, bags[j].destination) > 0) {
                Bag temp = bags[i];
                bags[i] = bags[j];
                bags[j] = temp;
            }
        }
    }
    printf("Bags sorted by destination.\n");
}

void retrieve_bag(int id) {
    for (int i = 0; i < bag_count; i++) {
        if (bags[i].id == id) {
            printf("Retrieving Bag ID %d destined for %s. Status: %s\n",
                   bags[i].id, bags[i].destination, bags[i].status);
            strncpy(bags[i].status, "Retrieved", BAG_STATUS_LENGTH);
            return;
        }
    }
    printf("Bag ID %d not found.\n", id);
}

void display_bags() {
    printf("\nCurrent bags in the system:\n");
    for (int i = 0; i < bag_count; i++) {
        printf("Bag ID: %d, Destination: %s, Status: %s\n",
               bags[i].id, bags[i].destination, bags[i].status);
    }
}

int main() {
    int choice, id;
    char destination[DESTINATION_LENGTH];

    while (1) {
        printf("\n--- Airport Baggage Handling System ---\n");
        printf("1. Check in bag\n");
        printf("2. Sort bags\n");
        printf("3. Retrieve bag\n");
        printf("4. Display bags\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter bag ID: ");
                scanf("%d", &id);
                printf("Enter destination: ");
                scanf("%s", destination);
                check_in_bag(id, destination);
                break;
            case 2:
                sort_bags();
                break;
            case 3:
                printf("Enter bag ID to retrieve: ");
                scanf("%d", &id);
                retrieve_bag(id);
                break;
            case 4:
                display_bags();
                break;
            case 5:
                printf("Exiting program. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}