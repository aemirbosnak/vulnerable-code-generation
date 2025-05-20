//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50

int getMenuSelection();
void displayMenu();
void addItem();
void displayItems();
void generateBill();

struct MenuItem {
    char name[50];
    int price;
    int quantity;
};

struct MenuItem menu[MAX_ITEMS];
int itemCount = 0;

int main()
{
    while(1) {
        int selection = getMenuSelection();

        switch(selection) {
            case 1:
                addItem();
                break;

            case 2:
                displayItems();
                break;

            case 3:
                generateBill();
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("\n Invalid selection. Please try again!\n\n");
        }
    }

    return 0;
}

int getMenuSelection()
{
    int selection;

    printf("********** C Cafe Billing System **********\n\n");
    printf("\t1. Add Item\n");
    printf("\t2. Display Items\n");
    printf("\t3. Generate Bill\n");
    printf("\t4. Exit\n\n");

    printf("Enter your selection: ");
    scanf("%d", &selection);

    return selection;
}

void displayMenu()
{
    printf("========== Menu ==========\n\n");
    printf("Name \t\t Price\n\n");

    printf("1. Coffee \t $2\n");
    printf("2. Tea \t\t $1\n");
    printf("3. Sandwich \t $5\n");
    printf("4. Cake \t\t $3\n");

    printf("\n");
}

void addItem()
{
    if(itemCount >= MAX_ITEMS) {
        printf("\n Sorry, you have reached the maximum item limit of %d.\n", MAX_ITEMS);
        return;
    }

    displayMenu();

    printf("Enter item number: ");
    int choice;
    scanf("%d", &choice);

    if(choice < 1 || choice > 4) {
        printf("\n Invalid item number. Please try again!\n\n");
        return;
    }

    printf("Enter quantity: ");
    int quantity;
    scanf("%d", &quantity);

    struct MenuItem item;
    switch(choice) {
        case 1:
            strcpy(item.name, "Coffee");
            item.price = 2;
            break;

        case 2:
            strcpy(item.name, "Tea");
            item.price = 1;
            break;

        case 3:
            strcpy(item.name, "Sandwich");
            item.price = 5;
            break;

        case 4:
            strcpy(item.name, "Cake");
            item.price = 3;
            break;
    }

    item.quantity = quantity;

    menu[itemCount] = item;
    itemCount++;

    printf("\n Item added successfully.\n\n");
}

void displayItems()
{
    if(itemCount == 0) {
        printf("\n No items to display.\n\n");
        return;
    }

    printf("============== Items ==============\n\n");
    printf("Name \t\t Price \t\t Quantity \n\n");

    int i;
    for(i=0; i<itemCount; i++) {
        printf("%s \t\t $%d \t\t %d\n", menu[i].name, menu[i].price, menu[i].quantity);
    }

    printf("\n");
}

void generateBill()
{
    if(itemCount == 0) {
        printf("\n No items to generate bill.\n\n");
        return;
    }

    int total = 0;

    printf("\n\n============== Bill ==============\n\n");
    printf("Name \t\t Price \t\t Quantity \t Amount\n\n");

    int i;
    for(i=0; i<itemCount; i++) {
        struct MenuItem item = menu[i];
        int amount = item.price * item.quantity;
        printf("%s \t\t $%d \t\t %d \t\t $%d\n", item.name, item.price, item.quantity, amount);
        total += amount;
    }

    printf("\n Total bill amount: $%d\n\n", total);

    itemCount = 0;
}