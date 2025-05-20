//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 10
#define MAX_NAME_LENGTH 30

// Structure to hold information about an appointment
struct Appointment {
   char name[MAX_NAME_LENGTH];
   int day;
   int month;
   int year;
   int hour;
   int minute;
};

// Function to check if two dates are equal
int date_equals(int day1, int month1, int year1, int day2, int month2, int year2) {
   return (day1 == day2 && month1 == month2 && year1 == year2);
}

// Function to check if two times are equal
int time_equals(int hour1, int minute1, int hour2, int minute2) {
   return (hour1 == hour2 && minute1 == minute2);
}

// Function to add a new appointment
void add_appointment(struct Appointment *appointments, int *num_appointments) {
   if (*num_appointments == MAX_APPOINTMENTS) {
      printf("Error: Maximum number of appointments reached.\n");
      return;
   }

   struct Appointment new_appointment;
   printf("Enter name: ");
   scanf("%s", new_appointment.name);
   printf("Enter date (dd/mm/yyyy): ");
   scanf("%d/%d/%d", &new_appointment.day, &new_appointment.month, &new_appointment.year);
   printf("Enter time (hh:mm): ");
   scanf("%d:%d", &new_appointment.hour, &new_appointment.minute);

   // Check if appointment already exists at this date and time
   int i;
   for (i = 0; i < *num_appointments; i++) {
      if (date_equals(new_appointment.day, new_appointment.month, new_appointment.year,
                       appointments[i].day, appointments[i].month, appointments[i].year)
          && time_equals(new_appointment.hour, new_appointment.minute,
                          appointments[i].hour, appointments[i].minute)) {
         printf("Error: Appointment already exists at this date and time.\n");
         return;
      }
   }

   // Add new appointment and increment number of appointments
   appointments[*num_appointments] = new_appointment;
   (*num_appointments)++;
   printf("Appointment added successfully.\n");
}

// Function to print all appointments
void print_appointments(struct Appointment *appointments, int num_appointments) {
   if (num_appointments == 0) {
      printf("No appointments.\n");
      return;
   }

   printf("Appointments:\n");
   int i;
   for (i = 0; i < num_appointments; i++) {
      printf("%s - %02d/%02d/%04d at %02d:%02d\n",
             appointments[i].name, appointments[i].day, appointments[i].month,
             appointments[i].year, appointments[i].hour, appointments[i].minute);
   }
}

int main() {
   struct Appointment appointments[MAX_APPOINTMENTS];
   int num_appointments = 0;

   int choice;
   do {
      printf("\n1. Add Appointment\n");
      printf("2. Print Appointments\n");
      printf("3. Exit\n");
      printf("Enter choice: ");
      scanf("%d", &choice);

      switch(choice) {
         case 1:
            add_appointment(appointments, &num_appointments);
            break;
         case 2:
            print_appointments(appointments, num_appointments);
            break;
         case 3:
            printf("Exiting...\n");
            break;
         default:
            printf("Error: Invalid choice. Try again.\n");
      }
   } while (choice != 3);

   return 0;
}