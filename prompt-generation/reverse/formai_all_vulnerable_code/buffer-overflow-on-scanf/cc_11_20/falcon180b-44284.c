//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_CUSTOMERS 100
#define MAX_BOOKINGS 500
#define MAX_STAFF 50
#define MAX_SERVICES 10

struct room {
    int room_number;
    int room_type;
    int room_price;
    int availability;
};

struct customer {
    int customer_id;
    char customer_name[50];
    char customer_address[100];
    char customer_phone[15];
};

struct booking {
    int booking_id;
    int customer_id;
    int room_number;
    int check_in_date;
    int check_out_date;
    int total_days;
    int total_price;
};

struct staff {
    int staff_id;
    char staff_name[50];
    char staff_position[50];
    int staff_salary;
};

struct service {
    int service_id;
    char service_name[50];
    int service_price;
};

int main() {
    int choice;
    while(1) {
        printf("\nHotel Management System\n");
        printf("1. Add Room\n2. View Rooms\n3. Book Room\n4. View Bookings\n5. Add Customer\n6. View Customers\n7. Add Staff\n8. View Staff\n9. Add Service\n10. View Services\n11. Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                // add room
                break;
            case 2:
                // view rooms
                break;
            case 3:
                // book room
                break;
            case 4:
                // view bookings
                break;
            case 5:
                // add customer
                break;
            case 6:
                // view customers
                break;
            case 7:
                // add staff
                break;
            case 8:
                // view staff
                break;
            case 9:
                // add service
                break;
            case 10:
                // view services
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}