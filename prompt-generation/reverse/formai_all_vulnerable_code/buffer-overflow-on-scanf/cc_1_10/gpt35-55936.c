//FormAI DATASET v1.0 Category: Hotel Management System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct guest {
    char name[50];
    int room_no;
    int days_stayed;
    float total_bill;
};

struct guest guests[100]; // Maximum of 100 guests

int num_guests = 0;

void add_guest() {
    if (num_guests >= 100) {
        printf("Sorry, the hotel is currently full.\n");
        return;
    }

    printf("Enter guest name: ");
    scanf("%s", guests[num_guests].name);

    printf("Enter room number (1-100): ");
    scanf("%d", &guests[num_guests].room_no);

    printf("Enter number of days stayed: ");
    scanf("%d", &guests[num_guests].days_stayed);

    // Calculate total bill
    guests[num_guests].total_bill = guests[num_guests].days_stayed * 100.0;

    num_guests++;

    printf("Guest added successfully.\n");
}

void view_guests() {
    printf("Guests currently staying at the hotel:\n");
    for (int i = 0; i < num_guests; i++) {
        printf("Name: %s\n", guests[i].name);
        printf("Room Number: %d\n", guests[i].room_no);
        printf("Days Stayed: %d\n", guests[i].days_stayed);
        printf("Total Bill: %.2f\n", guests[i].total_bill);
        printf("\n");
    }
}

void search_guest() {
    char search_name[50];
    printf("Enter guest name to search: ");
    scanf("%s", search_name);

    for (int i = 0; i < num_guests; i++) {
        if (strcmp(search_name, guests[i].name) == 0) {
            printf("Name: %s\n", guests[i].name);
            printf("Room Number: %d\n", guests[i].room_no);
            printf("Days Stayed: %d\n", guests[i].days_stayed);
            printf("Total Bill: %.2f\n", guests[i].total_bill);
            return;
        }
    }

    printf("Guest not found.\n");
}

int main() {
    int choice;
    do {
        printf("Hotel Management System\n");
        printf("1. Add Guest\n");
        printf("2. View Guests\n");
        printf("3. Search Guest\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_guest();
                break;
            case 2:
                view_guests();
                break;
            case 3:
                search_guest();
                break;
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");

    } while (1);

    return 0;
}