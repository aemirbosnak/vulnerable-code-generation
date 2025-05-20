//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_ITEMS 10
#define NAME_SIZE 20

//Structure for menu items
struct menuItem {
    char name[NAME_SIZE];
    int price;
};

//Function to read menu items
void readMenu(struct menuItem menu[]) {
    int i;
    for(i=0;i<MAX_ITEMS;i++) {
        printf("Enter name of item %d\n",i+1);
        scanf("%s",menu[i].name);

        printf("Enter price of item %d\n",i+1);
        scanf("%d",&menu[i].price);
    }
}

//Function to print menu items
void printMenu(struct menuItem menu[]) {
    int i;
    printf("\n\n");
    printf("Menu items:\n");
    for(i=0;i<MAX_ITEMS;i++) {
        printf("%d. %s - $%d\n",i+1,menu[i].name,menu[i].price);
    }
    printf("\n\n");
}

//Function to calculate total price
int calculatePrice(int bill[],int n) {
    int i,total=0;
    for(i=0;i<n;i++) {
        total+=bill[i];
    }
    return total;
}

//Main function
int main() {
    int i,n;
    char ch;
    struct menuItem menu[MAX_ITEMS];
    int bill[MAX_ITEMS];
    int price,total;

    printf("Welcome to the Cafe Billing System\n");
    printf("---------------------------------\n");

    //Read menu
    readMenu(menu);

    //Print menu
    printMenu(menu);

    //Read items from customer and calculate total
    printf("Enter number of items: ");
    scanf("%d",&n);
    printf("\n");
    for(i=0;i<n;i++) {
        printf("Enter item number %d: ",i+1);
        scanf("%d",&price);
        bill[i]=menu[price-1].price;
    }

    //Print bill
    printf("\n\n");
    printf("Bill\n");
    printf("----\n");
    for(i=0;i<n;i++) {
        printf("%d. %s - $%d\n",i+1,menu[i].name,menu[i].price);
    }
    printf("Total: $%d\n",calculatePrice(bill,n));

    //Ask for feedback
    printf("\n\n");
    printf("Did you enjoy our service? (y/n): ");
    scanf("\n%c",&ch);
    if(ch=='y' || ch=='Y') {
        printf("Thank you for your visit! Have a nice day!\n");
    }
    else {
        printf("We are sorry for any inconvenience caused. Please let us know how we can improve our service.\n");
    }
    return 0;
}