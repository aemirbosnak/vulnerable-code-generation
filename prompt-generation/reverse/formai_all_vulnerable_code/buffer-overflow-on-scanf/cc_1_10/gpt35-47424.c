//FormAI DATASET v1.0 Category: Hotel Management System ; Style: standalone
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define max 100

struct customer {
    char name[20];
    int room_number;
    char contact[15];
    float bill;
};

struct customer customers[max];
int count = 0;

void add_customer() {
    if (count >= max) {
        printf("Can't add more customers!\n");
        return;
    }
    struct customer new_customer;
    printf("Enter customer name: ");
    scanf("%s", new_customer.name);
    printf("Enter room number: ");
    scanf("%d", &new_customer.room_number);
    printf("Enter contact number: ");
    scanf("%s", new_customer.contact);
    new_customer.bill = 0;
    customers[count++] = new_customer;
    printf("Customer added successfully!\n");
}

void display_customer(struct customer c) {
    printf("Name: %s\n", c.name);
    printf("Room Number: %d\n", c.room_number);
    printf("Contact: %s\n", c.contact);
    printf("Current Bill: %f\n", c.bill);
}

void display_customers() {
    if (count == 0) {
        printf("No customers found!\n");
        return;
    }
    int i;
    for (i = 0; i < count; i++) {
        printf("Customer %d\n", i+1);
        display_customer(customers[i]);
        printf("\n");
    }
}

void update_bill() {
    int room_num, i;
    float new_bill;
    printf("Enter room number: ");
    scanf("%d", &room_num);
    for (i = 0; i < count; i++) {
        if (customers[i].room_number == room_num) {
            printf("Enter new bill amount: ");
            scanf("%f", &new_bill);
            customers[i].bill = new_bill;
            printf("Bill updated successfully!\n");
            return;
        }
    }
    printf("Customer not found!\n");
}

void delete_customer() {
    int room_num, i, flag = 0;
    printf("Enter room number: ");
    scanf("%d", &room_num);
    for (i = 0; i < count; i++) {
        if (customers[i].room_number == room_num) {
            flag = 1;
            break;
        }
    }
    if (flag == 1) {
        for (i = i; i < count-1; i++)
            customers[i] = customers[i+1];
        count--;
        printf("Customer deleted successfully!\n");
    }
    else
        printf("Customer not found!\n");
}

int main() {
    int option;
    while (1) {
        printf("Enter 1 to add customer\n");
        printf("Enter 2 to display all customers\n");
        printf("Enter 3 to update bill amount\n");
        printf("Enter 4 to delete customer\n");
        printf("Enter 0 to exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        switch(option) {
            case 1:
                add_customer();
                break;
            case 2:
                display_customers();
                break;
            case 3:
                update_bill();
                break;
            case 4:
                delete_customer();
                break;
            case 0:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid option!\n");
        }
    }
    return 0;
}