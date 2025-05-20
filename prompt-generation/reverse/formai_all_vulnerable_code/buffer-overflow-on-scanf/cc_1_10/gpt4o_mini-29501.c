//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Medicine {
    int id;
    char name[100];
    char manufacturer[100];
    float price;
    int quantity;
    struct Medicine *next;
} Medicine;

Medicine *head = NULL;

void addMedicine() {
    Medicine *new_medicine = (Medicine *)malloc(sizeof(Medicine));
    printf("Enter Medicine ID: ");
    scanf("%d", &new_medicine->id);
    printf("Enter Medicine Name: ");
    scanf("%s", new_medicine->name);
    printf("Enter Manufacturer: ");
    scanf("%s", new_medicine->manufacturer);
    printf("Enter Price: ");
    scanf("%f", &new_medicine->price);
    printf("Enter Quantity: ");
    scanf("%d", &new_medicine->quantity);
    new_medicine->next = head;
    head = new_medicine;
    printf("Medicine added successfully.\n");
}

void deleteMedicine() {
    int id;
    printf("Enter Medicine ID to delete: ");
    scanf("%d", &id);
    Medicine *current = head;
    Medicine *previous = NULL;

    while (current != NULL && current->id != id) {
        previous = current;
        current = current->next;
    }
    
    if (current == NULL) {
        printf("Medicine with ID %d not found.\n", id);
        return;
    }
    
    if (previous == NULL) {
        head = current->next;
    } else {
        previous->next = current->next;
    }
    
    free(current);
    printf("Medicine deleted successfully.\n");
}

void displayMedicines() {
    if (head == NULL) {
        printf("No medicines available.\n");
        return;
    }

    Medicine *current = head;
    printf("\nID\tName\tManufacturer\tPrice\tQuantity\n");
    printf("-------------------------------------------------\n");
    while (current != NULL) {
        printf("%d\t%s\t%s\t%.2f\t%d\n", current->id, current->name, current->manufacturer, current->price, current->quantity);
        current = current->next;
    }
}

void searchMedicine() {
    int id;
    printf("Enter Medicine ID to search: ");
    scanf("%d", &id);
    Medicine *current = head;

    while (current != NULL) {
        if (current->id == id) {
            printf("\nMedicine Found:\n");
            printf("ID: %d, Name: %s, Manufacturer: %s, Price: %.2f, Quantity: %d\n", current->id, current->name, current->manufacturer, current->price, current->quantity);
            return;
        }
        current = current->next;
    }
    printf("Medicine with ID %d not found.\n", id);
}

void freeMemory() {
    Medicine *current = head;
    Medicine *next = NULL;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    int choice;
    do {
        printf("\n--- Medical Store Management System ---\n");
        printf("1. Add Medicine\n");
        printf("2. Delete Medicine\n");
        printf("3. Display All Medicines\n");
        printf("4. Search Medicine\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                deleteMedicine();
                break;
            case 3:
                displayMedicines();
                break;
            case 4:
                searchMedicine();
                break;
            case 5:
                printf("Exiting the program...\n");
                freeMemory();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}