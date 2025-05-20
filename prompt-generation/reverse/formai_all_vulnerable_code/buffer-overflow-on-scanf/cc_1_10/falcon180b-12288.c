//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char name[50];
    int age;
    int phone;
    char email[100];
    struct tm appointment;
} patient;

void add_patient(patient *p) {
    printf("Enter patient name: ");
    scanf("%s", p->name);
    printf("Enter patient age: ");
    scanf("%d", &p->age);
    printf("Enter patient phone number: ");
    scanf("%d", &p->phone);
    printf("Enter patient email: ");
    scanf("%s", p->email);
    printf("Enter appointment date (YYYY-MM-DD): ");
    scanf("%d-%d-%d", &p->appointment.tm_year, &p->appointment.tm_mon, &p->appointment.tm_mday);
    printf("Appointment added for %s on %d-%02d-%02d\n", p->name, p->appointment.tm_year, p->appointment.tm_mon, p->appointment.tm_mday);
}

void display_appointments(patient *p, int n) {
    time_t now = time(NULL);
    struct tm *current_time = localtime(&now);
    printf("Appointments for %s:\n", p[0].name);
    for (int i = 0; i < n; i++) {
        if (p[i].appointment.tm_year == current_time->tm_year && p[i].appointment.tm_mon == current_time->tm_mon && p[i].appointment.tm_mday == current_time->tm_mday) {
            printf("- %s on %d-%02d-%02d\n", p[i].name, p[i].appointment.tm_year, p[i].appointment.tm_mon, p[i].appointment.tm_mday);
        }
    }
}

int main() {
    patient p[100];
    int n = 0;
    while (1) {
        printf("\n1. Add patient\n2. Display appointments\n3. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (n >= 100) {
                    printf("Maximum number of patients reached\n");
                } else {
                    add_patient(&p[n]);
                    n++;
                }
                break;
            case 2:
                display_appointments(p, n);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}