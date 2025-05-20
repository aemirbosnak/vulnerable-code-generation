//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define MAX_DAYS 30 // Maximum number of days to track
#define MAX_EXERCISES 5 // Maximum exercises to track

// Exercise struct to hold exercise type and duration
typedef struct exercise_struct {
    char type[20];
    int duration; // in minutes
} Exercise; 

// Day struct to hold date and exercises
typedef struct day_struct {
    int day;
    int month;
    int year;
    Exercise exercises[MAX_EXERCISES];
} Day; 

// Main function to run the program
int main() {
    Day days[MAX_DAYS];
    int num_days = 0;
    char action;

    do {
        printf("Enter 'a' to add a day or 'q' to quit: ");
        scanf(" %c", &action);

        if (action == 'a') {
            if (num_days < MAX_DAYS) {
                Day new_day;
                printf("Enter the date (DD MM YYYY): ");
                scanf("%d %d %d", &new_day.day, &new_day.month, &new_day.year);

                for (int i = 0; i < MAX_EXERCISES; i++) {
                    Exercise new_exercise;
                    printf("Enter exercise type and duration (in minutes) for exercise %d: ", i+1);
                    scanf("%s %d", new_exercise.type, &new_exercise.duration);
                    new_day.exercises[i] = new_exercise;
                }

                days[num_days] = new_day;
                num_days++;
            } else {
                printf("Maximum number of days reached.\n");
            }
        } else {
            printf("Invalid option.\n");
        }

    } while (action != 'q');

    // Print weekly exercise report
    printf("Weekly Exercise Report:\n");
    printf("-----------------------\n");

    time_t t = time(NULL);
    struct tm *current_time = localtime(&t);
    int current_week = current_time->tm_yday / 7;

    int total_hrs = 0;

    for (int i = 0; i < num_days; i++) {
        struct tm time = {0};
        time.tm_year = days[i].year - 1900;
        time.tm_mon = days[i].month - 1;
        time.tm_mday = days[i].day;

        int day_of_year = mktime(&time) / (60*60*24);
        int week_of_year = day_of_year / 7;

        if (week_of_year == current_week) {
            printf("%d/%d/%d:\n", days[i].day, days[i].month, days[i].year);

            for (int j = 0; j < MAX_EXERCISES; j++) {
                printf("- %s: %d min\n", days[i].exercises[j].type, days[i].exercises[j].duration);
                total_hrs += days[i].exercises[j].duration;
            }

            printf("\n");
        }
    }

    printf("Total weekly exercise time: %d hours\n", total_hrs / 60);

    return 0;
}