//FormAI DATASET v1.0 Category: Hotel Management System ; Style: authentic
#include <stdio.h>

//Structure for a room
struct Room {
    int room_number;
    char room_type[20];
    float room_price;
    int is_available;
};

//Structure for a guest
struct Guest {
    char name[50];
    char phone_number[20];
    char email[50];
    int room_number;
};

//Function to display menu
void display_menu() {
    printf("\n\nWelcome to C Hotel Management System\n");
    printf("Choose an option from the menu:\n");
    printf("1. Book a room\n");
    printf("2. Check out a guest\n");
    printf("3. Display room status\n");
    printf("4. Exit\n");
}

//Function to book a room
void book_room(struct Room rooms[], int n) {
    int room, i;
    printf("\nEnter the room number: ");
    scanf("%d", &room);
    for (i=0; i<n; i++) {
        if (rooms[i].room_number == room && rooms[i].is_available == 1) {
            rooms[i].is_available = 0;
            printf("\nEnter guest details:\n");
            struct Guest guest;
            printf("Name: ");
            scanf("%s", guest.name);
            printf("Phone number: ");
            scanf("%s", guest.phone_number);
            printf("Email: ");
            scanf("%s", guest.email);
            guest.room_number = room;
            printf("\nRoom reserved successfully!\n");
            return;
        }
    }
    printf("\nRoom not available or does not exist!\n");
}

//Function to check out a guest
void check_out(struct Room rooms[], int n) {
    int room, i;
    printf("\nEnter the room number: ");
    scanf("%d", &room);
    for (i=0; i<n; i++) {
        if (rooms[i].room_number == room && rooms[i].is_available == 0) {
            rooms[i].is_available = 1;
            printf("\nGuest checked out successfully!\n");
            return;
        }
    }
    printf("\nRoom not available or does not exist!\n");
}

//Function to display room status
void display_rooms(struct Room rooms[], int n) {
    int i;
    printf("\nRoom #\tRoom Type\tPrice\tStatus\n");
    for (i=0; i<n; i++) {
        printf("%d\t%s\t\t%.2f\t%s\n", rooms[i].room_number, rooms[i].room_type, rooms[i].room_price,
               rooms[i].is_available == 1 ? "Available" : "Occupied");
    }
}

//Main function
int main() {
    struct Room rooms[10] = {{101, "Single", 100.00, 1}, {102, "Single", 100.00, 1}, {103, "Double", 150.00, 1},
                             {104, "Double", 150.00, 1}, {105, "Suite", 200.00, 1}, {106, "Suite", 200.00, 1},
                             {107, "Single", 100.00, 1}, {108, "Double", 150.00, 1}, {109, "Double", 150.00, 1},
                             {110, "Suite", 200.00, 1}};
    int n = 10, choice;
    printf("C Hotel Management System\n\n");
    do {
        display_menu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                book_room(rooms, n);
                break;
            case 2:
                check_out(rooms, n);
                break;
            case 3:
                display_rooms(rooms, n);
                break;
            case 4:
                printf("\nThank you for using C Hotel Management System!");
                break;
            default:
                printf("\nInvalid choice!\n");
        }
    } while (choice != 4);
    return 0;
}