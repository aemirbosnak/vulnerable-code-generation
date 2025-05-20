//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: statistical
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_DAYS 31
#define MAX_APPTS 24

#define DAY_OF_WEEK "Mon Tue Wed Thu Fri Sat Sun"
#define DAY_ABBR "Mon Tue Wed Thu Fri Sat Sun"

typedef struct {
    char name[50];
    int day;
    int hour;
} Appt;

int main() {
    int days[MAX_DAYS] = {0};
    int num_appts = 0;
    int hour_of_day = 0;

    printf("Enter the day(s) of the week you want to schedule appointments for: ");
    fflush(stdout);
    scanf("%s", days);
    for (int i = 0; i < strlen(days); i++) {
        days[i] = toupper(days[i]) - 'A';
    }

    printf("Enter the hour of the day you want to schedule appointments for: ");
    fflush(stdout);
    scanf("%d", &hour_of_day);

    Appt appts[MAX_APPTS] = {0};
    printf("Enter the name of the appointment: ");
    fflush(stdout);
    for (int i = 0; i < num_appts; i++) {
        scanf("%s %d %d", appts[i].name, &appts[i].day, &appts[i].hour);
        if (appts[i].day > MAX_DAYS || appts[i].hour > MAX_APPTS) {
            printf("Invalid day or hour. Please enter a day and hour between 1 and %d.\n", MAX_DAYS - 1);
            return 1;
        }
    }

    printf("Your appointments are:\n");
    for (int i = 0; i < num_appts; i++) {
        printf("%s at %d:00 on %s\n", appts[i].name, appts[i].hour, DAY_OF_WEEK[appts[i].day - 1]);
    }

    return 0;
}