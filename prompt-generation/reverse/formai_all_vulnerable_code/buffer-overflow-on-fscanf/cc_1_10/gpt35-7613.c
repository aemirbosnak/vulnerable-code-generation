//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to add a new medicine to the inventory
void add_medicine(char name[50], int quantity, float price) {
    FILE *fptr;
    fptr = fopen("medicine.txt", "a"); // Append mode
    fprintf(fptr, "%s %d %.2f\n", name, quantity, price);
    fclose(fptr);
}

// Function to search for a medicine in the inventory
void search_medicine(char search[50]) {
    FILE *fptr;
    fptr = fopen("medicine.txt", "r");
    char name[50];
    int quantity;
    float price;
    int found = 0; // flag variable to indicate if medicine is found
    while(fscanf(fptr, "%s %d %f", name, &quantity, &price) != EOF) {
        if(strcmp(search, name) == 0) {
            printf("Medicine name: %s\nQuantity: %d\nPrice: %.2f\n", name, quantity, price);
            found = 1;
            break;
        }
    }
    if(found == 0) {
        printf("Medicine not found.\n");
    }
    fclose(fptr);
}

// Function to update the quantity of a medicine in the inventory
void update_quantity(char name[50], int new_quantity) {
    FILE *fptr, *temp;
    fptr = fopen("medicine.txt", "r");
    temp = fopen("temp.txt", "w");
    char medicine_name[50];
    int quantity;
    float price;
    while(fscanf(fptr, "%s %d %f", medicine_name, &quantity, &price) != EOF) {
        if(strcmp(name, medicine_name) == 0) {
            fprintf(temp, "%s %d %.2f\n", name, new_quantity, price);
        } else {
            fprintf(temp, "%s %d %.2f\n", medicine_name, quantity, price);
        }
    }
    fclose(fptr);
    fclose(temp);
    remove("medicine.txt");
    rename("temp.txt", "medicine.txt");
}

// Function to update the price of a medicine in the inventory
void update_price(char name[50], float new_price) {
    FILE *fptr, *temp;
    fptr = fopen("medicine.txt", "r");
    temp = fopen("temp.txt", "w");
    char medicine_name[50];
    int quantity;
    float price;
    while(fscanf(fptr, "%s %d %f", medicine_name, &quantity, &price) != EOF) {
        if(strcmp(name, medicine_name) == 0) {
            fprintf(temp, "%s %d %.2f\n", name, quantity, new_price);
        } else {
            fprintf(temp, "%s %d %.2f\n", medicine_name, quantity, price);
        }
    }
    fclose(fptr);
    fclose(temp);
    remove("medicine.txt");
    rename("temp.txt", "medicine.txt");
}

// Main function to run the program
int main() {
    int choice, quantity;
    float price;
    char name[50], search[50];
    printf("Welcome to Medical Store Management System.\n");
    do {
        printf("1. Add medicine to inventory.\n");
        printf("2. Search for a medicine from inventory.\n");
        printf("3. Update medicine quantity in inventory.\n");
        printf("4. Update medicine price in inventory.\n");
        printf("5. Exit program.\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter medicine name: ");
                scanf("%s", name);
                printf("Enter medicine quantity: ");
                scanf("%d", &quantity);
                printf("Enter medicine price: ");
                scanf("%f", &price);
                add_medicine(name, quantity, price);
                printf("Medicine added to inventory successfully.\n");
                break;
            case 2:
                printf("Enter medicine name to search: ");
                scanf("%s", search);
                search_medicine(search);
                break;
            case 3:
                printf("Enter medicine name: ");
                scanf("%s", name);
                printf("Enter new quantity: ");
                scanf("%d", &quantity);
                update_quantity(name, quantity);
                printf("Medicine quantity updated successfully.\n");
                break;
            case 4:
                printf("Enter medicine name: ");
                scanf("%s", name);
                printf("Enter new price: ");
                scanf("%f", &price);
                update_price(name, price);
                printf("Medicine price updated successfully.\n");
                break;
            case 5:
                printf("Exiting program...");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while(choice != 5);
    return 0;
}