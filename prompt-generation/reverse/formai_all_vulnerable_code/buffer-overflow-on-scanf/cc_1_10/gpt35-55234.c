//FormAI DATASET v1.0 Category: Hotel Management System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure Definition
struct customer {
    char name[50], address[50], phone[15];
    int room_no, days;
    float total_amt;
};

// Function to Calculate the Total Bill for the Customer
float calculate_bill(int room_no, int days) {
    float rate_per_day;
    if (room_no >= 101 && room_no <= 110) {
        rate_per_day = 2000;
    } else if (room_no >= 111 && room_no <= 120) {
        rate_per_day = 2500;
    } else {
        rate_per_day = 3000;
    }
    return rate_per_day * (float) days;
}

// Function to Add a New Customer Record
void add_customer(struct customer *c, int n) {
    printf("Enter the following details:\n");
    printf("Name: ");
    scanf("%s", c[n].name);
    printf("Address: ");
    scanf("%s", c[n].address);
    printf("Phone Number: ");
    scanf("%s", c[n].phone);
    printf("Room Number: ");
    scanf("%d", &c[n].room_no);
    printf("Number of Days: ");
    scanf("%d", &c[n].days);
    c[n].total_amt = calculate_bill(c[n].room_no, c[n].days);
    printf("Customer Record Added Successfully!\n");
}

// Function to Display Existing Customer Records
void display_customers(struct customer *c, int n) {
    printf("CUSTOMER DETAILS:\n");
    for (int i = 0; i < n; i++) {
        printf("Customer %d:\n", i+1);
        printf("Name: %s\n", c[i].name);
        printf("Address: %s\n", c[i].address);
        printf("Phone Number: %s\n", c[i].phone);
        printf("Room Number: %d\n", c[i].room_no);
        printf("Number of Days: %d\n", c[i].days);
        printf("Total Amount: %.2f\n", c[i].total_amt);
    }
}

int main() {
    struct customer c[50];
    int num_customers = 0, option;
    while (1) {
        printf("\n\t====== HOTEL MANAGEMENT SYSTEM ======\n\n");
        printf("\t1. Add New Customer\n");
        printf("\t2. Display Existing Customers\n");
        printf("\t3. Exit\n");
        printf("\tChoose an option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                add_customer(c, num_customers);
                num_customers++;
                break;
            case 2:
                display_customers(c, num_customers);
                break;
            case 3:
                printf("Thank You for using the Hotel Management System.\n");
                exit(0);
            default:
                printf("Invalid Option. Please choose a valid option.\n");
        }
    }
    return 0;
}