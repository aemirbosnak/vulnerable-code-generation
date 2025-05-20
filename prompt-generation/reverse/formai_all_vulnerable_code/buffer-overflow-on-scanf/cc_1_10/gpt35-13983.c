//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to represent a medicine
struct Medicine {
    int id;
    char name[50];
    int quantity;
    float price;
};

// Define a structure to represent a node in the linked list
struct Node {
    struct Medicine* medicine;
    struct Node* next;
};

// Define global variables
struct Node* head = NULL;
int last_id = 0;

// Function to create a new medicine
struct Medicine* createMedicine(char* name, int quantity, float price) {
    struct Medicine* medicine = (struct Medicine*) malloc(sizeof(struct Medicine));
    medicine->id = last_id++;
    strncpy(medicine->name, name, 50);
    medicine->quantity = quantity;
    medicine->price = price;
    return medicine;
}

// Function to add a medicine to the linked list
void addMedicine(char* name, int quantity, float price) {
    struct Medicine* medicine = createMedicine(name, quantity, price);
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->medicine = medicine;
    node->next = head;
    head = node;
}

// Function to print all the medicines in the linked list
void printMedicines() {
    struct Node* node = head;
    printf("ID\tName\tQuantity\tPrice\n");
    while (node != NULL) {
        printf("%d\t%s\t%d\t\t%.2f\n", node->medicine->id, node->medicine->name, node->medicine->quantity, node->medicine->price);
        node = node->next;
    }
}

// Function to find a medicine in the linked list by ID
struct Node* findMedicineById(int id) {
    struct Node* node = head;
    while (node != NULL) {
        if (node->medicine->id == id) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}

// Function to buy a medicine
void buyMedicine(int id, int quantity) {
    struct Node* node = findMedicineById(id);
    if (node == NULL) {
        printf("Error: Medicine not found\n");
        return;
    }
    if (node->medicine->quantity < quantity) {
        printf("Error: Quantity not available\n");
        return;
    }
    node->medicine->quantity -= quantity;
    printf("Purchase successful. Total cost: %.2f\n", node->medicine->price * quantity);
}

// Main function
int main() {
    int choice, id, quantity;
    char name[50];
    float price;

    do {
        printf("1. Add medicine\n");
        printf("2. Print all medicines\n");
        printf("3. Buy medicine\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter medicine name: ");
                scanf("%s", name);
                printf("Enter medicine quantity: ");
                scanf("%d", &quantity);
                printf("Enter medicine price: ");
                scanf("%f", &price);
                addMedicine(name, quantity, price);
                printf("Medicine added successfully\n");
                break;

            case 2:
                printMedicines();
                break;

            case 3:
                printf("Enter medicine ID: ");
                scanf("%d", &id);
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                buyMedicine(id, quantity);
                break;

            case 4:
                printf("Exiting program\n");
                break;

            default:
                printf("Error: Invalid choice\n");
        }
    } while (choice != 4);

    return 0;
}