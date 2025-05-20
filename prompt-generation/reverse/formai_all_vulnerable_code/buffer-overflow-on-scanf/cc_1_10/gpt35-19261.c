//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_APPOINTMENTS 10
#define MAX_NAME_LEN 50

struct Appointment {
    int day, month, year, hour, minute;
    char name[MAX_NAME_LEN];
};

void addAppointment(struct Appointment *appointments, int *count) {
    if(*count == MAX_APPOINTMENTS) {
        printf("Appointment schedule is full. Cannot add more appointments.\n");
        return;
    }
    printf("Enter date and time (dd-mm-yyyy hh:mm):\n");
    scanf("%d-%d-%d %d:%d", &appointments[*count].day, &appointments[*count].month, &appointments[*count].year, &appointments[*count].hour, &appointments[*count].minute);
    printf("Enter the name of the appointment:\n");
    getchar();
    fgets(appointments[*count].name, MAX_NAME_LEN, stdin);
    appointments[*count].name[strlen(appointments[*count].name)-1] = '\0';
    (*count)++;
    printf("Appointment added successfully.\n");
}

void printAppointment(struct Appointment appointment) {
    printf("%02d-%02d-%4d %02d:%02d: %s\n", appointment.day, appointment.month, appointment.year, appointment.hour, appointment.minute, appointment.name);
}

void printAllAppointments(struct Appointment *appointments, int count) {
    if(count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    printf("Scheduled appointments:\n");
    for(int i=0; i<count; i++) {
        printAppointment(appointments[i]);
    }
}

void deleteAppointment(struct Appointment *appointments, int *count) {
    if(*count == 0) {
        printf("No appointments scheduled.\n");
        return;
    }
    printf("Enter the index of the appointment to delete:\n");
    int index;
    scanf("%d", &index);
    if(index<0 || index>=*count) {
        printf("Invalid index.\n");
        return;
    }
    for(int i=index; i<*count-1; i++) {
        appointments[i] = appointments[i+1];
    }
    (*count)--;
    printf("Appointment deleted successfully.\n");
}

int main() {
    struct Appointment appointments[MAX_APPOINTMENTS];
    int count = 0;
    while(1) {
        printf("\nEnter your choice:\n");
        printf("1. Add appointment\n");
        printf("2. View appointments\n");
        printf("3. Delete appointment\n");
        printf("4. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1: addAppointment(appointments, &count); break;
            case 2: printAllAppointments(appointments, count); break;
            case 3: deleteAppointment(appointments, &count); break;
            case 4: exit(0);
            default: printf("Invalid choice.\n");
        }
    }
    return 0;
}