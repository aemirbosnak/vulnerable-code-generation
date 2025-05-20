//Falcon2-11B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Global Variables
int num_bags = 0;
int num_planes = 0;
int num_bags_on_plane = 0;
int num_bags_on_belt = 0;
int num_bags_removed = 0;

// Function Prototypes
void print_menu();
void handle_bag(int bag_id, int plane_id, int belt_id);
void process_bag();

int main() {
    // Initialization
    print_menu();

    // Loop
    while (1) {
        int choice;
        printf("Enter your choice: \n");
        printf("1. Add Bag \n");
        printf("2. Remove Bag \n");
        printf("3. View Bag Status \n");
        printf("4. Quit \n");
        scanf("%d", &choice);

        // Add Bag
        if (choice == 1) {
            int bag_id, plane_id, belt_id;
            printf("Enter bag id: ");
            scanf("%d", &bag_id);
            printf("Enter plane id: ");
            scanf("%d", &plane_id);
            printf("Enter belt id: ");
            scanf("%d", &belt_id);
            handle_bag(bag_id, plane_id, belt_id);
        }

        // Remove Bag
        else if (choice == 2) {
            int bag_id, plane_id, belt_id;
            printf("Enter bag id: ");
            scanf("%d", &bag_id);
            printf("Enter plane id: ");
            scanf("%d", &plane_id);
            printf("Enter belt id: ");
            scanf("%d", &belt_id);
            handle_bag(bag_id, plane_id, belt_id);
        }

        // View Bag Status
        else if (choice == 3) {
            int bag_id, plane_id, belt_id;
            printf("Enter bag id: ");
            scanf("%d", &bag_id);
            printf("Enter plane id: ");
            scanf("%d", &plane_id);
            printf("Enter belt id: ");
            scanf("%d", &belt_id);
            handle_bag(bag_id, plane_id, belt_id);
        }

        // Quit
        else if (choice == 4) {
            printf("Program terminated.\n");
            break;
        }

        // Invalid Choice
        else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}

// Function to print the menu
void print_menu() {
    printf("-----------------------------------------\n");
    printf("Airport Baggage Handling Simulation\n");
    printf("-----------------------------------------\n");
    printf("1. Add Bag\n");
    printf("2. Remove Bag\n");
    printf("3. View Bag Status\n");
    printf("4. Quit\n");
    printf("-----------------------------------------\n");
}

// Function to handle a bag
void handle_bag(int bag_id, int plane_id, int belt_id) {
    // Add Bag Logic
    if (num_bags_on_plane < num_bags_on_belt) {
        num_bags_on_plane++;
    }
    else {
        num_bags_on_belt++;
    }

    // Remove Bag Logic
    if (num_bags_on_plane == num_bags_on_belt) {
        num_bags_removed++;
    }
}

// Function to process the bag
void process_bag() {
    if (num_bags_on_plane < num_bags_on_belt) {
        printf("Bag added to the plane.\n");
    }
    else {
        printf("Bag added to the belt.\n");
    }

    if (num_bags_on_plane == num_bags_on_belt) {
        printf("Bag removed from the belt.\n");
    }
}