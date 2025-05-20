//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 1000
#define MAX_NAME_LENGTH 100
#define MAX_PHONE_LENGTH 20
#define MAX_EMAIL_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    int appointment_id;
} appointment;

appointment appointments[MAX_APPOINTMENTS];
int next_appointment_id = 1;

void print_appointment(int id) {
    for (int i = 0; i < MAX_APPOINTMENTS; i++) {
        if (appointments[i].appointment_id == id) {
            printf("Name: %s\nPhone: %s\nEmail: %s\n", appointments[i].name, appointments[i].phone, appointments[i].email);
            return;
        }
    }
    printf("Appointment not found.\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nAppointment Scheduler\n");
        printf("1. Add appointment\n2. View appointment\n3. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", appointments[next_appointment_id-1].name);
                printf("Enter phone: ");
                scanf("%s", appointments[next_appointment_id-1].phone);
                printf("Enter email: ");
                scanf("%s", appointments[next_appointment_id-1].email);
                appointments[next_appointment_id-1].appointment_id = next_appointment_id;
                next_appointment_id++;
                printf("Appointment added.\n");
                break;
            case 2:
                printf("Enter appointment ID: ");
                int id;
                scanf("%d", &id);
                print_appointment(id);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}