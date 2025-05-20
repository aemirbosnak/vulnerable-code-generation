//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: complex
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct medicine {
    char name[50];
    char generic_name[50];
    float price;
    int quantity;
};

typedef struct medicine Medicine;

void add_to_inventory(Medicine *inventory, int *n);
void display_inventory(Medicine *inventory, int n);
void sell_medicine(Medicine *inventory, int n);
void search_medicine(Medicine *inventory, int n);

int main() {
    int n = 0, choice;
    Medicine *inventory = malloc(sizeof(Medicine));
    do {
        printf("\n\n------MEDICAL STORE MANAGEMENT SYSTEM------\n\n");
        printf("1. Add new medicine to inventory\n");
        printf("2. Display inventory\n");
        printf("3. Sell medicine\n");
        printf("4. Search medicine\n");
        printf("5. Exit program\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_to_inventory(inventory, &n);
                break;
            case 2:
                display_inventory(inventory, n);
                break;
            case 3:
                sell_medicine(inventory, n);
                break;
            case 4:
                search_medicine(inventory, n);
                break;
            case 5:
                printf("\nExiting program...\n");
                break;
            default:
                printf("\nInvalid choice! Please enter a valid choice.\n");
        }
    } while(choice != 5);
    free(inventory);
    return 0;
}

void add_to_inventory(Medicine *inventory, int *n) {
    printf("\n------Adding new medicine to inventory------\n");
    printf("Enter name of medicine: ");
    scanf("%s", inventory[*n].name);
    printf("Enter generic name of medicine: ");
    scanf("%s", inventory[*n].generic_name);
    printf("Enter price of medicine: ");
    scanf("%f", &inventory[*n].price);
    printf("Enter quantity of medicine: ");
    scanf("%d", &inventory[*n].quantity);
    *n += 1;
    inventory = realloc(inventory, (*n+1)*sizeof(Medicine));
    printf("\nSuccessfully added the medicine to inventory!\n");
}

void display_inventory(Medicine *inventory, int n) {
    printf("\n------Current inventory------\n");
    printf("-----------------------------------------------------------\n");
    printf("|%-30s|%-30s|%-10s|%-10s|\n", "Name", "Generic Name", "Price", "Quantity");
    printf("-----------------------------------------------------------\n");
    for(int i=0; i<n; i++) {
        printf("|%-30s|%-30s|%-10.2f|%-10d|\n", inventory[i].name, inventory[i].generic_name, inventory[i].price, inventory[i].quantity);
    }
    printf("-----------------------------------------------------------\n");
}

void sell_medicine(Medicine *inventory, int n) {
    char name[50];
    int quantity, found = 0;
    printf("\n------Selling medicine------\n");
    printf("Enter name of medicine: ");
    scanf("%s", name);
    for(int i=0; i<n; i++) {
        if(strcmp(inventory[i].name, name) == 0) {
            found = 1;
            printf("Enter quantity to sell: ");
            scanf("%d", &quantity);
            if(quantity <= inventory[i].quantity) {
                inventory[i].quantity -= quantity;
                printf("\nSold %d units of %s successfully!\n", quantity, name);
                printf("Total cost: %.2f\n", inventory[i].price*quantity);
                if(inventory[i].quantity == 0) {
                    printf("\n%s is now out of stock!\n", name);
                }
                break;
            } else {
                printf("\nInsufficient stock! Only %d units are available for %s.\n", inventory[i].quantity, name);
                break;
            }
        }
    }
    if(found == 0) {
        printf("\nMedicine not found in inventory!\n");
    }
}

void search_medicine(Medicine *inventory, int n) {
    char name[50];
    int found = 0;
    printf("\n------Search medicine------\n");
    printf("Enter name of medicine: ");
    scanf("%s", name);
    for(int i=0; i<n; i++) {
        if(strcmp(inventory[i].name, name) == 0) {
            found = 1;
            printf("\nMedicine found!\n");
            printf("Name: %s\nGeneric Name: %s\nPrice: %.2f\nQuantity: %d\n", inventory[i].name, inventory[i].generic_name, inventory[i].price, inventory[i].quantity);
            break;
        }
    }
    if(found == 0) {
        printf("\nMedicine not found in inventory!\n");
    }
}