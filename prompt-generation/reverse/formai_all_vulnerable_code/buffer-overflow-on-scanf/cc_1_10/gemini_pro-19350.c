//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct medicine {
    char name[50];
    char manufacturer[50];
    float price;
    int quantity;
} medicine;

typedef struct node {
    medicine data;
    struct node *next;
} node;

node *head = NULL;

void addMedicine() {
    medicine m;
    printf("Enter medicine name: ");
    scanf("%s", m.name);
    printf("Enter manufacturer name: ");
    scanf("%s", m.manufacturer);
    printf("Enter price: ");
    scanf("%f", &m.price);
    printf("Enter quantity: ");
    scanf("%d", &m.quantity);
    node *temp = (node *)malloc(sizeof(node));
    temp->data = m;
    temp->next = NULL;
    if (head == NULL) {
        head = temp;
    } else {
        node *ptr = head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
    printf("Medicine added successfully!\n");
}

void displayMedicine() {
    if (head == NULL) {
        printf("No medicines to display!\n");
    } else {
        node *ptr = head;
        while (ptr != NULL) {
            printf("Medicine name: %s\n", ptr->data.name);
            printf("Manufacturer name: %s\n", ptr->data.manufacturer);
            printf("Price: %f\n", ptr->data.price);
            printf("Quantity: %d\n", ptr->data.quantity);
            printf("\n");
            ptr = ptr->next;
        }
    }
}

void searchMedicine() {
    char name[50];
    printf("Enter medicine name to search: ");
    scanf("%s", name);
    node *ptr = head;
    while (ptr != NULL) {
        if (strcmp(ptr->data.name, name) == 0) {
            printf("Medicine found!\n");
            printf("Medicine name: %s\n", ptr->data.name);
            printf("Manufacturer name: %s\n", ptr->data.manufacturer);
            printf("Price: %f\n", ptr->data.price);
            printf("Quantity: %d\n", ptr->data.quantity);
            return;
        }
        ptr = ptr->next;
    }
    printf("Medicine not found!\n");
}

void updateMedicine() {
    char name[50];
    printf("Enter medicine name to update: ");
    scanf("%s", name);
    node *ptr = head;
    while (ptr != NULL) {
        if (strcmp(ptr->data.name, name) == 0) {
            printf("Enter new price: ");
            scanf("%f", &ptr->data.price);
            printf("Enter new quantity: ");
            scanf("%d", &ptr->data.quantity);
            printf("Medicine updated successfully!\n");
            return;
        }
        ptr = ptr->next;
    }
    printf("Medicine not found!\n");
}

void deleteMedicine() {
    char name[50];
    printf("Enter medicine name to delete: ");
    scanf("%s", name);
    node *ptr = head;
    node *prev = NULL;
    while (ptr != NULL) {
        if (strcmp(ptr->data.name, name) == 0) {
            if (prev == NULL) {
                head = ptr->next;
            } else {
                prev->next = ptr->next;
            }
            free(ptr);
            printf("Medicine deleted successfully!\n");
            return;
        }
        prev = ptr;
        ptr = ptr->next;
    }
    printf("Medicine not found!\n");
}

int main() {
    int choice;
    do {
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Update Medicine\n");
        printf("5. Delete Medicine\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
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
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 6);
    return 0;
}