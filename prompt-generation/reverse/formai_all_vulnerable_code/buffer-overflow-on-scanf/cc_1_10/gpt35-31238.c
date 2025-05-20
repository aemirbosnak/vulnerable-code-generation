//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct appointment {
    char date[20];
    char time[20];
    char name[50];
    char contact[20];
} Appointment;

void create(Appointment *apt, int n);
void view(Appointment *apt, int n);
void update(Appointment *apt, int n);
void delete(Appointment *apt, int *n);

int main() {
    int n = 0;
    Appointment *apt;
    apt = (Appointment*) malloc(sizeof(Appointment));
    int choice;

    printf("------Appointment Scheduler------\n\n");

    do {
        printf("1. Create\n2. View\n3. Update\n4. Delete\n5. Exit\n");
        printf("Enter the option: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                create(apt, n);
                n++;
                apt = (Appointment*) realloc(apt, (n + 1) * sizeof(Appointment));
                break;

            case 2:
                view(apt, n);
                break;

            case 3:
                update(apt, n);
                break;

            case 4:
                delete(apt, &n);
                apt = (Appointment*) realloc(apt, (n + 1) * sizeof(Appointment));
                break;

            case 5:
                printf("Exiting...");
                break;

            default:
                printf("Invalid option. Try again.\n");
                break;
        }
    } while (choice != 5);

    free(apt);
    return 0;
}

void create(Appointment *apt, int n) {
    printf("\n------Create Appointment------\n\n");

    printf("Enter the date (DD/MM/YYYY): ");
    scanf("%s", apt[n].date);

    printf("Enter the time (HH:MM): ");
    scanf("%s", apt[n].time);

    printf("Enter the name: ");
    scanf("%s", apt[n].name);

    printf("Enter the contact number: ");
    scanf("%s", apt[n].contact);

    printf("\nAppointment created successfully.\n");
}

void view(Appointment *apt, int n) {
    printf("\n------View Appointments------\n\n");

    if (n == 0) {
        printf("No appointments yet.\n");
        return;
    }

    for(int i = 0; i < n; i++) {
        printf("Appointment %d\n", i+1);
        printf("Date: %s\n", apt[i].date);
        printf("Time: %s\n", apt[i].time);
        printf("Name: %s\n", apt[i].name);
        printf("Contact: %s\n\n", apt[i].contact);
    }
}

void update(Appointment *apt, int n) {
    printf("\n------Update Appointment------\n\n");

    if (n == 0) {
        printf("No appointments yet.\n");
        return;
    }

    int choice;
    printf("Enter the appointment number to update: ");
    scanf("%d", &choice);

    if (choice > n || choice <= 0) {
        printf("Invalid appointment number. Try again.\n");
        return;
    }

    printf("Enter the date (DD/MM/YYYY): ");
    scanf("%s", apt[choice-1].date);
    printf("Enter the time (HH:MM): ");
    scanf("%s", apt[choice-1].time);
    printf("Enter the name: ");
    scanf("%s", apt[choice-1].name);
    printf("Enter the contact number: ");
    scanf("%s", apt[choice-1].contact);

    printf("\nAppointment updated successfully.\n");
}

void delete(Appointment *apt, int *n) {
    printf("\n------Delete Appointment------\n\n");

    if (*n == 0) {
        printf("No appointments yet.\n");
        return;
    }

    int choice;
    printf("Enter the appointment number to delete: ");
    scanf("%d", &choice);

    if (choice > *n || choice <= 0) {
        printf("Invalid appointment number. Try again.\n");
        return;
    }

    for (int i = choice-1; i < (*n)-1; i++) {
        strcpy(apt[i].date, apt[i+1].date);
        strcpy(apt[i].time, apt[i+1].time);
        strcpy(apt[i].name, apt[i+1].name);
        strcpy(apt[i].contact, apt[i+1].contact);
    }

    printf("\nAppointment deleted successfully.\n");
    (*n)--;
}