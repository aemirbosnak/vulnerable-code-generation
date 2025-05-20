//MISTRAL-7B DATASET v1.0 Category: Medical Store Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_MEDICINES 100

typedef struct {
    char name[50];
    int stock;
} Medicine;

Medicine inventory[MAX_MEDICINES];
int num_medicines = 0;

void add_medicine() {
    if (num_medicines >= MAX_MEDICINES) {
        printf("Inventory is full.\n");
        return;
    }

    printf("Enter medicine name: ");
    scanf("%s", inventory[num_medicines].name);

    printf("Enter initial stock: ");
    scanf("%d", &inventory[num_medicines].stock);

    num_medicines++;
}

void remove_medicine() {
    char name[50];
    int i;

    printf("Enter medicine name to remove: ");
    scanf("%s", name);

    for (i = 0; i < num_medicines; i++) {
        if (strcmp(name, inventory[i].name) == 0) {
            for (int j = i; j < num_medicines - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            num_medicines--;
            printf("Medicine removed successfully.\n");
            return;
        }
    }

    printf("Medicine not found.\n");
}

void search_medicine() {
    char name[50];
    int i;

    printf("Enter medicine name to search: ");
    scanf("%s", name);

    for (i = 0; i < num_medicines; i++) {
        if (strcmp(name, inventory[i].name) == 0) {
            printf("Name: %s\n", inventory[i].name);
            printf("Stock: %d\n", inventory[i].stock);
            return;
        }
    }

    printf("Medicine not found.\n");
}

void display_inventory() {
    int i;

    printf("\nCurrent inventory:\n");

    for (i = 0; i < num_medicines; i++) {
        printf("%s - %d\n", inventory[i].name, inventory[i].stock);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nMedical Store Management System\n");
        printf("1. Add medicine\n");
        printf("2. Remove medicine\n");
        printf("3. Search medicine\n");
        printf("4. Display inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                remove_medicine();
                break;
            case 3:
                search_medicine();
                break;
            case 4:
                display_inventory();
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}