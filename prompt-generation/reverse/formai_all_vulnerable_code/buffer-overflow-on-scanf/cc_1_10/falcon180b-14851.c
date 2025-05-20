//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ITEMS 50
#define MAX_QUANTITY 10
#define MAX_NAME_SIZE 30
#define MAX_PRICE 10000

typedef struct {
    char name[MAX_NAME_SIZE];
    int quantity;
    float price;
}Item;

void print_item(Item item);
float calculate_total(Item items[], int num_items);

int main() {
    int num_items;
    printf("Enter number of items: ");
    scanf("%d",&num_items);

    Item items[num_items];

    for(int i=0;i<num_items;i++) {
        printf("Enter name of item %d: ",i+1);
        scanf("%s",items[i].name);

        printf("Enter quantity of item %d: ",i+1);
        scanf("%d",&items[i].quantity);

        printf("Enter price of item %d: ",i+1);
        scanf("%f",&items[i].price);
    }

    printf("Total cost: $%.2f\n",calculate_total(items,num_items));

    return 0;
}

void print_item(Item item) {
    printf("%s - %d units - $%.2f\n",item.name,item.quantity,item.price);
}

float calculate_total(Item items[], int num_items) {
    if(num_items == 0) {
        return 0;
    } else {
        return items[0].price * items[0].quantity + calculate_total(items+1,num_items-1);
    }
}