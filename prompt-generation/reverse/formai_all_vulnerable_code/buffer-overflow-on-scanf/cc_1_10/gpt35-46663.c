//FormAI DATASET v1.0 Category: Hotel Management System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 50
#define MAX_GUESTS 100

typedef struct {
    int room_number;
    char guest_name[50];
    int number_of_guests;
    int number_of_nights;
    double total_cost;
    int checked_in;
} Room;

Room rooms[MAX_ROOMS];
int num_available_rooms = MAX_ROOMS;

void display_main_menu();
void check_in_guest();
void check_out_guest();
void display_guests();
void search_guest(char *guest_name);

int main() {
    int choice;
    do {
        display_main_menu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                check_in_guest();
                break;
            case 2:
                check_out_guest();
                break;
            case 3:
                display_guests();
                break;
            case 4:
                printf("Thank you for using our management system.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(choice != 4);
    return 0;
}

void display_main_menu() {
    printf("==== Hotel Management System ====\n");
    printf("1. Check in guest\n");
    printf("2. Check out guest\n");
    printf("3. Display guests\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

void check_in_guest() {
    if(num_available_rooms == 0) {
        printf("No more available rooms.\n");
        return;
    }
    Room room;
    printf("Enter room number: ");
    scanf("%d", &room.room_number);
    if(room.room_number < 1 || room.room_number > MAX_ROOMS) {
        printf("Invalid room number. Please try again.\n");
        return;
    }
    if(rooms[room.room_number-1].checked_in) {
        printf("Room already occupied.\n");
        return;
    }
    printf("Enter guest name: ");
    scanf("%s", &room.guest_name);
    printf("Enter number of guests: ");
    scanf("%d", &room.number_of_guests);
    printf("Enter number of nights: ");
    scanf("%d", &room.number_of_nights);
    room.total_cost = room.number_of_guests * room.number_of_nights * 100.0;
    room.checked_in = 1;
    rooms[room.room_number-1] = room;
    num_available_rooms--;
}

void check_out_guest() {
    int room_number;
    printf("Enter room number: ");
    scanf("%d", &room_number);
    if(room_number < 1 || room_number > MAX_ROOMS) {
        printf("Invalid room number. Please try again.\n");
        return;
    }
    if(!rooms[room_number-1].checked_in) {
        printf("Room is not occupied.\n");
        return;
    }
    printf("Guest: %s\n", rooms[room_number-1].guest_name);
    printf("Number of guests: %d\n", rooms[room_number-1].number_of_guests);
    printf("Number of nights: %d\n", rooms[room_number-1].number_of_nights);
    printf("Total cost: $%.2f\n", rooms[room_number-1].total_cost);
    printf("Thank you for staying with us!\n");
    memset(&rooms[room_number-1], 0, sizeof(Room));
    num_available_rooms++;
}

void display_guests() {
    printf("Room  Guest name      # of guests  # of nights  Total cost  Checked in\n");
    for(int i = 0; i < MAX_ROOMS; i++) {
        if(rooms[i].checked_in) {
            printf("%-6d%-15s%-12d%-12d$%-10.2f%c\n", rooms[i].room_number, rooms[i].guest_name, rooms[i].number_of_guests, rooms[i].number_of_nights, rooms[i].total_cost, rooms[i].checked_in ? 'Y' : 'N');
        }
    }
}

void search_guest(char *guest_name) {
    int count = 0;
    printf("Room  Guest name      # of guests  # of nights  Total cost  Checked in\n");
    for(int i = 0; i < MAX_ROOMS; i++) {
        if(rooms[i].checked_in && strcmp(guest_name, rooms[i].guest_name) == 0) {
            printf("%-6d%-15s%-12d%-12d$%-10.2f%c\n", rooms[i].room_number, rooms[i].guest_name, rooms[i].number_of_guests, rooms[i].number_of_nights, rooms[i].total_cost, rooms[i].checked_in ? 'Y' : 'N');
            count++;
        }
    }
    if(count == 0) {
        printf("Guest not found.\n");
    }
}