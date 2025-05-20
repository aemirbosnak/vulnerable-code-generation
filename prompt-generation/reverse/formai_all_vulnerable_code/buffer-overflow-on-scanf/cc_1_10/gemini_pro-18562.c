//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    char name[50];
    float price;
    int quantity;
};

struct node {
    struct medicine data;
    struct node *next;
};

struct node *head = NULL;

void insert_medicine() {
    struct medicine m;
    printf("Enter medicine name: ");
    scanf("%s", m.name);
    printf("Enter medicine price: ");
    scanf("%f", &m.price);
    printf("Enter medicine quantity: ");
    scanf("%d", &m.quantity);

    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = m;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    printf("Medicine inserted successfully\n");
}

void display_medicines() {
    struct node *temp = head;
    if (temp == NULL) {
        printf("No medicines found\n");
    } else {
        printf("Medicine Name\tPrice\tQuantity\n");
        while (temp != NULL) {
            printf("%s\t\t%.2f\t%d\n", temp->data.name, temp->data.price, temp->data.quantity);
            temp = temp->next;
        }
    }
}

void search_medicine() {
    char name[50];
    printf("Enter medicine name to search: ");
    scanf("%s", name);

    struct node *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->data.name, name) == 0) {
            printf("Medicine found:\n");
            printf("Medicine Name: %s\n", temp->data.name);
            printf("Medicine Price: %.2f\n", temp->data.price);
            printf("Medicine Quantity: %d\n", temp->data.quantity);
            return;
        }
        temp = temp->next;
    }

    printf("Medicine not found\n");
}

void update_medicine() {
    char name[50];
    printf("Enter medicine name to update: ");
    scanf("%s", name);

    struct node *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->data.name, name) == 0) {
            printf("Enter new medicine name: ");
            scanf("%s", temp->data.name);
            printf("Enter new medicine price: ");
            scanf("%f", &temp->data.price);
            printf("Enter new medicine quantity: ");
            scanf("%d", &temp->data.quantity);
            printf("Medicine updated successfully\n");
            return;
        }
        temp = temp->next;
    }

    printf("Medicine not found\n");
}

void delete_medicine() {
    char name[50];
    printf("Enter medicine name to delete: ");
    scanf("%s", name);

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
            printf("Medicine deleted successfully\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("Medicine not found\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nMedical Store Management System\n");
        printf("1. Insert Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Update Medicine\n");
        printf("5. Delete Medicine\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert_medicine();
                break;
            case 2:
                display_medicines();
                break;
            case 3:
                search_medicine();
                break;
            case 4:
                update_medicine();
                break;
            case 5:
                delete_medicine();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}