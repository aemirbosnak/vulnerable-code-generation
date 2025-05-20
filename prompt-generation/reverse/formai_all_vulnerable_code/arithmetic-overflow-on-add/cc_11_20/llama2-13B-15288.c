//LLAMA2-13B DATASET v1.0 Category: Hotel Management System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_GUESTS 100
#define MAX_ROOMS 10

typedef struct {
    int guest_id;
    char name[20];
    char email[50];
    int check_in_date;
    int check_out_date;
    int room_number;
} guest_info_t;

typedef struct {
    char room_name[20];
    int num_guests;
    int availability;
} room_info_t;

guest_info_t guests[MAX_GUESTS];
room_info_t rooms[MAX_ROOMS];

int main() {
    int i, j, k;
    char input[50];

    // Initialize guest and room information
    for (i = 0; i < MAX_GUESTS; i++) {
        guests[i].guest_id = i + 1;
        strcpy(guests[i].name, "Guest");
        strcpy(guests[i].email, "guest");
        guests[i].check_in_date = time(NULL);
        guests[i].check_out_date = time(NULL) + 24 * 60 * 60; // 1 day
        guests[i].room_number = -1;
    }

    for (i = 0; i < MAX_ROOMS; i++) {
        rooms[i].room_name[0] = 'R';
        rooms[i].num_guests = 0;
        rooms[i].availability = 1;
    }

    while (1) {
        // Display menu options
        printf("Welcome to the C Hotel Management System!\n");
        printf("Please enter your choice: \n");
        printf("1. Check in a guest\n");
        printf("2. Check out a guest\n");
        printf("3. View guest information\n");
        printf("4. Update room availability\n");
        printf("5. Quit\n");

        // Get user input
        scanf("%d", &k);

        // Process user input
        switch (k) {
            case 1:
                // Check in a guest
                printf("Please enter the guest's name: ");
                scanf("%s", input);
                for (i = 0; i < MAX_GUESTS; i++) {
                    if (strcmp(input, guests[i].name) == 0) {
                        break;
                    }
                }
                if (i == MAX_GUESTS) {
                    printf("Sorry, the guest already checked in\n");
                } else {
                    guests[i].check_in_date = time(NULL);
                    guests[i].check_out_date = time(NULL) + 24 * 60 * 60; // 1 day
                    printf("Guest %s checked in successfully\n", input);
                }
                break;

            case 2:
                // Check out a guest
                printf("Please enter the guest's name: ");
                scanf("%s", input);
                for (i = 0; i < MAX_GUESTS; i++) {
                    if (strcmp(input, guests[i].name) == 0) {
                        break;
                    }
                }
                if (i == MAX_GUESTS) {
                    printf("Sorry, the guest not found\n");
                } else {
                    guests[i].check_out_date = time(NULL);
                    printf("Guest %s checked out successfully\n", input);
                }
                break;

            case 3:
                // View guest information
                for (i = 0; i < MAX_GUESTS; i++) {
                    printf("%d. %s (%s) - Checked in: %s, Checked out: %s\n",
                           i + 1, guests[i].name, guests[i].email,
                           ctime(&guests[i].check_in_date),
                           ctime(&guests[i].check_out_date));
                }
                break;

            case 4:
                // Update room availability
                printf("Please enter the room number: ");
                scanf("%d", &j);
                for (i = 0; i < MAX_ROOMS; i++) {
                    if (rooms[i].room_name[0] == 'R' + j - '1') {
                        break;
                    }
                }
                if (i == MAX_ROOMS) {
                    printf("Sorry, the room not found\n");
                } else {
                    rooms[i].availability = !rooms[i].availability;
                    printf("Room %c%d is now %s\n", 'R' + j - '1', j,
                           rooms[i].availability ? "available" : "unavailable");
                }
                break;

            case 5:
                // Quit
                printf("Goodbye! Thank you for using the C Hotel Management System\n");
                break;
        }
    }

    return 0;
}