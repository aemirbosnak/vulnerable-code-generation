//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ROOMS 100
#define MAX_GUESTS 100
#define MAX_STAFF 50
#define MAX_BOOKINGS 1000
#define MAX_SERVICES 10

typedef struct {
    int room_number;
    int guest_id;
    char name[50];
    int days_stayed;
    int total_charges;
} Guest;

typedef struct {
    int staff_id;
    char name[50];
    int salary;
} Staff;

typedef struct {
    int booking_id;
    int guest_id;
    int room_number;
    int check_in_date;
    int check_out_date;
    int total_charges;
} Booking;

typedef struct {
    int service_id;
    char name[50];
    int price;
} Service;

int main() {
    system("clear");
    printf("Welcome to Hotel Management System\n");
    int choice;
    while(true) {
        system("clear");
        printf("1. Add Guest\n2. Check-in\n3. Check-out\n4. View Guest Details\n5. Add Staff\n6. View Staff Details\n7. Add Service\n8. View Services\n9. Make Booking\n10. View Bookings\n11. Exit\n");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                // Add Guest
                break;
            case 2:
                // Check-in
                break;
            case 3:
                // Check-out
                break;
            case 4:
                // View Guest Details
                break;
            case 5:
                // Add Staff
                break;
            case 6:
                // View Staff Details
                break;
            case 7:
                // Add Service
                break;
            case 8:
                // View Services
                break;
            case 9:
                // Make Booking
                break;
            case 10:
                // View Bookings
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}