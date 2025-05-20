//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct appointment {
    char* description;
    int date;
    int start_time;
    int duration;
    int status;
};

int main() {
    struct appointment app1 = {"Meeting with client", 1, 10, 1, 1};
    struct appointment app2 = {"Team meeting", 1, 14, 1, 1};
    struct appointment app3 = {"Lunch break", 1, 16, 1, 0};
    struct appointment app4 = {"Phone call", 1, 17, 1, 0};
    struct appointment app5 = {"Presentation", 1, 18, 1, 0};

    printf("Appointments:\n");
    printf("1. Meeting with client\n");
    printf("2. Team meeting\n");
    printf("3. Lunch break\n");
    printf("4. Phone call\n");
    printf("5. Presentation\n");
    printf("Enter the number of the appointment you want to schedule: ");
    scanf("%d", &app1.status);

    if (app1.status == 1) {
        printf("You have selected appointment 1: Meeting with client.\n");
        printf("Enter the date of the appointment: ");
        scanf("%d", &app1.date);
        printf("Enter the start time of the appointment: ");
        scanf("%d", &app1.start_time);
        printf("Enter the duration of the appointment in minutes: ");
        scanf("%d", &app1.duration);
    } else if (app1.status == 2) {
        printf("You have selected appointment 2: Team meeting.\n");
        printf("Enter the date of the appointment: ");
        scanf("%d", &app2.date);
        printf("Enter the start time of the appointment: ");
        scanf("%d", &app2.start_time);
        printf("Enter the duration of the appointment in minutes: ");
        scanf("%d", &app2.duration);
    } else if (app1.status == 3) {
        printf("You have selected appointment 3: Lunch break.\n");
        printf("Enter the date of the appointment: ");
        scanf("%d", &app3.date);
        printf("Enter the start time of the appointment: ");
        scanf("%d", &app3.start_time);
        printf("Enter the duration of the appointment in minutes: ");
        scanf("%d", &app3.duration);
    } else if (app1.status == 4) {
        printf("You have selected appointment 4: Phone call.\n");
        printf("Enter the date of the appointment: ");
        scanf("%d", &app4.date);
        printf("Enter the start time of the appointment: ");
        scanf("%d", &app4.start_time);
        printf("Enter the duration of the appointment in minutes: ");
        scanf("%d", &app4.duration);
    } else if (app1.status == 5) {
        printf("You have selected appointment 5: Presentation.\n");
        printf("Enter the date of the appointment: ");
        scanf("%d", &app5.date);
        printf("Enter the start time of the appointment: ");
        scanf("%d", &app5.start_time);
        printf("Enter the duration of the appointment in minutes: ");
        scanf("%d", &app5.duration);
    } else {
        printf("Invalid appointment number.\n");
        return 0;
    }

    printf("Appointment scheduled successfully!\n");

    return 0;
}