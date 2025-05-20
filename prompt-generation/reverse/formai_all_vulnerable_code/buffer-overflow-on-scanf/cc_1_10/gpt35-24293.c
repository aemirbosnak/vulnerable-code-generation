//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char medicine[20];
    int quantity;
    float price;
} Inventory;

void welcome(){
    printf("Welcome to the C Medical Store Management System!\n");
    printf("In this surreal world, medicine will only be exchanged for your deepest fears...\n");
    printf("Just kidding, please browse our inventory below:\n");
}

void print_inventory(Inventory* inventory, int num_medicines){
    printf("===========================================\n");
    printf("|   Medicine   |   Quantity   |   Price   |\n");
    printf("===========================================\n");
    for(int i=0; i<num_medicines; i++){
        printf("| %12s | %12d | %8.2f |\n", inventory[i].medicine, inventory[i].quantity, inventory[i].price);
    }
    printf("===========================================\n");
}

void purchase(char* medicine, Inventory* inventory, int num_medicines){
    for(int i=0; i<num_medicines; i++){
        if(strcmp(medicine, inventory[i].medicine) == 0){
            if(inventory[i].quantity <= 0){
                printf("Sorry, we are out of stock for %s.\n", medicine);
                return;
            }else{
                printf("That will be %.2f nightmares please...\n", inventory[i].price);
                inventory[i].quantity--;
                return;
            }
        }
    }
    printf("Sorry, we do not carry %s.\n", medicine);
}

int main(){
    Inventory inventory[5];
    strcpy(inventory[0].medicine, "Morphine");
    inventory[0].quantity = 3;
    inventory[0].price = 666.13;

    strcpy(inventory[1].medicine, "Prozac");
    inventory[1].quantity = 8;
    inventory[1].price = 89.42;

    strcpy(inventory[2].medicine, "Xanax");
    inventory[2].quantity = 0;
    inventory[2].price = 777.77;

    strcpy(inventory[3].medicine, "Valium");
    inventory[3].quantity = 5;
    inventory[3].price = 1000.00;

    strcpy(inventory[4].medicine, "Zoloft");
    inventory[4].quantity = 2;
    inventory[4].price = 305.15;

    welcome();
    print_inventory(inventory, 5);
    char medicine_to_purchase[20];
    printf("Enter the name of the medicine you would like to purchase: ");
    scanf("%s", medicine_to_purchase);
    purchase(medicine_to_purchase, inventory, 5);

    return 0;
}