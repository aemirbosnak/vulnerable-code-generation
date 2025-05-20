//Falcon-180B DATASET v1.0 Category: Appointment Scheduler ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

typedef struct {
    char name[50];
    int age;
    int phone;
    time_t appointment[10];
    int count;
} patient;

void addPatient(patient *p) {
    printf("Enter patient name: ");
    scanf("%s", p->name);

    printf("Enter patient age: ");
    scanf("%d", &p->age);

    printf("Enter patient phone number: ");
    scanf("%d", &p->phone);

    p->count = 0;
    for (int i = 0; i < 10; i++) {
        p->appointment[i] = -1;
    }
}

void displayPatients(patient p[], int n) {
    printf("\nPatient List:\n");
    for (int i = 0; i < n; i++) {
        printf("%s | %d years old | %d |", p[i].name, p[i].age, p[i].phone);
        for (int j = 0; j < 10; j++) {
            if (p[i].appointment[j]!= -1) {
                printf("%s ", ctime(&p[i].appointment[j]));
            } else {
                printf("-------- ");
            }
        }
        printf("\n");
    }
}

void scheduleAppointment(patient *p, time_t currentTime) {
    int choice;
    printf("\nEnter choice:\n1. Schedule appointment\n2. Cancel appointment\n3. View appointments\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            if (p->count < 10) {
                printf("Enter appointment date and time (YYYY-MM-DD HH:MM:SS): ");
                scanf("%s", ctime(&currentTime));
                p->appointment[p->count] = currentTime;
                p->count++;
            } else {
                printf("Sorry, no more appointments available.\n");
            }
            break;
        case 2:
            printf("Enter appointment index to cancel: ");
            scanf("%d", &choice);
            p->appointment[choice] = -1;
            break;
        case 3:
            displayPatients(p, 1);
            break;
        default:
            printf("Invalid choice.\n");
    }
}

int main() {
    patient p;
    addPatient(&p);

    while (1) {
        time_t currentTime = time(NULL);
        scheduleAppointment(&p, currentTime);
    }

    return 0;
}