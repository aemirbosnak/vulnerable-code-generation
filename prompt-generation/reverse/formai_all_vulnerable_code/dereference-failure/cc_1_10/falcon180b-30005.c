//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100

struct Appointment {
    char name[50];
    char phone[15];
    char reason[100];
    time_t date;
};

void addAppointment(struct Appointment *appointments, int *count) {
    printf("Enter name: ");
    scanf("%s", appointments[*count].name);

    printf("Enter phone number: ");
    scanf("%s", appointments[*count].phone);

    printf("Enter reason for appointment: ");
    scanf("%s", appointments[*count].reason);

    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", appointments[*count].date);

    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    tm->tm_year += 1900;
    tm->tm_mon += 1;
    tm->tm_mday += 1;
    mktime(tm);

    (*count)++;
}

void displayAppointments(struct Appointment *appointments, int count) {
    printf("\nAppointments:\n");
    printf("-----------------\n");
    for (int i = 0; i < count; i++) {
        printf("%s - %s - %s - %s\n", appointments[i].name, appointments[i].phone, appointments[i].reason, ctime(&appointments[i].date));
    }
}

int main() {
    struct Appointment appointments[MAX_APPOINTMENTS];
    int count = 0;

    while (count < MAX_APPOINTMENTS) {
        addAppointment(appointments, &count);
        printf("\nDo you want to add another appointment? (y/n): ");
        char choice;
        scanf("%c", &choice);
        if (choice!= 'y') {
            break;
        }
    }

    displayAppointments(appointments, count);

    return 0;
}