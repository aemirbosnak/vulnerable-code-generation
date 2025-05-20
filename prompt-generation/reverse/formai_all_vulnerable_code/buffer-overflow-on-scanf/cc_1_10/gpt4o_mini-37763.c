//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Medicine {
    char name[50];
    int quantity;
    float price;
    struct Medicine* next;
} Medicine;

Medicine* head = NULL;

void addMedicine() {
    Medicine* newMedicine = (Medicine*)malloc(sizeof(Medicine));
    
    printf("Enter medicine name: ");
    scanf("%s", newMedicine->name);
    printf("Enter quantity: ");
    scanf("%d", &newMedicine->quantity);
    printf("Enter price: ");
    scanf("%f", &newMedicine->price);

    newMedicine->next = head;
    head = newMedicine;

    printf("Medicine added successfully!\n");
}

void deleteMedicine() {
    char name[50];
    printf("Enter medicine name to delete: ");
    scanf("%s", name);

    Medicine* current = head;
    Medicine* prev = NULL;

    while (current != NULL && strcmp(current->name, name) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Medicine not found!\n");
        return;
    }

    if (prev == NULL) {
        head = current->next; 
    } else {
        prev->next = current->next;
    }
    
    free(current);
    printf("Medicine deleted successfully!\n");
}

void displayMedicines() {
    Medicine* current = head;

    if (current == NULL) {
        printf("No medicines in the store!\n");
        return;
    }

    printf("\nMedicines in Store:\n");
    printf("Name\tQuantity\tPrice\n");
    printf("---------------------------------\n");
    while (current != NULL) {
        printf("%s\t%d\t\t%.2f\n", current->name, current->quantity, current->price);
        current = current->next;
    }
}

void searchMedicine() {
    char name[50];
    printf("Enter medicine name to search: ");
    scanf("%s", name);

    Medicine* current = head;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("Medicine found!\n");
            printf("Name: %s\n", current->name);
            printf("Quantity: %d\n", current->quantity);
            printf("Price: %.2f\n", current->price);
            return;
        }
        current = current->next;
    }

    printf("Medicine not found!\n");
}

void menu() {
    int choice;

    do {
        printf("\n--- Medical Store Management System ---\n");
        printf("1. Add Medicine\n");
        printf("2. Delete Medicine\n");
        printf("3. Display Medicines\n");
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
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    menu();
    return 0;
}