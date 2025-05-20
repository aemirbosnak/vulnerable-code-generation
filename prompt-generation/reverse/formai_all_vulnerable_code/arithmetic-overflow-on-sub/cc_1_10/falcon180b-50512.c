//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item{
    char name[50];
    float price;
};

void display_menu(struct item menu[], int size){
    printf("\nCafe Menu\n");
    for(int i=0; i<size; i++){
        printf("%d. %s - $%.2f\n", i+1, menu[i].name, menu[i].price);
    }
}

void take_order(struct item menu[], int size, char order[100]){
    int choice;
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    strcpy(order, menu[choice-1].name);
    printf("\nYou ordered %s\n", order);
}

void generate_bill(struct item menu[], int size, char order[], float quantity){
    int index = -1;
    for(int i=0; i<size; i++){
        if(strcmp(menu[i].name, order) == 0){
            index = i;
            break;
        }
    }
    if(index == -1){
        printf("\nItem not found\n");
        return;
    }
    float total = menu[index].price * quantity;
    printf("\nTotal bill: $%.2f\n", total);
}

int main(){
    struct item menu[] = {{"Coffee", 3.50}, {"Tea", 2.50}, {"Coke", 1.50}, {"Pepsi", 1.50}};
    int size = sizeof(menu)/sizeof(menu[0]);

    char order[100];
    float quantity;

    int choice;
    do{
        system("clear");
        display_menu(menu, size);
        printf("\nEnter 1 to order\n");
        printf("Enter 2 to view bill\n");
        printf("Enter 3 to exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("\nEnter quantity: ");
                scanf("%f", &quantity);
                take_order(menu, size, order);
                generate_bill(menu, size, order, quantity);
                break;
            case 2:
                generate_bill(menu, size, order, 1);
                break;
            case 3:
                printf("\nThank you for visiting our cafe\n");
                break;
            default:
                printf("\nInvalid choice\n");
        }
    }while(choice!= 3);

    return 0;
}