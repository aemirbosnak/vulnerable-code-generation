//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct of the Cafe Billing System
typedef struct CafeBillingSystem {
    char food_name[50];
    int quantity;
    double price;
    double total_price;
} CBS;

// Function to calculate the total price of a single item
double calculateTotalPrice(double price, int quantity){
    return price * quantity;
}

int main(){
    CBS cbs[10];
    
    int choice; // user's choice of action
    int itemCount = 0; // number of items in the system
    double totalAmount = 0; // total amount of all the items
    
    while(1){
        printf("\nWelcome to Cafe Billing System\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Show Items\n");
        printf("4. Checkout\n");
        printf("5. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if(choice == 1){
            if(itemCount > 9){
                printf("Sorry, the system can only store up to 10 items.\n");
                continue;
            }
            
            char temp_food_name[50];
            printf("Enter the name of the food: ");
            scanf("%s", temp_food_name);
            strcpy(cbs[itemCount].food_name, temp_food_name);
            
            printf("Enter the quantity: ");
            scanf("%d", &cbs[itemCount].quantity);
            
            printf("Enter the price per unit: ");
            scanf("%lf", &cbs[itemCount].price);
            
            cbs[itemCount].total_price = calculateTotalPrice(cbs[itemCount].price, cbs[itemCount].quantity);
            
            totalAmount += cbs[itemCount].total_price;
            itemCount++;
            
            printf("Item Added Successfully.\n");
        } else if(choice == 2){
            char temp_food_name[50];
            printf("Enter the name of the food you want to remove: ");
            scanf("%s", temp_food_name);
            
            int index_to_remove = -1;
            
            for(int i = 0; i < itemCount; i++){
                if(strcmp(cbs[i].food_name, temp_food_name) == 0){
                    index_to_remove = i;
                    break;
                }
            }
            
            if(index_to_remove == -1){
                printf("Item not found to remove.\n");
            } else {
                totalAmount -= cbs[index_to_remove].total_price;
                for(int i = index_to_remove; i < itemCount; i++){
                    cbs[i] = cbs[i+1];
                }
                itemCount--;
                printf("Item removed successfully.\n");
            }
        } else if(choice == 3){
            if(itemCount == 0){
                printf("No items have been added yet.\n");
            } else {
                printf("Items in the Billing System:\n");
                printf("|%-50s | %-10s | %-10s | %-10s |\n", "Food Name", "Quantity", "Price", "Total Price");
                for(int i = 0; i < itemCount; i++){
                    printf("|%-50s | %-10d | %-10.2lf | %-10.2lf |\n", cbs[i].food_name, cbs[i].quantity, cbs[i].price, cbs[i].total_price);
                }
                printf("Total Amount: %-10.2lf\n", totalAmount);
            }
        } else if(choice == 4){
            printf("Total Amount to be paid is: %.2lf\n", totalAmount);
            printf("Thank you for using our Cafe Billing System.\n");
            break;
        } else if(choice == 5){
            printf("Exiting Cafe Billing System...\n");
            break;
        } else {
            printf("Invalid Choice.\n");
        }
    }
    
    return 0;
}