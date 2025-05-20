//Code Llama-13B DATASET v1.0 Category: Appointment Scheduler ; Style: excited
// Appointment Scheduler Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100
#define MAX_LENGTH 256

struct Appointment {
    char name[MAX_LENGTH];
    int time;
    char date[MAX_LENGTH];
};

void printAppointments(struct Appointment appointments[], int numAppointments) {
    printf("Appointments:\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("- %s, %s, %d\n", appointments[i].name, appointments[i].date, appointments[i].time);
    }
}

void addAppointment(struct Appointment appointments[], int* numAppointments) {
    printf("Enter appointment name: ");
    scanf("%s", appointments[*numAppointments].name);
    printf("Enter appointment time: ");
    scanf("%d", &appointments[*numAppointments].time);
    printf("Enter appointment date: ");
    scanf("%s", appointments[*numAppointments].date);
    (*numAppointments)++;
}

int main() {
    struct Appointment appointments[MAX_APPOINTMENTS];
    int numAppointments = 0;

    while (1) {
        int choice;
        printf("1. Add appointment\n2. Print appointments\n3. Quit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addAppointment(appointments, &numAppointments);
                break;
            case 2:
                printAppointments(appointments, numAppointments);
                break;
            case 3:
                return 0;
        }
    }
}