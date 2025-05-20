//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Medicine {
    char name[20];
    int quantity;
    float price;
    struct Medicine *next;
} Medicine;

void displayMenu() {
    printf("\n=== Medical Store Management System ===\n");
    printf("1. Add Medicine\n");
    printf("2. Update Medicine\n");
    printf("3. Sell Medicine\n");
    printf("4. Generate Report\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

Medicine* addMedicine(Medicine *head) {
    Medicine *newMedicine = (Medicine*) malloc(sizeof(Medicine));
    printf("\nEnter medicine name: ");
    scanf("%s", newMedicine->name);
    printf("Enter quantity: ");
    scanf("%d", &newMedicine->quantity);
    printf("Enter price: ");
    scanf("%f", &newMedicine->price);
    newMedicine->next = NULL;
    if (head == NULL) {
        head = newMedicine;
    } else {
        Medicine *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newMedicine;
    }
    printf("\nMedicine added successfully!\n");
    return head;
}

void displayMedicines(Medicine *head) {
    if (head == NULL) {
        printf("\nNo medicines in the store!\n");
    } else {
        printf("\nMedicine List:\n");
        printf("%-20s %-20s %-20s\n", "Name", "Quantity", "Price");
        Medicine *temp = head;
        while (temp != NULL) {
            printf("%-20s %-20d %-20.2f\n", temp->name, temp->quantity, temp->price);
            temp = temp->next;
        }
    }
}

Medicine* updateMedicine(Medicine *head) {
    if (head == NULL) {
        printf("\nNo medicines in the store!\n");
    } else {
        printf("\nEnter medicine name to update: ");
        char name[20];
        scanf("%s", name);
        Medicine *temp = head;
        while (temp != NULL) {
            if (strcmp(temp->name, name) == 0) {
                printf("Enter new quantity: ");
                scanf("%d", &temp->quantity);
                printf("Enter new price: ");
                scanf("%f", &temp->price);
                printf("\nMedicine updated successfully!\n");
                break;
            }
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("\nMedicine not found!\n");
        }
    }
    return head;
}

Medicine* sellMedicine(Medicine *head) {
    if (head == NULL) {
        printf("\nNo medicines in the store!\n");
    } else {
        printf("\nEnter medicine name to sell: ");
        char name[20];
        scanf("%s", name);
        Medicine *temp = head;
        while (temp != NULL) {
            if (strcmp(temp->name, name) == 0) {
                int quantityToSell;
                printf("Enter quantity to sell: ");
                scanf("%d", &quantityToSell);
                if (temp->quantity < quantityToSell) {
                    printf("\nInsufficient quantity!\n");
                } else {
                    temp->quantity -= quantityToSell;
                    float totalPrice = temp->price * quantityToSell;
                    printf("\nTotal Price: %.2f\n", totalPrice);
                    printf("Medicine sold successfully!\n");
                }
                break;
            }
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("\nMedicine not found!\n");
        }
    }
    return head;
}

void generateReport(Medicine *head) {
    if (head == NULL) {
        printf("\nNo medicines in the store!\n");
    } else {
        printf("\nReport:\n");
        printf("%-20s %-20s %-20s %-20s\n", "Name", "Quantity", "Price", "Value");
        float totalValue = 0;
        Medicine *temp = head;
        while (temp != NULL) {
            float value = temp->quantity * temp->price;
            totalValue += value;
            printf("%-20s %-20d %-20.2f %-20.2f\n", temp->name, temp->quantity, temp->price, value);
            temp = temp->next;
        }
        printf("\nTotal Value: %.2f\n", totalValue);
    }
}

int main() {
    Medicine *head = NULL;
    int choice = 0;
    printf("=== Welcome to Medical Store Management System ===\n");
    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                head = addMedicine(head);
                break;
            case 2:
                head = updateMedicine(head);
                break;
            case 3:
                head = sellMedicine(head);
                break;
            case 4:
                generateReport(head);
                break;
            case 5:
                printf("\nThank you for using Medical Store Management System.\n");
                break;
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    } while (choice != 5);
    return 0;
}