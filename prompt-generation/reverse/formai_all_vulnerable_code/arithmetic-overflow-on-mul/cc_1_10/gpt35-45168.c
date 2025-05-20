//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    time_t currentTime = time(NULL);
    struct tm* localTime = localtime(&currentTime);

    int currentYear = localTime->tm_year + 1900;
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Today's date is: %d-%02d-%02d\n", currentYear, localTime->tm_mon+1, localTime->tm_mday);

    printf("\nWhere would you like to go?\n");
    printf("1. Past\n");
    printf("2. Future\n");
    int timeSelection;
    printf("Enter your choice: ");
    scanf("%d", &timeSelection);

    if (timeSelection == 1) {
        printf("\nHow far back would you like to go?\n");
        printf("1. 1 year ago\n");
        printf("2. 10 years ago\n");
        printf("3. Custom year\n");
        int pastSelection;
        printf("Enter your choice: ");
        scanf("%d", &pastSelection);

        if (pastSelection == 1) {
            struct tm* pastTime = localtime(&currentTime - (365 * 24 * 60 * 60));
            int pastYear = pastTime->tm_year + 1900;
            printf("\nWelcome to the year %d!\n", pastYear);
        }
        else if (pastSelection == 2) {
            struct tm* pastTime = localtime(&currentTime - (10 * 365 * 24 * 60 * 60));
            int pastYear = pastTime->tm_year + 1900;
            printf("\nWelcome to the year %d!\n", pastYear);
        }
        else if (pastSelection == 3) {
            int customYear;
            printf("\nEnter a year: ");
            scanf("%d", &customYear);
            struct tm* pastTime = localtime(&currentTime - ((currentYear - customYear) * 365 * 24 * 60 * 60));
            printf("\nWelcome to the year %d!\n", customYear);
        }
        else {
            printf("\nInvalid selection.\n");
            exit(0);
        }
    }
    else if (timeSelection == 2) {
        printf("\nHow far into the future would you like to go?\n");
        printf("1. 1 year from now\n");
        printf("2. 10 years from now\n");
        printf("3. Custom year\n");
        int futureSelection;
        printf("Enter your choice: ");
        scanf("%d", &futureSelection);

        if (futureSelection == 1) {
            struct tm* futureTime = localtime(&currentTime + (365 * 24 * 60 * 60));
            int futureYear = futureTime->tm_year + 1900;
            printf("\nWelcome to the year %d!\n", futureYear);
        }
        else if (futureSelection == 2) {
            struct tm* futureTime = localtime(&currentTime + (10 * 365 * 24 * 60 * 60));
            int futureYear = futureTime->tm_year + 1900;
            printf("\nWelcome to the year %d!\n", futureYear);
        }
        else if (futureSelection == 3) {
            int customYear;
            printf("\nEnter a year: ");
            scanf("%d", &customYear);
            struct tm* futureTime = localtime(&currentTime + ((customYear - currentYear) * 365 * 24 * 60 * 60));
            printf("\nWelcome to the year %d!\n", customYear);
        }
        else {
            printf("\nInvalid selection.\n");
            exit(0);
        }
    }
    else {
        printf("\nInvalid selection.\n");
        exit(0);
    }
    return 0;
}