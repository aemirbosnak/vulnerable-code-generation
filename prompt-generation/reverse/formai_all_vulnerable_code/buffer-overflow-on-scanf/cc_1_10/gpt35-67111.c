//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: complex
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct order{
    int id;
    char name[20];
    int price;
    int quantity;
};

struct bill{
    int id;
    char name[20];
    int price;
    int quantity;
    int total_price;
};

int main(){
    printf("\t\tC Cafe Billing System\n");
    printf("==============================================================\n\n");
    
    struct order o[100];
    struct bill b[100];
    
    int i, j, n, id, temp = 0, total_bill = 0;
    char name[20];
    
    printf("Enter the number of items you want to order: ");
    scanf("%d", &n);
    
    for(i = 0; i < n; i++){
        printf("\nItem %d:\n", i+1);
        printf("Enter the item id: ");
        scanf("%d", &o[i].id);
        printf("Enter the item name: ");
        scanf("%s", o[i].name);
        printf("Enter the item price: ");
        scanf("%d", &o[i].price);
        printf("Enter the item quantity: ");
        scanf("%d", &o[i].quantity);
    }
    
    printf("\n");
    
    printf("==============================================================\n");
    printf("\t\t\t\tBILL\n");
    printf("==============================================================\n\n");
    printf("Item ID\t\tName\t\tPrice\t\tQty\t\tTotal Price\n");
    
    for(i = 0; i < n; i++){
        id = o[i].id;
        strcpy(name, o[i].name);
        
        for(j = 0; j < n-i-1; j++){
            if(o[j].id > o[j+1].id){
                temp = o[j].id; o[j].id = o[j+1].id; o[j+1].id = temp;
                strcpy(name, o[j].name); strcpy(o[j].name, o[j+1].name); strcpy(o[j+1].name, name);
                temp = o[j].price; o[j].price = o[j+1].price; o[j+1].price = temp;
                temp = o[j].quantity; o[j].quantity = o[j+1].quantity; o[j+1].quantity = temp;
            }
        }
        
        b[i].id = id;
        strcpy(b[i].name, name);
        b[i].price = o[i].price;
        b[i].quantity = o[i].quantity;
        b[i].total_price = b[i].price * b[i].quantity;
        
        printf("%d\t\t%s\t\t%d\t\t%d\t\t%d\n", b[i].id, b[i].name, b[i].price, b[i].quantity, b[i].total_price);
        total_bill += b[i].total_price;
    }
    
    printf("\n\t\t\t\t\tTotal Bill: %d\n", total_bill);
    
    return 0;
}