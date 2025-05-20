//FormAI DATASET v1.0 Category: Hotel Management System ; Style: romantic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct guest {
    char name[50];
    char address[50];
    char room_type[10];
    int room_number;
} guests[100];

int count = 0;

void add_guest() {
    printf("\nEnter guest name: ");
    scanf("%s", &guests[count].name);
    printf("\nEnter guest address: ");
    scanf("%s", &guests[count].address);
    printf("\nEnter room type (Single/Double): ");
    scanf("%s", &guests[count].room_type);
    printf("\nEnter room number: ");
    scanf("%d", &guests[count].room_number);

    count++;

    printf("\nGuest added successfully!\n");
}

void print_guests() {
    printf("\nList of Guests:\n");
    printf("| %-10s | %-20s | %-15s | %-10s |\n", "Name", "Address", "Room Type", "Room No.");
    printf("+------------+----------------------+---------------+------------+\n");
    
    for(int i=0; i<count; i++) {
        printf("| %-10s | %-20s | %-15s | %-10d |\n", guests[i].name, guests[i].address, guests[i].room_type, guests[i].room_number);
    }
}

int main() {
    int choice;

    do {
        printf("\n\tHotel Management System\n");
        printf("==============================\n");
        printf("1. Add Guest\n");
        printf("2. View Guests\n");
        printf("3. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                add_guest();
                break;

            case 2:
                print_guests();
                break;

            case 3:
                exit(0);

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while(1);

    return 0;
}