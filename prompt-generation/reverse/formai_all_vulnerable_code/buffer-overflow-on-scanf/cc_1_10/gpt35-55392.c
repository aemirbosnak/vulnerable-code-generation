//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure for medicine information
struct medicine {
    char name[30];
    int quantity;
    float price;
};

// Global variable for store inventory
struct medicine store[50];

// Function to add medicine to the inventory
void add_medicine(int index) {
    printf("Enter medicine name: ");
    scanf("%s", store[index].name);
    printf("Enter quantity: ");
    scanf("%d", &store[index].quantity);
    printf("Enter price: ");
    scanf("%f", &store[index].price);
    printf("Medicine added successfully!\n");
}

// Function to update existing medicine in the inventory
void update_medicine(int index) {
    printf("Enter new quantity: ");
    scanf("%d", &store[index].quantity);
    printf("Enter new price: ");
    scanf("%f", &store[index].price);
    printf("Medicine updated successfully!\n");
}

// Function to delete medicine from the inventory
void delete_medicine(int index) {
    strcpy(store[index].name, "");
    store[index].quantity = 0;
    store[index].price = 0;
    printf("Medicine deleted successfully!\n");
}

// Function to search for medicine by name
void search_by_name(char name[]) {
    int found = 0;
    for(int i=0; i<50; i++) {
        if(strcmp(store[i].name, name) == 0) {
            printf("Name: %s | Quantity: %d | Price: %f\n", store[i].name, store[i].quantity, store[i].price);
            found = 1;
        }
    }
    if(!found) {
        printf("Medicine not found!\n");
    }
}

int main() {
    int choice, index = 0;
    char name[30];
    // Menu driven program
    while(1) {
        printf("\nMENU\n");
        printf("1. Add medicine\n");
        printf("2. Update medicine\n");
        printf("3. Delete medicine\n");
        printf("4. Search medicine by name\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_medicine(index);
                index++;
                break;
            case 2:
                printf("Enter medicine name to update: ");
                scanf("%s", name);
                for(int i=0; i<50; i++) {
                    if(strcmp(store[i].name, name) == 0) {
                        update_medicine(i);
                    }
                }
                break;
            case 3:
                printf("Enter medicine name to delete: ");
                scanf("%s", name);
                for(int i=0; i<50; i++) {
                    if(strcmp(store[i].name, name) == 0) {
                        delete_medicine(i);
                    }
                }
                break;
            case 4:
                printf("Enter medicine name to search: ");
                scanf("%s", name);
                search_by_name(name);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }  
    return 0;
}