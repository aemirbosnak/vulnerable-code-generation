//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: accurate
#include<stdio.h>
#include<string.h>
#define MAX 100

int top = -1, arr[MAX], price[MAX], quantity[MAX];
char name[MAX][20], food[MAX][20];
int bill = 0;

void push(int val) {
    if(top == MAX-1) {
        printf("Stack Overflow!\n");
    } else {
        top++;
        arr[top] = val;
    }
}

int pop() {
    if(top == -1) {
        return -1;
    } else {
        int val = arr[top];
        top--;
        return val;
    }
}

int main() {
    int choice;
    do {
        printf("\n---------- Cafe Billing System ----------\n");
        printf("1. Add item to bill\n");
        printf("2. Remove item from bill\n");
        printf("3. View bill\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("\nEnter the name of the food item: ");
                scanf("%s", &name[top+1]);
                printf("Enter the price of the food item: ");
                scanf("%d", &price[top+1]);
                printf("Enter the quantity of the food item: ");
                scanf("%d", &quantity[top+1]);
                push(top+1);
                break;
            case 2:
                if(top == -1) {
                    printf("\nBill is already empty!\n");
                } else {
                    printf("\n%s with price %d and quantity %d removed from bill.\n", name[top], price[top], quantity[top]);
                    bill -= price[top] * quantity[top];
                    pop();
                }
                break;
            case 3:
                printf("\n---------- BILL ----------\n");
                printf("S.No.\tItem\tPrice\tQuantity\n");
                for(int i=0; i<=top; i++) {
                    printf("%d\t%s\t%d\t%d\n", i+1, name[i], price[i], quantity[i]);
                    bill += price[i] * quantity[i];
                }
                printf("\nTotal bill amount: %d\n", bill);
                break;
            case 4:
                printf("\nExiting program..\n");
                break;
            default:
                printf("\nInvalid choice! Please enter a valid choice.\n");
        }
    } while(choice != 4);
    return 0;
}