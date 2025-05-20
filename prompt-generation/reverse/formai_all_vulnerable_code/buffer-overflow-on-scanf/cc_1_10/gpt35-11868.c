//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000

// Structure for Item
struct Item {
    char id[10];
    char name[100];
    int quantity;
    float price;
}items[MAX];

// Function to Add Item to Warehouse
void addItem(int *count) {
    // Check limit for Items in Warehouse
    if(*count == MAX) {
        printf("Warehouse Full! Cannot Add any More Items\n");
        return;
    }
    printf("Enter Item ID: ");
    scanf("%s", items[*count].id);
    printf("Enter Item Name: ");
    scanf("%s", items[*count].name);
    printf("Enter Item Quantity: ");
    scanf("%d", &items[*count].quantity);
    printf("Enter Item Price: ");
    scanf("%f", &items[*count].price);
    printf("Item Added to Warehouse Successfully!\n");
    *count += 1;
}

// Function to Remove Item from Warehouse
void removeItem(int *count, char *id) {
    int found = 0;
    for(int i=0; i<*count; i++) {
        if(strcmp(items[i].id, id) == 0) {
            found = 1;
            *count -= 1;
            for(int j=i; j<*count; j++) {
                strcpy(items[j].id, items[j+1].id);
                strcpy(items[j].name, items[j+1].name);
                items[j].quantity = items[j+1].quantity;
                items[j].price = items[j+1].price;
            }
            printf("Item with ID %s Removed from Warehouse Successfully!\n", id);
            break;
        }
    }
    if(!found) {
        printf("No Item with ID %s Found in Warehouse\n", id);
    }
}

// Function to Display Items in Warehouse
void displayItems(int count) {
    printf("ID\tName\tQuantity\tPrice\n");
    printf("------------------------------------------------------\n");
    for(int i=0; i<count; i++) {
        printf("%s\t%s\t%d\t\t%.2f\n", items[i].id, items[i].name, items[i].quantity, items[i].price);
    }
}

int main() {
    printf("********************* Warehouse Management System *********************\n");
    int count = 0;
    while(1) {
        printf("----------------------------------------------------------------------------\n");
        printf("1. Add Item\n2. Remove Item by ID\n3. Display All Items\n4. Exit\nEnter Choice: ");
        int choice;
        scanf("%d", &choice);
        printf("----------------------------------------------------------------------------\n");
        switch(choice) {
            case 1: addItem(&count);
                    break;
            case 2: {
                    char id[10];
                    printf("Enter Item ID: ");
                    scanf("%s", id);
                    removeItem(&count, id);
                    break;
            }
            case 3: displayItems(count);
                    break;
            case 4: printf("Exiting System!\n");
                    exit(0);
            default: printf("Invalid Input! Please Try Again\n");
        }
    }
    return 0;
}