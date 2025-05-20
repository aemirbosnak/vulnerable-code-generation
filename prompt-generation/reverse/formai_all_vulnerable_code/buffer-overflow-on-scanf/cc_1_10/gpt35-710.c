//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_APPOINTMENTS 1000

struct Appointment {
    int day;
    int month;
    int year;
    char time[10];
    char patient_name[50];
    char doctor_name[50];
};

struct Appointment appointment_list[MAX_APPOINTMENTS];
int num_appointments = 0;

void add_appointment() {
    printf("Enter appointment date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &appointment_list[num_appointments].day, 
                        &appointment_list[num_appointments].month, 
                        &appointment_list[num_appointments].year);
    printf("Enter appointment time (hh:mm): ");
    scanf("%s", appointment_list[num_appointments].time);
    printf("Enter patient name: ");
    scanf("%s", appointment_list[num_appointments].patient_name);
    printf("Enter doctor name: ");
    scanf("%s", appointment_list[num_appointments].doctor_name);
    num_appointments++;
    printf("Appointment added successfully!\n");
}

void delete_appointment() {
    int day, month, year;
    char time[10];
    printf("Enter appointment date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &day, &month, &year);
    printf("Enter appointment time (hh:mm): ");
    scanf("%s", time);
    for(int i = 0; i < num_appointments; i++) {
        if(appointment_list[i].day == day && 
           appointment_list[i].month == month && 
           appointment_list[i].year == year && 
           strcmp(appointment_list[i].time, time) == 0) {
            for(int j = i; j < num_appointments - 1; j++) {
                appointment_list[j] = appointment_list[j+1];
            }
            num_appointments--;
            printf("Appointment deleted successfully!\n");
            return;
        }
    }
    printf("Appointment not found!\n");
}

void print_appointments() {
    printf("Appointments:\n");
    for(int i = 0; i < num_appointments; i++) {
        printf("%d/%d/%d %s %s %s\n", appointment_list[i].day, 
                                      appointment_list[i].month, 
                                      appointment_list[i].year, 
                                      appointment_list[i].time, 
                                      appointment_list[i].patient_name,
                                      appointment_list[i].doctor_name);
    }
}

int main() {
    int choice;
    while(1) {
        printf("1. Add appointment\n");
        printf("2. Delete appointment\n");
        printf("3. Print appointments\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: add_appointment(); break;
            case 2: delete_appointment(); break;
            case 3: print_appointments(); break;
            case 4: printf("Exiting...\n"); exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}