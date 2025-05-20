//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINES 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Medicine;

Medicine medicines[MAX_MEDICINES];
int medicine_count = 0;

void add_medicine();
void display_medicines();
void delete_medicine();
void search_medicine();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;

    do {
        printf("\n=== Medical Store Management System ===\n");
        printf("1. Add Medicine\n");
        printf("2. Display All Medicines\n");
        printf("3. Delete Medicine\n");
        printf("4. Search for a Medicine\n");
        printf("5. Exit\n");
        printf("=======================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                display_medicines();
                break;
            case 3:
                delete_medicine();
                break;
            case 4:
                search_medicine();
                break;
            case 5:
                printf("Exiting the system...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
}

void add_medicine() {
    if (medicine_count < MAX_MEDICINES) {
        Medicine new_medicine;
        new_medicine.id = medicine_count + 1;

        printf("Enter medicine name: ");
        scanf("%s", new_medicine.name);

        printf("Enter quantity: ");
        scanf("%d", &new_medicine.quantity);

        printf("Enter price: ");
        scanf("%f", &new_medicine.price);

        medicines[medicine_count] = new_medicine;
        medicine_count++;

        printf("Medicine added successfully!\n");
    } else {
        printf("Medicine inventory is full! Cannot add more medicines.\n");
    }
}

void display_medicines() {
    if (medicine_count == 0) {
        printf("No medicines available in the inventory.\n");
        return;
    }

    printf("\nMedicines in Inventory:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("=============================================\n");
    for (int i = 0; i < medicine_count; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", medicines[i].id, medicines[i].name, medicines[i].quantity, medicines[i].price);
    }
}

void delete_medicine() {
    int id;

    printf("Enter medicine ID to delete: ");
    scanf("%d", &id);

    if (id < 1 || id > medicine_count) {
        printf("Invalid ID! No medicine found with the given ID.\n");
        return;
    }

    for (int i = id - 1; i < medicine_count - 1; i++) {
        medicines[i] = medicines[i + 1];
    }
    medicine_count--;
    printf("Medicine with ID %d deleted successfully!\n", id);
}

void search_medicine() {
    char name[NAME_LENGTH];
    printf("Enter medicine name to search: ");
    scanf("%s", name);

    int found = 0;
    printf("\nSearching for medicines named '%s':\n", name);
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("=============================================\n");
    
    for (int i = 0; i < medicine_count; i++) {
        if (strcmp(medicines[i].name, name) == 0) {
            printf("%d\t%s\t\t%d\t\t%.2f\n", medicines[i].id, medicines[i].name, medicines[i].quantity, medicines[i].price);
            found = 1;
        }
    }

    if (!found) {
        printf("No medicines found with the name '%s'.\n", name);
    }
}