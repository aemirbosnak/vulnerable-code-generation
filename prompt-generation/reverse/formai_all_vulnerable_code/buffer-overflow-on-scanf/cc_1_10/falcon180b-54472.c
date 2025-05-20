//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROOMS 50
#define MAX_GUESTS 100
#define MAX_BOOKINGS 200
#define MAX_STAFF 20
#define MAX_CUSTOMERS 50
#define MAX_MENU_ITEMS 50
#define MAX_ORDERS 100
#define MAX_ORDERS_PER_CUSTOMER 5

typedef struct {
    int room_number;
    char guest_name[50];
    int days_stayed;
    int total_cost;
} Booking;

typedef struct {
    int staff_id;
    char staff_name[50];
    char staff_position[50];
    int staff_salary;
} Staff;

typedef struct {
    int customer_id;
    char customer_name[50];
    int customer_balance;
} Customer;

typedef struct {
    int menu_item_id;
    char menu_item_name[50];
    int menu_item_price;
} MenuItem;

typedef struct {
    int order_id;
    int customer_id;
    int staff_id;
    MenuItem order_items[MAX_MENU_ITEMS];
    int num_items;
    int total_cost;
} Order;

int main() {
    int choice;
    
    while(1) {
        printf("Hotel Management System\n");
        printf("1. Room Management\n");
        printf("2. Guest Management\n");
        printf("3. Booking Management\n");
        printf("4. Staff Management\n");
        printf("5. Customer Management\n");
        printf("6. Menu Management\n");
        printf("7. Order Management\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                // Room Management
                break;
            case 2:
                // Guest Management
                break;
            case 3:
                // Booking Management
                break;
            case 4:
                // Staff Management
                break;
            case 5:
                // Customer Management
                break;
            case 6:
                // Menu Management
                break;
            case 7:
                // Order Management
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}