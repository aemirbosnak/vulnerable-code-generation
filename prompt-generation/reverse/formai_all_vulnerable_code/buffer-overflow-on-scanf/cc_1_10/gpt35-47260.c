//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Constants
#define MAX_STOCK 100 //maximum stock of a medicine
#define MAX_MED 10 //maximum number of medicines in inventory
#define PASSWORD "secure123" //password for management mode

//Structures
typedef struct {
    char name[20];
    int stock;
    float price;
} Medicine;

//Global variables
Medicine inventory[MAX_MED]; //inventory array
int count = 0; //number of medicines in inventory

//Functions
void addMedicine();
void sellMedicine();
void deleteMedicine();
void showInventory();
void showProfit();
void manageInventory();

//Main function
int main() {
    int option;
    do {
        printf("Welcome to Medical Store Management System\n");
        printf("1. Add Medicine\n");
        printf("2. Sell Medicine\n");
        printf("3. Delete Medicine\n");
        printf("4. Show Inventory\n");
        printf("5. Show Profit\n");
        printf("6. Manage Inventory\n");
        printf("0. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        switch (option) {
            case 0: //exit the program
                printf("Thank you for using Medical Store Management System\n");
                break;
            case 1: //add a new medicine to inventory
                addMedicine();
                break;
            case 2: //sell a medicine
                sellMedicine();
                break;
            case 3: //delete a medicine from inventory
                deleteMedicine();
                break;
            case 4: //display inventory
                showInventory();
                break;
            case 5: //calculate and display total profit
                showProfit();
                break;
            case 6: //enter management mode to add/delete/manage medicines
                manageInventory();
                break;
            default: //invalid option
                printf("Invalid option. Please try again.\n");
                break;
        }
        printf("\n");
    } while (option != 0);
    return 0;
}

//Adds medicine to inventory
void addMedicine() {
    if (count == MAX_MED) { //check if inventory is full
        printf("Inventory is full. Cannot add any more medicines.\n");
        return;
    }
    Medicine m;
    printf("Enter medicine name: ");
    scanf("%s", m.name);
    printf("Enter medicine stock: ");
    scanf("%d", &m.stock);
    if (m.stock > MAX_STOCK) { //check if stock exceeds maximum
        printf("Maximum stock limit is %d. Please enter a valid stock value.\n", MAX_STOCK);
        return;
    }
    printf("Enter medicine price: ");
    scanf("%f", &m.price);
    inventory[count++] = m;
    printf("Medicine added successfully to inventory.\n");
}

//Sells medicine and updates inventory
void sellMedicine() {
    if (count == 0) { //check if inventory is empty
        printf("Inventory is empty. Cannot make a sale.\n");
        return;
    }
    char name[20];
    printf("Enter the name of medicine to sell: ");
    scanf("%s", name);
    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(name, inventory[i].name) == 0) { //if medicine is found in inventory
            int quantity;
            printf("Enter the quantity to sell: ");
            scanf("%d", &quantity);
            if (quantity > inventory[i].stock) { //check if stock is sufficient
                printf("Insufficient stock. Only %d available for sale.\n", inventory[i].stock);
                return;
            }
            inventory[i].stock -= quantity;
            printf("%d %s sold for $%.2f each.\nTotal sale: $%.2f\n", quantity, inventory[i].name, inventory[i].price, quantity * inventory[i].price);
            return;
        }
    }
    printf("%s not found in inventory.\n", name);
}

//Deletes medicine from inventory
void deleteMedicine() {
    if (count == 0) { //check if inventory is empty
        printf("Inventory is empty. Cannot delete any medicine.\n");
        return;
    }
    char name[20];
    printf("Enter the name of medicine to delete: ");
    scanf("%s", name);
    int i, j;
    for (i = 0; i < count; i++) {
        if (strcmp(name, inventory[i].name) == 0) { //if medicine is found in inventory
            for (j = i; j < count - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            count--;
            printf("%s deleted successfully from inventory.\n", name);
            return;
        }
    }
    printf("%s not found in inventory.\n", name);
}

//Displays inventory
void showInventory() {
    if (count == 0) { //check if inventory is empty
        printf("Inventory is empty. No medicines to display.\n");
        return;
    }
    printf("NAME\tSTOCK\tPRICE\n");
    int i;
    for (i = 0; i < count; i++) {
        printf("%s\t%d\t%.2f\n", inventory[i].name, inventory[i].stock, inventory[i].price);
    }
}

//Displays total profit
void showProfit() {
    if (count == 0) { //check if inventory is empty
        printf("Inventory is empty. No profit to display.\n");
        return;
    }
    float total_profit = 0;
    int i;
    for (i = 0; i < count; i++) {
        total_profit += (MAX_STOCK - inventory[i].stock) * inventory[i].price;
    }
    printf("Total profit: $%.2f\n", total_profit);
}

//Enters management mode to add/delete/manage medicines
void manageInventory() {
    char password[20];
    printf("Enter management mode password: ");
    scanf("%s", password);
    if (strcmp(password, PASSWORD) != 0) { //if password is incorrect
        printf("Incorrect management mode password. Please try again.\n");
        return;
    }
    int option;
    do {
        printf("MANAGEMENT MODE\n");
        printf("1. Add Medicine\n");
        printf("2. Delete Medicine\n");
        printf("3. Show Inventory\n");
        printf("0. Exit Management Mode\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        switch (option) {
            case 0: //exit management mode
                printf("Exiting management mode.\n");
                break;
            case 1: //add a new medicine to inventory
                addMedicine();
                break;
            case 2: //delete a medicine from inventory
                deleteMedicine();
                break;
            case 3: //display inventory
                showInventory();
                break;
            default: //invalid option
                printf("Invalid option. Please try again.\n");
                break;
        }
        printf("\n");
    } while (option != 0);
}