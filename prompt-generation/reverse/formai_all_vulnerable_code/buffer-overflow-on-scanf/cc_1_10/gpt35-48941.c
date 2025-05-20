//FormAI DATASET v1.0 Category: Hotel Management System ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

struct hotel {
    int room_number;
    char room_type[20];
    char guest_name[30];
    float price;
} rooms[100];

int count = 0;

void add_room() {
    printf("Enter Room Number: ");
    scanf("%d", &rooms[count].room_number);
    fflush(stdin);
    printf("Enter Room Type: ");
    gets(rooms[count].room_type);
    printf("Enter Guest Name: ");
    gets(rooms[count].guest_name);
    printf("Enter Price: ");
    scanf("%f", &rooms[count].price);
    count++;
    printf("Room Added Successfully!\n");
}

void delete_room() {
    int room_number, i, flag = 0;
    printf("Enter Room Number to Delete: ");
    scanf("%d", &room_number);
    for (i = 0; i < count; i++) {
        if (rooms[i].room_number == room_number) {
            flag = 1;
            rooms[i] = rooms[count-1];
            count--;
            printf("Room Deleted Successfully!\n");
            break;
        }
    }
    if (flag == 0) {
        printf("Room Not Found!\n");
    }
}

void search_room() {
    int room_number, i, flag = 0;
    printf("Enter Room Number to Search: ");
    scanf("%d", &room_number);
    for (i = 0; i < count; i++) {
        if (rooms[i].room_number == room_number) {
            flag = 1;
            printf("Room Number: %d\n", rooms[i].room_number);
            printf("Room Type: %s\n", rooms[i].room_type);
            printf("Guest Name: %s\n", rooms[i].guest_name);
            printf("Price: %.2f\n", rooms[i].price);
            break;
        }
    }
    if (flag == 0) {
        printf("Room Not Found!\n");
    }
}

void display_all_rooms() {
    int i;
    printf("Room Number\tRoom Type\tGuest Name\tPrice\n");
    for (i = 0; i < count; i++) {
        printf("%d\t\t%s\t\t%s\t\t%.2f\n", rooms[i].room_number, rooms[i].room_type, rooms[i].guest_name, rooms[i].price);
    }
}

int main() {
    int choice;
    do {
        printf("\n\n=== Hotel Management System ===\n");
        printf("1. Add Room\n");
        printf("2. Delete Room\n");
        printf("3. Search Room\n");
        printf("4. Display All Rooms\n");
        printf("5. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        fflush(stdin);
        switch (choice) {
            case 1:
                add_room();
                break;
            case 2:
                delete_room();
                break;
            case 3:
                search_room();
                break;
            case 4:
                display_all_rooms();
                break;
            case 5:
                printf("Exiting Hotel Management System...");
                exit(0);
            default:
                printf("Invalid Choice! Please Try Again.\n");
        }
    } while (choice != 5);
    return 0;
}