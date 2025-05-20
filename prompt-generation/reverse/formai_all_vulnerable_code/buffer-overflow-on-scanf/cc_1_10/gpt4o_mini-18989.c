//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BAGS 100

typedef struct {
    int id;
    char owner[50];
    char destination[50];
    int processed;
} Bag;

Bag baggage[MAX_BAGS];
int bag_count = 0;

void add_bag(int id, const char* owner, const char* destination) {
    if (bag_count < MAX_BAGS) {
        baggage[bag_count].id = id;
        strcpy(baggage[bag_count].owner, owner);
        strcpy(baggage[bag_count].destination, destination);
        baggage[bag_count].processed = 0;
        bag_count++;
        printf("Bag added: ID %d, Owner %s, Destination %s\n", id, owner, destination);
    } else {
        printf("Error: Bag storage full!\n");
    }
}

void process_bag(int id) {
    for (int i = 0; i < bag_count; i++) {
        if (baggage[i].id == id) {
            if (baggage[i].processed == 0) {
                baggage[i].processed = 1;
                printf("Bag ID %d processed successfully!\n", id);
            } else {
                printf("Bag ID %d has already been processed.\n", id);
            }
            return;
        }
    }
    printf("Error: Bag ID %d not found.\n", id);
}

void display_baggage_status() {
    printf("\n--- Baggage Status ---\n");
    for (int i = 0; i < bag_count; i++) {
        printf("ID: %d, Owner: %s, Destination: %s, Processed: %s\n",
               baggage[i].id, baggage[i].owner, baggage[i].destination,
               baggage[i].processed ? "Yes" : "No");
    }
    printf("----------------------\n");
}

void menu() {
    printf("Welcome to the Airport Baggage Handling System\n");
    printf("1. Add Bag\n");
    printf("2. Process Bag\n");
    printf("3. Display Baggage Status\n");
    printf("4. Exit\n");
}

int main() {
    int choice, id;
    char owner[50], destination[50];

    while (1) {
        menu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Bag ID: ");
                scanf("%d", &id);
                printf("Enter Owner's Name: ");
                scanf("%s", owner);
                printf("Enter Destination: ");
                scanf("%s", destination);
                add_bag(id, owner, destination);
                break;
            case 2:
                printf("Enter Bag ID to process: ");
                scanf("%d", &id);
                process_bag(id);
                break;
            case 3:
                display_baggage_status();
                break;
            case 4:
                printf("Exiting the system...\n");
                exit(0);
            default:
                printf("Invalid option! Please choose again.\n");
        }
        sleep(1); // Wait for a moment before showing the menu again
    }
    
    return 0;
}