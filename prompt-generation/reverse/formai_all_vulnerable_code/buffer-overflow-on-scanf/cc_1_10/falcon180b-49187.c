//Falcon-180B DATASET v1.0 Category: Hotel Management System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_CUSTOMERS 100
#define MAX_BOOKINGS 100

typedef struct {
    int room_number;
    int customer_id;
    int booking_status;
    int check_in_date;
    int check_out_date;
    int total_nights;
    int total_cost;
} Booking;

typedef struct {
    int customer_id;
    char name[50];
    char address[100];
    char phone_number[15];
} Customer;

typedef struct {
    int room_number;
    int room_type;
    int room_status;
    int room_cost;
} Room;

int main() {
    int choice;
    char ch;

    while (1) {
        printf("\n\nWelcome to Hotel Management System\n");
        printf("1. Create Customer\n");
        printf("2. Create Room\n");
        printf("3. Book Room\n");
        printf("4. Check Room Availability\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter customer name: ");
            scanf("%s", &ch);
            printf("Enter customer address: ");
            scanf("%s", &ch);
            printf("Enter customer phone number: ");
            scanf("%s", &ch);
            break;
        case 2:
            printf("Enter room number: ");
            scanf("%d", &ch);
            printf("Enter room type: ");
            scanf("%d", &ch);
            printf("Enter room status: ");
            scanf("%d", &ch);
            printf("Enter room cost: ");
            scanf("%d", &ch);
            break;
        case 3:
            printf("Enter customer ID: ");
            scanf("%d", &ch);
            printf("Enter room number: ");
            scanf("%d", &ch);
            printf("Enter check-in date: ");
            scanf("%d", &ch);
            printf("Enter check-out date: ");
            scanf("%d", &ch);
            break;
        case 4:
            printf("Enter room number: ");
            scanf("%d", &ch);
            printf("Enter check-in date: ");
            scanf("%d", &ch);
            printf("Enter check-out date: ");
            scanf("%d", &ch);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}