//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Romeo and Juliet
// Romeo and Juliet - A Medical Store Management System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items that can be stored in the inventory
#define MAX_ITEMS 100

// Define a structure to represent an item in the inventory
struct item {
    char name[100];
    int quantity;
    float price;
};

// Declare global variables for the inventory and the current number of items
struct item inventory[MAX_ITEMS];
int num_items = 0;

// Declare function prototypes
void add_item();
void remove_item();
void view_inventory();
void search_item();
void error_message();

int main() {
    int choice;
    
    // Print a welcoming message
    printf("\n\nOh, my heart beats with hope when I see thee, my dear customer!\n");
    printf("What would you like me to do for you today?\n\n");
    
    while(1) {
        // Print the menu options and get the user's choice
        printf("1. Add item to inventory\n");
        printf("2. Remove item from inventory\n");
        printf("3. View inventory\n");
        printf("4. Search for item\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        // Call the appropriate function based on the user's choice
        switch(choice) {
            case 1:
                add_item();
                break;
            case 2:
                remove_item();
                break;
            case 3:
                view_inventory();
                break;
            case 4:
                search_item();
                break;
            case 5:
                printf("\nGood night, good night! Parting is such sweet sorrow\n");
                printf("That I shall say good night till it be morrow.\n\n");
                exit(0);
            default:
                error_message();
        }
    }
    
    return 0;
}

void add_item() {
    // Check if the inventory is already full
    if(num_items == MAX_ITEMS) {
        printf("\nMy bounty is as boundless as the sea,\n");
        printf("My love as deep; the more I give to thee,\n");
        printf("The more I have, for both are infinite.\n");
        return;
    }
    
    // Get the details of the new item from the user
    printf("\nWhat's in a name? That which we call a rose\n");
    printf("By any other name would smell as sweet.\n");
    printf("Enter the name of the item: ");
    scanf("%s", inventory[num_items].name);
    printf("Enter the quantity: ");
    scanf("%d", &inventory[num_items].quantity);
    printf("Enter the price per unit: ");
    scanf("%f", &inventory[num_items].price);
    printf("\nI take thee at thy word:\n");
    printf("Call me but love, and I'll be new baptized;\n");
    printf("Henceforth I never will be Romeo.\n");
    
    // Increase the number of items in the inventory
    num_items++;
}

void remove_item() {
    char name[100];
    int i, index = -1;
    
    // Get the name of the item to be removed from the user
    printf("\nWhat’s Montague? it is nor hand, nor foot,\n");
    printf("Nor arm, nor face, nor any other part\n");
    printf("Belonging to a man. O, be some other name!\n");
    printf("Enter the name of the item: ");
    scanf("%s", name);
    
    // Find the index of the item in the inventory, if it exists
    for(i = 0; i < num_items; i++) {
        if(strcmp(name, inventory[i].name) == 0) {
            index = i;
            break;
        }
    }
    
    if(index == -1) {
        // The item was not found in the inventory
        printf("\nDid my heart love till now? forswear it, sight!\n");
        printf("For I ne'er saw true beauty till this night.\n");
    } else {
        // Remove the item from the inventory and shift the remaining items up
        printf("\nSee, how she leans her cheek upon her hand!\n");
        printf("O, that I were a glove upon that hand,\n");
        printf("That I might touch that cheek!\n");
        for(i = index; i < num_items - 1; i++) {
            inventory[i] = inventory[i+1];
        }
        num_items--;
        printf("\nO Romeo, Romeo! wherefore art thou Romeo?\n");
        printf("Deny thy father and refuse thy name;\n");
        printf("Or, if thou wilt not, be but sworn my love,\n");
        printf("And I'll no longer be a Capulet.\n");
    }
}

void view_inventory() {
    int i;
    
    // Print the header for the inventory table
    printf("\nWhat light through yonder window breaks?\n");
    printf("It is the east, and Juliet is the sun.\n");
    printf("%-25s %-15s %-15s\n", "Item name", "Quantity", "Price per unit");
    
    // Print each item in the inventory
    for(i = 0; i < num_items; i++) {
        printf("%-25s %-15d %-15.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void search_item() {
    char name[100];
    int i, found = 0;
    
    // Get the name of the item to be searched for from the user
    printf("\nFor thou wilt lie upon the wings of night,\n");
    printf("Whiter than new snow on a raven’s back.\n");
    printf("Enter the name of the item: ");
    scanf("%s", name);
    
    // Find the index of the item in the inventory, if it exists
    for(i = 0; i < num_items; i++) {
        if(strcmp(name, inventory[i].name) == 0) {
            found = 1;
            printf("\nMy bounty is as boundless as the sea,\n");
            printf("My love as deep; the more I give to thee,\n");
            printf("The more I have, for both are infinite.\n");
            printf("Item name: %s\n", inventory[i].name);
            printf("Quantity: %d\n", inventory[i].quantity);
            printf("Price per unit: %.2f\n", inventory[i].price);
            break;
        }
    }
    
    if(!found) {
        // The item was not found in the inventory
        printf("\nAlas, that love, whose view is muffled still,\n");
        printf("Should, without eyes, see pathways to his will!\n");
    }
}

void error_message() {
    printf("\nGood night, good night! parting is such\n");
    printf("Sweet sorrow, that I shall say good night\n");
    printf("Till it be morrow.\n");
    printf("Please enter a valid choice.\n");
}