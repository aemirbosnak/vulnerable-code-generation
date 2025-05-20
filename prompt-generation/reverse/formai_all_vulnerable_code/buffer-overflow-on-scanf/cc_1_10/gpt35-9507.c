//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Menu{
    char item[50];
    int price;
};

struct Bill{
    char item[50];
    int quantity;
    int price;
};

void showMenu(struct Menu m[]){
    printf("Menu:\n");
    for(int i = 0; i < 5; i++)
        printf("%d. %s\tRs. %d\n", i+1, m[i].item, m[i].price);
    printf("\n");
}

int main(){

    struct Menu menu[5] = {{"Coffee", 30}, {"Sandwich", 50}, {"Tea", 20}, {"Burger", 70}, {"Cake", 60}};
    struct Bill *bill;
    int total = 0, i = 0, j = 0, k = 0, n, choice, amt;

    printf("\n***WELCOME TO C CAFE***\n");

    while(choice != 2){
        printf("1. Place Order\n2. Exit\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter the number of items: ");
                scanf("%d", &n);

                bill = (struct Bill*)malloc(n * sizeof(struct Bill));

                for(i = 0; i < n; i++){
                    printf("\nItem %d:\n", i+1);
                    showMenu(menu);

                    printf("Enter item choice: ");
                    scanf("%d", &choice);
                    strcpy(bill[j].item, menu[choice-1].item);
                    bill[j].price = menu[choice-1].price;

                    printf("Enter quantity: ");
                    scanf("%d", &bill[j++].quantity);

                }

                printf("\n\nC Cafe\n");
                printf("Invoice:\n\n");

                printf("%-20s%-10s%-10s\n", "Item", "Qty", "Price");
                for(i = 0; i < j; i++){
                    printf("%-20s%-10d%-10d\n", bill[i].item, bill[i].quantity, bill[i].price * bill[i].quantity);
                    total += bill[i].price * bill[i].quantity;
                }

                printf("------------------------------\n");
                printf("%-20s%-10s%-10d\n", " ", "Total", total);
                printf("------------------------------\n\n");

                free(bill);
                total = 0, j = 0;
                break;

            case 2:
                printf("\nThank You! Visist Again..\n");
                break;

            default:
                printf("\nInvalid input! Please try again.\n");
        }
    }
    return 0;
}