//FormAI DATASET v1.0 Category: Hotel Management System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for booking details
struct Bookings {
    char name[20];
    char room_type[10];
    int duration;
    int room_no;
};

// Structure for hotel details
struct Hotel {
    int single_bed;
    int double_bed;
    int deluxe;
    int booked;
};

int main() {
    struct Bookings booking[100];  // Maximum 100 bookings allowed
    struct Hotel hotel;

    hotel.single_bed = 50;  // Number of single bed rooms available
    hotel.double_bed = 30;  // Number of double bed rooms available
    hotel.deluxe = 20;  // Number of deluxe rooms available
    hotel.booked = 0;  // Number of rooms currently booked

    int choice, i, j, flag, room_type_choice, duration, room_no, cancel_choice, cancel_flag;

    do {
        flag = 0;  // Reset flag value for each iteration

        printf("\nWelcome to C Hotel Management System\n\n");
        printf("1. Book a room\n");
        printf("2. Cancel a booking\n");
        printf("3. Display all bookings\n");
        printf("4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            
            case 1:  // Book a room
                if (hotel.booked >= 100) {
                    printf("\nSorry, all rooms are currently booked.\n");
                } else {
                    do {
                        printf("\nPlease enter your name: ");
                        scanf("%s", booking[hotel.booked].name);

                        printf("\nPlease choose the type of room:\n");
                        printf("1. Single bed room\n");
                        printf("2. Double bed room\n");
                        printf("3. Deluxe room\n");
                        printf("\nEnter your choice: ");
                        scanf("%d", &room_type_choice);

                        switch(room_type_choice) {
                            case 1:
                                if (hotel.single_bed > 0) {
                                    strcpy(booking[hotel.booked].room_type, "Single Bed");
                                    hotel.single_bed--;
                                    flag = 1;
                                } else {
                                    printf("\nSorry, all single bed rooms are booked. Please choose another room type.\n");
                                }
                                break;
                            case 2:
                                if (hotel.double_bed > 0) {
                                    strcpy(booking[hotel.booked].room_type, "Double Bed");
                                    hotel.double_bed--;
                                    flag = 1;
                                } else {
                                    printf("\nSorry, all double bed rooms are booked. Please choose another room type.\n");
                                }
                                break;
                            case 3:
                                if (hotel.deluxe > 0) {
                                    strcpy(booking[hotel.booked].room_type, "Deluxe");
                                    hotel.deluxe--;
                                    flag = 1;
                                } else {
                                    printf("\nSorry, all deluxe rooms are booked. Please choose another room type.\n");
                                }
                                break;
                            default:
                                printf("\nInvalid choice. Please choose a valid room type.\n");
                        }

                    } while(flag != 1);

                    do {
                        printf("\nPlease enter the duration of your stay (in days): ");
                        scanf("%d", &duration);

                        if (duration <= 0) {
                            printf("\nInvalid duration. Please enter a valid duration.\n");
                        } else {
                            booking[hotel.booked].duration = duration;
                            flag = 1;
                        }

                    } while(flag != 1);

                    booking[hotel.booked].room_no = hotel.booked + 1;
                    hotel.booked++;

                    printf("\nBooking successful. Thank you for choosing C Hotel!\n");
                }
                break;
            
            case 2:  // Cancel a booking
                if (hotel.booked == 0) {
                    printf("\nNo bookings to cancel.\n");
                } else {
                    do {
                        printf("\nPlease enter your room number: ");
                        scanf("%d", &room_no);

                        if (room_no <= 0 || room_no > hotel.booked) {
                            printf("\nInvalid room number. Please enter a valid room number.\n");
                        } else {
                            printf("\nAre you sure you want to cancel your booking?\n");
                            printf("1. Yes\n");
                            printf("2. No\n");
                            printf("\nEnter your choice: ");
                            scanf("%d", &cancel_choice);

                            if (cancel_choice == 1) {
                                cancel_flag = 1;
                                printf("\nBooking cancelled. Thank you for choosing C Hotel.\n");

                                // Update hotel room availability
                                if (strcmp(booking[room_no-1].room_type, "Single Bed") == 0) {
                                    hotel.single_bed++;
                                } else if (strcmp(booking[room_no-1].room_type, "Double Bed") == 0) {
                                    hotel.double_bed++;
                                } else if (strcmp(booking[room_no-1].room_type, "Deluxe") == 0) {
                                    hotel.deluxe++;
                                }

                                // Shift all bookings after the cancelled booking one position left
                                for (i = room_no-1; i < hotel.booked-1; i++) {
                                    booking[i] = booking[i+1];
                                }

                                hotel.booked--;
                            } else {
                                cancel_flag = 0;
                                printf("\nBooking not cancelled.\n");
                            }
                        }

                    } while(cancel_flag != 1);
                }
                break;
            
            case 3:  // Display all bookings
                if (hotel.booked == 0) {
                    printf("\nNo bookings made yet.\n");
                } else {
                    printf("\nAll bookings:\n\n");
                    printf("Room No  Guest Name  Room Type  Duration (in days)\n");
                    for (i = 0; i < hotel.booked; i++) {
                        printf("%-9d%-12s%-11s%-15d\n", booking[i].room_no, booking[i].name, booking[i].room_type, booking[i].duration);
                    }
                }
                break;
            
            case 4:  // Exit
                printf("\nThank you for using C Hotel Management System!\n");
                break;

            default:
                printf("\nInvalid choice. Please choose a valid option.\n");
        }
    } while(choice != 4);

    return 0;
}