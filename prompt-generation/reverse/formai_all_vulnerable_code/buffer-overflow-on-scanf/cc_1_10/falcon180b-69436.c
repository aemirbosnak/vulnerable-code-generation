//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<time.h>

#define MAX 100
#define TRUE 1
#define FALSE 0
#define OVERFLOW -1
#define INVALID_INPUT -2

typedef struct{
    char name[20];
    int quantity;
    float price;
}Item;

typedef struct{
    char name[20];
    int quantity;
    float price;
}Order;

void addItem(Item menu[], int *size){
    printf("Enter item name: ");
    scanf("%s", menu[*size].name);
    printf("Enter item quantity: ");
    scanf("%d", &menu[*size].quantity);
    printf("Enter item price: ");
    scanf("%f", &menu[*size].price);
    (*size)++;
}

int searchItem(Item menu[], int size, char name[20]){
    int i;
    for(i=0;i<size;i++){
        if(strcmp(menu[i].name, name)==0){
            return i;
        }
    }
    return -1;
}

void displayMenu(Item menu[], int size){
    printf("Menu:\n");
    for(int i=0;i<size;i++){
        printf("%d. %s - %.2f\n", i+1, menu[i].name, menu[i].price);
    }
}

void addOrder(Order order[], int *size){
    printf("Enter customer name: ");
    scanf("%s", order[*size].name);
    printf("Enter order quantity: ");
    scanf("%d", &order[*size].quantity);
    printf("Enter order price: ");
    scanf("%f", &order[*size].price);
    (*size)++;
}

void displayOrder(Order order[], int size){
    printf("Order:\n");
    for(int i=0;i<size;i++){
        printf("%d. %s - %.2f\n", i+1, order[i].name, order[i].price);
    }
}

int main(){
    Item menu[MAX];
    int menuSize=0;
    addItem(menu, &menuSize);
    addItem(menu, &menuSize);
    addItem(menu, &menuSize);

    int choice, quantity;
    char name[20];
    float price;

    while(TRUE){
        system("clear");
        printf("Welcome to Cafe Billing System\n");
        displayMenu(menu, menuSize);
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        if(choice==1){
            printf("\nEnter item name: ");
            scanf("%s", name);
            int index=searchItem(menu, menuSize, name);
            if(index==-1){
                printf("\nItem not found\n");
            }
            else{
                printf("\nEnter quantity: ");
                scanf("%d", &quantity);
                float totalPrice=menu[index].price*quantity;
                printf("\nTotal price: %.2f\n", totalPrice);
            }
        }
        else if(choice==2){
            printf("\nEnter customer name: ");
            scanf("%s", name);
            printf("\nEnter order quantity: ");
            scanf("%d", &quantity);
            printf("\nEnter order price: ");
            scanf("%f", &price);
            addOrder(menu, &menuSize);
        }
        else if(choice==3){
            displayOrder(menu, menuSize);
        }
        else if(choice==4){
            exit(0);
        }
        else{
            printf("\nInvalid choice\n");
        }
    }

    return 0;
}