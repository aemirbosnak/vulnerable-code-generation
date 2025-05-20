//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining structures
struct Medicine {
    char name[50];
    int quantity;
    float price;
};

struct Node {
    struct Medicine medicine;
    struct Node* next;
};

typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

// Defining function prototypes
void displayMainMenu();
void displayMedicines(List list);
void addMedicine(List* list);
void removeMedicine(List* list);
void updateMedicine(List list);
void searchMedicine(List list);
void sellMedicine(List* list);

// Main function
int main() {
    List list = NULL;
    int choice;
    
    do {
        displayMainMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addMedicine(&list);
                break;
            case 2:
                removeMedicine(&list);
                break;
            case 3:
                updateMedicine(list);
                break;
            case 4:
                displayMedicines(list);
                break;
            case 5:
                searchMedicine(list);
                break;
            case 6:
                sellMedicine(&list);
                break;
            case 7:
                printf("\nThank you for using the C Medical Store Management System!\n");
                exit(1);
                break;
            default:
                printf("\nPlease choose a valid option!\n");
        }
    } while (choice != 7);
    
    return 0;
}

// Function to display main menu
void displayMainMenu() {
    printf("\n======== C MEDICAL STORE MANAGEMENT SYSTEM ========\n");
    printf("1. Add medicine\n");
    printf("2. Remove medicine\n");
    printf("3. Update medicine details\n");
    printf("4. Display all medicines\n");
    printf("5. Search for medicine\n");
    printf("6. Sell medicine\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

// Function to display all medicines in the store
void displayMedicines(List list) {
    if (list == NULL) {
        printf("\nThere are no medicines in the store!\n");
        return;
    }
    
    printf("\n=============== ALL MEDICINES ===============\n");
    printf("%-30s %-10s %-10s\n", "Name", "Quantity", "Price");
    printf("---------------------------------------------\n");
    
    Position p = list;
    while (p != NULL) {
        printf("%-30s %-10d %-10.2f\n", p->medicine.name, p->medicine.quantity, p->medicine.price);
        p = p->next;
    }
}

// Function to add a medicine to the store
void addMedicine(List* list) {
    struct Medicine medicine;
    
    printf("\nEnter the name of the medicine: ");
    scanf("%s", medicine.name);
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &medicine.quantity);
    printf("Enter the price of the medicine: ");
    scanf("%f", &medicine.price);
    
    Position p = *list;
    Position prev = NULL;
    
    while (p != NULL) {
        if (strcmp(p->medicine.name, medicine.name) == 0) {
            // If the medicine already exists, update the details
            printf("\nThe medicine \"%s\" already exists. Updating its details...\n", medicine.name);
            p->medicine.quantity += medicine.quantity;
            p->medicine.price = medicine.price;
            return;
        }
        
        prev = p;
        p = p->next;
    }
    
    Position new_node = malloc(sizeof(struct Node));
    new_node->medicine = medicine;
    new_node->next = NULL;
    
    if (prev == NULL) {
        *list = new_node;
    }
    else {
        prev->next = new_node;
    }
    
    printf("\nThe medicine \"%s\" has been added to the store!\n", medicine.name);
}

// Function to remove a medicine from the store
void removeMedicine(List* list) {
    if (*list == NULL) {
        printf("\nThere are no medicines in the store to remove!\n");
        return;
    }
    
    char name[50];
    printf("\nEnter the name of the medicine you want to remove: ");
    scanf("%s", name);
    
    Position p = *list;
    Position prev = NULL;
    
    while (p != NULL) {
        if (strcmp(p->medicine.name, name) == 0) {
            // If the medicine is found, remove it from the list
            if (prev == NULL) {
                *list = p->next;
            }
            else {
                prev->next = p->next;
            }
            
            printf("\nThe medicine \"%s\" has been removed from the store!\n", name);
            free(p);
            return;
        }
        
        prev = p;
        p = p->next;
    }
    
    printf("\nThe medicine \"%s\" was not found in the store!\n", name);
}

// Function to update the details of a medicine
void updateMedicine(List list) {
    if (list == NULL) {
        printf("\nThere are no medicines in the store to update!\n");
        return;
    }
    
    char name[50];
    printf("\nEnter the name of the medicine you want to update: ");
    scanf("%s", name);
    
    Position p = list;
    
    while (p != NULL) {
        if (strcmp(p->medicine.name, name) == 0) {
            // If the medicine is found, update its details
            printf("\nEnter the new quantity of the medicine: ");
            scanf("%d", &p->medicine.quantity);
            printf("Enter the new price of the medicine: ");
            scanf("%f", &p->medicine.price);
            
            printf("\nThe details of medicine \"%s\" have been updated!\n", name);
            return;
        }
        
        p = p->next;
    }
    
    printf("\nThe medicine \"%s\" was not found in the store!\n", name);
}

// Function to search for a medicine in the store
void searchMedicine(List list) {
    if (list == NULL) {
        printf("\nThere are no medicines in the store to search!\n");
        return;
    }
    
    char name[50];
    printf("\nEnter the name of the medicine you want to search: ");
    scanf("%s", name);
    
    Position p = list;
    
    while (p != NULL) {
        if (strcmp(p->medicine.name, name) == 0) {
            // If the medicine is found, display its details
            printf("\nThe details of medicine \"%s\" are as follows:\n", name);
            printf("Quantity: %d\n", p->medicine.quantity);
            printf("Price: %.2f\n", p->medicine.price);
            return;
        }
        
        p = p->next;
    }
    
    printf("\nThe medicine \"%s\" was not found in the store!\n", name);
}

// Function to sell a medicine to a customer
void sellMedicine(List* list) {
    if (*list == NULL) {
        printf("\nThere are no medicines in the store to sell!\n");
        return;
    }
    
    char name[50];
    printf("\nEnter the name of the medicine you want to sell: ");
    scanf("%s", name);
    
    Position p = *list;
    Position prev = NULL;
    
    while (p != NULL) {
        if (strcmp(p->medicine.name, name) == 0) {
            // If the medicine is found, ask for quantity to be sold and update its details
            int quantity;
            printf("\nEnter the quantity of \"%s\" you want to sell: ", name);
            scanf("%d", &quantity);
            
            if (quantity > p->medicine.quantity) {
                printf("\nOnly %d units of \"%s\" are available in the store!\n", p->medicine.quantity, name);
            }
            else {
                p->medicine.quantity -= quantity;
                printf("\n%d units of \"%s\" have been sold for %.2f!\n", quantity, name, quantity * p->medicine.price);
                
                if (p->medicine.quantity == 0) {
                    // If all units of a medicine are sold, remove it from the store
                    if (prev == NULL) {
                        *list = p->next;
                    }
                    else {
                        prev->next = p->next;
                    }
                    
                    printf("\nThe medicine \"%s\" is out of stock and has been removed from the store!\n", name);
                    free(p);
                }
            }
            
            return;
        }
        
        prev = p;
        p = p->next;
    }
    
    printf("\nThe medicine \"%s\" was not found in the store!\n", name);
}