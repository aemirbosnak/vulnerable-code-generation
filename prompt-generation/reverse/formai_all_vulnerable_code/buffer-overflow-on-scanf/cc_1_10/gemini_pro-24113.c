//GEMINI-pro DATASET v1.0 Category: Medical Store Management System ; Style: energetic
// Welcome to the Pharmacy!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A seamless, efficient pharmacy management system

typedef struct {
    char name[50];
    char company[50];
    int quantity;
    float price;
} medicine;

medicine inventory[100];
int num_medicines = 0;

void add_medicine() {
    printf("\n** Add a Life-Saving Potion **\n");
    printf("Enter Medicine Name: ");
    scanf("%s", inventory[num_medicines].name);
    printf("Enter Medicine Company: ");
    scanf("%s", inventory[num_medicines].company);
    printf("Enter Medicine Quantity: ");
    scanf("%d", &inventory[num_medicines].quantity);
    printf("Enter Medicine Price: ");
    scanf("%f", &inventory[num_medicines].price);
    num_medicines++;
}

void display_inventory() {
    printf("\n** Our Magical Inventory **\n");
    for (int i = 0; i < num_medicines; i++) {
        printf("Medicine: %s\n", inventory[i].name);
        printf("Company: %s\n", inventory[i].company);
        printf("Quantity: %d\n", inventory[i].quantity);
        printf("Price: %.2f\n\n", inventory[i].price);
    }
}

void search_medicine() {
    char name[50];
    printf("\n** Find Your Remedy **\n");
    printf("Enter Medicine Name: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Medicine: %s\n", inventory[i].name);
            printf("Company: %s\n", inventory[i].company);
            printf("Quantity: %d\n", inventory[i].quantity);
            printf("Price: %.2f\n\n", inventory[i].price);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Medicine not found. Consult a doctor!\n");
    }
}

void update_medicine() {
    char name[50];
    printf("\n** Time for a Medicine Makeover **\n");
    printf("Enter Medicine Name: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Enter New Medicine Quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter New Medicine Price: ");
            scanf("%f", &inventory[i].price);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Medicine not found. Time to restock!\n");
    }
}

void delete_medicine() {
    char name[50];
    printf("\n** Say Goodbye to an Old Friend **\n");
    printf("Enter Medicine Name: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < num_medicines; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            for (int j = i + 1; j < num_medicines; j++) {
                inventory[j - 1] = inventory[j];
            }
            num_medicines--;
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Medicine not found. Time for a checkup!\n");
    }
}

int main() {
    int choice;
    
    printf("\nWelcome to the Pharmacy of Wonders!");
    printf("\n** Menu **\n");
    printf("1. Add a Medicine\n");
    printf("2. Display Inventory\n");
    printf("3. Search for a Medicine\n");
    printf("4. Update Medicine Details\n");
    printf("5. Delete a Medicine\n");
    printf("6. Exit\n");
    
    do {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                display_inventory();
                break;
            case 3:
                search_medicine();
                break;
            case 4:
                update_medicine();
                break;
            case 5:
                delete_medicine();
                break;
            case 6:
                printf("\nThank you for visiting! Get well soon!");
                break;
            default:
                printf("\nInvalid choice. Please try again.");
        }
    } while (choice != 6);
    
    return 0;
}