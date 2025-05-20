//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: multivariable
#include <stdio.h>
#include <time.h>

int main() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    int day, month, year, hour, minute;

    printf("Welcome to the Time Travel Simulator!\n");
    printf("Enter the date and time you want to travel to (in dd-mm-yyyy hh:mm format):\n");
    scanf("%d-%d-%d %d:%d", &day, &month, &year, &hour, &minute);

    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;
    tm.tm_hour = hour;
    tm.tm_min = minute;
    tm.tm_sec = 0;

    time_t future_time = mktime(&tm);

    if (future_time == (time_t)-1) {
        printf("Invalid date/time. Please try again.\n");
        return 1;
    }

    printf("You have successfully set the time to %02d-%02d-%d %02d:%02d.\n", day, month, year, hour, minute);

    while (1) {
        t = time(NULL);
        double seconds_left = difftime(future_time, t);

        if (seconds_left <= 0) {
            printf("You have arrived at your destination!\n");
            break;
        }

        int days_left = (int)(seconds_left / (60 * 60 * 24));
        seconds_left -= days_left * (60 * 60 * 24);

        int hours_left = (int)(seconds_left / (60 * 60));
        seconds_left -= hours_left * (60 * 60);

        int minutes_left = (int)(seconds_left / 60);
        seconds_left -= minutes_left * 60;

        printf("Time left until arrival: %d days, %02d:%02d:%02d\n", days_left, hours_left, minutes_left, (int)seconds_left);

        // Adjust the speed of time travel based on user input
        int speed;
        
        do {
            printf("Please enter the speed of time travel (1-10): ");
            scanf("%d", &speed);
        } while (speed < 1 || speed > 10);

        if (speed == 10) {
            break;
        }

        future_time += (time_t)(seconds_left / speed);
    }

    return 0;
}