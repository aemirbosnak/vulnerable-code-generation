//FormAI DATASET v1.0 Category: Hotel Management System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store hotel guest information
struct guest {
    char name[50];
    char phone_number[20];
    char room_type[20];
    int room_number;
    int nights;
    int total_cost;
};

// Function to display main menu
void display_menu(void) {
    printf("\n\n\t\t\t+------------------------+\n");
    printf("\t\t\t| C Hotel Management System |\n");
    printf("\t\t\t+------------------------+\n\n");
    printf("\t\t\t1. Check In\n");
    printf("\t\t\t2. Check Out\n");
    printf("\t\t\t3. View Guest Directory\n");
    printf("\t\t\t4. Exit\n\n");
}

// Function to check in a guest
void check_in(struct guest *new_guest) {
    printf("\n\n\t\t\t+----------------+\n");
    printf("\t\t\t| Guest Check-In |\n");
    printf("\t\t\t+----------------+\n\n");

    printf("Enter guest name: ");
    fgets(new_guest->name, 50, stdin);
    new_guest->name[strcspn(new_guest->name, "\n")] = 0;

    printf("Enter guest phone number: ");
    fgets(new_guest->phone_number, 20, stdin);
    new_guest->phone_number[strcspn(new_guest->phone_number, "\n")] = 0;

    printf("Enter room type (Single / Double / Suite): ");
    fgets(new_guest->room_type, 20, stdin);
    new_guest->room_type[strcspn(new_guest->room_type, "\n")] = 0;

    printf("Enter room number: ");
    scanf("%d", &new_guest->room_number);

    printf("Enter number of nights staying: ");
    scanf("%d", &new_guest->nights);

    printf("\n\n\t\t\t+---------------------+\n");
    printf("\t\t\t| Check-In Successful |\n");
    printf("\t\t\t+---------------------+\n");
}

// Function to check out a guest
void check_out(struct guest *guest) {
    printf("\n\n\t\t\t+-----------------+\n");
    printf("\t\t\t| Guest Check-Out |\n");
    printf("\t\t\t+-----------------+\n\n");

    printf("Guest Name: %s\n", guest->name);
    printf("Guest Phone Number: %s\n", guest->phone_number);
    printf("Room Type: %s\n", guest->room_type);
    printf("Room Number: %d\n", guest->room_number);
    printf("Number of Nights Staying: %d\n", guest->nights);

    printf("\n\n\t\t\t+------------------------+\n");
    printf("\t\t\t| Check-Out Successful |\n");
    printf("\t\t\t+------------------------+\n");
}

// Function to view guest directory
void view_directory(struct guest *guestlist, int count) {
    printf("\n\n\t\t\t+------------------------+\n");
    printf("\t\t\t| Guest Directory (%d guests) |\n", count);
    printf("\t\t\t+------------------------+\n\n");

    if(count == 0) {
        printf("\n\nNo guests checked in\n\n");
        return;
    }

    printf("%-25s%-20s%-20s%-15s%-15s\n", "Name", "Phone Number", "Room Type", "Room Number", "Nights Staying");
    for(int i = 0; i < count; i++) {
        printf("%-25s%-20s%-20s%-15d%-15d\n", guestlist[i].name, guestlist[i].phone_number, guestlist[i].room_type, guestlist[i].room_number, guestlist[i].nights);
    }
}

// Main function
int main() {
    int choice = 0, guest_count = 0;
    struct guest guestlist[100];

    while(choice != 4) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1:
                check_in(&guestlist[guest_count]);
                guest_count++;
                break;
            case 2:
                if(guest_count == 0) {
                    printf("\n\nNo guests checked in\n\n");
                    break;
                }
                int room_number;
                printf("\n\nEnter room number to check out: ");
                scanf("%d", &room_number);
                getchar();
                int guest_index = -1;
                for(int i = 0; i < guest_count; i++) {
                    if(guestlist[i].room_number == room_number) {
                        guest_index = i;
                        break;
                    }
                }
                if(guest_index == -1) {
                    printf("\n\nInvalid room number\n\n");
                    break;
                }
                check_out(&guestlist[guest_index]);
                for(int i = guest_index; i < guest_count-1; i++) {
                    guestlist[i] = guestlist[i+1];
                }
                guest_count--;
                break;
            case 3:
                view_directory(guestlist, guest_count);
                break;
            case 4:
                printf("\n\nExiting program...\n\n");
                break;
            default:
                printf("\n\nInvalid choice\n\n");
        }
    }

    return 0;
}