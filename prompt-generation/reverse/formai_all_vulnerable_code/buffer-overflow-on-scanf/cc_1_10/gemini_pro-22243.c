//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: genious
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
struct node *head = NULL;
void add_medicine() {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    printf("Enter medicine name: ");
    scanf("%s", new_node->med.name);
    printf("Enter medicine quantity: ");
    scanf("%d", &new_node->med.quantity);
    printf("Enter medicine price: ");
    scanf("%f", &new_node->med.price);
    new_node->next = head;
    head = new_node;
    printf("Medicine added successfully!\n");
}
void display_medicines() {
    struct node *temp = head;
    if (temp == NULL) {
        printf("No medicines found!\n");
    } else {
        printf("---------------------------------------------------------\n");
        printf("| %-5s | %-20s | %-10s | %-10s |\n", "ID", "Name", "Quantity", "Price");
        printf("---------------------------------------------------------\n");
        int count = 1;
        while (temp != NULL) {
            printf("| %-5d | %-20s | %-10d | %-10.2f |\n", count++, temp->med.name, temp->med.quantity, temp->med.price);
            temp = temp->next;
        }
        printf("---------------------------------------------------------\n");
    }
}
void search_medicine() {
    char name[50];
    printf("Enter medicine name to search: ");
    scanf("%s", name);
    struct node *temp = head;
    int found = 0;
    while (temp != NULL) {
        if (strcmp(temp->med.name, name) == 0) {
            printf("Medicine found!\n");
            printf("Name: %s\n", temp->med.name);
            printf("Quantity: %d\n", temp->med.quantity);
            printf("Price: %.2f\n", temp->med.price);
            found = 1;
            break;
        }
        temp = temp->next;
    }
    if (found == 0) {
        printf("Medicine not found!\n");
    }
}
void update_medicine() {
    char name[50];
    printf("Enter medicine name to update: ");
    scanf("%s", name);
    struct node *temp = head;
    int found = 0;
    while (temp != NULL) {
        if (strcmp(temp->med.name, name) == 0) {
            printf("Medicine found!\n");
            printf("Enter new medicine quantity: ");
            scanf("%d", &temp->med.quantity);
            printf("Enter new medicine price: ");
            scanf("%f", &temp->med.price);
            found = 1;
            break;
        }
        temp = temp->next;
    }
    if (found == 0) {
        printf("Medicine not found!\n");
    }
}
void delete_medicine() {
    char name[50];
    printf("Enter medicine name to delete: ");
    scanf("%s", name);
    struct node *temp = head;
    struct node *prev = NULL;
    int found = 0;
    while (temp != NULL) {
        if (strcmp(temp->med.name, name) == 0) {
            found = 1;
            if (prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    if (found == 0) {
        printf("Medicine not found!\n");
    }
}
void exit_program() {
    printf("Thank you for using the Medical Store Management System!\n");
    exit(0);
}
int main() {
    int choice;
    while (1) {
        printf("---------------------------------------------------------\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Update Medicine\n");
        printf("5. Delete Medicine\n");
        printf("6. Exit Program\n");
        printf("---------------------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_medicine();
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
                exit_program();
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }
    return 0;
}