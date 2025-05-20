//Falcon2-11B DATASET v1.0 Category: Appointment Scheduler ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_APPOINTMENTS 10
#define MAX_NAME_LEN 50
#define MAX_TIME_LEN 10
#define MAX_DURATION_LEN 10
#define MAX_DESCRIPTION_LEN 100

typedef struct appointment {
    char name[MAX_NAME_LEN];
    char time[MAX_TIME_LEN];
    char duration[MAX_DURATION_LEN];
    char description[MAX_DESCRIPTION_LEN];
} Appointment;

typedef struct appointment_list {
    Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments;
} AppointmentList;

AppointmentList create_appointment_list() {
    AppointmentList alist;
    alist.num_appointments = 0;
    return alist;
}

void add_appointment(AppointmentList* alist, char* name, char* time, char* duration, char* description) {
    if (alist->num_appointments >= MAX_APPOINTMENTS) {
        printf("Appointment list is full, cannot add more appointments.\n");
        return;
    }
    Appointment new_appointment;
    strcpy(new_appointment.name, name);
    strcpy(new_appointment.time, time);
    strcpy(new_appointment.duration, duration);
    strcpy(new_appointment.description, description);
    alist->appointments[alist->num_appointments] = new_appointment;
    alist->num_appointments++;
}

void delete_appointment(AppointmentList* alist, int index) {
    if (index < 0 || index >= alist->num_appointments) {
        printf("Invalid appointment index.\n");
        return;
    }
    for (int i = index; i < alist->num_appointments - 1; i++) {
        alist->appointments[i] = alist->appointments[i + 1];
    }
    alist->num_appointments--;
}

void print_appointments(AppointmentList* alist) {
    if (alist->num_appointments == 0) {
        printf("Appointment list is empty.\n");
        return;
    }
    for (int i = 0; i < alist->num_appointments; i++) {
        printf("Name: %s, Time: %s, Duration: %s, Description: %s\n",
               alist->appointments[i].name, alist->appointments[i].time,
               alist->appointments[i].duration, alist->appointments[i].description);
    }
}

int main() {
    AppointmentList alist = create_appointment_list();
    char name[MAX_NAME_LEN], time[MAX_TIME_LEN], duration[MAX_DURATION_LEN], description[MAX_DESCRIPTION_LEN];
    char choice;
    do {
        printf("Welcome to the Cyberpunk Appointment Scheduler!\n");
        printf("1. Add appointment\n");
        printf("2. Delete appointment\n");
        printf("3. Print appointments\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        switch (choice) {
            case '1':
                printf("Enter appointment details:\n");
                printf("Name: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                printf("Time: ");
                fgets(time, sizeof(time), stdin);
                time[strcspn(time, "\n")] = '\0';
                printf("Duration: ");
                fgets(duration, sizeof(duration), stdin);
                duration[strcspn(duration, "\n")] = '\0';
                printf("Description: ");
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = '\0';
                add_appointment(&alist, name, time, duration, description);
                break;
            case '2':
                printf("Enter appointment index to delete: ");
                scanf("%d", &index);
                delete_appointment(&alist, index - 1);
                break;
            case '3':
                print_appointments(&alist);
                break;
            case '4':
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= '4');
    return 0;
}