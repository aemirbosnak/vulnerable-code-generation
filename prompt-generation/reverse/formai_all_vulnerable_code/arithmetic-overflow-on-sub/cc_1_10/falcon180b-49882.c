//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int choice;
    int year, month, day, hour, minute, second;
    struct tm time;
    time_t now;

    printf("Welcome to the Time Travel Simulator!\n\n");
    printf("Please enter your destination:\n");
    printf("1. Ancient Egypt\n2. Renaissance Italy\n3. Victorian England\n4. Roaring Twenties\n5. Future\n");
    scanf("%d", &choice);

    printf("Enter the date and time you wish to depart:\n");
    printf("Year: ");
    scanf("%d", &year);
    printf("Month (1-12): ");
    scanf("%d", &month);
    printf("Day: ");
    scanf("%d", &day);
    printf("Hour (0-23): ");
    scanf("%d", &hour);
    printf("Minute: ");
    scanf("%d", &minute);
    printf("Second: ");
    scanf("%d", &second);

    time.tm_year = year - 1900;
    time.tm_mon = month - 1;
    time.tm_mday = day;
    time.tm_hour = hour;
    time.tm_min = minute;
    time.tm_sec = second;

    now = mktime(&time);
    if (now == -1) {
        printf("Invalid date and time.\n");
        exit(1);
    }

    switch (choice) {
        case 1:
            printf("You are now in Ancient Egypt.\n");
            break;
        case 2:
            printf("You are now in Renaissance Italy.\n");
            break;
        case 3:
            printf("You are now in Victorian England.\n");
            break;
        case 4:
            printf("You are now in the Roaring Twenties.\n");
            break;
        case 5:
            printf("You are now in the Future.\n");
            break;
        default:
            printf("Invalid destination.\n");
            exit(1);
    }

    return 0;
}