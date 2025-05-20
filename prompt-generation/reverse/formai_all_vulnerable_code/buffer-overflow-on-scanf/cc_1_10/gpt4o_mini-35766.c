//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MEDICINE_NAME 50
#define MAX_MEDICINE_COUNT 100

typedef struct Medicine {
    int id;
    char name[MAX_MEDICINE_NAME];
    int quantity;
    float price;
    struct Medicine *next;
} Medicine;

Medicine *head = NULL;
int nextId = 1; // To keep track of the next Medicine ID

void addMedicine() {
    Medicine *newMedicine = (Medicine *)malloc(sizeof(Medicine));
    newMedicine->id = nextId++;
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

void displayMedicines() {
    if (head == NULL) {
        printf("No medicines in inventory!\n");
        return;
    }
    Medicine *current = head;
    printf("\nMedicine Inventory:\n");
    printf("ID\tName\t\tQuantity\tPrice\n");
    printf("---------------------------------------------\n");
    while (current != NULL) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", current->id, current->name, current->quantity, current->price);
        current = current->next;
    }
}

void deleteMedicine() {
    if (head == NULL) {
        printf("No medicines to delete!\n");
        return;
    }
    int idToDelete;
    printf("Enter medicine ID to delete: ");
    scanf("%d", &idToDelete);

    Medicine *current = head;
    Medicine *previous = NULL;

    while (current != NULL && current->id != idToDelete) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Medicine ID not found!\n");
        return;
    }

    if (previous == NULL) {
        head = current->next; // Deleting the head node
    } else {
        previous->next = current->next; // Bypass the current node
    }
    free(current);
    printf("Medicine deleted successfully!\n");
}

void menu() {
    int choice;
    do {
        printf("\n=== Medical Store Management System ===\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Delete Medicine\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                displayMedicines();
                break;
            case 3:
                deleteMedicine();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
                break;
        }
    } while (choice != 4);
}

int main() {
    printf("Welcome to the Medical Store Management System!\n");
    menu();
    return 0;
}