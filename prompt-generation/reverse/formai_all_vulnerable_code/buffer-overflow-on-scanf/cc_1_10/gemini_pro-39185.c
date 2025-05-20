//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    char name[50];
    int quantity;
    float price;
};

struct node {
    struct medicine med;
    struct node *next;
};

struct linkedList {
    struct node *head;
    int size;
};

void createLinkedList(struct linkedList *list) {
    list->head = NULL;
    list->size = 0;
}

void insertMedicine(struct linkedList *list, struct medicine med) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->med = med;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        struct node *temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    list->size++;
}

void deleteMedicine(struct linkedList *list, char *name) {
    struct node *temp = list->head;
    struct node *prev = NULL;

    while (temp != NULL && strcmp(temp->med.name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Medicine not found\n");
    } else {
        if (prev == NULL) {
            list->head = temp->next;
        } else {
            prev->next = temp->next;
        }
        free(temp);
        list->size--;
    }
}

void updateQuantity(struct linkedList *list, char *name, int quantity) {
    struct node *temp = list->head;

    while (temp != NULL && strcmp(temp->med.name, name) != 0) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Medicine not found\n");
    } else {
        temp->med.quantity += quantity;
    }
}

void displayLinkedList(struct linkedList *list) {
    struct node *temp = list->head;

    while (temp != NULL) {
        printf("%s %d %.2f\n", temp->med.name, temp->med.quantity, temp->med.price);
        temp = temp->next;
    }
}

int main() {
    struct linkedList *list = (struct linkedList*)malloc(sizeof(struct linkedList));
    createLinkedList(list);

    char choice;
    do {
        printf("Enter your choice:\n");
        printf("1. Add a medicine\n");
        printf("2. Delete a medicine\n");
        printf("3. Update the quantity of a medicine\n");
        printf("4. Display the list of medicines\n");
        printf("5. Exit\n");
        scanf(" %c", &choice);

        switch (choice) {
            case '1': {
                struct medicine med;
                printf("Enter medicine name: ");
                scanf(" %s", med.name);
                printf("Enter quantity: ");
                scanf(" %d", &med.quantity);
                printf("Enter price: ");
                scanf(" %f", &med.price);
                insertMedicine(list, med);
                break;
            }
            case '2': {
                char name[50];
                printf("Enter medicine name to delete: ");
                scanf(" %s", name);
                deleteMedicine(list, name);
                break;
            }
            case '3': {
                char name[50];
                int quantity;
                printf("Enter medicine name to update quantity: ");
                scanf(" %s", name);
                printf("Enter quantity to add: ");
                scanf(" %d", &quantity);
                updateQuantity(list, name, quantity);
                break;
            }
            case '4':
                displayLinkedList(list);
                break;
            case '5':
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (choice != '5');

    return 0;
}