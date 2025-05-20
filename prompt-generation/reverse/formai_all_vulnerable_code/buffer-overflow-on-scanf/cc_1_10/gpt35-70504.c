//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: safe
#include <stdio.h>
#include <stdlib.h>

void main_menu();
void add_item();
void view_menu();
void print_bill();
void safe_exit();

int total_items = 0;
double total_price = 0.0;

struct MenuItem{
    char name[25];
    double price;
    int quantity;
}menu[50];

int main(){
    main_menu();
    return 0;
}

void main_menu(){
    int choice;
    printf("\n==== C CAFE BILLING SYSTEM ====\n");
    printf("\n1. Add Item to Menu\n");
    printf("2. View Menu\n");
    printf("3. Print Bill\n");
    printf("4. Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    switch(choice){
        case 1:
            add_item();
            break;
        case 2:
            view_menu();
            break;
        case 3:
            print_bill();
            break;
        case 4:
            safe_exit();
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
            main_menu();
            break;
    }
}

void add_item(){
    printf("\nEnter name of item: ");
    scanf("%s", menu[total_items].name);
    printf("Enter price of item: ");
    scanf("%lf", &menu[total_items].price);
    printf("Enter quantity of item: ");
    scanf("%d", &menu[total_items].quantity);
    total_items++;
    printf("\nItem added successfully!\n");
    main_menu();
}

void view_menu(){
    if(total_items == 0){
        printf("\nNo items in menu. Please add items first.\n");
        main_menu();
    }
    else{
        printf("\n==== MENU ====\n");
        printf("%-15s%-15s%-15s\n", "Name", "Price", "Quantity");
        for(int i = 0; i < total_items; i++){
            printf("%-15s%-15.2f%-15d\n", menu[i].name, menu[i].price, menu[i].quantity);
        }
        main_menu();
    }
}

void print_bill(){
    if(total_items == 0){
        printf("\nNo items in menu. Please add items first.\n");
        main_menu();
    }
    else{
        printf("\n==== BILL ====\n");
        printf("%-15s%-15s%-15s%-15s\n", "Sl. No.", "Name", "Price", "Quantity");
        for(int i = 0; i < total_items; i++){
            double item_price = menu[i].price * menu[i].quantity;
            total_price += item_price;
            printf("%-15d%-15s%-15.2f%-15d\n", i+1, menu[i].name, menu[i].price, menu[i].quantity);
        }
        printf("\nTotal Price: %.2f\n", total_price);
        main_menu();
    }
}

void safe_exit(){
    printf("\nThank you for using C CAFE BILLING SYSTEM!\n");
    exit(0);
}