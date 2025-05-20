//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DATE_LENGTH 15
#define MAX_TIME_LENGTH 10
#define MAX_PHONE_LENGTH 15

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char date[MAX_DATE_LENGTH];
    char time[MAX_TIME_LENGTH];
} appointment;

appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment() {
    printf("Enter name: ");
    scanf("%s", appointments[num_appointments].name);
    printf("Enter phone number: ");
    scanf("%s", appointments[num_appointments].phone);
    printf("Enter date (MM/DD/YYYY): ");
    scanf("%s", appointments[num_appointments].date);
    printf("Enter time (HH:MM AM/PM): ");
    scanf("%s", appointments[num_appointments].time);
    num_appointments++;
}

void view_appointments() {
    printf("Appointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%d. %s - %s - %s - %s\n", i+1, appointments[i].name, appointments[i].phone, appointments[i].date, appointments[i].time);
    }
}

void delete_appointment() {
    int index;
    printf("Enter appointment number to delete: ");
    scanf("%d", &index);
    if (index >= 1 && index <= num_appointments) {
        for (int i = index-1; i < num_appointments-1; i++) {
            strcpy(appointments[i].name, appointments[i+1].name);
            strcpy(appointments[i].phone, appointments[i+1].phone);
            strcpy(appointments[i].date, appointments[i+1].date);
            strcpy(appointments[i].time, appointments[i+1].time);
        }
        num_appointments--;
    } else {
        printf("Invalid appointment number.\n");
    }
}

int main() {
    int choice;
    do {
        printf("Appointment Scheduler\n");
        printf("1. Add appointment\n");
        printf("2. View appointments\n");
        printf("3. Delete appointment\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                view_appointments();
                break;
            case 3:
                delete_appointment();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);
    return 0;
}