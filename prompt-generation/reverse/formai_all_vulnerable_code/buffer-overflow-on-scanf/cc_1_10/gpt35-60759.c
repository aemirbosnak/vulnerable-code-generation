//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[30];
    int quantity;
    float price;
} Medicine;

// function declarations
void add_medicine(Medicine *inventory, int *num_medicines);
void sell_medicine(Medicine *inventory, int *num_medicines);
void display_inventory(Medicine *inventory, int num_medicines);

int main(){
    Medicine inventory[100]; 
    int num_medicines = 0; 

    printf("Welcome to the Medical Store Management System\n");

    int choice; 
    do{
        printf("\nEnter your choice:\n");
        printf("1. Add medicine\n");
        printf("2. Sell medicine\n");
        printf("3. Display inventory\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch(choice){
            case 1: 
                add_medicine(inventory, &num_medicines);
                break;
            case 2: 
                sell_medicine(inventory, &num_medicines);
                break;
            case 3: 
                display_inventory(inventory, num_medicines);
                break;
            case 4: 
                printf("Thank you for using the Medical Store Management System\n");
                break;
            default: 
                printf("Invalid choice\n");
        }
    }while(choice != 4);

    return 0;
}

void add_medicine(Medicine *inventory, int *num_medicines){
    char name[30];
    int quantity;
    float price;

    printf("Enter name of medicine to add: ");
    scanf("%s", name);
    printf("Enter quantity of medicine to add: ");
    scanf("%d", &quantity);
    printf("Enter price of medicine to add: ");
    scanf("%f", &price);

    strcpy(inventory[*num_medicines].name, name);
    inventory[*num_medicines].quantity = quantity;
    inventory[*num_medicines].price = price;
    *num_medicines += 1;

    printf("Added %d units of %s with price %.2f to inventory\n", quantity, name, price);
}

void sell_medicine(Medicine *inventory, int *num_medicines){
    char name[30];
    int quantity;

    printf("Enter name of medicine to sell: ");
    scanf("%s", name);
    printf("Enter quantity of medicine to sell: ");
    scanf("%d", &quantity);

    for(int i=0; i<*num_medicines; i++){
        if(strcmp(inventory[i].name, name) == 0){
            if(quantity <= inventory[i].quantity){ 
                inventory[i].quantity -= quantity;
                printf("Sold %d units of %s for %.2f\n", quantity, name, inventory[i].price*quantity);
                return;
            }
            else{
                printf("Not enough quantity of %s in inventory\n", name);
                return;
            }
        }
    }
    
    printf("%s not found in inventory\n", name);
}

void display_inventory(Medicine *inventory, int num_medicines){
    printf("===Inventory===\n");
    for(int i=0; i<num_medicines; i++){
        printf("%s (%d):\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}