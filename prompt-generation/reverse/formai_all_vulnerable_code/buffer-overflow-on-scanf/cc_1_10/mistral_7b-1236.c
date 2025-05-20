//MISTRAL-7B DATASET v1.0 Category: Medical Store Management System ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MEDICINES 50
#define MAX_NAME_LENGTH 20
#define MAX_QUANTITY 100

typedef struct Medicine {
    char name[MAX_NAME_LENGTH];
    int quantity;
} Medicine;

Medicine inventory[MAX_MEDICINES];
int num_medicines = 0;

void add_medicine() {
    if (num_medicines == MAX_MEDICINES) {
        printf("Maximum number of medicines reached.\n");
        return;
    }

    printf("Enter medicine name: ");
    scanf("%s", inventory[num_medicines].name);
    printf("Enter medicine quantity: ");
    scanf("%d", &inventory[num_medicines].quantity);

    num_medicines++;
}

void update_stock(char name[]) {
    int index = -1;

    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Medicine not found.\n");
        return;
    }

    printf("Enter new medicine quantity: ");
    scanf("%d", &inventory[index].quantity);
}

void display_inventory() {
    printf("\nCurrent inventory:\n");

    for (int i = 0; i < num_medicines; i++) {
        printf("%s: %d\n", inventory[i].name, inventory[i].quantity);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Add medicine\n2. Update stock\n3. Display inventory\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2: {
                char name[MAX_NAME_LENGTH];
                printf("Enter medicine name: ");
                scanf("%s", name);
                update_stock(name);
                break;
            }
            case 3:
                display_inventory();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}