//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold appointment details
typedef struct {
    char* name;
    char* date;
    char* time;
} Appointment;

// Function to get user input for an appointment
void getAppointment(Appointment* apt) {
    apt->name = (char*) malloc(50 * sizeof(char));
    apt->date = (char*) malloc(15 * sizeof(char));
    apt->time = (char*) malloc(10 * sizeof(char));
    
    printf("Enter appointment name:\n");
    scanf("%s", apt->name);
    printf("Enter appointment date (dd/mm/yyyy):\n");
    scanf("%s", apt->date);
    printf("Enter appointment time (hh:mm):\n");
    scanf("%s", apt->time);
}

// Function to print an appointment
void printAppointment(Appointment* apt) {
    printf("Appointment Name: %s\n", apt->name);
    printf("Appointment Date: %s\n", apt->date);
    printf("Appointment Time: %s\n", apt->time);
}

// Struct to hold a list of Appointments
typedef struct {
    Appointment* appointments;
    int length;
    int capacity;
} AppointmentList;

// Function to initialize an AppointmentList
void initAppointmentList(AppointmentList* list) {
    list->appointments = NULL;
    list->length = 0;
    list->capacity = 0;
}

// Function to add an appointment to an AppointmentList
void addAppointment(AppointmentList* list, Appointment apt) {
    // Initialize list if necessary
    if (list->appointments == NULL) {
        list->length = 0;
        list->capacity = 2;
        list->appointments = (Appointment*) malloc(list->capacity * sizeof(Appointment));
    }
    
    // Check if list needs to be resized
    if (list->length == list->capacity) {
        list->capacity *= 2;
        list->appointments = (Appointment*) realloc(list->appointments, list->capacity * sizeof(Appointment));
    }
    
    // Add new appointment to the list
    list->appointments[list->length++] = apt;
}

// Function to print all appointments in an AppointmentList
void printAppointments(AppointmentList* list) {
    printf("Appointment List:\n");
    for (int i = 0; i < list->length; i++) {
        printf("Appointment #%d:\n", i+1);
        printAppointment(&list->appointments[i]);
    }
}

int main() {
    // Initialize appointment list
    AppointmentList aptList;
    initAppointmentList(&aptList);
    
    // Get user input for appointments
    char keepAdding = 'y';
    while (keepAdding == 'y') {
        Appointment apt;
        getAppointment(&apt);
        addAppointment(&aptList, apt);
        
        printf("Do you want to add another appointment? (y/n)\n");
        scanf(" %c", &keepAdding); // Note: leading space in scanf to consume newline character
    }
    
    // Print appointment list
    printAppointments(&aptList);
    
    // Free memory
    for (int i = 0; i < aptList.length; i++) {
        free(aptList.appointments[i].name);
        free(aptList.appointments[i].date);
        free(aptList.appointments[i].time);
    }
    free(aptList.appointments);
    
    return 0;
}