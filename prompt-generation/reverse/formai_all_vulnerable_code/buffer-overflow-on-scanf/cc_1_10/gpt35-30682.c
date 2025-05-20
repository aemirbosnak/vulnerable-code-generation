//FormAI DATASET v1.0 Category: Banking Record System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[30];
    char address[50];
    char phone[15];
    float balance;
} Customer;

void display_menu();
void add_customer();
void search_customer();
void delete_customer();
void print_records();

Customer customers[100];
int count = 0;

int main() {
    int choice;

    do {
        display_menu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_customer();
                break;
            case 2:
                search_customer();
                break;
            case 3:
                delete_customer();
                break;
            case 4:
                print_records();
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while(choice != 0);

    return 0;
}

void display_menu() {
    printf("\n\n**** Bank Records Management System ****\n\n");
    printf("1. Add Customer Records.\n");
    printf("2. Search Customer Records.\n");
    printf("3. Delete Customer Records.\n");
    printf("4. Print All Customer Records.\n");
    printf("0. Exit Program.\n");
    printf("\nEnter your choice: ");
}

void add_customer() {
    Customer new_customer;
    printf("\n\n**** Adding New Customer Record ****\n\n");
    printf("Enter customer name: ");
    scanf("%s", new_customer.name);
    printf("Enter customer address: ");
    scanf("%s", new_customer.address);
    printf("Enter customer phone number: ");
    scanf("%s", new_customer.phone);
    printf("Enter customer balance: ");
    scanf("%f", &new_customer.balance);
    customers[count++] = new_customer;
    printf("\nRecord added successfully.\n");
}

void search_customer() {
    char search_name[30];
    printf("\n\n**** Searching Customer Records ****\n\n");
    printf("Enter customer name to search: ");
    scanf("%s", search_name);
    for(int i=0;i<count;i++) {
        if(strcmp(search_name, customers[i].name) == 0) {
            printf("\nRecord found.\n");
            printf("Name\tAddress\t\tPhone\t\tBalance\n");
            printf("%s\t%s\t%s\t%.2f\n", customers[i].name, customers[i].address, customers[i].phone, customers[i].balance);
            break;
        }
        if(i == count-1) {
            printf("\nRecord not found.\n");
        }
    }
}

void delete_customer() {
    char search_name[30];
    printf("\n\n**** Deleting Customer Records ****\n\n");
    printf("Enter customer name to delete: ");
    scanf("%s", search_name);
    for(int i=0;i<count;i++) {
        if(strcmp(search_name, customers[i].name) == 0) {
            for(int j=i;j<count-1;j++) {
                customers[j] = customers[j+1];
            }
            count--;
            printf("\nRecord deleted successfully.\n");
            return;
        }
        if(i == count-1) {
            printf("\nRecord not found.\n");
        }
    }
}

void print_records() {
    printf("\n\n**** Printing All Customer Records ****\n\n");
    printf("Name\tAddress\t\tPhone\t\tBalance\n");
    for(int i=0;i<count;i++) {
        printf("%s\t%s\t%s\t%.2f\n", customers[i].name, customers[i].address, customers[i].phone, customers[i].balance);
    }
}