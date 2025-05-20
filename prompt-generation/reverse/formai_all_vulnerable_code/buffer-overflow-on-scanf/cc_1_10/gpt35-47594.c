//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: all-encompassing
/*
  C Appointment Scheduler Example Program
  Author: [Your Name]
  Date: [Current Date]

  This program allows users to schedule appointments
  with a doctor or any other professional. The program
  first checks the availability of the professional 
  based on the time and date provided by the user. 
  If the professional is available, the user can proceed
  to book the appointment.

  NOTE: This is a simplified version of an appointment
  scheduling program. It does not handle conflicts or 
  overlapping appointments. It assumes that the 
  availability of the professional is accurately listed 
  in the program.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold appointment information
typedef struct {
  char professional[50];
  char patient[50];
  char date[11]; // in format MM/DD/YYYY
  char time[6]; // in format HH:MM
} Appointment;

// Hardcoded list of available professionals
char professionals[][50] = {"Dr. Smith", "Dr. Johnson", "Dr. Patel"};

// Hardcoded list of available appointments for each professional
// Each array represents one professional's appointments for one day (9:00 AM - 5:00 PM)
char appointments[][8][6] = {
  {"09:00", "11:00", "12:00", "", "", "", ""}, // Dr. Smith's availability for 10/01/2021
  {"09:30", "11:30", "12:30", "", "", "", ""}, // Dr. Johnson's availability for 10/01/2021
  {"10:00", "11:00", "12:00", "", "", "", ""}  // Dr. Patel's availability for 10/01/2021
};

// Function to print available professionals
void printProfessionals() {
  int numProfessionals = sizeof(professionals) / sizeof(professionals[0]);
  printf("\nAvailable professionals:\n");
  for (int i = 0; i < numProfessionals; i++) {
    printf("%d. %s\n", i+1, professionals[i]);
  }
}

// Function to print available appointments for a given professional and date
void printAppointments(char* professional, char* date) {
  // Find the professional's index in the array
  int professionalIndex = -1;
  int numProfessionals = sizeof(professionals) / sizeof(professionals[0]);
  for (int i = 0; i < numProfessionals; i++) {
    if (strcmp(professionals[i], professional) == 0) {
      professionalIndex = i;
      break;
    }
  }
  
  // If professional not found, print error message and return
  if (professionalIndex == -1) {
    printf("\nError: Professional not found!\n");
    return;
  }
  
  printf("\nAvailable appointments for %s on %s:\n", professional, date);
  int numAppointments = sizeof(appointments[0]) / sizeof(appointments[0][0]);
  for (int i = 0; i < numAppointments; i++) {
    if (strcmp(appointments[professionalIndex][i], "") == 0) {
      printf("%d. %s\n", i+1, "Available");
    } else {
      printf("%d. %s\n", i+1, appointments[professionalIndex][i]);
    }
  }
}

// Function to book an appointment for a given professional, patient, date, and time
void bookAppointment(char* professional, char* patient, char* date, char* time) {
  // Find the professional's index in the array
  int professionalIndex = -1;
  int numProfessionals = sizeof(professionals) / sizeof(professionals[0]);
  for (int i = 0; i < numProfessionals; i++) {
    if (strcmp(professionals[i], professional) == 0) {
      professionalIndex = i;
      break;
    }
  }
  
  // If professional not found, print error message and return
  if (professionalIndex == -1) {
    printf("\nError: Professional not found!\n");
    return;
  }
  
  // Find the appointment's index in the array
  int appointmentIndex = -1;
  int numAppointments = sizeof(appointments[0]) / sizeof(appointments[0][0]);
  for (int i = 0; i < numAppointments; i++) {
    if (strcmp(appointments[professionalIndex][i], time) == 0) {
      appointmentIndex = i;
      break;
    }
  }
  
  // If appointment not found, print error message and return
  if (appointmentIndex == -1) {
    printf("\nError: Appointment not found!\n");
    return;
  }
  
  // Book the appointment
  strcpy(appointments[professionalIndex][appointmentIndex], patient);
  printf("\nAppointment booked for %s with %s on %s at %s.\n", patient, professional, date, time);
}

int main() {
  printf("Welcome to the appointment scheduler!\n");
  
  // Prompt user for professional
  printProfessionals();
  int professionalIndex = 0;
  printf("\nEnter the number of the professional you want to see: ");
  scanf("%d", &professionalIndex);
  char professional[50];
  strcpy(professional, professionals[professionalIndex-1]);
  
  // Prompt user for date
  char date[11];
  printf("\nEnter the date you would like to schedule an appointment (MM/DD/YYYY): ");
  scanf("%s", date);
  
  // Print available appointments for selected professional and date
  printAppointments(professional, date);
  
  // Prompt user for desired appointment time
  char time[6];
  printf("\nEnter the time of the appointment you would like (HH:MM): ");
  scanf("%s", time);
  
  // Prompt user for patient name and book appointment
  char patient[50];
  printf("\nEnter the name of the patient: ");
  scanf("%s", patient);
  bookAppointment(professional, patient, date, time);
  
  return 0;
}