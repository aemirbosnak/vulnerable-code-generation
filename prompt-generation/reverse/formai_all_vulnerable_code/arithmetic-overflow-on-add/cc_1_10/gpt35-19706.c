//FormAI DATASET v1.0 Category: Date and time ; Style: curious
#include <stdio.h>
#include <time.h>

int main() {

    //Declare time_t variable to store seconds
    time_t current_time;

    //Get current time using time() function
    current_time = time(NULL);

    //Convert current time to local time
    struct tm *local_time = localtime(&current_time);

    //Print current date and time in DD-MM-YYYY HH:MM:SS format
    printf("Curious Date and Time Example\n");

    //Print current date in DD-MM-YYYY format
    printf("Current date is %02d-%02d-%d\n", local_time->tm_mday, local_time->tm_mon + 1, local_time->tm_year + 1900);

    //Print current time in HH:MM:SS format
    printf("Current time is %02d:%02d:%02d\n", local_time->tm_hour, local_time->tm_min, local_time->tm_sec);

    //Add 100000 seconds to current time
    current_time += 100000;
    local_time = localtime(&current_time);

    //Print date and time after adding 100000 seconds
    printf("\nDate and time after adding 100000 seconds\n");

    //Print date in DD-MM-YYYY format
    printf("Date is %02d-%02d-%d\n", local_time->tm_mday, local_time->tm_mon + 1, local_time->tm_year + 1900);

    //Print time in HH:MM:SS format
    printf("Time is %02d:%02d:%02d\n", local_time->tm_hour, local_time->tm_min, local_time->tm_sec);

    //Subtract 50000 seconds from current time
    current_time -= 50000;
    local_time = localtime(&current_time);

    //Print date and time after subtracting 50000 seconds
    printf("\nDate and time after subtracting 50000 seconds\n");

    //Print date in DD-MM-YYYY format
    printf("Date is %02d-%02d-%d\n", local_time->tm_mday, local_time->tm_mon + 1, local_time->tm_year + 1900);

    //Print time in HH:MM:SS format
    printf("Time is %02d:%02d:%02d\n", local_time->tm_hour, local_time->tm_min, local_time->tm_sec);

    return 0;
}