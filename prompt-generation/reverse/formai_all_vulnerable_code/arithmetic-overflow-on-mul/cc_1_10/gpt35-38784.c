//FormAI DATASET v1.0 Category: Hotel Management System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct guest {
    char name[50];
    int room_num;
    int days_staying;
    float total_bill;
};

int total_guests = 0;
struct guest guests[50];

void add_guest() {
    printf("Enter guest name: ");
    scanf(" %[^\n]s", guests[total_guests].name);
    printf("Enter room number: ");
    scanf("%d", &guests[total_guests].room_num);
    printf("Enter number of days staying: ");
    scanf("%d", &guests[total_guests].days_staying);
    guests[total_guests].total_bill = 100 * guests[total_guests].days_staying;
    total_guests++;
    printf("\nGuest added successfully!\n");
}

void check_out() {
    int room_num;
    printf("Enter room number of the guest to check out: ");
    scanf("%d", &room_num);
    for (int i = 0; i < total_guests; i++) {
        if (guests[i].room_num == room_num) {
            printf("\nGuest %s checked out. Total bill: $%.2f\n", guests[i].name, guests[i].total_bill);
            for (int j = i; j < total_guests - 1; j++) {
                guests[j] = guests[j + 1];
            }
            total_guests--;
            return;
        }
    }
    printf("\nRoom number not found.\n");
}

void display_guests() {
    printf("\n=======================\n");
    printf("| %-20s | %-10s |\n", "Name", "Room #");
    printf("=======================\n");
    for (int i = 0; i < total_guests; i++) {
        printf("| %-20s | %-10d |\n", guests[i].name, guests[i].room_num);
    }
    printf("=======================\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nWelcome to C Hotel Management System!\n");
        printf("1. Add Guest\n");
        printf("2. Check Out Guest\n");
        printf("3. Display Guests\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_guest();
                break;
            case 2:
                check_out();
                break;
            case 3:
                display_guests();
                break;
            case 4:
                printf("\nThank you for using C Hotel Management System!\n");
                exit(0);
            default:
                printf("\nInvalid choice.\n");
        }
    }
    return 0;
}