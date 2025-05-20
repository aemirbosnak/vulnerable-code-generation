//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice, year;
    char time_machine[50];

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Please choose a time machine:\n");
    printf("1. DeLorean\n");
    printf("2. TARDIS\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            strcpy(time_machine, "DeLorean");
            break;
        case 2:
            strcpy(time_machine, "TARDIS");
            break;
        default:
            printf("Invalid choice.\n");
            return 0;
    }

    printf("Enter the year you want to travel to (between 1900 and 2099): ");
    scanf("%d", &year);

    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    t->tm_year = year - 1900;
    time_t target_time = mktime(t);

    if(difftime(target_time, now) < 0) {
        printf("You cannot travel back in time!\n");
    } else {
        printf("Get ready for time travel in the %s!\n", time_machine);
        sleep(2);
        printf("3...2...1...\n");
        sleep(1);
        printf("Time travel initiated...\n");
        sleep(2);
        printf("Arriving in %d...\n", year);
        sleep(1);
        printf("Welcome to the year %d!\n", year);
    }

    return 0;
}