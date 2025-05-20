//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
int travel(int year);
void print_time(struct tm *time);

// Main function
int main() {
    int choice, year;

    while (1) {
        printf("Enter your choice:\n");
        printf("1. Travel to a specific year\n");
        printf("2. Travel to a random year\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the year you want to travel to: ");
                scanf("%d", &year);
                travel(year);
                break;
            case 2:
                srand(time(NULL));
                year = rand() % 1000 + 1;
                printf("You are traveling to the year %d.\n", year);
                travel(year);
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}

// Travel function
int travel(int year) {
    time_t now = time(NULL);
    struct tm *time = localtime(&now);

    // Set the year
    time->tm_year = year - 1900;

    // Print the time
    printf("You have traveled to the year %d.\n", time->tm_year + 1900);
    print_time(time);

    return 0;
}

// Print time function
void print_time(struct tm *time) {
    printf("Current date and time: %s", asctime(time));
}