//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    char name[50];
    int quantity;
    float price;
    char expiry[11];
    char manufacturer[50];
};

struct node {
    struct medicine data;
    struct node *next;
};

struct node *head = NULL;

void addMedicine() {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter medicine name: ");
    scanf(" %[^\n]", newNode->data.name);
    printf("Enter quantity: ");
    scanf(" %d", &newNode->data.quantity);
    printf("Enter price: ");
    scanf(" %f", &newNode->data.price);
    printf("Enter expiry date (YYYY-MM-DD): ");
    scanf(" %[^\n]", newNode->data.expiry);
    printf("Enter manufacturer: ");
    scanf(" %[^\n]", newNode->data.manufacturer);
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Medicine added successfully!\n");
}

void displayMedicine() {
    if (head == NULL) {
        printf("No medicine found!\n");
    } else {
        struct node *temp = head;
        while (temp != NULL) {
            printf("Medicine Name: %s\n", temp->data.name);
            printf("Quantity: %d\n", temp->data.quantity);
            printf("Price: %.2f\n", temp->data.price);
            printf("Expiry Date: %s\n", temp->data.expiry);
            printf("Manufacturer: %s\n", temp->data.manufacturer);
            printf("-------------------------------\n");
            temp = temp->next;
        }
    }
}

void searchMedicine() {
    char name[50];
    printf("Enter medicine name: ");
    scanf(" %[^\n]", name);
    int found = 0;
    struct node *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->data.name, name) == 0) {
            printf("Medicine Name: %s\n", temp->data.name);
            printf("Quantity: %d\n", temp->data.quantity);
            printf("Price: %.2f\n", temp->data.price);
            printf("Expiry Date: %s\n", temp->data.expiry);
            printf("Manufacturer: %s\n", temp->data.manufacturer);
            found = 1;
        }
        temp = temp->next;
    }
    if (!found) {
        printf("Medicine not found!\n");
    }
}

void updateMedicine() {
    char name[50];
    printf("Enter medicine name: ");
    scanf(" %[^\n]", name);
    int found = 0;
    struct node *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->data.name, name) == 0) {
            printf("Enter new quantity: ");
            scanf(" %d", &temp->data.quantity);
            printf("Enter new price: ");
            scanf(" %f", &temp->data.price);
            printf("Enter new expiry date (YYYY-MM-DD): ");
            scanf(" %[^\n]", temp->data.expiry);
            printf("Enter new manufacturer: ");
            scanf(" %[^\n]", temp->data.manufacturer);
            found = 1;
        }
        temp = temp->next;
    }
    if (!found) {
        printf("Medicine not found!\n");
    }
}

void deleteMedicine() {
    char name[50];
    printf("Enter medicine name: ");
    scanf(" %[^\n]", name);
    struct node *temp = head;
    struct node *prev = NULL;
    while (temp != NULL) {
        if (strcmp(temp->data.name, name) == 0) {
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf("Medicine deleted successfully!\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Medicine not found!\n");
}

int main() {
    int choice;
    do {
        printf("\n\n----- Medical Store Management System -----\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Update Medicine\n");
        printf("5. Delete Medicine\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf(" %d", &choice);
        switch (choice) {
            case 1:
                addMedicine();
                break;
            case 2:
                displayMedicine();
                break;
            case 3:
                searchMedicine();
                break;
            case 4:
                updateMedicine();
                break;
            case 5:
                deleteMedicine();
                break;
            case 6:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);
    return 0;
}