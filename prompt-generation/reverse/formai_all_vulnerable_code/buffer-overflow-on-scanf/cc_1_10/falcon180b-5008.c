//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_APPOINTMENTS 1000
#define MAX_NAME_LEN 50
#define MAX_DATE_LEN 20
#define MAX_TIME_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char date[MAX_DATE_LEN];
    char time[MAX_TIME_LEN];
} appointment;

int num_appointments = 0;
appointment appointments[MAX_APPOINTMENTS];

void add_appointment() {
    printf("Enter name: ");
    scanf("%s", appointments[num_appointments].name);

    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", appointments[num_appointments].date);

    printf("Enter time (HH:MM): ");
    scanf("%s", appointments[num_appointments].time);

    num_appointments++;
}

void print_appointments() {
    printf("\nAppointments:\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s on %s at %s\n", appointments[i].name, appointments[i].date, appointments[i].time);
    }
}

void delete_appointment() {
    printf("Enter name to delete appointment: ");
    char name[MAX_NAME_LEN];
    scanf("%s", name);

    for (int i = 0; i < num_appointments; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            for (int j = i; j < num_appointments - 1; j++) {
                strcpy(appointments[j].name, appointments[j+1].name);
                strcpy(appointments[j].date, appointments[j+1].date);
                strcpy(appointments[j].time, appointments[j+1].time);
            }
            num_appointments--;
            break;
        }
    }
}

void search_appointment() {
    printf("Enter name to search for appointment: ");
    char name[MAX_NAME_LEN];
    scanf("%s", name);

    for (int i = 0; i < num_appointments; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            printf("Appointment found on %s at %s\n", appointments[i].date, appointments[i].time);
            break;
        }
    }
}

int main() {
    system("clear");

    int choice;
    do {
        printf("\nAppointment Scheduler\n");
        printf("1. Add appointment\n");
        printf("2. Print appointments\n");
        printf("3. Delete appointment\n");
        printf("4. Search appointment\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                print_appointments();
                break;
            case 3:
                delete_appointment();
                break;
            case 4:
                search_appointment();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice!= 5);

    return 0;
}