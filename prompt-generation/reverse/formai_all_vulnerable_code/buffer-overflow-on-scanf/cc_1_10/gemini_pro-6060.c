//GEMINI-pro DATASET v1.0 Category: Hotel Management System ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int age;
    char address[100];
    char phone[20];
    char email[50];
} guest_t;

typedef struct {
    int room_no;
    char type[20];
    int price;
    int status; // 0 for available, 1 for occupied
} room_t;

typedef struct {
    guest_t guest;
    room_t room;
    int check_in_date;
    int check_out_date;
} reservation_t;

reservation_t reservations[100];
int num_reservations = 0;

void add_reservation() {
    printf("Enter guest name: ");
    scanf("%s", reservations[num_reservations].guest.name);

    printf("Enter guest age: ");
    scanf("%d", &reservations[num_reservations].guest.age);

    printf("Enter guest address: ");
    scanf("%s", reservations[num_reservations].guest.address);

    printf("Enter guest phone number: ");
    scanf("%s", reservations[num_reservations].guest.phone);

    printf("Enter guest email: ");
    scanf("%s", reservations[num_reservations].guest.email);

    printf("Enter room number: ");
    scanf("%d", &reservations[num_reservations].room.room_no);

    printf("Enter room type: ");
    scanf("%s", reservations[num_reservations].room.type);

    printf("Enter room price: ");
    scanf("%d", &reservations[num_reservations].room.price);

    printf("Enter check-in date: ");
    scanf("%d", &reservations[num_reservations].check_in_date);

    printf("Enter check-out date: ");
    scanf("%d", &reservations[num_reservations].check_out_date);

    num_reservations++;
}

void view_reservations() {
    for (int i = 0; i < num_reservations; i++) {
        printf("Reservation %d:\n", i + 1);
        printf("Guest name: %s\n", reservations[i].guest.name);
        printf("Guest age: %d\n", reservations[i].guest.age);
        printf("Guest address: %s\n", reservations[i].guest.address);
        printf("Guest phone number: %s\n", reservations[i].guest.phone);
        printf("Guest email: %s\n", reservations[i].guest.email);
        printf("Room number: %d\n", reservations[i].room.room_no);
        printf("Room type: %s\n", reservations[i].room.type);
        printf("Room price: %d\n", reservations[i].room.price);
        printf("Check-in date: %d\n", reservations[i].check_in_date);
        printf("Check-out date: %d\n", reservations[i].check_out_date);
        printf("\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("1. Add reservation\n");
        printf("2. View reservations\n");
        printf("3. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_reservation();
                break;
            case 2:
                view_reservations();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}