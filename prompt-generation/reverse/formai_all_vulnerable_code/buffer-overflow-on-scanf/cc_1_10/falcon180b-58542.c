//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define DAYS_PER_WEEK 7
#define HOURS_PER_DAY 24
#define MINUTES_PER_HOUR 60

typedef struct {
    char name[50];
    char date[11];
    char time[9];
} appointment;

void add_appointment(appointment* appointments, int num_appointments) {
    printf("Enter name: ");
    scanf("%s", appointments[num_appointments].name);
    printf("Enter date (yyyy-mm-dd): ");
    scanf("%s", appointments[num_appointments].date);
    printf("Enter time (hh:mm): ");
    scanf("%s", appointments[num_appointments].time);
    num_appointments++;
}

void display_appointments(appointment* appointments, int num_appointments) {
    printf("Name\tDate\tTime\n");
    for(int i=0; i<num_appointments; i++) {
        printf("%s\t%s\t%s\n", appointments[i].name, appointments[i].date, appointments[i].time);
    }
}

void delete_appointment(appointment* appointments, int num_appointments) {
    printf("Enter name of appointment to delete: ");
    char name[50];
    scanf("%s", name);
    for(int i=0; i<num_appointments; i++) {
        if(strcmp(appointments[i].name, name) == 0) {
            for(int j=i; j<num_appointments-1; j++) {
                strcpy(appointments[j].name, appointments[j+1].name);
                strcpy(appointments[j].date, appointments[j+1].date);
                strcpy(appointments[j].time, appointments[j+1].time);
            }
            num_appointments--;
            break;
        }
    }
}

int main() {
    appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;
    int choice;
    do {
        printf("1. Add appointment\n");
        printf("2. Display appointments\n");
        printf("3. Delete appointment\n");
        printf("4. Quit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_appointment(appointments, num_appointments);
                break;
            case 2:
                display_appointments(appointments, num_appointments);
                break;
            case 3:
                delete_appointment(appointments, num_appointments);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= 4);
    return 0;
}