//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Item {
    char name[50];
    int quantity;
    float price;
    struct Item *next;
};

struct Customer {
    char name[50];
    char address[100];
    int contactNo;
    struct Customer *next;
};

void insertItem(struct Item **head) {
    struct Item *newItem = (struct Item *)malloc(sizeof(struct Item));
    printf("Enter item name:");
    scanf("%s", newItem->name);
    printf("Enter item quantity:");
    scanf("%d", &newItem->quantity);
    printf("Enter item price:");
    scanf("%f", &newItem->price);

    if (*head == NULL) {
        *head = newItem;
    } else {
        (*head)->next = newItem;
    }
}

void insertCustomer(struct Customer **head) {
    struct Customer *newCustomer = (struct Customer *)malloc(sizeof(struct Customer));
    printf("Enter customer name:");
    scanf("%s", newCustomer->name);
    printf("Enter customer address:");
    scanf("%s", newCustomer->address);
    printf("Enter customer contact number:");
    scanf("%d", &newCustomer->contactNo);

    if (*head == NULL) {
        *head = newCustomer;
    } else {
        (*head)->next = newCustomer;
    }
}

void displayItems(struct Item *head) {
    printf("Items:");
    while (head) {
        printf("\nName: %s", head->name);
        printf("Quantity: %d", head->quantity);
        printf("Price: %.2f", head->price);
        head = head->next;
    }
}

void displayCustomers(struct Customer *head) {
    printf("Customers:");
    while (head) {
        printf("\nName: %s", head->name);
        printf("Address: %s", head->address);
        printf("Contact No: %d", head->contactNo);
        head = head->next;
    }
}

int main() {
    struct Item *headItem = NULL;
    struct Customer *headCustomer = NULL;

    int choice;

    printf("Welcome to the Medical Store Management System!\n");

    while (1) {
        printf("Enter 1 to insert an item, 2 to insert a customer, 3 to display items, 4 to display customers, 5 to exit:");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertItem(&headItem);
                break;
            case 2:
                insertCustomer(&headCustomer);
                break;
            case 3:
                displayItems(headItem);
                break;
            case 4:
                displayCustomers(headCustomer);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}