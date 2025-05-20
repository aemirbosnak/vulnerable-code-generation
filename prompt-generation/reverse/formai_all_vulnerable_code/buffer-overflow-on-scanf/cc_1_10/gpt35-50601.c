//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: happy
#include <stdio.h>
#include <string.h>
#define MAX 100

struct menuitem{
    char name[50];
    float price;
}menu[MAX];

int count = 0;

void addMenuItem(){
    if(count >= MAX){
        printf("Sorry, we can't add any more menu items.\n");
        return;
    }
    printf("Enter the name of the item: ");
    scanf("%s", menu[count].name);
    printf("Enter the price of the item: ");
    scanf("%f", &menu[count].price);
    count++;
}

float calculateBill(int* items, int n){
    float total = 0;
    int i;
    for(i = 0; i < n; i++){
        total += menu[items[i]].price;
    }
    return total;
}

int main(){
    printf("Welcome to Happy Cafe Billing System!\n");
    printf("=====================================\n");

    int option;
    do{
        printf("Please select an option:\n");
        printf("1. Add menu item\n");
        printf("2. Generate bill\n");
        printf("3. Exit\n");
        printf("Your choice: ");
        scanf("%d", &option);

        switch(option){
            case 1:
                addMenuItem();
                break;
            case 2:{
                int items[MAX];
                int n;
                printf("How many items did the customer order? ");
                scanf("%d", &n);
                printf("Enter the item numbers: ");
                int i;
                for(i = 0; i < n; i++){
                    scanf("%d", &items[i]);
                }
                float total = calculateBill(items, n);
                printf("The total bill is: %.2f\n", total);
                break;
            }
            case 3:
                printf("Thank you for using Happy Cafe Billing System!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }while(option != 3);

    return 0;
}