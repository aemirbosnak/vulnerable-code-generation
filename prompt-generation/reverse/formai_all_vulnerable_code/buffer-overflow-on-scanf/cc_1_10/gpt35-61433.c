//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <time.h>

int main() {
    // Get current time
    time_t current_time;
    time(&current_time);

    // Initialize time struct
    struct tm* time_info;
    time_info = localtime(&current_time);

    // Initialize user input variables
    int future_years, future_months, future_days, travel_sped;
    printf("Welcome to the Time Travel Simulator!\n");
    printf("Enter how many years from now you would like to travel: ");
    scanf("%d", &future_years);
    printf("Enter how many months from now you would like to travel: ");
    scanf("%d", &future_months);
    printf("Enter how many days from now you would like to travel: ");
    scanf("%d", &future_days);
    printf("Enter the speed of your time machine (in years per second): ");
    scanf("%d", &travel_sped);

    // Update time struct with future date
    time_info->tm_year += future_years;
    time_info->tm_mon += future_months;
    time_info->tm_mday += future_days;
    mktime(time_info);

    // Loop through time travel
    int elapsed_time = 0;
    while (elapsed_time <= (future_years*365*24*60*60 + future_months*30*24*60*60 + future_days*24*60*60)) {
        // Set time to current time plus elapsed time
        time_t new_time = current_time + elapsed_time;
        struct tm* new_time_info;
        new_time_info = localtime(&new_time);

        // Print current time
        printf("Current time: %d-%02d-%02d %02d:%02d:%02d\n", 
        new_time_info->tm_year + 1900, new_time_info->tm_mon + 1, new_time_info->tm_mday, 
        new_time_info->tm_hour, new_time_info->tm_min, new_time_info->tm_sec);

        // Add elapsed time based on time machine speed
        elapsed_time += (int) (1.0 / travel_sped * 365*24*60*60);

        // Wait for one second
        sleep(1);
    }

    printf("You have arrived at your destination!\n");

    return 0;
}