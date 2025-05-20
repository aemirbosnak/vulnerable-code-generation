//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 100

typedef struct {
    char name[50];
    char time[20];
    char date[20];
} Appointment;

Appointment appointments[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment() {
    if (num_appointments >= MAX_APPOINTMENTS) {
        printf("Error: Appointment list is full.\n");
        return;
    }

    printf("Enter name: ");
    scanf("%s", appointments[num_appointments].name);

    printf("Enter time: ");
    scanf("%s", appointments[num_appointments].time);

    printf("Enter date: ");
    scanf("%s", appointments[num_appointments].date);

    num_appointments++;
}

void print_appointments() {
    for (int i = 0; i < num_appointments; i++) {
        printf("%s %s %s\n", appointments[i].name, appointments[i].time, appointments[i].date);
    }
}

void search_appointments() {
    char name[50];
    printf("Enter name: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < num_appointments; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            printf("%s %s %s\n", appointments[i].name, appointments[i].time, appointments[i].date);
            found = 1;
        }
    }

    if (!found) {
        printf("Error: No appointments found for %s.\n", name);
    }
}

void delete_appointment() {
    char name[50];
    printf("Enter name: ");
    scanf("%s", name);

    int found = 0;
    for (int i = 0; i < num_appointments; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            for (int j = i + 1; j < num_appointments; j++) {
                appointments[j - 1] = appointments[j];
            }
            num_appointments--;
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Error: No appointments found for %s.\n", name);
    }
}

int main() {
    int choice;
    do {
        printf("1. Add appointment\n");
        printf("2. Print appointments\n");
        printf("3. Search appointments\n");
        printf("4. Delete appointment\n");
        printf("5. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_appointment();
                break;
            case 2:
                print_appointments();
                break;
            case 3:
                search_appointments();
                break;
            case 4:
                delete_appointment();
                break;
            case 5:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}