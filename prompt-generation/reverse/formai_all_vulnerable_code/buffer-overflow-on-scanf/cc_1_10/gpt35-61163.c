//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine {
    char name[50];
    int id;
    float price;
    int quantity;
    int reorder_level;
};

typedef struct medicine Medicine;

struct node {
    Medicine med;
    struct node *next;
};

typedef struct node Node;

Node *head = NULL;

int id_counter = 1;

void addMedicine() {
    Medicine newMed;
    printf("Enter medicine details:\n");
    printf("Name: ");
    scanf("%s", newMed.name);
    newMed.id = id_counter++;
    printf("Price: ");
    scanf("%f", &newMed.price);
    printf("Quantity: ");
    scanf("%d", &newMed.quantity);
    printf("Reorder level: ");
    scanf("%d", &newMed.reorder_level);
    
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->med = newMed;
    newNode->next = NULL;
    
    if(head == NULL) {
        head = newNode;
    } else {
        Node *temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
    printf("\nMedicine added successfully!\n\n");
}

void searchMedicine() {
    printf("Enter medicine name: ");
    char name[50];
    scanf("%s", name);
    
    Node *temp = head;
    int found = 0;
    while(temp != NULL) {
        if(strcmp(temp->med.name, name) == 0) {
            printf("\nDetails for %s:\n", name);
            printf("ID: %d\n", temp->med.id);
            printf("Price: %.2f\n", temp->med.price);
            printf("Quantity: %d\n", temp->med.quantity);
            printf("Reorder Level: %d\n\n", temp->med.reorder_level);
            found = 1;
            break;
        }
        temp = temp->next;
    }
    if(!found) {
        printf("\nMedicine not found!\n\n");
    }
}

void displayInventory() {
    Node *temp = head;
    printf("\nCurrent inventory:\n");
    printf("%-20s %-10s %-10s %-15s\n", "Name", "ID", "Price", "Quantity");
    while(temp != NULL) {
        printf("%-20s %-10d %-10.2f %-15d\n", temp->med.name, temp->med.id, temp->med.price, temp->med.quantity);
        temp = temp->next;
    }
    printf("\n");
}

void reorderList() {
    printf("Enter reorder level: ");
    int reorder;
    scanf("%d", &reorder);
    
    Node *temp = head;
    printf("\nMedicine to be reordered:\n");
    printf("%-20s %-10s\n", "Name", "Quantity");
    while(temp != NULL) {
        if(temp->med.quantity < reorder) {
            printf("%-20s %-10d\n", temp->med.name, temp->med.reorder_level - temp->med.quantity);
        }
        temp = temp->next;
    }
    printf("\n");
}

void removeMedicine() {
    printf("Enter medicine ID: ");
    int id;
    scanf("%d", &id);
    
    Node *temp = head;
    Node *prev = NULL;
    int found = 0;
    while(temp != NULL) {
        if(temp->med.id == id) {
            found = 1;
            if(prev == NULL) {
                head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf("\nMedicine removed successfully!\n\n");
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    if(!found) {
        printf("\nMedicine not found!\n\n");
    }
}

int main() {
    int choice;
    do {
        printf("Menu:\n");
        printf("1. Add Medicine\n");
        printf("2. Search Medicine\n");
        printf("3. Display Inventory\n");
        printf("4. Reorder List\n");
        printf("5. Remove Medicine\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: addMedicine(); break;
            case 2: searchMedicine(); break;
            case 3: displayInventory(); break;
            case 4: reorderList(); break;
            case 5: removeMedicine(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid Choice!\n"); break;
        }
    } while(choice != 6);
    return 0;
}