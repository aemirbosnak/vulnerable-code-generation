//Falcon-180B DATASET v1.0 Category: Automated Fortune Teller ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int num = 0;
    int random_num = 0;
    int random_num2 = 0;
    int random_num3 = 0;
    char again = 'y';
    char fortune_cookie[100];
    char fortune[100];

    srand(time(0));

    // Fortune Cookie Generator
    while (again == 'y' || again == 'Y') {
        printf("What would you like to do?\n");
        printf("1. Get a fortune cookie\n");
        printf("2. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                random_num = rand() % 10; // Generate random number between 0-9
                random_num2 = rand() % 10; // Generate random number between 0-9
                random_num3 = rand() % 10; // Generate random number between 0-9

                num = (random_num * 100) + (random_num2 * 10) + random_num3; // Combine random numbers to get unique number

                sprintf(fortune_cookie, "Your fortune cookie number is %d\n", num); // Create fortune cookie message
                printf("%s", fortune_cookie); // Display fortune cookie message

                sprintf(fortune, "Fortune #%d: %s\n", num, fortune_cookie); // Create fortune message
                printf("%s", fortune); // Display fortune message
                break;

            case 2:
                printf("Thank you for using the Automated Fortune Teller!\n");
                again = 'n'; // Exit loop
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}