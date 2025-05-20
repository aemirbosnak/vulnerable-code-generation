//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20

// Structure for appointment
typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    time_t appointment_time;
} Appointment;

int add_appointment(Appointment* appointments, int num_appointments) {
    printf("Enter name: ");
    scanf("%s", appointments[num_appointments].name);

    printf("Enter phone number: ");
    scanf("%s", appointments[num_appointments].phone);

    printf("Enter appointment time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", appointments[num_appointments].appointment_time);

    return num_appointments + 1;
}

int view_appointments(Appointment* appointments, int num_appointments) {
    printf("Appointments:\n");
    for(int i = 0; i < num_appointments; i++) {
        printf("%s - %s - %s\n", appointments[i].name, appointments[i].phone, ctime(&appointments[i].appointment_time));
    }
}

int remove_appointment(Appointment* appointments, int num_appointments) {
    printf("Enter appointment number to remove: ");
    int appt_num;
    scanf("%d", &appt_num);

    if(appt_num >= 0 && appt_num < num_appointments) {
        for(int i = appt_num; i < num_appointments - 1; i++) {
            memcpy(&appointments[i], &appointments[i+1], sizeof(Appointment));
        }
        num_appointments--;
        return 0;
    } else {
        printf("Invalid appointment number.\n");
        return -1;
    }
}

int main() {
    int num_appointments = 0;
    Appointment appointments[MAX_APPOINTMENTS];

    while(num_appointments < MAX_APPOINTMENTS) {
        int choice;
        printf("1. Add appointment\n2. View appointments\n3. Remove appointment\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                num_appointments = add_appointment(appointments, num_appointments);
                break;
            case 2:
                view_appointments(appointments, num_appointments);
                break;
            case 3:
                remove_appointment(appointments, num_appointments);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}