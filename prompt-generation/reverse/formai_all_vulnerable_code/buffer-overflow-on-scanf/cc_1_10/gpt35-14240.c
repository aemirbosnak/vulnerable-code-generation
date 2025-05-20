//FormAI DATASET v1.0 Category: Hotel Management System ; Style: happy
#include<stdio.h>
#include<string.h>

struct guest {
    char name[50];
    char address[100];
    char contact[20];
    int room_no;
    int num_days;
};
struct guest g;

void book_room();
void view_details();

int main() {
    int choice;

    printf("Welcome to the C Hotel Management System\n");

    do {
        printf("\nMain Menu\n");
        printf("1. Book a room\n");
        printf("2. View details\n");
        printf("3. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                book_room();
                break;
            case 2:
                view_details();
                break;
            case 3:
                printf("\nThank you for using the C Hotel Management System\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

void book_room() {
    printf("\nBooking a room\n");

    printf("Enter your name: ");
    scanf("%s", g.name);

    printf("Enter your address: ");
    scanf("%s", g.address);

    printf("Enter your contact number: ");
    scanf("%s", g.contact);

    printf("Enter the room number: ");
    scanf("%d", &g.room_no);

    printf("Enter the number of days you will stay: ");
    scanf("%d", &g.num_days);

    printf("\nThank you for booking a room with us, %s!\n", g.name);
}

void view_details() {
    printf("\nViewing guest details\n");

    printf("Name: %s\n", g.name);
    printf("Address: %s\n", g.address);
    printf("Contact number: %s\n", g.contact);
    printf("Room number: %d\n", g.room_no);
    printf("Number of days stay: %d\n", g.num_days);
}