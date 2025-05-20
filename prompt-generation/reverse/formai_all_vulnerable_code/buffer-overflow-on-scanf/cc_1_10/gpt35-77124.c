//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 100     // maximum number of items that the warehouse can hold
#define MAX_LENGTH 20     // maximum length of an item name

// Function prototypes
void add_item(char item_list[MAX_ITEMS][MAX_LENGTH], int item_count, char new_item[]);
void remove_item(char item_list[MAX_ITEMS][MAX_LENGTH], int item_count, char item_to_remove[]);
void display_inventory(char item_list[MAX_ITEMS][MAX_LENGTH], int item_count);

int main() {

    char item_list[MAX_ITEMS][MAX_LENGTH] = {"Keyboard", "Mouse", "Monitor", "CPU", "RAM"};   // initial inventory
    int item_count = 5;   // number of items in inventory

    printf("Warehouse Management System\n");
    printf("===========================\n\n");

    // Menu loop
    while (1) {
        int choice;
        char new_item[MAX_LENGTH];
        char item_to_remove[MAX_LENGTH];

        printf("\nMenu:\n");
        printf("1. Add item\n");
        printf("2. Remove item\n");
        printf("3. Display inventory\n");
        printf("4. Exit\n");
        printf("Enter choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", new_item);
                add_item(item_list, item_count, new_item);
                item_count++;
                break;

            case 2:
                printf("Enter item name: ");
                scanf("%s", item_to_remove);
                remove_item(item_list, item_count, item_to_remove);
                item_count--;
                break;

            case 3:
                display_inventory(item_list, item_count);
                break;

            case 4:
                printf("\nExiting program.\n");
                exit(0);

            default:
                printf("\nInvalid choice. Please enter a number from 1-4.\n");
                break;
        }
    }

    return 0;
}

// Function to add a new item to the inventory
void add_item(char item_list[MAX_ITEMS][MAX_LENGTH], int item_count, char new_item[]) {
    int i;

    for (i=0; i<item_count; i++) {
        if (strcmp(item_list[i], new_item) == 0) {
            printf("\nItem already exists in inventory.\n");
            return;
        }
    }

    strcpy(item_list[item_count], new_item);
    printf("\nItem successfully added to inventory.\n");
}

// Function to remove an item from the inventory
void remove_item(char item_list[MAX_ITEMS][MAX_LENGTH], int item_count, char item_to_remove[]) {
    int i, j;
    int found = 0;

    for (i=0; i<item_count; i++) {
        if (strcmp(item_list[i], item_to_remove) == 0) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nItem not found in inventory.\n");
        return;
    }

    for (j=i; j<item_count-1; j++) {
        strcpy(item_list[j], item_list[j+1]);
    }

    printf("\nItem successfully removed from inventory.\n");
}

// Function to display the current inventory
void display_inventory(char item_list[MAX_ITEMS][MAX_LENGTH], int item_count) {
    int i;

    printf("\nCurrent inventory:\n");

    for (i=0; i<item_count; i++) {
        printf("%s\n", item_list[i]);
    }
}