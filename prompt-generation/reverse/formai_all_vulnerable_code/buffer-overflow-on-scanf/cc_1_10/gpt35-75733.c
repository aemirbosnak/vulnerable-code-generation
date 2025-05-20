//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: automated
#include <stdio.h>
#include <time.h>

int main(){
    //set current date and time
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    int year, month, day, hour, min, sec;
    int choice;
    printf("Welcome to Time Travel Simulator!\n");
    printf("Enter the year: ");
    scanf("%d", &year);
    printf("Enter the month (1-12): ");
    scanf("%d", &month);
    printf("Enter the day (1-31): ");
    scanf("%d", &day);
    printf("Enter the hour (0-23): ");
    scanf("%d", &hour);
    printf("Enter the minute (0-59): ");
    scanf("%d", &min);
    printf("Enter the second (0-59): ");
    scanf("%d", &sec);

    //set future date and time
    struct tm future;
    future.tm_year = year - 1900;   //years since 1900
    future.tm_mon = month - 1;      //0-11
    future.tm_mday = day;           //1-31
    future.tm_hour = hour;          //0-23
    future.tm_min = min;            //0-59
    future.tm_sec = sec;            //0-59
    time_t time_future = mktime(&future);

    //calculate time difference
    double diff_seconds = difftime(time_future, now);

    printf("You have entered the following date and time:\n");
    printf("%d-%02d-%02d %02d:%02d:%02d\n", year, month, day, hour, min, sec);

    if (diff_seconds < 0){
        printf("You have entered a date and time in the past. Do you want to travel to this time? (1 = Yes / 0 = No): ");
        scanf("%d", &choice);
        if (choice == 0){
            printf("Goodbye!\n");
            return 0;
        }
    }

    printf("\nChecking time machine... \n");
    int i;
    for(i = 3; i > 0 ; i--){
        printf("%d.. ", i);
        fflush(stdout);
        sleep(1);   //wait for 1 second
    }

    printf("\n\nCongratulations! You have just time travelled to: \n");
    printf("%d-%02d-%02d %02d:%02d:%02d\n\n", year, month, day, hour, min, sec);

    return 0;
}