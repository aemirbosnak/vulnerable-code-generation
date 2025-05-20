//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_APPOINTMENTS 100
#define MAX_NAME_LEN 50
#define MAX_DESCRIPTION_LEN 100
#define MAX_DATE_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESCRIPTION_LEN];
    char date[MAX_DATE_LEN];
} appointment;

void add_appointment(appointment* appointments, int* num_appointments) {
    printf("Enter name: ");
    scanf("%s", appointments[*num_appointments].name);
    printf("Enter description: ");
    scanf("%s", appointments[*num_appointments].description);
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", appointments[*num_appointments].date);
    (*num_appointments)++;
}

void view_appointments(appointment* appointments, int num_appointments) {
    printf("Name\tDescription\tDate\n");
    for (int i = 0; i < num_appointments; i++) {
        printf("%s\t%s\t%s\n", appointments[i].name, appointments[i].description, appointments[i].date);
    }
}

void delete_appointment(appointment* appointments, int* num_appointments) {
    printf("Enter name of appointment to delete: ");
    char name[MAX_NAME_LEN];
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < *num_appointments; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            found = 1;
            for (int j = i; j < *num_appointments - 1; j++) {
                memcpy(&appointments[j], &appointments[j + 1], sizeof(appointment));
            }
            (*num_appointments)--;
        }
    }
    if (!found) {
        printf("Appointment not found.\n");
    }
}

int main() {
    appointment appointments[MAX_APPOINTMENTS];
    int num_appointments = 0;
    int choice;
    do {
        printf("1. Add appointment\n2. View appointments\n3. Delete appointment\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_appointment(appointments, &num_appointments);
                break;
            case 2:
                view_appointments(appointments, num_appointments);
                break;
            case 3:
                delete_appointment(appointments, &num_appointments);
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