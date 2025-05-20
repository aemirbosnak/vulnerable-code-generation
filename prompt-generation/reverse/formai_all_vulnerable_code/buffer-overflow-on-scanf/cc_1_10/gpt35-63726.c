//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: portable
#include <stdio.h>
#include <string.h>

struct Appointment {
    char date[11], time[6], name[50];
};

void bookAppointment(struct Appointment a[], int* count) {
    printf("Enter the date (dd/mm/yyyy): ");
    scanf("%s", a[*count].date);
    printf("Enter the time (hh:mm): ");
    scanf("%s", a[*count].time);
    getchar();
    printf("Enter the name: ");
    fgets(a[*count].name, 50, stdin);
    a[*count].name[strcspn(a[*count].name, "\n")] = 0;
    printf("Appointment booked on %s at %s for %s\n", a[*count].date, a[*count].time, a[*count].name);
    *count += 1;
}

void printAppointments(struct Appointment a[], int count) {
    printf("\nAppointments:\n");
    for (int i = 0; i < count; i++) {
        printf("Date: %s, Time: %s, Name: %s\n", a[i].date, a[i].time, a[i].name);
    }
}

int main() {
    struct Appointment appointments[10];
    int count = 0;
    while (1) {
        printf("\n1. Book Appointment\n2. View Appointments\n3. Exit\n");
        int choice;
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                bookAppointment(appointments, &count);
                break;
            case 2:
                printAppointments(appointments, count);
                break;
            case 3:
                printf("Exiting\n");
                return 0;
            default:
                printf("Invalid Choice\n");
                break;
        }
    }
}