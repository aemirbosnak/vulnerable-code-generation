//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DAYS 7
#define MAX_APPOINTMENTS 24

struct Appointment {
    char day[20];
    char startTime[10];
    char endTime[10];
    char subject[50];
    int priority;
};

struct Appointment appointments[MAX_APPOINTMENTS];
int numAppointments = 0;

void scheduleAppointment(struct Appointment* a) {
    int day, startHour, startMinute, endHour, endMinute;
    char subject[50];
    
    printf("Enter day of the week (1-7): ");
    scanf("%d", &day);
    if (day < 1 || day > MAX_DAYS) {
        printf("Invalid day entered.\n");
        return;
    }
    
    printf("Enter start time (hh:mm): ");
    scanf("%d:%d", &startHour, &startMinute);
    if (startHour < 0 || startHour > 23 || startMinute < 0 || startMinute > 59) {
        printf("Invalid start time entered.\n");
        return;
    }
    
    printf("Enter end time (hh:mm): ");
    scanf("%d:%d", &endHour, &endMinute);
    if (endHour < 0 || endHour > 23 || endMinute < 0 || endMinute > 59) {
        printf("Invalid end time entered.\n");
        return;
    }
    
    printf("Enter subject: ");
    fgets(subject, sizeof(subject), stdin);
    strncpy(subject, subject, sizeof(subject));
    
    a->day[0] = day + 'a';
    a->startTime[0] = startHour + '0';
    a->endTime[0] = endHour + '0';
    strncpy(a->subject, subject, sizeof(a->subject));
    a->priority = 0;
    
    printf("Appointment scheduled successfully.\n");
}

void printAppointments() {
    printf("Appointments for today:\n");
    int i;
    for (i = 0; i < numAppointments; i++) {
        struct Appointment a = appointments[i];
        printf("Day: %c\n", a.day[0]);
        printf("Start time: %d:%d\n", a.startTime[0] - '0', a.startTime[1] - '0');
        printf("End time: %d:%d\n", a.endTime[0] - '0', a.endTime[1] - '0');
        printf("Subject: %s\n", a.subject);
        printf("Priority: %d\n", a.priority);
        printf("\n");
    }
}

int main() {
    int choice;
    char c;
    
    do {
        printf("Welcome to the Appointment Scheduler!\n");
        printf("-------------------------------\n");
        printf("1. Schedule an appointment\n");
        printf("2. Print appointments\n");
        printf("3. Quit\n");
        printf("-------------------------------\n");
        printf("Enter your choice: ");
        scanf(" %d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter day of the week (1-7): ");
                scanf(" %d", &c);
                break;
            case 2:
                printAppointments();
                break;
            case 3:
                printf("Thank you for using the Appointment Scheduler!\n");
                break;
            default:
                printf("Invalid choice entered.\n");
        }
    } while (choice!= 3);
    
    return 0;
}