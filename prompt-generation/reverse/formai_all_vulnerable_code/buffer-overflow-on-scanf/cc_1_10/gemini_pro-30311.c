//GEMINI-pro DATASET v1.0 Category: Appointment Scheduler ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char date[20];
    char time[20];
} appointment;

appointment *appointments;
int numAppointments = 0;

void addAppointment() {
    appointments = realloc(appointments, (numAppointments + 1) * sizeof(appointment));
    printf("Enter name: ");
    scanf("%s", appointments[numAppointments].name);
    printf("Enter date (dd/mm/yyyy): ");
    scanf("%s", appointments[numAppointments].date);
    printf("Enter time (hh:mm): ");
    scanf("%s", appointments[numAppointments].time);
    numAppointments++;
}

void printAppointments() {
    printf("Appointments:\n");
    for (int i = 0; i < numAppointments; i++) {
        printf("%s, %s, %s\n", appointments[i].name, appointments[i].date, appointments[i].time);
    }
}

void searchAppointments() {
    char searchTerm[50];
    printf("Enter search term: ");
    scanf("%s", searchTerm);
    for (int i = 0; i < numAppointments; i++) {
        if (strstr(appointments[i].name, searchTerm) || strstr(appointments[i].date, searchTerm) || strstr(appointments[i].time, searchTerm)) {
            printf("%s, %s, %s\n", appointments[i].name, appointments[i].date, appointments[i].time);
        }
    }
}

void deleteAppointment() {
    char name[50];
    printf("Enter name of appointment to delete: ");
    scanf("%s", name);
    for (int i = 0; i < numAppointments; i++) {
        if (strcmp(appointments[i].name, name) == 0) {
            for (int j = i; j < numAppointments - 1; j++) {
                appointments[j] = appointments[j + 1];
            }
            numAppointments--;
            break;
        }
    }
}

void saveAppointments() {
    FILE *fp = fopen("appointments.txt", "w");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }
    for (int i = 0; i < numAppointments; i++) {
        fprintf(fp, "%s,%s,%s\n", appointments[i].name, appointments[i].date, appointments[i].time);
    }
    fclose(fp);
}

void loadAppointments() {
    FILE *fp = fopen("appointments.txt", "r");
    if (fp == NULL) {
        return;
    }
    char line[100];
    while (fgets(line, 100, fp)) {
        char *name = strtok(line, ",");
        char *date = strtok(NULL, ",");
        char *time = strtok(NULL, "\n");
        addAppointment(name, date, time);
    }
    fclose(fp);
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Add appointment\n");
        printf("2. Print appointments\n");
        printf("3. Search appointments\n");
        printf("4. Delete appointment\n");
        printf("5. Save appointments\n");
        printf("6. Load appointments\n");
        printf("7. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addAppointment();
                break;
            case 2:
                printAppointments();
                break;
            case 3:
                searchAppointments();
                break;
            case 4:
                deleteAppointment();
                break;
            case 5:
                saveAppointments();
                break;
            case 6:
                loadAppointments();
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice");
        }
    }
    return 0;
}