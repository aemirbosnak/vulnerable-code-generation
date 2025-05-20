//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_CUSTOMERS 100

typedef struct {
    int room_number;
    char *customer_name;
    char *check_in_date;
    char *check_out_date;
    float bill_amount;
} room_info;

typedef struct {
    int customer_id;
    char *customer_name;
    char *address;
    char *phone_number;
    char *email_id;
} customer_info;

room_info rooms[MAX_ROOMS];
customer_info customers[MAX_CUSTOMERS];

int num_rooms = 0;
int num_customers = 0;

void add_room() {
    int room_number;
    char customer_name[50];
    char check_in_date[11];
    char check_out_date[11];
    float bill_amount;

    printf("Enter room number: ");
    scanf("%d", &room_number);
    printf("Enter customer name: ");
    scanf("%s", customer_name);
    printf("Enter check-in date (YYYY-MM-DD): ");
    scanf("%s", check_in_date);
    printf("Enter check-out date (YYYY-MM-DD): ");
    scanf("%s", check_out_date);
    printf("Enter bill amount: ");
    scanf("%f", &bill_amount);

    rooms[num_rooms].room_number = room_number;
    rooms[num_rooms].customer_name = strdup(customer_name);
    rooms[num_rooms].check_in_date = strdup(check_in_date);
    rooms[num_rooms].check_out_date = strdup(check_out_date);
    rooms[num_rooms].bill_amount = bill_amount;

    num_rooms++;
}

void add_customer() {
    int customer_id;
    char customer_name[50];
    char address[100];
    char phone_number[20];
    char email_id[50];

    printf("Enter customer ID: ");
    scanf("%d", &customer_id);
    printf("Enter customer name: ");
    scanf("%s", customer_name);
    printf("Enter address: ");
    scanf("%s", address);
    printf("Enter phone number: ");
    scanf("%s", phone_number);
    printf("Enter email ID: ");
    scanf("%s", email_id);

    customers[num_customers].customer_id = customer_id;
    customers[num_customers].customer_name = strdup(customer_name);
    customers[num_customers].address = strdup(address);
    customers[num_customers].phone_number = strdup(phone_number);
    customers[num_customers].email_id = strdup(email_id);

    num_customers++;
}

void display_rooms() {
    int i;

    printf("Room Number\tCustomer Name\tCheck-In Date\tCheck-Out Date\tBill Amount\n");
    for (i = 0; i < num_rooms; i++) {
        printf("%d\t%s\t%s\t%s\t%.2f\n", rooms[i].room_number, rooms[i].customer_name, rooms[i].check_in_date, rooms[i].check_out_date, rooms[i].bill_amount);
    }
}

void display_customers() {
    int i;

    printf("Customer ID\tCustomer Name\tAddress\tPhone Number\tEmail ID\n");
    for (i = 0; i < num_customers; i++) {
        printf("%d\t%s\t%s\t%s\t%s\n", customers[i].customer_id, customers[i].customer_name, customers[i].address, customers[i].phone_number, customers[i].email_id);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Add Room\n2. Add Customer\n3. Display Rooms\n4. Display Customers\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_room();
                break;
            case 2:
                add_customer();
                break;
            case 3:
                display_rooms();
                break;
            case 4:
                display_customers();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}