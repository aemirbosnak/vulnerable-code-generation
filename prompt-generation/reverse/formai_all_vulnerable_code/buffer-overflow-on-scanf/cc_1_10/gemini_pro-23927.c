//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person {
    char name[100];
    int age;
    char phone[100];
    char email[100];
} person;

typedef struct appointment {
    person person;
    char date[100];
    char time[100];
    char reason[100];
} appointment;

int main() {
    int n;
    printf("Enter the number of appointments: ");
    scanf("%d", &n);

    appointment *appointments = (appointment *)malloc(n * sizeof(appointment));

    for (int i = 0; i < n; i++) {
        printf("Enter the name of the person: ");
        scanf("%s", appointments[i].person.name);

        printf("Enter the age of the person: ");
        scanf("%d", &appointments[i].person.age);

        printf("Enter the phone number of the person: ");
        scanf("%s", appointments[i].person.phone);

        printf("Enter the email address of the person: ");
        scanf("%s", appointments[i].person.email);

        printf("Enter the date of the appointment: ");
        scanf("%s", appointments[i].date);

        printf("Enter the time of the appointment: ");
        scanf("%s", appointments[i].time);

        printf("Enter the reason for the appointment: ");
        scanf("%s", appointments[i].reason);
    }

    for (int i = 0; i < n; i++) {
        printf("\nAppointment %d:\n", i + 1);
        printf("Name: %s\n", appointments[i].person.name);
        printf("Age: %d\n", appointments[i].person.age);
        printf("Phone number: %s\n", appointments[i].person.phone);
        printf("Email address: %s\n", appointments[i].person.email);
        printf("Date: %s\n", appointments[i].date);
        printf("Time: %s\n", appointments[i].time);
        printf("Reason: %s\n", appointments[i].reason);
    }

    free(appointments);
    return 0;
}