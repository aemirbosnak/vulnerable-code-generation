//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESOURCES 100
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    float value; // value per item
} Resource;

Resource resources[MAX_RESOURCES];
int resource_count = 0;

void add_resource(char *name, int quantity, float value) {
    if (resource_count < MAX_RESOURCES) {
        strcpy(resources[resource_count].name, name);
        resources[resource_count].quantity = quantity;
        resources[resource_count].value = value;
        resource_count++;
        printf("Added %d of %s valued at %.2f each.\n", quantity, name, value);
    } else {
        printf("Resource limit reached! Unable to add more resources.\n");
    }
}

void display_resources() {
    printf("\nCurrent Resources:\n");
    printf("| %-15s | %-10s | %-10s |\n", "Name", "Quantity", "Value");
    printf("|-----------------|------------|------------|\n");
    
    for (int i = 0; i < resource_count; i++) {
        printf("| %-15s | %-10d | %-10.2f |\n", resources[i].name, resources[i].quantity, resources[i].value);
    }
    printf("|-----------------|------------|------------|\n");
}

float calculate_total_worth() {
    float total_worth = 0.0;
    for (int i = 0; i < resource_count; i++) {
        total_worth += resources[i].quantity * resources[i].value;
    }
    return total_worth;
}

void show_total_worth() {
    float total_worth = calculate_total_worth();
    printf("\nTotal Worth of Resources: %.2f scraps\n", total_worth);
}

void shelter_status() {
    printf("\nSurvivor's Status:\n");
    printf("It's a tough day out here. Keep your wits sharp!\n");
    display_resources();
    show_total_worth();
}

void clear_all_resources() {
    resource_count = 0;
    printf("All resources have been cleared. Prepare for a fresh start.\n");
}

int main() {
    int choice;
    char name[NAME_LENGTH];
    int quantity;
    float value;

    printf("=== Wasteland Survivor Finance Planner ===\n");
    
    do {
        printf("\nSelect an option:\n");
        printf("1. Add Resource\n");
        printf("2. Display Resources\n");
        printf("3. Show Total Worth\n");
        printf("4. Show Shelter Status\n");
        printf("5. Clear All Resources\n");
        printf("6. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Resource Name: ");
                scanf("%s", name);
                printf("Enter Quantity: ");
                scanf("%d", &quantity);
                printf("Enter Value per Item: ");
                scanf("%f", &value);
                add_resource(name, quantity, value);
                break;
            case 2:
                display_resources();
                break;
            case 3:
                show_total_worth();
                break;
            case 4:
                shelter_status();
                break;
            case 5:
                clear_all_resources();
                break;
            case 6:
                printf("Preparing to exit the planner. Stay safe out there!\n");
                break;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    } while (choice != 6);

    return 0;
}