//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int quantity;
    float price;
} medicine_t;

medicine_t medicines[MAX_MEDICINES];
int num_medicines = 0;

void add_medicine() {
    if (num_medicines >= MAX_MEDICINES) {
        printf("Medicine database is full.\n");
        return;
    }

    medicine_t *medicine = &medicines[num_medicines++];

    printf("Enter the name of the medicine: ");
    scanf("%s", medicine->name);

    printf("Enter the description of the medicine: ");
    scanf("%[^\n]", medicine->description);

    printf("Enter the quantity of the medicine: ");
    scanf("%d", &medicine->quantity);

    printf("Enter the price of the medicine: ");
    scanf("%f", &medicine->price);
}

void delete_medicine() {
    char name[MAX_NAME_LENGTH];

    printf("Enter the name of the medicine to delete: ");
    scanf("%s", name);

    for (int i = 0; i < num_medicines; i++) {
        medicine_t *medicine = &medicines[i];

        if (strcmp(medicine->name, name) == 0) {
            for (int j = i + 1; j < num_medicines; j++) {
                medicines[j - 1] = medicines[j];
            }

            num_medicines--;

            printf("Medicine deleted successfully.\n");
            return;
        }
    }

    printf("Medicine not found.\n");
}

void update_medicine() {
    char name[MAX_NAME_LENGTH];

    printf("Enter the name of the medicine to update: ");
    scanf("%s", name);

    for (int i = 0; i < num_medicines; i++) {
        medicine_t *medicine = &medicines[i];

        if (strcmp(medicine->name, name) == 0) {
            printf("Enter the new name of the medicine: ");
            scanf("%s", medicine->name);

            printf("Enter the new description of the medicine: ");
            scanf("%[^\n]", medicine->description);

            printf("Enter the new quantity of the medicine: ");
            scanf("%d", &medicine->quantity);

            printf("Enter the new price of the medicine: ");
            scanf("%f", &medicine->price);

            printf("Medicine updated successfully.\n");
            return;
        }
    }

    printf("Medicine not found.\n");
}

void list_medicines() {
    for (int i = 0; i < num_medicines; i++) {
        medicine_t *medicine = &medicines[i];

        printf("Name: %s\n", medicine->name);
        printf("Description: %s\n", medicine->description);
        printf("Quantity: %d\n", medicine->quantity);
        printf("Price: %.2f\n\n", medicine->price);
    }
}

int main() {
    int choice;

    while (1) {
        printf("1. Add medicine\n");
        printf("2. Delete medicine\n");
        printf("3. Update medicine\n");
        printf("4. List medicines\n");
        printf("5. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                delete_medicine();
                break;
            case 3:
                update_medicine();
                break;
            case 4:
                list_medicines();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}