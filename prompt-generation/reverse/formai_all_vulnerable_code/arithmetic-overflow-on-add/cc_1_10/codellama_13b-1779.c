//Code Llama-13B DATASET v1.0 Category: Hotel Management System ; Style: lively
/*
 * Hotel Management System
 *
 * A lively hotel management system that allows guests to check in, check out, and request services.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a guest
struct guest {
    int id;
    char name[256];
    char email[256];
    char phone[256];
    int room_num;
    int check_in_date;
    int check_out_date;
    int services[5]; // Services requested (e.g. room service, cleaning, etc.)
};

// Function to print the menu
void print_menu() {
    printf("1. Check in\n");
    printf("2. Check out\n");
    printf("3. Request services\n");
    printf("4. View room information\n");
    printf("5. Exit\n");
}

// Function to check in a guest
void check_in(struct guest *g) {
    printf("Enter the guest's name: ");
    scanf("%s", g->name);
    printf("Enter the guest's email: ");
    scanf("%s", g->email);
    printf("Enter the guest's phone number: ");
    scanf("%s", g->phone);
    printf("Enter the room number: ");
    scanf("%d", &g->room_num);
    g->check_in_date = time(NULL);
    g->check_out_date = g->check_in_date + 24 * 60 * 60; // Check out date is 24 hours after check-in date
    printf("Guest checked in successfully.\n");
}

// Function to check out a guest
void check_out(struct guest *g) {
    g->check_out_date = time(NULL);
    printf("Guest checked out successfully.\n");
}

// Function to request services
void request_services(struct guest *g) {
    int services[5];
    printf("Enter the services you would like to request (1-5): ");
    scanf("%d", services);
    for (int i = 0; i < 5; i++) {
        if (services[i] == 1) {
            printf("Room service requested.\n");
        } else if (services[i] == 2) {
            printf("Cleaning requested.\n");
        } else if (services[i] == 3) {
            printf("Transportation requested.\n");
        } else if (services[i] == 4) {
            printf("Entertainment requested.\n");
        } else if (services[i] == 5) {
            printf("Other requested.\n");
        }
    }
}

// Function to view room information
void view_room_information(struct guest *g) {
    printf("Guest's name: %s\n", g->name);
    printf("Guest's email: %s\n", g->email);
    printf("Guest's phone number: %s\n", g->phone);
    printf("Room number: %d\n", g->room_num);
    printf("Check-in date: %s\n", g->check_in_date);
    printf("Check-out date: %s\n", g->check_out_date);
    printf("Services requested: %s\n", g->services);
}

int main() {
    struct guest g;
    int choice;

    while (1) {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            check_in(&g);
            break;
        case 2:
            check_out(&g);
            break;
        case 3:
            request_services(&g);
            break;
        case 4:
            view_room_information(&g);
            break;
        case 5:
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}