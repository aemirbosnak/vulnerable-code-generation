//Falcon2-11B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the structure to hold bag information
typedef struct {
    int id;
    char name[50];
    int weight;
    int checked;
} Bag;

// Function to read bag information from the user
Bag read_bag(void) {
    Bag bag;
    printf("Enter the bag's ID: ");
    scanf("%d", &bag.id);
    fflush(stdin);

    printf("Enter the bag's name: ");
    scanf("%s", bag.name);
    fflush(stdin);

    printf("Enter the bag's weight: ");
    scanf("%d", &bag.weight);
    fflush(stdin);

    printf("Enter 1 to check the bag and 0 to not check the bag: ");
    scanf("%d", &bag.checked);
    fflush(stdin);

    return bag;
}

// Function to print the bag information
void print_bag(Bag bag) {
    printf("ID: %d\n", bag.id);
    printf("Name: %s\n", bag.name);
    printf("Weight: %d\n", bag.weight);
    printf("Checked: %d\n", bag.checked);
}

// Function to add a bag to the baggage handling system
void add_bag(Bag bag, int num_bags) {
    srand(time(NULL));

    printf("Adding bag %d...\n", bag.id);
    if (rand() % 2 == 0) {
        bag.checked = 1;
        printf("Bag is checked\n");
    } else {
        bag.checked = 0;
        printf("Bag is not checked\n");
    }

    // Add the bag to the system
    printf("Bag %d added to the system\n", bag.id);

    // Print the bag information
    print_bag(bag);

    // Update the number of bags
    num_bags++;
}

// Function to remove a bag from the baggage handling system
void remove_bag(Bag bag, int num_bags) {
    printf("Removing bag %d...\n", bag.id);

    // Print the bag information
    print_bag(bag);

    // Update the number of bags
    num_bags--;
}

// Main function
int main() {
    int num_bags = 0;

    Bag bag;
    bag = read_bag();
    add_bag(bag, num_bags);
    remove_bag(bag, num_bags);

    printf("Number of bags: %d\n", num_bags);

    return 0;
}