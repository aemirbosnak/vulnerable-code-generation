//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: accurate
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct medicine {
    char name[50];
    int quantity;
    float price;
};
typedef struct medicine med;

void display(med m[], int n);
void addNewMedicine(med m[], int *n);
int searchMedicine(med m[], int n, char key[]);

int main() {
    med inventory[100];
    int numMeds = 0;
    int choice;
    char search[50];
    
    printf("Welcome to Medical Store Management System!\n");
    
    do {
        printf("\nMenu:\n");
        printf("1. Display all medicines\n");
        printf("2. Add a new medicine\n");
        printf("3. Search for a medicine\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                display(inventory, numMeds);
                break;
            case 2:
                addNewMedicine(inventory, &numMeds);
                break;
            case 3:
                printf("\nEnter the name of the medicine to search: ");
                scanf("%s", search);
                
                int result = searchMedicine(inventory, numMeds, search);
                
                if (result == -1) {
                    printf("Medicine not found.\n");
                }
                else {
                    printf("\nMedicine Details:\n");
                    printf("Name: %s\n", inventory[result].name);
                    printf("Quantity: %d\n", inventory[result].quantity);
                    printf("Price: %.2f\n", inventory[result].price);
                }
                break;
            case 4:
                printf("Thank you for using Medical Store Management System.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}

void display(med m[], int n) {
    if (n == 0) {
        printf("\nNo medicines available in inventory.\n");
    }
    else {
        printf("\nMedicine List:\n");
        for (int i = 0; i < n; i++) {
            printf("%d. %s - Quantity: %d, Price: %.2f\n", i+1, m[i].name, m[i].quantity, m[i].price);
        }
    }
}

void addNewMedicine(med m[], int *n) {
    printf("\nEnter the name of the medicine: ");
    scanf("%s", m[*n].name);
    
    printf("Enter the quantity of the medicine: ");
    scanf("%d", &m[*n].quantity);
    
    printf("Enter the price of the medicine: ");
    scanf("%f", &m[*n].price);
    
    printf("Medicine added successfully!\n");
    (*n)++;
}

int searchMedicine(med m[], int n, char key[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(m[i].name, key) == 0) {
            return i;
        }
    }
    return -1;
}