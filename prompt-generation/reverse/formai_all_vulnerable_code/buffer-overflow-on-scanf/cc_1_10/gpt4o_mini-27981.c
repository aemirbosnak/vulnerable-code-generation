//GPT-4o-mini DATASET v1.0 Category: Medical Store Management System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Medicine {
    char name[50];
    char description[200];
    float price;
    int quantity;
} Medicine;

typedef struct Node {
    Medicine med;
    struct Node* next;
} Node;

Node* head = NULL;

void insertMedicine() {
    Node* newNode = (Node*)malloc(sizeof(Node));
    printf("Enter the name of the medicine: ");
    scanf("%s", newNode->med.name);
    printf("Enter the description of the medicine: ");
    scanf(" %[^\n]s", newNode->med.description);
    printf("Enter the price of the medicine: ");
    scanf("%f", &newNode->med.price);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &newNode->med.quantity);
    
    newNode->next = head;
    head = newNode;

    printf("Oh, fair medicine, thou art added to our kingdom!\n");
}

void displayMedicines() {
    if (head == NULL) {
        printf("Alas, no medicine is here in Verona!\n");
        return;
    }
    Node* temp = head;
    printf("List of Medicines: \n");
    while (temp != NULL) {
        printf("Name: %s\n", temp->med.name);
        printf("Description: %s\n", temp->med.description);
        printf("Price: %.2f\n", temp->med.price);
        printf("Quantity: %d\n", temp->med.quantity);
        printf("-------------------------\n");
        temp = temp->next;
    }
}

void searchMedicine() {
    char name[50];
    printf("Which medicine dost thou seek? Enter its name: ");
    scanf("%s", name);

    Node* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->med.name, name) == 0) {
            printf("Found! Name: %s\n", temp->med.name);
            printf("Description: %s\n", temp->med.description);
            printf("Price: %.2f\n", temp->med.price);
            printf("Quantity: %d\n", temp->med.quantity);
            return;
        }
        temp = temp->next;
    }
    printf("Oh no! The medicine thou seeketh is not in our store!\n");
}

void updateMedicine() {
    char name[50];
    printf("Whence doth thou wish to update? Enter the name of the medicine: ");
    scanf("%s", name);

    Node* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->med.name, name) == 0) {
            printf("Current price: %.2f\n", temp->med.price);
            printf("New price: ");
            scanf("%f", &temp->med.price);
            printf("Current quantity: %d\n", temp->med.quantity);
            printf("New quantity: ");
            scanf("%d", &temp->med.quantity);
            printf("Thy medicine hath been updated!\n");
            return;
        }
        temp = temp->next;
    }
    printf("Fie! The medicine is not found for update!\n");
}

void deleteMedicine() {
    char name[50];
    printf("To remove a medicine from our laps, enter its name: ");
    scanf("%s", name);

    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL && strcmp(temp->med.name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Oh tragic fate, the medicine is not to be found!\n");
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    printf("The medicine hath been banished from our realm!\n");
}

void menu() {
    int choice;
    do {
        printf("\nWelcome to the Medicinal Apothecary of Verona!\n");
        printf("1. Add Medicine\n");
        printf("2. Display Medicines\n");
        printf("3. Search Medicine\n");
        printf("4. Update Medicine\n");
        printf("5. Delete Medicine\n");
        printf("6. Exit\n");
        printf("Enter thy choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: insertMedicine(); break;
            case 2: displayMedicines(); break;
            case 3: searchMedicine(); break;
            case 4: updateMedicine(); break;
            case 5: deleteMedicine(); break;
            case 6: printf("Farewell! May thy health be ever strong!\n"); break;
            default: printf("What sorcery is this? Please choose a valid option!\n");
        }
    } while (choice != 6);
}

int main() {
    menu();
    return 0;
}