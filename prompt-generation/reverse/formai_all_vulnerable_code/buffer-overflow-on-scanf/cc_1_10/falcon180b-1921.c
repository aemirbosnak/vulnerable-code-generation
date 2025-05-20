//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct item {
    char name[20];
    int price;
};

struct customer {
    char name[20];
    int bill;
};

void display_menu(struct item menu[], int size) {
    printf("\nMenu:\n");
    for(int i = 0; i < size; i++) {
        printf("%d. %s - $%d\n", i+1, menu[i].name, menu[i].price);
    }
}

void order(struct item menu[], int size, struct customer *customer) {
    int choice;
    printf("\nEnter your choice:\n");
    scanf("%d", &choice);
    if(choice >= 1 && choice <= size) {
        customer->bill += menu[choice-1].price;
        printf("\n%s ordered. Your bill is now $%d.\n", menu[choice-1].name, customer->bill);
    } else {
        printf("\nInvalid choice. Please try again.\n");
    }
}

void pay(struct customer *customer) {
    printf("\nYour total bill is $%d.\n", customer->bill);
    printf("\nThank you for your patronage!\n");
}

int main() {
    struct item menu[MAX] = {{"Coffee", 3}, {"Tea", 2}, {"Cake", 5}, {"Sandwich", 4}};
    struct customer customer;

    int choice;
    while(1) {
        printf("\nWelcome to the C Cafe!\n");
        printf("\n1. View Menu\n2. Place Order\n3. Pay Bill\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                display_menu(menu, 4);
                break;
            case 2:
                order(menu, 4, &customer);
                break;
            case 3:
                pay(&customer);
                break;
            case 4:
                printf("\nThank you for visiting the C Cafe!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}