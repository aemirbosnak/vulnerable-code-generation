//FormAI DATASET v1.0 Category: Hotel Management System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct room {
    int room_num;
    char room_type[10];
    char room_guest[50];
    float rate;
};

void check_in(struct room* rm) {
    printf("Welcome to the Hotel Bizzaro! Please enter your name: ");
    scanf("%s", rm->room_guest);
    printf("Which room type would you like to book? (single/double/triple): ");
    scanf("%s", rm->room_type);
    printf("Enter the room number: ");
    scanf("%d", &rm->room_num);
    printf("Enter the nightly rate: ");
    scanf("%f", &rm->rate);
    printf("Thank you! Your reservation has been confirmed. Enjoy your stay.\n");
}

void check_out(struct room* rm) {
    printf("We hope you had a pleasant stay at our hotel!\n");
    printf("Your bill is: $%.2f\n", rm->rate);
    rm->room_guest[0] = '\0';
    rm->room_type[0] = '\0';
    rm->room_num = 0;
    rm->rate = 0.0;
}

int main() {
    struct room rm;
    rm.room_guest[0] = '\0';
    rm.room_type[0] = '\0';
    rm.room_num = 0;
    rm.rate = 0.0;

    printf("Welcome to the Hotel Bizzaro! How may we assist you today?\n");
    printf("1. Check in\n");
    printf("2. Check out\n");
    printf("3. Exit\n");

    int choice;
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                check_in(&rm);
                break;
            case 2:
                check_out(&rm);
                break;
            case 3:
                printf("Thank you for choosing the Hotel Bizzaro. Come back soon!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}