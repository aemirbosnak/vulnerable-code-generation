//MISTRAL-7B DATASET v1.0 Category: Medical Store Management System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char name[50];
    int stock;
    float price;
} Medicine;

typedef struct Node {
    Medicine med;
    struct Node *next;
} Node;

Node *head = NULL;
Node *temp = NULL;
Node *iterator = NULL;

void createMedicine(Medicine *med) {
    printf("\nEnter Medicine Name : ");
    fgets(med->name, sizeof(med->name), stdin);
    med->name[strlen(med->name) - 1] = '\0';
    printf("Enter Stock : ");
    scanf("%d", &med->stock);
    printf("Enter Price : ");
    scanf("%f", &med->price);
}

void addMedicine() {
    Medicine newMed;
    Node *newNode = (Node *)malloc(sizeof(Node));

    createMedicine(&newMed);

    newNode->med = newMed;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayMedicine() {
    iterator = head;
    while (iterator != NULL) {
        printf("\nMedicine Name : %s", iterator->med.name);
        printf("\nStock : %d", iterator->med.stock);
        printf("\nPrice : %.2f", iterator->med.price);
        iterator = iterator->next;
    }
}

void searchMedicine() {
    char searchName[50];
    iterator = head;

    printf("\nEnter Medicine Name to Search : ");
    scanf("%s", searchName);

    while (iterator != NULL) {
        if (strcmp(iterator->med.name, searchName) == 0) {
            printf("\nMedicine Found : ");
            printf("\nMedicine Name : %s", iterator->med.name);
            printf("\nStock : %d", iterator->med.stock);
            printf("\nPrice : %.2f", iterator->med.price);
            return;
        }
        iterator = iterator->next;
    }

    printf("\nMedicine Not Found.");
}

int main() {
    int choice;

    while (1) {
        printf("\n----------------------- MEDICAL STORE MANAGEMENT SYSTEM -----------------------");
        printf("\n1. Add Medicine");
        printf("\n2. Display All Medicines");
        printf("\n3. Search Medicine");
        printf("\n4. Exit");
        printf("\nEnter Your Choice : ");
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
                exit(0);
            default:
                printf("\nInvalid Choice. Please Try Again.");
        }
    }

    return 0;
}