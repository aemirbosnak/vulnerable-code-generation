//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining the struct for medicine 
struct Medicine {
    char name[50];
    int quantity;
    float price;
};

// Global variables
struct Medicine all_medicines[100];  // Array of Medicine struct
int num_of_medicines = 0;  // Total number of medicines in the store

// Function to add a new medicine
void add_medicine() {
    printf("\nEnter name of medicine: ");
    scanf("%s", all_medicines[num_of_medicines].name);
    printf("Enter quantity of medicine: ");
    scanf("%d", &all_medicines[num_of_medicines].quantity);
    printf("Enter price of medicine: ");
    scanf("%f", &all_medicines[num_of_medicines].price);
    num_of_medicines++;
    printf("\nSuccessfully added medicine!\n");
}

// Function to search for a medicine by its name
void search_medicine() {
    char med_name[50];
    printf("\nEnter name of medicine to search: ");
    scanf("%s", med_name);
    for(int i = 0; i < num_of_medicines; i++) {
        if(strcmp(all_medicines[i].name, med_name) == 0) {
            printf("Medicine found!\nName: %s\nQuantity: %d\nPrice: %.2f\n", 
                    all_medicines[i].name, all_medicines[i].quantity, all_medicines[i].price);
            return;
        }
    }
    printf("\nMedicine not found.\n");
}

// Function to display all medicines in the store
void display_all_medicines() {
    printf("\nTotal number of medicines: %d\n\n", num_of_medicines);
    for(int i = 0; i < num_of_medicines; i++) {
        printf("Medicine %d:\nName: %s\nQuantity: %d\nPrice: %.2f\n", 
                i+1, all_medicines[i].name, all_medicines[i].quantity, all_medicines[i].price);
    }
}

// Main function to run the program
int main() {
    printf("Welcome to the C Medical Store Management System!\n");
    char input[20];
    while(1) {
        printf("\nEnter your choice:\n1. Add a medicine\n2. Search for a medicine\n3. Display all medicines\n4. Exit\n");
        scanf("%s", input);
        if(strcmp(input, "1") == 0) {
            add_medicine();
        }
        else if(strcmp(input, "2") == 0) {
            search_medicine();
        }
        else if(strcmp(input, "3") == 0) {
            display_all_medicines();
        }
        else if(strcmp(input, "4") == 0) {
            printf("\nThank you for using C Medical Store Management System!\n");
            exit(0);
        }
        else {
            printf("\nInvalid input! Please try again.\n");
        }
    }
    return 0;
}