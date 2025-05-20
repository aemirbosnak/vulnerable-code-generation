//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 1000
#define MAX_EMPLOYEES 100
#define MAX_ORDERS 1000
#define MAX_ITEMS 1000

typedef struct {
    char name[50];
    int age;
    char address[100];
    char phone[15];
    char email[50];
} Guest;

typedef struct {
    char name[50];
    int age;
    char address[100];
    char phone[15];
    char email[50];
    int employee_id;
} Employee;

typedef struct {
    int room_number;
    int guest_id;
    int check_in_date;
    int check_out_date;
    int total_nights;
    int total_cost;
} Reservation;

typedef struct {
    int order_id;
    int guest_id;
    int employee_id;
    int order_date;
    int total_cost;
} Order;

typedef struct {
    char name[50];
    int price;
} Item;

int main() {
    int choice;
    do {
        printf("\nHotel Management System\n");
        printf("1. Guest Check-in\n2. Guest Check-out\n3. Room Reservation\n4. Order Placement\n5. Employee Management\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Guest Check-in
                break;
            case 2:
                // Guest Check-out
                break;
            case 3:
                // Room Reservation
                break;
            case 4:
                // Order Placement
                break;
            case 5:
                // Employee Management
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while(1);
    return 0;
}