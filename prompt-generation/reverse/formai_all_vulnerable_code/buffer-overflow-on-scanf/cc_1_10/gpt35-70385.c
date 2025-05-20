//FormAI DATASET v1.0 Category: Hotel Management System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hotel {
    int room_num;
    int floor_num;
    char guest_name[50];
    int occupancy_days;
    double bill_amount;
};

void show_menu();
void add_booking(struct hotel [], int *);
void display_bookings(struct hotel [], int);
void search_booking(struct hotel [], int);
void modify_booking(struct hotel [], int);
void delete_booking(struct hotel [], int *);
void generate_bill(struct hotel [], int);

int main() {
    struct hotel bookings[50];
    int num_bookings = 0;
    int option;

    do {
        show_menu();
        printf("\nEnter your option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                add_booking(bookings, &num_bookings);
                printf("\nBooking added successfully!\n");
                break;
            case 2:
                display_bookings(bookings, num_bookings);
                break;
            case 3:
                search_booking(bookings, num_bookings);
                break;
            case 4:
                modify_booking(bookings, num_bookings);
                printf("\nBooking modified successfully!\n");
                break;
            case 5:
                delete_booking(bookings, &num_bookings);
                printf("\nBooking deleted successfully!\n");
                break;
            case 6:
                generate_bill(bookings, num_bookings);
                break;
            case 7:
                printf("\nThank you for using our hotel management system!\n");
                exit(0);
            default:
                printf("\nInvalid option! Please enter a valid option.\n");
        }
    } while(option != 7);

    return 0;
}

void show_menu() {
    printf("\n***** HOTEL MANAGEMENT SYSTEM *****\n");
    printf("1. Add Booking\n");
    printf("2. Display Bookings\n");
    printf("3. Search Bookings\n");
    printf("4. Modify Bookings\n");
    printf("5. Delete Bookings\n");
    printf("6. Generate Bill\n");
    printf("7. Exit\n");
}

void add_booking(struct hotel bookings[], int *num_bookings) {
    int room_num, floor_num, occupancy_days;
    char guest_name[50];
    double bill_amount;

    printf("\n***** ADD BOOKING *****\n");
    printf("Enter room number: ");
    scanf("%d", &room_num);
    printf("Enter floor number: ");
    scanf("%d", &floor_num);
    printf("Enter guest name: ");
    scanf("%s", guest_name); // use %s format specifier to read string
    printf("Enter number of occupancy days: ");
    scanf("%d", &occupancy_days);
    printf("Enter bill amount: ");
    scanf("%lf", &bill_amount); // use %lf format specifier to read double

    bookings[*num_bookings].room_num = room_num;
    bookings[*num_bookings].floor_num = floor_num;
    strcpy(bookings[*num_bookings].guest_name, guest_name);
    bookings[*num_bookings].occupancy_days = occupancy_days;
    bookings[*num_bookings].bill_amount = bill_amount;

    (*num_bookings)++;
}

void display_bookings(struct hotel bookings[], int num_bookings) {
    if(num_bookings == 0) {
        printf("\nNo bookings found!");
        return;
    }

    printf("\n***** DISPLAY BOOKINGS *****\n");
    printf("Room No.\tFloor No.\tGuest Name\tOccupancy Days\tBill Amount\n");
    printf("---------------------------------------------------------------------------------------------------------\n");

    for(int i = 0; i < num_bookings; i++) {
        printf("%d\t\t%d\t\t%s\t\t%d\t\t%lf\n", bookings[i].room_num, bookings[i].floor_num, bookings[i].guest_name, bookings[i].occupancy_days, bookings[i].bill_amount);
    }
}

void search_booking(struct hotel bookings[], int num_bookings) {
    if(num_bookings == 0) {
        printf("\nNo bookings found!");
        return;
    }

    int search_room_num;
    printf("\n***** SEARCH BOOKING *****\n");
    printf("Enter room number to search: ");
    scanf("%d", &search_room_num);

    for(int i = 0; i < num_bookings; i++) {
        if(bookings[i].room_num == search_room_num) {
            printf("\nRoom No.\tFloor No.\tGuest Name\tOccupancy Days\tBill Amount\n");
            printf("---------------------------------------------------------------------------------------------------------\n");
            printf("%d\t\t%d\t\t%s\t\t%d\t\t%lf\n", bookings[i].room_num, bookings[i].floor_num, bookings[i].guest_name, bookings[i].occupancy_days, bookings[i].bill_amount);
            return;
        }
    }

    printf("\nNo booking found with room number %d", search_room_num);
}

void modify_booking(struct hotel bookings[], int num_bookings) {
    if(num_bookings == 0) {
        printf("\nNo bookings found!");
        return;
    }

    int modify_room_num;
    printf("\n***** MODIFY BOOKING *****\n");
    printf("Enter room number to modify: ");
    scanf("%d", &modify_room_num);

    for(int i = 0; i < num_bookings; i++) {
        if(bookings[i].room_num == modify_room_num) {
            int room_num, floor_num, occupancy_days;
            char guest_name[50];
            double bill_amount;

            printf("\nEnter new values for the booking: ");
            printf("\nEnter room number: ");
            scanf("%d", &room_num);
            printf("Enter floor number: ");
            scanf("%d", &floor_num);
            printf("Enter guest name: ");
            scanf("%s", guest_name);
            printf("Enter number of occupancy days: ");
            scanf("%d", &occupancy_days);
            printf("Enter bill amount: ");
            scanf("%lf", &bill_amount);

            bookings[i].room_num = room_num;
            bookings[i].floor_num = floor_num;
            strcpy(bookings[i].guest_name, guest_name);
            bookings[i].occupancy_days = occupancy_days;
            bookings[i].bill_amount = bill_amount;

            return;
        }
    }

    printf("\nNo booking found with room number %d", modify_room_num);
}

void delete_booking(struct hotel bookings[], int *num_bookings) {
    if(*num_bookings == 0) {
        printf("\nNo bookings found!");
        return;
    }

    int delete_room_num;
    printf("\n***** DELETE BOOKING *****\n");
    printf("Enter room number to delete: ");
    scanf("%d", &delete_room_num);

    for(int i = 0; i < *num_bookings; i++) {
        if(bookings[i].room_num == delete_room_num) {
            for(int j = i; j < (*num_bookings) - 1; j++) {
                bookings[j] = bookings[j + 1];
            }

            (*num_bookings)--;
            return;
        }
    }

    printf("\nNo booking found with room number %d", delete_room_num);
}

void generate_bill(struct hotel bookings[], int num_bookings) {
    if(num_bookings == 0) {
        printf("\nNo bookings found!");
        return;
    }

    int bill_room_num;
    printf("\n***** GENERATE BILL *****\n");
    printf("Enter room number to generate bill: ");
    scanf("%d", &bill_room_num);

    for(int i = 0; i < num_bookings; i++) {
        if(bookings[i].room_num == bill_room_num) {
            printf("\nRoom No.: %d", bookings[i].room_num);
            printf("\nFloor No.: %d", bookings[i].floor_num);
            printf("\nGuest Name: %s", bookings[i].guest_name);
            printf("\nOccupancy Days: %d", bookings[i].occupancy_days);
            printf("\nBill Amount: %lf", bookings[i].bill_amount);

            return;
        }
    }

    printf("\nNo booking found with room number %d", bill_room_num);
}