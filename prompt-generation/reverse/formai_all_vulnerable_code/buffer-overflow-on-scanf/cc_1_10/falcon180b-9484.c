//Falcon-180B DATASET v1.0 Category: Time Travel Simulator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} Time;

void print_time(Time time) {
    printf("%04d-%02d-%02d %02d:%02d:%02d\n", time.year, time.month, time.day, time.hour, time.minute, time.second);
}

int main() {
    Time current_time, target_time;
    int choice;

    srand(time(NULL));
    current_time.year = rand() % 100 + 2000;
    current_time.month = rand() % 12 + 1;
    current_time.day = rand() % 28 + 1;
    current_time.hour = rand() % 24;
    current_time.minute = rand() % 60;
    current_time.second = rand() % 60;

    while (1) {
        printf("Current Time: ");
        print_time(current_time);
        printf("\n");

        printf("1. Travel to the future\n");
        printf("2. Travel to the past\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                target_time.year = current_time.year + rand() % 100;
                target_time.month = current_time.month + rand() % 12;
                target_time.day = current_time.day + rand() % 28;
                target_time.hour = current_time.hour + rand() % 24;
                target_time.minute = current_time.minute + rand() % 60;
                target_time.second = current_time.second + rand() % 60;
                break;
            case 2:
                target_time.year = current_time.year - rand() % 100;
                target_time.month = current_time.month - rand() % 12;
                target_time.day = current_time.day - rand() % 28;
                target_time.hour = current_time.hour - rand() % 24;
                target_time.minute = current_time.minute - rand() % 60;
                target_time.second = current_time.second - rand() % 60;
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }

        current_time = target_time;
    }

    return 0;
}