//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>

// define constants
#define MAX_BAGS 1000
#define MAX_DURATION 10

// define global variables
int num_bags = 0;
int bags[MAX_BAGS];

// define functions
void add_bag(int weight) {
    if (num_bags < MAX_BAGS) {
        bags[num_bags++] = weight;
        printf("Baggage added to system. Total bags: %d\n", num_bags);
    } else {
        printf("Baggage system is full. Cannot add bag.\n");
    }
}

void remove_bag(int index) {
    if (index < num_bags && index >= 0) {
        for (int i = index; i < num_bags - 1; i++) {
            bags[i] = bags[i+1];
        }
        num_bags--;
        printf("Baggage removed from system. Total bags: %d\n", num_bags);
    } else {
        printf("Invalid index. No baggage removed.\n");
    }
}

void print_status() {
    printf("\nBaggage System Status:\n");
    printf("Total Bags: %d\n", num_bags);
    printf("Weights: [");
    for (int i = 0; i < num_bags; i++) {
        printf("%d", bags[i]);
        if (i < num_bags - 1) {
            printf(", ");
        }
    }
    printf("]\n\n");
}

int main() {
    printf("Welcome to the Airport Baggage Handling Simulation.\n\n");
    
    while (1) {
        printf("Menu:\n");
        printf("1. Add baggage to system\n");
        printf("2. Remove baggage from system\n");
        printf("3. Print system status\n");
        printf("4. Exit program\n");
        printf("Select an option: ");
        
        // get user input and validate
        int option;
        while (1) {
            scanf("%d", &option);
            if (option >= 1 && option <= 4) {
                break;
            } else {
                printf("Invalid option. Please select again: ");
            }
        }
        
        // handle user input
        switch (option) {
            case 1:
                printf("Enter baggage weight: ");
                int weight;
                scanf("%d", &weight);
                add_bag(weight);
                break;
            case 2:
                printf("Enter the index of the baggage to be removed: ");
                int index;
                scanf("%d", &index);
                remove_bag(index);
                break;
            case 3:
                print_status();
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                exit(0);
        }
    }
    
    return 0;
}