//Gemma-7B DATASET v1.0 Category: Hotel Management System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define MAX_GUESTS 10

typedef struct Guest {
    char name[50];
    int room_no;
    float bill;
} Guest;

Guest guests[MAX_GUESTS];

int main() {

    int i, j, choice, guest_no, found = 0;
    float total_bill = 0;

    // Create guests
    for (i = 0; i < MAX_GUESTS; i++) {
        guests[i].name[0] = '\0';
        guests[i].room_no = 0;
        guests[i].bill = 0.0f;
    }

    // Menu options
    printf("Welcome to the C Hotel Management System!\n");
    printf("1. Check In\n");
    printf("2. Check Out\n");
    printf("3. View Bills\n");
    printf("Please enter your choice: ");

    // Get user input
    scanf("%d", &choice);

    // Process user input
    switch (choice) {
        case 1:
            // Check In
            printf("Enter your name: ");
            scanf("%s", guests[guest_no].name);
            printf("Enter your room number: ");
            scanf("%d", &guests[guest_no].room_no);
            printf("Enter your bill: ");
            scanf("%f", &guests[guest_no].bill);
            break;
        case 2:
            // Check Out
            printf("Enter your room number: ");
            scanf("%d", &guest_no);
            found = 0;
            for (i = 0; i < MAX_GUESTS; i++) {
                if (guests[i].room_no == guest_no) {
                    found = 1;
                    printf("Enter your new bill: ");
                    scanf("%f", &guests[i].bill);
                    break;
                }
            }
            if (!found) {
                printf("Guest not found.\n");
            }
            break;
        case 3:
            // View Bills
            for (i = 0; i < MAX_GUESTS; i++) {
                if (guests[i].name[0] != '\0') {
                    printf("Name: %s\n", guests[i].name);
                    printf("Room Number: %d\n", guests[i].room_no);
                    printf("Bill: %.2f\n", guests[i].bill);
                    total_bill += guests[i].bill;
                }
            }
            printf("Total Bill: %.2f\n", total_bill);
            break;
    }

    return 0;
}