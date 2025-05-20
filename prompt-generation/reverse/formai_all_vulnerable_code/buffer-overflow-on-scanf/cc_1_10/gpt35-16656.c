//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct medicine {
    char name[50];
    int id;
    int qty;
    float price;
};

struct node {
    struct medicine med;
    struct node *next;
};

typedef struct node *NODEPTR;

NODEPTR start = NULL;

NODEPTR getNode() {
    NODEPTR newNode;
    newNode = (NODEPTR)malloc(sizeof(struct node));
    return newNode;
}

void insertMedicine() {
    NODEPTR temp, p;
    temp = getNode();
    printf("\nEnter medicine details:");
    printf("\nName: ");
    scanf("%s", temp->med.name);
    printf("\nID number: ");
    scanf("%d", &temp->med.id);
    printf("\nQuantity: ");
    scanf("%d", &temp->med.qty);
    printf("\nPrice: ");
    scanf("%f", &temp->med.price);
    temp->next = NULL;
    if(start == NULL) {
        start = temp;
    }
    else {
        p = start;
        while(p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
    }
    printf("\nMedicine details added successfully!\n");
}

void searchMedicine() {
    NODEPTR p = start;
    int id;
    printf("\nEnter the ID number of the medicine to be searched: ");
    scanf("%d", &id);
    while(p != NULL && p->med.id != id) {
        p = p->next;
    }
    if(p == NULL) {
        printf("\nMedicine with ID number %d not found!\n", id);
        return;
    }
    printf("\nName: %s", p->med.name);
    printf("\nID number: %d", p->med.id);
    printf("\nQuantity: %d", p->med.qty);
    printf("\nPrice: %.2f", p->med.price);
}

void deleteMedicine() {
    NODEPTR curr, prev = NULL;
    int id;
    printf("\nEnter the ID number of the medicine to be deleted: ");
    scanf("%d", &id);
    curr = start;
    while(curr != NULL && curr->med.id != id) {
        prev = curr;
        curr = curr->next;
    }
    if(curr == NULL) {
        printf("\nMedicine with ID number %d not found!\n", id);
        return;
    }
    if(prev == NULL) {
        start = curr->next;
    }
    else {
        prev->next = curr->next;
    }
    free(curr);
    printf("\nMedicine with ID number %d successfully deleted!\n", id);
}

void displayMedicine() {
    NODEPTR p = start;
    if(p == NULL) {
        printf("\nNo medicines present in the inventory!\n");
        return;
    }
    printf("\nList of medicines in inventory:\n");
    while(p != NULL) {
        printf("\nName: %s", p->med.name);
        printf("\nID number: %d", p->med.id);
        printf("\nQuantity: %d", p->med.qty);
        printf("\nPrice: %.2f\n", p->med.price);
        p = p->next;
    }
}

void updateMedicine() {
    NODEPTR p = start;
    int id;
    printf("\nEnter the ID number of the medicine to be updated: ");
    scanf("%d", &id);
    while(p != NULL && p->med.id != id) {
        p = p->next;
    }
    if(p == NULL) {
        printf("\nMedicine with ID number %d not found!\n", id);
        return;
    }
    printf("\nEnter new details for the medicine:");
    printf("\nName: ");
    scanf("%s", p->med.name);
    printf("\nQuantity: ");
    scanf("%d", &p->med.qty);
    printf("\nPrice: ");
    scanf("%f", &p->med.price);
    printf("\nMedicine with ID number %d successfully updated!\n", id);
}

int main() {
    int choice;
    while(1) {
        printf("\nWelcome to the Medical Store Management System!");
        printf("\n===============================================");
        printf("\n1. Insert new medicine");
        printf("\n2. Search for a medicine");
        printf("\n3. Delete a medicine");
        printf("\n4. Display all medicines");
        printf("\n5. Update a medicine");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                insertMedicine();
                break;
            case 2:
                searchMedicine();
                break;
            case 3:
                deleteMedicine();
                break;
            case 4:
                displayMedicine();
                break;
            case 5:
                updateMedicine();
                break;
            case 6:
                printf("\nExiting the program...");
                exit(0);
            default:
                printf("\nInvalid choice!");
        }
    }
    return 0;
}