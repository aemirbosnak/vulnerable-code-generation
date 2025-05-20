//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_ITEMS 50 // Maximum items allowed to be ordered
#define MAX_NAME 20 // Maximum length for an item name
#define MAX_BILLINGS 100 // Maximum number of billings to store

// Function to print the menu options
void print_menu_options() {
    printf("\nMenu Options:\n");
    printf("1. Add item to order\n");
    printf("2. Remove item from order\n");
    printf("3. View current order\n");
    printf("4. View billing history\n");
    printf("5. Generate final bill\n");
    printf("6. Exit program\n");
    printf("\nSelect an option: ");
}

// Function to add an item to the current order
void add_item(char menu[][MAX_NAME], float price[], int order[], int quantity[]) {
    char item_name[MAX_NAME];
    int item_quantity, item_id;
    
    printf("\n--------Add Item--------\n");
    printf("\nEnter item name: ");
    scanf("%s", item_name);
    printf("Enter quantity: ");
    scanf("%d", &item_quantity);
    
    for(int i=0; i<MAX_ITEMS; i++) {
        if(strcmp(menu[i], item_name) == 0) {
            item_id = i;
            order[item_id]++;
            quantity[item_id] += item_quantity;
            printf("%s added to the order!\n", item_name);
            return;
        }
    }
    printf("Item not found.\n");
}

// Function to remove an item from the current order
void remove_item(char menu[][MAX_NAME], int order[], int quantity[]) {
    char item_name[MAX_NAME];
    int item_id;
    
    printf("\n------Remove Item-------\n");
    printf("Enter item name to remove: ");
    scanf("%s", item_name);
    
    for(int i=0; i<MAX_ITEMS; i++) {
        if(strcmp(menu[i], item_name) == 0) {
            item_id = i;
            if(order[item_id] == 0) {
                printf("Item not found in the order.\n");
                return;
            }
            order[item_id]--;
            printf("%s removed from the order!\n", item_name);
            return;
        }
    }
    printf("Item not found.\n");
}

// Function to view the current order
void view_order(char menu[][MAX_NAME], float price[], int order[], int quantity[]) {
    printf("\n--------Current Order--------\n");
    float total_price = 0.0;
    for(int i=0; i<MAX_ITEMS; i++) {
        if(order[i] > 0) {
            printf("%s x%d = %.2f\n", menu[i], quantity[i], price[i]*quantity[i]);
            total_price += price[i]*quantity[i];
        }
    }
    printf("Total price: %.2f\n", total_price);
}

// Function to view the billing history
void view_billing_history(char billing_history[][MAX_ITEMS][MAX_NAME], float billing_price[], int billing_quantity[], int billing_count) {
    printf("\n--------Billing History--------\n");
    for(int i=0; i<billing_count; i++) {
        printf("Billing %d:\n", i+1);
        for(int j=0; j<MAX_ITEMS; j++) {
            if(billing_quantity[i*MAX_ITEMS+j] > 0) {
                printf("%s x%d = %.2f\n", billing_history[i][j], billing_quantity[i*MAX_ITEMS+j], billing_price[i*MAX_ITEMS+j]);
            }
        }
    }
}

// Function to generate the final bill and add it to billing history
void generate_final_bill(char menu[][MAX_NAME], float price[], int order[], int quantity[], char billing_history[][MAX_ITEMS][MAX_NAME], float billing_price[], int billing_quantity[], int *billing_count) {
    printf("\n--------Final Bill--------\n");
    float total_price = 0.0;
    bool is_order_empty = true;
    
    // Check if the order is empty
    for(int i=0; i<MAX_ITEMS; i++) {
        if(order[i] > 0) {
            is_order_empty = false;
            break;
        }
    }
    if(is_order_empty) {
        printf("Order is empty. Cannot generate final bill.\n");
        return;
    }
    
    // Add items to billing history
    for(int i=0; i<MAX_ITEMS; i++) {
        if(order[i] > 0) {
            strcpy(billing_history[*billing_count][i], menu[i]);
            billing_quantity[(*billing_count)*MAX_ITEMS+i] = quantity[i];
            billing_price[(*billing_count)*MAX_ITEMS+i] = price[i]*quantity[i];
            total_price += billing_price[(*billing_count)*MAX_ITEMS+i];
        }
    }
    
    printf("Total price: %.2f\n", total_price);
    (*billing_count)++;
    // Reset the order and quantity arrays to zero
    memset(order, 0, sizeof(order));
    memset(quantity, 0, sizeof(quantity));
}

int main() {
    char menu[][MAX_NAME] = {"Coffee", "Tea", "Sandwich", "Burger", "Fries"};
    float price[] = {2.0, 1.5, 3.5, 4.0, 2.5};
    int order[MAX_ITEMS] = {0};
    int quantity[MAX_ITEMS] = {0};
    char billing_history[MAX_BILLINGS][MAX_ITEMS][MAX_NAME];
    float billing_price[MAX_BILLINGS*MAX_ITEMS] = {0.0};
    int billing_quantity[MAX_BILLINGS*MAX_ITEMS] = {0};
    int billing_count = 0;
    
    int option;
    do {
        print_menu_options();
        scanf("%d", &option);
        switch(option) {
            case 1: add_item(menu, price, order, quantity);
                    break;
            case 2: remove_item(menu, order, quantity);
                    break;
            case 3: view_order(menu, price, order, quantity);
                    break;
            case 4: view_billing_history(billing_history, billing_price, billing_quantity, billing_count);
                    break;
            case 5: generate_final_bill(menu, price, order, quantity, billing_history, billing_price, billing_quantity, &billing_count);
                    break;
            case 6: printf("\nExiting the program...\n");
                    exit(0);
            default: printf("Invalid option selected.\n");
        }
    } while(option != 6);
    return 0;
}