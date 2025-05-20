//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to check if a customer exists
int customerExists(int customerId, char* fileName) {
    FILE* fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Error: Could not open file\n");
        exit(0);
    }
    int id;
    char name[50];
    char address[50];
    while (fscanf(fp, "%d %s %s", &id, name, address) != EOF) {
        if (id == customerId) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

// Function to add a new customer
void addNewCustomer(int customerId, char* name, char* address, char* fileName) {
    FILE* fp = fopen(fileName, "a");
    if (fp == NULL) {
        printf("Error: Could not open file\n");
        exit(0);
    }
    fprintf(fp, "%d %s %s\n", customerId, name, address);
    fclose(fp);
    printf("New customer added successfully!\n");
}

// Function to display all customers
void displayAllCustomers(char* fileName) {
    FILE* fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Error: Could not open file\n");
        exit(0);
    }
    int id;
    char name[50];
    char address[50];
    printf("Customer ID\tName\t\tAddress\n");
    while (fscanf(fp, "%d %s %s", &id, name, address) != EOF) {
        printf("%d\t\t%s\t\t%s\n", id, name, address);
    }
    fclose(fp);
}

int main() {
    int customerId;
    char name[50];
    char address[50];
    int choice;
    char fileName[] = "customers.txt";

    while (1) {
        printf("1. Add a new customer\n");
        printf("2. Display all customers\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter customer ID: ");
            scanf("%d", &customerId);
            if (customerExists(customerId, fileName)) {
                printf("Customer with this ID already exists!\n");
            }
            else {
                printf("Enter customer name: ");
                scanf("%s", name);
                printf("Enter customer address: ");
                scanf("%s", address);
                addNewCustomer(customerId, name, address, fileName);
            }
            break;
        case 2:
            displayAllCustomers(fileName);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}