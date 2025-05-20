//FormAI DATASET v1.0 Category: Hotel Management System ; Style: thoughtful
#include <stdio.h>
#include <string.h>

struct room_type {
    char name[20];
    int price;
    int availability;
};

struct booking {
    char name[20];
    int room_no;
    int nights;
    int total_price;
};

typedef struct room_type room_type;
typedef struct booking booking;

int get_input() {
    int input;
    printf("Enter choice: ");
    scanf("%d", &input);
    return input;
}

void print_room_types(room_type* types, int count) {
    printf("\nRoom Types:\n");
    printf("------------\n");
    for(int i=0; i<count; i++) {
        printf("%d) Name: %s\nPrice: %d\nAvailability: %d\n\n", i+1, types[i].name, types[i].price, types[i].availability);
    }
}

void print_booking(booking* b) {
    printf("\nBooking Details:\n");
    printf("-----------------\n");
    printf("Name: %s\nRoom No: %d\nNights: %d\nTotal Price: %d\n", b->name, b->room_no, b->nights, b->total_price);
}

void book_room(room_type* types, int count, booking* bookings, int* booking_count) {
    char name[20];
    int room_no, nights;
    int found = 0;
    int b_count = *booking_count;

    printf("Enter your name: ");
    scanf("%s", name);

    print_room_types(types, count);

    printf("Enter room type choice: ");
    int choice = get_input();
    room_type selected_type = types[choice-1];

    printf("Enter number of nights: ");
    nights = get_input();

    for(int i=0; i<count; i++) {
        if(types[i].availability > 0 && strcmp(types[i].name, selected_type.name) == 0) {
            types[i].availability--;
            found = 1;

            booking new_booking;
            strcpy(new_booking.name, name);
            new_booking.room_no = i+1;
            new_booking.nights = nights;
            new_booking.total_price = selected_type.price * nights;

            bookings[b_count++] = new_booking;

            printf("\nBooking Successful!\n");
            printf("--------------------\n");
            print_booking(&new_booking);

            break;
        }
    }

    if(!found) {
        printf("\nUnable to book room.\n");
    }

    *booking_count = b_count;
}

void view_bookings(booking* bookings, int count) {
    if(count == 0) {
        printf("\nNo bookings found.\n");
        return;
    }

    printf("\nBookings:\n");
    printf("---------\n");

    for(int i=0; i<count; i++) {
        printf("Booking No: %d\n", i+1);
        print_booking(&bookings[i]);
    }
}

int main() {
    room_type types[3];
    types[0] = (room_type){"Standard", 100, 5};
    types[1] = (room_type){"Deluxe", 200, 3};
    types[2] = (room_type){"Suite", 300, 2};

    booking bookings[10];
    int booking_count = 0;

    while(1) {
        printf("\nWelcome to C Hotel Management System!\n");
        printf("What would you like to do?\n");
        printf("1) Book a room\n");
        printf("2) View bookings\n");
        printf("3) Exit\n");

        int choice = get_input();

        switch(choice) {
            case 1:
                book_room(types, 3, bookings, &booking_count);
                break;
            case 2:
                view_bookings(bookings, booking_count);
                break;
            case 3:
                printf("\nBye!\n");
                return 0;
            default:
                printf("\nInvalid Choice!\n");
                break;
        }
    }

    return 0;
}