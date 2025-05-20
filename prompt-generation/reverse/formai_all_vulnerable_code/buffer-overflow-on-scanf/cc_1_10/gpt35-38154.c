//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: introspective
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct cafe{
    int item_no;
    char name[30];
    float price;
};

void display_menu(struct cafe menu[], int n);
void take_order(struct cafe menu[], int n, int order[]);
void print_bill(struct cafe menu[], int n, int order[]);
float calculate_total(struct cafe menu[], int n, int order[]);

int main(){
    int n=5, choice;
    struct cafe menu[5]={{1, "Coffee", 3.50}, {2, "Tea", 2.50}, {3, "Sandwich", 5.00}, {4, "French fries", 4.00}, {5, "Burger", 6.00}};
    int order[5]={0};
    printf("Welcome to Cafe Billing System!\n");
    printf("Please select your choice:\n1. Display menu\n2. Take order\n3. Print bill\n4. Exit\n");
    scanf("%d", &choice);
    while(1){
        switch(choice){
            case 1:
                display_menu(menu, n);
                printf("Please select your choice:\n1. Display menu\n2. Take order\n3. Print bill\n4. Exit\n");
                scanf("%d", &choice);
                break;
            case 2:
                take_order(menu, n, order);
                printf("Please select your choice:\n1. Display menu\n2. Take order\n3. Print bill\n4. Exit\n");
                scanf("%d", &choice);
                break;
            case 3:
                print_bill(menu, n, order);
                printf("Please select your choice:\n1. Display menu\n2. Take order\n3. Print bill\n4. Exit\n");
                scanf("%d", &choice);
                break;
            case 4:
                printf("Thank you for using Cafe Billing System!\n");
                exit(0);
        }
    }
}

void display_menu(struct cafe menu[], int n){
    printf("Item No.\tItem Name\tPrice\n");
    for(int i=0; i<n; i++){
        printf("%d\t\t%s\t\t$%.2f\n", menu[i].item_no, menu[i].name, menu[i].price);
    }
}

void take_order(struct cafe menu[], int n, int order[]){
    display_menu(menu, n);
    int item_no, quantity;
    printf("Enter item number and quantity (separated by space) or enter -1 to exit:\n");
    scanf("%d", &item_no);
    while(item_no!=-1){
        scanf("%d", &quantity);
        if(item_no>0 && item_no<=n){
            order[item_no-1]+=quantity;
        }
        printf("Enter item number and quantity (separated by space) or enter -1 to exit:\n");
        scanf("%d", &item_no);
    }
}

void print_bill(struct cafe menu[], int n, int order[]){
    printf("---------------------------------------------\n");
    printf("\t\tCafe Bill\n");
    printf("---------------------------------------------\n");
    printf("Item No.\tItem Name\tQuantity\tPrice\n");
    for(int i=0; i<n; i++){
        if(order[i]>0){
            printf("%d\t\t%s\t\t%d\t\t$%.2f\n", menu[i].item_no, menu[i].name, order[i], menu[i].price*order[i]);
        }
    }
    printf("---------------------------------------------\n");
    printf("Total: $%.2f\n", calculate_total(menu, n, order));
    printf("---------------------------------------------\n");
}

float calculate_total(struct cafe menu[], int n, int order[]){
    float total=0;
    for(int i=0; i<n; i++){
        total+=menu[i].price*order[i];
    }
    return total;
}