//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Appointment {
    char name[50];
    int day;
    int month;
    int year;
    char time[10];
};

void addAppointment(struct Appointment *appointments, int *numAppointments);
void printAppointments(struct Appointment *appointments, int numAppointments);
void deleteAppointment(struct Appointment *appointments, int *numAppointments);
void searchAppointment(struct Appointment *appointments, int numAppointments);

int main() {
    int numAppointments = 0;
    struct Appointment appointments[100];
    char choice;

    do {
        printf("\n1. Add Appointment\n");
        printf("2. Print Appointments\n");
        printf("3. Delete Appointment\n");
        printf("4. Search Appointment\n");
        printf("5. Exit\n");
        printf("Enter Choice: ");
        fflush(stdin);
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                addAppointment(appointments, &numAppointments);
                break;
            case '2':
                printAppointments(appointments, numAppointments);
                break;
            case '3':
                deleteAppointment(appointments, &numAppointments);
                break;
            case '4':
                searchAppointment(appointments, numAppointments);
                break;
            case '5':
                printf("Exiting Program...\n");
                break;
            default:
                printf("Invalid Choice, Try Again.\n");
                break;
        }
    } while(choice != '5');

    return 0;
}

void addAppointment(struct Appointment *appointments, int *numAppointments) {
    char name[50];
    int day, month, year;
    char time[10];

    printf("Enter Name: ");
    fflush(stdin);
    gets(name);

    printf("Enter Day: ");
    fflush(stdin);
    scanf("%d", &day);

    printf("Enter Month: ");
    fflush(stdin);
    scanf("%d", &month);

    printf("Enter Year: ");
    fflush(stdin);
    scanf("%d", &year);

    printf("Enter Time (in 24-hour format): ");
    fflush(stdin);
    gets(time);

    struct Appointment newAppointment = { "", 0, 0, 0, "" };
    strcpy(newAppointment.name, name);
    newAppointment.day = day;
    newAppointment.month = month;
    newAppointment.year = year;
    strcpy(newAppointment.time, time);

    appointments[*numAppointments] = newAppointment;
    *numAppointments += 1;

    printf("Appointment added.\n");
}

void printAppointments(struct Appointment *appointments, int numAppointments) {
    printf("\nAppointments:\n");
    for(int i = 0; i < numAppointments; i++) {
        printf("%d. %s - %d/%d/%d @ %s\n", i+1, appointments[i].name, appointments[i].day, appointments[i].month, appointments[i].year, appointments[i].time);
    }
}

void deleteAppointment(struct Appointment *appointments, int *numAppointments) {
    printAppointments(appointments, *numAppointments);

    int deleteIndex;
    printf("Enter Appointment Number to Delete: ");
    fflush(stdin);
    scanf("%d", &deleteIndex);

    if(deleteIndex >= 1 && deleteIndex <= *numAppointments) {
        for(int i = deleteIndex; i < *numAppointments; i++) {
            appointments[i-1] = appointments[i];
        }
        *numAppointments -= 1;
        printf("Appointment deleted.\n");
    } else {
        printf("Invalid Appointment Number, Try Again.\n");
    }
}

void searchAppointment(struct Appointment *appointments, int numAppointments) {
    char searchQuery[50];
    printf("Enter Search Query: ");
    fflush(stdin);
    gets(searchQuery);

    bool found = false;
    for(int i = 0; i < numAppointments; i++) {
        if(strstr(appointments[i].name, searchQuery) != NULL) {
            printf("%s - %d/%d/%d @ %s\n", appointments[i].name, appointments[i].day, appointments[i].month, appointments[i].year, appointments[i].time);
            found = true;
        }
    }

    if(!found) {
        printf("No Appointments Found.\n");
    }
}