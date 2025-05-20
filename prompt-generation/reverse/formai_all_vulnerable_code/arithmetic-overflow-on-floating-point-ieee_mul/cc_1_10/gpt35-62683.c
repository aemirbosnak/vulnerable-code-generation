//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Linus Torvalds
#include<stdio.h>
#include<string.h>
struct medicine{
    char name[20];
    char brand[20];
    int quantity;
    float price;
};

int main(){
    printf("===Welcome to the Medical Store Management System===\n");

    // Initialize and display medicine inventory
    struct medicine inventory[5];
    strcpy(inventory[0].name, "Paracetamol");
    strcpy(inventory[0].brand, "Crocin");
    inventory[0].quantity = 15;
    inventory[0].price = 10.5;

    strcpy(inventory[1].name, "Ibuprofen");
    strcpy(inventory[1].brand, "Brufen");
    inventory[1].quantity = 20;
    inventory[1].price = 15.2;

    strcpy(inventory[2].name, "Aspirin");
    strcpy(inventory[2].brand, "Disprin");
    inventory[2].quantity = 10;
    inventory[2].price = 5.0;

    strcpy(inventory[3].name, "Anti-Biotic");
    strcpy(inventory[3].brand, "Amoxil");
    inventory[3].quantity = 4;
    inventory[3].price = 20.0;

    strcpy(inventory[4].name, "Cough Syrup");
    strcpy(inventory[4].brand, "Benadryl");
    inventory[4].quantity = 6;
    inventory[4].price = 25.0;

    printf("\nMedicine Inventory:\n");
    printf("=====================\n");
    for(int i=0; i<5; i++){
        printf("Name: %s \nBrand: %s \nQuantity: %d \nPrice: $%.2f \n\n", inventory[i].name, inventory[i].brand, inventory[i].quantity, inventory[i].price);
    }

    // Add new medicine
    struct medicine new_med;
    printf("\nAdding New Medicine:\n");
    printf("=====================\n");
    printf("Enter Name: ");
    scanf("%s", new_med.name);
    printf("Enter Brand: ");
    scanf("%s", new_med.brand);
    printf("Enter Quantity: ");
    scanf("%d", &new_med.quantity);
    printf("Enter Price: $");
    scanf("%f", &new_med.price);

    inventory[5] = new_med;

    printf("\nUpdated Medicine Inventory:\n");
    printf("============================\n");
    for(int i=0; i<6; i++){
        printf("Name: %s \nBrand: %s \nQuantity: %d \nPrice: $%.2f \n\n", inventory[i].name, inventory[i].brand, inventory[i].quantity, inventory[i].price);
    }

    // Search Medicine by Name
    char search_name[20];
    int found = 0;
    printf("\nSearch Medicine by Name:\n");
    printf("========================\n");
    printf("Enter Name to be searched: ");
    scanf("%s", search_name);
    for(int i=0; i<6; i++){
        if(strcmp(inventory[i].name, search_name)==0){
            printf("Name: %s \nBrand: %s \nQuantity: %d \nPrice: $%.2f \n\n", inventory[i].name, inventory[i].brand, inventory[i].quantity, inventory[i].price);
            found = 1;
            break;
        }
    }
    if(found==0){
        printf("Medicine not found.\n");
    }

    // Buy Medicine
    char buy_name[20];
    int buy_quantity;
    printf("\nBuy Medicine:\n");
    printf("=============\n");
    printf("Enter Name of Medicine to be bought: ");
    scanf("%s", buy_name);
    printf("Enter Quantity to be bought: ");
    scanf("%d", &buy_quantity);
    for(int i=0; i<6; i++){
        if(strcmp(inventory[i].name, buy_name)==0){
            if(inventory[i].quantity>=buy_quantity){
                inventory[i].quantity -= buy_quantity;
                printf("Total Cost: $%.2f\n", (buy_quantity*inventory[i].price));
                break;
            }
            else{
                printf("Insufficient Stock!\n");
            }
        }
    }

    printf("\nMedicine Inventory after Purchase:\n");
    printf("==================================\n");
    for(int i=0; i<6; i++){
        printf("Name: %s \nBrand: %s \nQuantity: %d \nPrice: $%.2f \n\n", inventory[i].name, inventory[i].brand, inventory[i].quantity, inventory[i].price);
    }

    return 0;
}