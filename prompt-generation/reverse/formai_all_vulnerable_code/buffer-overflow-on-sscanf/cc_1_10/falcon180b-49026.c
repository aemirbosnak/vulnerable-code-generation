//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define MAX_EMAIL_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    time_t appointment_time;
} Appointment;

int main() {
    FILE *appointments_file;
    Appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;
    char input_buffer[1024];
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    time_t appointment_time;

    appointments_file = fopen("appointments.txt", "r");

    if (appointments_file == NULL) {
        printf("No appointments found.\n");
        return 1;
    }

    while (fgets(input_buffer, sizeof(input_buffer), appointments_file)!= NULL) {
        sscanf(input_buffer, "%s %s %s %ld", name, phone, email, &appointment_time);
        strcpy(appointments[num_appointments].name, name);
        strcpy(appointments[num_appointments].phone, phone);
        strcpy(appointments[num_appointments].email, email);
        appointments[num_appointments].appointment_time = appointment_time;
        num_appointments++;
    }

    fclose(appointments_file);

    printf("Appointments for %s:\n", name);

    for (int i = 0; i < num_appointments; i++) {
        printf("%s - %s - %s - %s\n", appointments[i].name, appointments[i].phone, appointments[i].email, ctime(&appointments[i].appointment_time));
    }

    return 0;
}