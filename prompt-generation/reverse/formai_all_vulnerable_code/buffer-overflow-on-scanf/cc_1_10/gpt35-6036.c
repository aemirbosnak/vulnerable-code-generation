//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: retro
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct billing {
    char name[50];
    int quantity;
    float price;
    float amount;
};

void displayMenu() {
    printf("\nMenu\n");
    printf("------------------------------\n");
    printf("1. Coffee          Rs 20.00\n");
    printf("2. Sandwich        Rs 25.00\n");
    printf("3. Burger          Rs 35.00\n");
    printf("4. Fries           Rs 15.00\n");
    printf("5. Milkshake       Rs 30.00\n");
    printf("6. Exit\n\n");
}

int main() {
    int option, i = 0;
    float total = 0.00;
    struct billing bill[10];
    printf("\t Retro Cafe Billing System\n\n");
    printf("------------------------------\n\n");
    displayMenu();
    do {
        printf("Enter your option: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                strcpy(bill[i].name, "Coffee");
                bill[i].price = 20.00;
                break;
            case 2:
                strcpy(bill[i].name, "Sandwich");
                bill[i].price = 25.00;
                break;
            case 3:
                strcpy(bill[i].name, "Burger");
                bill[i].price = 35.00;
                break;
            case 4:
                strcpy(bill[i].name, "Fries");
                bill[i].price = 15.00;
                break;
            case 5:
                strcpy(bill[i].name, "Milkshake");
                bill[i].price = 30.00;
                break;
            case 6:
                printf("\nTotal amount: Rs %.2f/-\n", total);
                printf("Thank you for visiting!\n");
                exit(0);
                break;
            default:
                printf("\nError: Invalid option selected!\n\n");
                displayMenu();
                break;
        }
        if(option >= 1 && option <= 5) {
            printf("Enter quantity: ");
            scanf("%d", &bill[i].quantity);
            bill[i].amount = bill[i].price * bill[i].quantity;
            total += bill[i].amount;
            printf("Added to Cart: %s x %d ==> Rs %.2f/\n", bill[i].name, bill[i].quantity, bill[i].amount);
            i++;
        }
    } while(1);
    return 0;
}