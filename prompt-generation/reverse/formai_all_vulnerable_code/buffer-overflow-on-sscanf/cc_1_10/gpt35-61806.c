//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX_ITEMS 50
#define ITEM_NAME_LEN 50
#define TAX_RATE 0.05 //5% tax rate

//item struct
typedef struct{
    char name[ITEM_NAME_LEN];
    float price;
    int qty;
} Item;

//function prototypes
void add_item(Item[], int*);
float calculate_total(Item[], int);
void display_items(Item[], int);

int main(){
    Item items[MAX_ITEMS]; //array to hold all items
    int num_items = 0; //number of items currently in the array
    char input[10];
    
    do{
        printf("\nWelcome to the Cafe Billing System!\n");
        printf("1. Add Item\n");
        printf("2. View Order\n");
        printf("3. Calculate Total\n");
        printf("4. Exit\n");
        printf("Enter option (1-4): ");
        fgets(input, 10, stdin);
        input[strcspn(input, "\n")] = '\0'; //remove trailing newline
        
        //convert input to int
        int option = 0;
        if(sscanf(input, "%d", &option) != 1){
            printf("Invalid option. Please enter a number between 1 and 4.\n");
            continue;
        }
        
        switch(option){
            case 1:
                add_item(items, &num_items);
                break;
            case 2:
                display_items(items, num_items);
                break;
            case 3:
                printf("Total: $%.2f\n", calculate_total(items, num_items));
                break;
            case 4:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please enter a number between 1 and 4.\n");
                break;
        }
    } while(1);
    
    return 0;
}

void add_item(Item items[], int* num_items){
    if(*num_items >= MAX_ITEMS){
        printf("Max number of items reached.\n");
        return;
    }
    
    Item new_item;
    printf("Enter item name: ");
    fgets(new_item.name, ITEM_NAME_LEN, stdin);
    new_item.name[strcspn(new_item.name, "\n")] = '\0'; //remove trailing newline
    printf("Enter price: ");
    char input[10];
    fgets(input, 10, stdin);
    float price = 0;
    if(sscanf(input, "%f", &price) != 1){
        printf("Invalid price. Please enter a number.\n");
        return;
    }
    new_item.price = price;
    printf("Enter quantity: ");
    fgets(input, 10, stdin);
    int qty = 0;
    if(sscanf(input, "%d", &qty) != 1){
        printf("Invalid quantity. Please enter a number.\n");
        return;
    }
    new_item.qty = qty;
    
    //add item to array
    items[*num_items] = new_item;
    *num_items += 1;
    
    printf("Item added successfully.\n");
}

float calculate_total(Item items[], int num_items){
    float subtotal = 0;
    for(int i = 0; i < num_items; i++){
        subtotal += (items[i].price * items[i].qty);
    }
    
    float total = subtotal + (subtotal * TAX_RATE);
    return total;
}

void display_items(Item items[], int num_items){
    printf("\nItems\n");
    printf("------\n");
    for(int i = 0; i < num_items; i++){
        printf("%s ($%.2f) x %d\n", items[i].name, items[i].price, items[i].qty);
    }
}