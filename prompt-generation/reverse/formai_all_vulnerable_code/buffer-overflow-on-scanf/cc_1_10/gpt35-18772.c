//FormAI DATASET v1.0 Category: Hotel Management System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct for storing room details
struct room {
    int room_no;
    char room_type[10];
    char guest_name[20];
    int room_avail;
};

void add_room(struct room *h) {
    int i;
    printf("Enter room number: ");
    scanf("%d", &(h->room_no));
    printf("Enter room type (single/double/triple): ");
    scanf("%s", h->room_type);
    printf("Enter room availability (1 for available/0 for booked): ");
    scanf("%d", &(h->room_avail));
    if (h->room_avail == 0) {
        printf("Enter guest name: ");
        scanf("%s", h->guest_name);
    }
}

void display_room(const struct room *h) {
    printf("%-10d %-10s %-10s %-10d\n", h->room_no, h->room_type, h->guest_name, h->room_avail);
}

void search_room(const struct room *h, int size, int room_no) {
    int i, flag = 0;
    for (i=0; i<size; i++) {
        if ((h+i)->room_no == room_no) {
            printf("Record found:\n");
            display_room(h+i);
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        printf("Record not found.\n");
}

void display_all(const struct room *h, int size) {
    int i;
    printf("%-10s %-10s %-10s %-10s\n", "Room no.", "Type", "Guest", "Availability");
    for (i=0; i<size; i++) {
        display_room(h+i);
    }
}

void book_room(struct room *h, int size) {
    int i, room_no;
    printf("Enter the room number to book: ");
    scanf("%d", &room_no);
    for (i=0; i<size; i++) {
        if ((h+i)->room_no == room_no) {
            if ((h+i)->room_avail == 0) {
                printf("Room %d is already booked by %s\n", (h+i)->room_no, (h+i)->guest_name);
            }
            else {
                printf("Enter guest name: ");
                scanf("%s", (h+i)->guest_name);
                (h+i)->room_avail = 0;
                printf("Room %d booked successfully.\n", (h+i)->room_no);
            }
            break;
        }
    }
    if (i == size)
        printf("Invalid input.\n");
}

int main() {
    int ch, size, i;
    struct room *h;
    printf("Enter the number of rooms: ");
    scanf("%d", &size);
    h = (struct room*) malloc(size * sizeof(struct room));
    for (i=0; i<size; i++) {
        printf("Enter details for room %d\n", i+1);
        add_room(h+i);
    }
    while (1) {
        printf("Menu:\n1. Display all rooms\n2. Search room by room number\n3. Book a room\n4. Exit\n");
        printf("Enter your choice (1/2/3/4): ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                display_all(h, size);
                break;
            case 2:
                printf("Enter the room number to search: ");
                scanf("%d", &ch);
                search_room(h, size, ch);
                break;
            case 3:
                book_room(h, size);
                break;
            case 4:
                printf("Thank you for using the program.\n");
                free(h);
                exit(0);
            default:
                printf("Invalid input.\n");
        }
    }
    return 0;
}