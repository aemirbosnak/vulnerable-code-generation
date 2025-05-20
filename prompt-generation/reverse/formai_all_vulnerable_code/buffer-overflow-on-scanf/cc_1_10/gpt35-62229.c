//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: Romeo and Juliet
// Romeo and Juliet Medical Store Management System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} medicine;

medicine meds[100];
int count = 0;

// Function to add medicine to the inventory
void add_medicine() {
    printf("Enter Medicine ID: ");
    scanf("%d", &meds[count].id);
    printf("Enter Medicine Name: ");
    scanf("%s", meds[count].name);
    printf("Enter Medicine Quantity: ");
    scanf("%d", &meds[count].quantity);
    printf("Enter Medicine Price: ");
    scanf("%f", &meds[count].price);
    
    printf("\nMedicine Added Successfully!\n");
    count++;
}

// Function to update medicine in the inventory
void update_medicine() {
    int id, found = 0;
    printf("Enter Medicine ID to update: ");
    scanf("%d", &id);
    
    for(int i = 0; i < count; i++) {
        if(meds[i].id == id) {
            printf("Enter New Quantity: ");
            scanf("%d", &meds[i].quantity);
            printf("Enter New Price: ");
            scanf("%f", &meds[i].price);
            found = 1;
            printf("\nMedicine Updated Successfully!\n");
            break;
        }
    }
    if(found == 0) {
        printf("\nMedicine not found!\n");
    }
}

// Function to delete medicine from the inventory
void delete_medicine() {
    int id, found = 0;
    printf("Enter Medicine ID to delete: ");
    scanf("%d", &id);
    
    for(int i = 0; i < count; i++) {
        if(meds[i].id == id) {
            for(int j = i; j < count-1; j++) {
                meds[j] = meds[j+1]; 
            }
            count--;
            found = 1;
            printf("\nMedicine Deleted Successfully!\n");
            break;
        }
    }
    if(found == 0) {
        printf("\nMedicine not found!\n");
    }
}

// Function to display all medicines in the inventory
void display_medicines() {
    printf("\nID\tName\tQuantity\tPrice\n");
    for(int i = 0; i < count; i++) {
        printf("%d\t%s\t%d\t\t%.2f\n", meds[i].id, meds[i].name, meds[i].quantity, meds[i].price);
    }
}

int main() {
    printf("Oh Romeo, thou needst some medicine?\n");
    while(1) {
        printf("What dost thou desire?\n1. Add Medicine\n2. Update Medicine\n3. Delete Medicine\n4. Display Medicines\n5. Exit\n");
        int choice;
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_medicine();
                break;
            case 2:
                update_medicine();
                break;
            case 3:
                delete_medicine();
                break;
            case 4:
                display_medicines();
                break;
            case 5:
                printf("Farewell, my love!\n");
                exit(0);
            default:
                printf("Invalid Choice! Try again, sweet Juliet!\n");
                break;
        }
    }
    return 0;
}