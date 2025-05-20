//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Medicine {
    char name[50];
    int quantity;
    float price;
    struct Medicine *next;
} Medicine;

void insertMedicine(Medicine **headRef, char *name, int quantity, float price) {
    Medicine *newMedicine = (Medicine*)malloc(sizeof(Medicine));
    strcpy(newMedicine->name, name);
    newMedicine->quantity = quantity;
    newMedicine->price = price;
    newMedicine->next = NULL;
    if (*headRef == NULL) {
        *headRef = newMedicine;
        return;
    }
    if (strcmp(name, (*headRef)->name) < 0) {
        newMedicine->next = *headRef;
        *headRef = newMedicine;
        return;
    }
    Medicine *current = *headRef;
    while (current->next != NULL && strcmp(name, current->next->name) > 0) {
        current = current->next;
    }
    newMedicine->next = current->next;
    current->next = newMedicine;
    printf("Medicine %s added successfully.\n", newMedicine->name);
}

void deleteMedicine(Medicine **headRef, char *name) {
    if (*headRef == NULL) {
        printf("No medicine found.\n");
        return;
    }
    if (strcmp(name, (*headRef)->name) == 0) {
        printf("Medicine %s deleted successfully.\n", (*headRef)->name);
        Medicine *temp = *headRef;
        *headRef = (*headRef)->next;
        free(temp);
        return;
    }
    Medicine *current = *headRef;
    while (current->next != NULL && strcmp(name, current->next->name) != 0) {
        current = current->next;
    }
    if (current->next == NULL) {
        printf("No medicine found.\n");
        return;
    }
    printf("Medicine %s deleted successfully.\n", current->next->name);
    Medicine *temp = current->next;
    current->next = current->next->next;
    free(temp);
}

void displayMedicines(Medicine **headRef) {
    if (*headRef == NULL) {
        printf("No medicines found.\n");
        return;
    }
    printf("Medicines available:\n");
    Medicine *current = *headRef;
    while (current != NULL) {
        printf("%s - %d - %.2f\n", current->name, current->quantity, current->price);
        current = current->next;
    }
}

void searchMedicine(Medicine **headRef, char *name) {
    if (*headRef == NULL) {
        printf("No medicine found.\n");
        return;
    }
    Medicine *current = *headRef;
    while (current != NULL && strcmp(name, current->name) != 0) {
        current = current->next;
    }
    if (current == NULL) {
        printf("No medicine found.\n");
        return;
    }
    printf("%s - %d - %.2f\n", current->name, current->quantity, current->price);
}

void sellMedicine(Medicine **headRef, char *name, int quantity) {
    if (*headRef == NULL) {
        printf("No medicine found.\n");
        return;
    }
    Medicine *current = *headRef;
    while (current != NULL && strcmp(name, current->name) != 0) {
        current = current->next;
    }
    if (current == NULL) {
        printf("No medicine found.\n");
        return;
    }
    if (current->quantity < quantity) {
        printf("Not enough quantity.\n");
        return;
    }
    current->quantity -= quantity;
    printf("%d %s(s) sold successfully.\n", quantity, current->name);
}

void menu() {
    printf("1. Add medicine\n");
    printf("2. Delete medicine\n");
    printf("3. Display medicines\n");
    printf("4. Search medicine\n");
    printf("5. Sell medicine\n");
    printf("6. Exit\n");
}

void handleChoice(Medicine **headRef, int choice) {
    char name[50];
    int quantity;
    float price;
    switch (choice) {
        case 1:
            printf("Enter medicine name: ");
            scanf("%s", name);
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            printf("Enter price: ");
            scanf("%f", &price);
            insertMedicine(headRef, name, quantity, price);
            break;
        case 2:
            printf("Enter medicine name: ");
            scanf("%s", name);
            deleteMedicine(headRef, name);
            break;
        case 3:
            displayMedicines(headRef);
            break;
        case 4:
            printf("Enter medicine name: ");
            scanf("%s", name);
            searchMedicine(headRef, name);
            break;
        case 5:
            printf("Enter medicine name: ");
            scanf("%s", name);
            printf("Enter quantity: ");
            scanf("%d", &quantity);
            sellMedicine(headRef, name, quantity);
            break;
        case 6:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
            break;
    }
}

int main() {
    int choice;
    Medicine *head = NULL;
    menu();
    printf("Enter your choice: ");
    scanf("%d", &choice);
    handleChoice(&head, choice);
    if (choice != 6) {
        main();
    }
    return 0;
}