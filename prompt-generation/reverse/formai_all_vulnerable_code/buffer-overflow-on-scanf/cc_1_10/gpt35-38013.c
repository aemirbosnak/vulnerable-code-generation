//FormAI DATASET v1.0 Category: Hotel Management System ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int room_no;
    char date[50];
    int guests;
    float total_bill;
} Hotel;

void print_room(Hotel h, int index) {
    printf("%d \t %s \t %s \t %d \t %f\n", index, h.name, h.date, h.guests, h.total_bill);
}

int main() {
    int room_count, choice;
    printf("Enter the number of rooms in the hotel: ");
    scanf("%d", &room_count);

    Hotel hotel_list[room_count];
    int hotel_empty[room_count];
    memset(hotel_empty, 1, room_count);
    
    while (1) {
        printf("\nHotel Management System\n");
        printf("-----------------------\n");
        printf("1. Add room booking\n");
        printf("2. View all room bookings\n");
        printf("3. Search for booking by name\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nAdd Room Booking\n");
                printf("-----------------\n");
                int avail_room, i;
                for (i = 0; i < room_count; i++) {
                    if (hotel_empty[i]) {
                        avail_room = i;
                        hotel_empty[i] = 0;
                        break;
                    }
                }
                if (i == room_count) {
                    printf("All rooms are booked!\n");
                    break;
                }
                Hotel new_booking;
                new_booking.room_no = avail_room + 1;
                printf("Room %d is available\n", new_booking.room_no);
                printf("Enter guest name: ");
                scanf("%s", new_booking.name);
                printf("Enter date (dd/mm/yyyy): ");
                scanf("%s", new_booking.date);
                printf("Enter number of guests: ");
                scanf("%d", &new_booking.guests);
                new_booking.total_bill = 100.0 * new_booking.guests;
                hotel_list[avail_room] = new_booking;
                printf("Booking added successfully!\n");
                break;

            case 2:
                printf("\nAll Room Bookings\n");
                printf("------------------\n");
                printf("Room No \t Guest Name \t Booking Date \t No. of Guests \t Total Bill\n");
                for (i = 0; i < room_count; i++) {
                    if (!hotel_empty[i])
                        print_room(hotel_list[i], i+1);
                }
                break;

            case 3:
                printf("\nSearch Room Booking by Name\n");
                printf("---------------------------\n");
                char search_name[50];
                printf("Enter guest name: ");
                scanf("%s", search_name);
                printf("Room No \t Guest Name \t Booking Date \t No. of Guests \t Total Bill\n");
                int found = 0;
                for (i = 0; i < room_count; i++) {
                    if (!hotel_empty[i] && strcmp(search_name, hotel_list[i].name) == 0) {
                        print_room(hotel_list[i], i+1);
                        found = 1;
                    }
                }
                if (!found)
                    printf("No bookings found for guest %s\n", search_name);
                break;

            case 4:
                printf("\nExiting Program\n");
                exit(0);
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
                break;
        }
    }

    return 0;
}