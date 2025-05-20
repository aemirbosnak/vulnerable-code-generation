//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_APPOINTMENT_LENGTH 50

typedef struct {
    char name[50];
    char phone[15];
    char reason[MAX_APPOINTMENT_LENGTH];
    int date;
    int time;
} appointment;

void add_appointment(appointment* appointments, int count) {
    printf("Enter name: ");
    scanf("%s", appointments[count].name);
    printf("Enter phone number: ");
    scanf("%s", appointments[count].phone);
    printf("Enter reason for appointment: ");
    scanf("%s", appointments[count].reason);
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%d", &appointments[count].date);
    printf("Enter time (HH:MM): ");
    scanf("%d", &appointments[count].time);
    count++;
}

void display_appointments(appointment* appointments, int count) {
    printf("Name\tPhone\tReason\tDate\tTime\n");
    for(int i=0; i<count; i++) {
        printf("%s\t%s\t%s\t%d-%02d-%02d\t%02d:%02d\n", appointments[i].name, appointments[i].phone, appointments[i].reason, appointments[i].date, appointments[i].date%100, appointments[i].time);
    }
}

int main() {
    appointment appointments[MAX_APPOINTMENTS];
    int count = 0;
    add_appointment(appointments, count);

    while(count < MAX_APPOINTMENTS) {
        printf("Do you want to add another appointment? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if(choice == 'y' || choice == 'Y') {
            add_appointment(appointments, count);
        } else {
            display_appointments(appointments, count);
            break;
        }
    }

    return 0;
}