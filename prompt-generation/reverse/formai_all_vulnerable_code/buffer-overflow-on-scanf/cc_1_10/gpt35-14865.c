//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_MENU_ITEMS 10

struct MenuItem{
    char name[30];
    int price;
    int quantity;
};

struct Bill{
    struct MenuItem items[MAX_MENU_ITEMS];
    int num_items;
    int total;
};

void print_menu(){
    printf("Menu:\n");
    printf("1. Coffee - $3\n");
    printf("2. Tea - $2\n");
    printf("3. Cake - $4\n");
    printf("4. Sandwich - $5\n");
    printf("5. Exit menu\n");
    printf("\nEnter your choice: ");
}

void add_item(struct Bill *bill, char name[], int price, int quantity){
    strcpy(bill->items[bill->num_items].name, name);
    bill->items[bill->num_items].price = price;
    bill->items[bill->num_items].quantity = quantity;
    bill->num_items++;

    bill->total += (price * quantity);
}

void print_bill(struct Bill *bill){
    printf("\nBill:\n");
    printf("Name\tPrice\tQuantity\n");
    for(int i=0; i<bill->num_items; i++){
        printf("%s\t$%d\t%d\n", bill->items[i].name, bill->items[i].price, bill->items[i].quantity);
    }
    printf("\nTotal: $%d", bill->total);
}

int main(){
    struct Bill bill;
    bill.num_items = 0;
    bill.total = 0;

    int choice, quantity;

    do{
        print_menu();
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                add_item(&bill, "Coffee", 3, quantity);
                break;
            case 2:
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                add_item(&bill, "Tea", 2, quantity);
                break;
            case 3:
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                add_item(&bill, "Cake", 4, quantity);
                break;
            case 4:
                printf("Enter quantity: ");
                scanf("%d", &quantity);
                add_item(&bill, "Sandwich", 5, quantity);
                break;
            case 5:
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }

    }while(choice != 5);

    print_bill(&bill);

    return 0;
}