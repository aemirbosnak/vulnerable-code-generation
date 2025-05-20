//FormAI DATASET v1.0 Category: Hotel Management System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct guest {
    int room_number;
    char name[30];
    int age;
    int days_stayed;
    float bill_amount;
} Guest;

Guest guests[100];
int num_guests = 0;

void add_guest() {
    printf("Enter guest name: ");
    scanf("%s", guests[num_guests].name);
    printf("Enter guest age: ");
    scanf("%d", &guests[num_guests].age);
    printf("Enter room number: ");
    scanf("%d", &guests[num_guests].room_number);
    printf("Enter days stayed: ");
    scanf("%d", &guests[num_guests].days_stayed);
    guests[num_guests].bill_amount = guests[num_guests].days_stayed * 100.0;
    num_guests++;
    printf("Guest added successfully!\n\n");
}

void display_guests() {
    printf("Room Number\tName\t\tAge\tDays Stayed\tBill Amount\n");
    for (int i = 0; i < num_guests; i++) {
        printf("%d\t\t%s\t\t%d\t%d\t\t%.2f\n", guests[i].room_number, guests[i].name, guests[i].age, guests[i].days_stayed, guests[i].bill_amount);
    }
}

int main() {
    int choice;
    do {
        printf("Welcome to C Hotel Management System!\n");
        printf("1. Add Guest\n");
        printf("2. Display Guests\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_guest();
                break;
            case 2:
                display_guests();
                break;
            case 3:
                printf("Thanks for using C Hotel Management System!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);

    return 0;
}