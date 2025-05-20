//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_DATE_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char date[MAX_DATE_LENGTH];
    int duration;
} appointment;

appointment appointments[MAX_APPOINTMENTS];
int num_appointments;

void add_appointment() {
    printf("Enter name: ");
    scanf("%s", appointments[num_appointments].name);
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", appointments[num_appointments].date);
    printf("Enter duration (in minutes): ");
    scanf("%d", &appointments[num_appointments].duration);
    num_appointments++;
}

void view_appointments() {
    printf("Name\tDate\tDuration\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s\t%s\t%d\n", appointments[i].name, appointments[i].date, appointments[i].duration);
    }
}

void delete_appointment() {
    int index;
    printf("Enter index of appointment to delete: ");
    scanf("%d", &index);
    if (index >= 0 && index < num_appointments) {
        num_appointments--;
        for (int i = index; i < num_appointments; i++) {
            strcpy(appointments[i].name, appointments[i+1].name);
            strcpy(appointments[i].date, appointments[i+1].date);
            appointments[i].duration = appointments[i+1].duration;
        }
    } else {
        printf("Invalid index.\n");
    }
}

int main() {
    int choice;
    do {
        printf("1. Add appointment\n2. View appointments\n3. Delete appointment\n4. Exit\n");
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