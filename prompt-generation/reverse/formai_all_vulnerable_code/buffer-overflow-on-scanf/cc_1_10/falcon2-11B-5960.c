//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_DAYS 31
#define MAX_HOURS 24
#define MAX_MINUTES 60
#define MAX_NAME 50
#define MAX_DESCRIPTION 100

typedef struct appointment_s {
    char name[MAX_NAME];
    char description[MAX_DESCRIPTION];
    int day;
    int hour;
    int minute;
    int duration;
} appointment_t;

void get_appointments(int n, appointment_t *arr) {
    int i;
    for (i = 0; i < n; i++) {
        scanf("%s %s %d %d %d", arr[i].name, arr[i].description, &arr[i].day, &arr[i].hour, &arr[i].minute);
    }
}

void print_appointments(int n, appointment_t *arr) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%s: %s %d:%d:%d\n", arr[i].name, arr[i].description, arr[i].day, arr[i].hour, arr[i].minute);
    }
}

int main() {
    int n, i, day, hour, minute, duration;
    appointment_t *arr = (appointment_t *)malloc(n * sizeof(appointment_t));

    printf("Enter the number of appointments: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("No appointments.\n");
    } else {
        get_appointments(n, arr);
        printf("Appointments:\n");
        print_appointments(n, arr);
        printf("Enter the day (1-%d): ", MAX_DAYS);
        scanf("%d", &day);
        printf("Enter the hour (0-%d): ", MAX_HOURS);
        scanf("%d", &hour);
        printf("Enter the minute (0-%d): ", MAX_MINUTES);
        scanf("%d", &minute);
        printf("Enter the duration (0-%d): ", MAX_MINUTES);
        scanf("%d", &duration);

        for (i = 0; i < n; i++) {
            if (arr[i].day == day && arr[i].hour == hour && arr[i].minute == minute && arr[i].duration == duration) {
                printf("Appointment found!\n");
                free(arr[i].name);
                free(arr[i].description);
                free(arr[i].day);
                free(arr[i].hour);
                free(arr[i].minute);
                free(arr[i].duration);
                break;
            }
        }
    }

    free(arr);
    return 0;
}