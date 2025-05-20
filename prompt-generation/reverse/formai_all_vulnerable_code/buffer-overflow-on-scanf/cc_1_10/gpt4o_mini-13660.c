//GPT-4o-mini DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_BAGS 10
#define MAX_NAME_LENGTH 50

typedef enum { ARRIVED, CHECKED_IN, LOADED, DELIVERED } BagStatus;

typedef struct {
    char name[MAX_NAME_LENGTH];
    BagStatus status;
    int id;
} Bag;

void initialize_bag(Bag *bag, int id, const char *name) {
    strncpy(bag->name, name, MAX_NAME_LENGTH - 1);
    bag->name[MAX_NAME_LENGTH - 1] = '\0'; // Ensure null-termination
    bag->status = ARRIVED;
    bag->id = id;
}

void print_bag_status(Bag *bag) {
    const char* status_names[] = { "Arrived", "Checked-In", "Loaded", "Delivered" };
    printf("Bag ID: %d, Name: %s, Status: %s\n", bag->id, bag->name, status_names[bag->status]);
}

void update_bag_status(Bag *bag) {
    if (bag->status < DELIVERED) {
        bag->status++;
    } else {
        printf("Bag %s has already been delivered!\n", bag->name);
    }
}

void process_bags(Bag *bags, int bag_count) {
    for (int i = 0; i < bag_count; i++) {
        print_bag_status(&bags[i]);
        printf("Processing bag...\n");
        update_bag_status(&bags[i]);
        print_bag_status(&bags[i]);
        printf("\n");
    }
}

void randomize_bag_names(Bag *bags, int bag_count) {
    const char *possible_names[] = { "Suitcase", "Backpack", "Sports Bag", "Travel Bag", "Hand Luggage" };
    srand(time(NULL));

    for (int i = 0; i < bag_count; i++) {
        const char *name = possible_names[rand() % (sizeof(possible_names) / sizeof(possible_names[0]))];
        initialize_bag(&bags[i], i + 1, name);
    }
}

int main() {
    Bag bags[MAX_BAGS];
    int bag_count;

    printf("Welcome to the Airport Baggage Handling Simulation!\n");
    printf("How many bags would you like to process today (max %d)? ", MAX_BAGS);
    
    scanf("%d", &bag_count);
    if (bag_count < 1 || bag_count > MAX_BAGS) {
        printf("Invalid number of bags. Please restart the simulation and enter a number between 1 and %d.\n", MAX_BAGS);
        return 1;
    }

    randomize_bag_names(bags, bag_count);
    printf("\nLet's get started with processing the bags...\n\n");
    process_bags(bags, bag_count);

    printf("All bags have been processed and the simulation is complete! Thank you for playing!\n");
    return 0;
}