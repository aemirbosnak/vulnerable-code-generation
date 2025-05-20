//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct appointment {
    int day;
    char month[10];
    int year;
    int hour;
    int minute;
    char description[100];
};

int main() {
    int menu;
    struct appointment a[10]; // creating an array of 10 appointment structures
    int count = 0; // count variable to keep track of the number of appointments added

    while(1) {
        printf("\nWelcome to Appointment Scheduler\n");
        printf("1. Add Appointment\n");
        printf("2. View Appointments\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &menu);
        fflush(stdin);

        switch(menu) {
            case 1:
                printf("Enter the day (1-31): ");
                scanf("%d", &a[count].day);
                fflush(stdin);

                printf("Enter the month (e.g. January): ");
                gets(a[count].month);

                printf("Enter the year (e.g. 2022): ");
                scanf("%d", &a[count].year);
                fflush(stdin);

                printf("Enter the hour (0-23): ");
                scanf("%d", &a[count].hour);
                fflush(stdin);

                printf("Enter the minute (0-59): ");
                scanf("%d", &a[count].minute);
                fflush(stdin);

                printf("Enter the appointment description: ");
                gets(a[count].description);

                printf("Appointment added successfully.\n");
                count++;
                break;

            case 2:
                printf("\nScheduled Appointments:\n");
                if(count == 0) {
                    printf("There are no appointments to show.\n");
                    break;
                }
                for(int i=0; i<count; i++) {
                    printf("Appointment %d:\n", i+1);
                    printf("Date: %d %s %d\n", a[i].day, a[i].month, a[i].year);
                    printf("Time: %02d:%02d\n", a[i].hour, a[i].minute);
                    printf("Description: %s\n", a[i].description);
                }
                break;

            case 3:
                printf("\nThank you for using Appointment Scheduler!\n");
                exit(0);
                break;

            default:
                printf("\nInvalid choice. Please enter a valid choice.\n");
                break;
        }
    }
    return 0;
}