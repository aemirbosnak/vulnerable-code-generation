//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct item {
    char name[20];
    int quantity;
    float price;
};

struct item medstore[MAX];
int top=-1;

void push(struct item item) {
    if(top==MAX-1){
        printf("\nStack Overflow");
        exit(0);
    }
    else{
        top++;
        medstore[top]=item;
    }
}

void pop() {
    if(top==-1){
        printf("\nStack Underflow");
        exit(0);
    }
    else{
        printf("\nItem popped from stack is: %s", medstore[top].name);
        top--;
    }
}

void display() {
    int i;
    for(i=top;i>=0;i--){
        printf("\nName: %s, Quantity: %d, Price: %.2f", medstore[i].name, medstore[i].quantity, medstore[i].price);
    }
}

int main() {
    int choice,i;
    float price;
    char name[20];

    do{
        printf("\n\nWelcome to Medical Store Management System\n");
        printf("\n1. Add Item");
        printf("\n2. Remove Item");
        printf("\n3. Display Items");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("\nEnter the name of the item: ");
                scanf("%s",name);
                printf("\nEnter the quantity of the item: ");
                scanf("%d",&medstore[++top].quantity);
                printf("\nEnter the price of the item: ");
                scanf("%f",&medstore[top].price);
                break;

            case 2:
                printf("\nEnter the name of the item to be removed: ");
                scanf("%s",name);
                for(i=0;i<=top;i++){
                    if(strcmp(name,medstore[i].name)==0){
                        pop();
                        break;
                    }
                }
                break;

            case 3:
                display();
                break;

            case 4:
                exit(0);

            default:
                printf("\nInvalid choice");
        }
    }while(choice!=4);

    return 0;
}