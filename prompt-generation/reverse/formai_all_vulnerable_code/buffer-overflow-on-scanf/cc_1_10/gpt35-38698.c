//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

struct Medicine {
    int id;
    char name[100];
    int quantity;
    float cost;
};

struct Medicine medicines[MAX_ITEMS];
int num_medicines = 0;

void add_medicine() {
    struct Medicine m;
    m.id = num_medicines + 1;
    printf("Enter medicine name: ");
    scanf("%s", m.name);
    printf("Enter quantity available: ");
    scanf("%d", &m.quantity);
    printf("Enter cost per unit: ");
    scanf("%f", &m.cost);
    medicines[num_medicines] = m;
    num_medicines++;
    printf("Medicine added successfully!\n\n");
}

void search_medicine() {
    char name[100];
    printf("Enter name of medicine to search: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            printf("Medicine found!\n");
            printf("ID: %d\n", medicines[i].id);
            printf("Name: %s\n", medicines[i].name);
            printf("Quantity Available: %d\n", medicines[i].quantity);
            printf("Cost per unit: %.2f\n\n", medicines[i].cost);
            found = 1;
        }
    }
    if (!found) {
        printf("Medicine not found!\n\n");
    }
}

void update_medicine() {
    int id;
    printf("Enter ID number of medicine to update: ");
    scanf("%d", &id);
    int found = 0;
    for (int i = 0; i < num_medicines; i++) {
        if (medicines[i].id == id) {
            printf("Enter updated quantity available: ");
            scanf("%d", &medicines[i].quantity);
            printf("Enter updated cost per unit: ");
            scanf("%f", &medicines[i].cost);
            printf("Medicine updated successfully!\n\n");
            found = 1;
        }
    }
    if (!found) {
        printf("Medicine not found!\n\n");
    }
}

void delete_medicine() {
    int id;
    printf("Enter ID number of medicine to delete: ");
    scanf("%d", &id);
    int found = 0;
    for (int i = 0; i < num_medicines; i++) {
        if (medicines[i].id == id) {
            for (int j = i; j < num_medicines - 1; j++) {
                medicines[j] = medicines[j+1];
            }
            num_medicines--;
            printf("Medicine deleted successfully!\n\n");
            found = 1;
        }
    }
    if (!found) {
        printf("Medicine not found!\n\n");
    }
}

void display_all_medicines() {
    printf("ID\tName\tQuantity Available\tCost per unit\n");
    for (int i = 0; i < num_medicines; i++) {
        printf("%d\t%s\t%d\t%.2f\n", medicines[i].id, medicines[i].name,
            medicines[i].quantity, medicines[i].cost);
    }
    printf("\n");
}

int main() {
    int option;
    do {
        printf("===== Medical Store Management System =====\n");
        printf("1. Add medicine\n");
        printf("2. Search medicine\n");
        printf("3. Update medicine\n");
        printf("4. Delete medicine\n");
        printf("5. Display all medicines\n");
        printf("6. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &option);
        printf("\n");
        switch (option) {
            case 1:
                add_medicine();
                break;
            case 2:
                search_medicine();
                break;
            case 3:
                update_medicine();
                break;
            case 4:
                delete_medicine();
                break;
            case 5:
                display_all_medicines();
                break;
            case 6:
                printf("Thanks for using the system!\n");
                break;
            default:
                printf("Invalid choice! Please enter a number from 1 to 6.\n\n");
        }
    } while (option != 6);

    return 0;
}