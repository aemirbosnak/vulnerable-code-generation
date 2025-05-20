//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Romeo and Juliet
/* Romeo and Juliet style Warehouse Management System */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// A struct to store the warehouse item details
struct item {
    char name[100];
    int quantity;
};

// A function to add items to the warehouse
void add_item(struct item inventory[], int size) {
    char name[100];
    int quantity;
    
    printf("My bounty is as boundless as the sea,\n");
    printf("My love as deep; the more I give to thee,\n");
    printf("The more I have, for both are infinite.\n");
    printf("What is the item's name to add into our warehouse?\n");
    scanf("%s", name);
    
    for(int i=0; i<size; i++) {
        if(strcmp(inventory[i].name, name) == 0) {
            printf("O, swear not by the moon, th' inconstant moon,\n");
            printf("That monthly changes in her circled orb,\n");
            printf("Lest we confuse it with another item with the same name.\n");
            return;
        }
    }
    
    printf("What's in a name? That which we call a rose,\n");
    printf("By any other name would smell as sweet;\n");
    printf("We shall add it to our warehouse.\n");
    printf("How many of this item is being added?\n");
    scanf("%d", &quantity);
    
    for(int i=0; i<size; i++) {
        if(inventory[i].quantity == 0) {
            strcpy(inventory[i].name, name);
            inventory[i].quantity += quantity;
            return;
        }
    }
    
    printf("My only love sprung from my only hate!\n");
    printf("Too early seen unknown, and known too late!\n");
    printf("The warehouse is full, we cannot add more items.\n");
}

// A function to remove items from the warehouse
void remove_item(struct item inventory[], int size) {
    char name[100];
    int quantity;
    
    printf("Good night, good night! Parting is such sweet sorrow,\n");
    printf("That I shall say good night till it be morrow.\n");
    printf("What is the item's name to remove from our warehouse?\n");
    scanf("%s", name);
    
    for(int i=0; i<size; i++) {
        if(strcmp(inventory[i].name, name) == 0) {
            printf("These violent delights have violent ends,\n");
            printf("And in their triumph die, like fire and powder,\n");
            printf("We shall remove it from our warehouse.\n");
            printf("How many of this item is being removed?\n");
            scanf("%d", &quantity);
            if(inventory[i].quantity < quantity) {
                printf("My dismal scene I needs must act alone.\n");
                printf("The quantity requested to remove exceeds the quantity available.\n");
                return;
            }
            inventory[i].quantity -= quantity;
            if(inventory[i].quantity == 0) {
                strcpy(inventory[i].name, "");
            }
            return;
        }
    }
    
    printf("A plague o' both your houses!\n");
    printf("The item is not available in our warehouse.\n");
}

// A function to display the current inventory
void display_inventory(struct item inventory[], int size) {
    printf("My mistress' eyes are nothing like the sun;\n");
    printf("Coral is far more red than her lips' red;\n");
    printf("We currently have these items in our warehouse:\n");
    
    for(int i=0; i<size; i++) {
        if(inventory[i].quantity != 0) {
            printf("%s - %d\n", inventory[i].name, inventory[i].quantity);
        }
    }
}

// The main function
int main() {
    struct item inventory[50];
    int choice, size=50;
    printf("What's in a name? That which we call a rose,\n");
    printf("By any other name would smell as sweet;\n");
    printf("Welcome to our Warehouse Management System!\n");
    
    while(1) {
        printf("\nPlease choose an option:\n");
        printf("1. Add item\n2. Remove item\n3. Display inventory\n4. Exit\n");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_item(inventory, size);
                break;
            case 2:
                remove_item(inventory, size);
                break;
            case 3:
                display_inventory(inventory, size);
                break;
            case 4:
                printf("Parting is such sweet sorrow,\n");
                printf("That I shall say good night till it be morrow.\n");
                exit(0);
            default:
                printf("What's in a name? That which we call a rose,\n");
                printf("By any other name would smell as sweet;\n");
                printf("You have made an invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}