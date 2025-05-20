//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_APPOINTMENTS 10

struct Appointment // A structure to hold the details of an appointment 
{
  char date[20];
  char time[20];
  char patient_name[50];
  char doctor_name[50];
};

int main()
{
  struct Appointment appointments[MAX_APPOINTMENTS]; // An array to hold all the appointments 

  int option, current_index = 0;
  while(1) // Run this loop until the user chooses to exit 
  {
    printf("\nWelcome to the Appointment Scheduler!\n");
    printf("1. Add New Appointment\n");
    printf("2. Edit an Existing Appointment\n");
    printf("3. View All Appointments\n");
    printf("4. Exit\n");

    printf("\nEnter your choice: ");
    scanf("%d", &option);

    if(option == 1) // If the user chooses to add a new appointment 
    {
      if(current_index >= MAX_APPOINTMENTS) // Check if there is any room for a new appointment 
      {
        printf("\nSorry, the Appointment Scheduler is full! Please edit or delete an existing appointment to create room for a new one.\n");
      }
      else
      {
        struct Appointment new_appointment;
        printf("\nEnter the Date of the Appointment: ");
        scanf("%s", new_appointment.date);
        printf("Enter the Time of the Appointment: ");
        scanf("%s", new_appointment.time);
        printf("Enter the Name of the Patient: ");
        scanf("%s", new_appointment.patient_name);
        printf("Enter the Name of the Doctor: ");
        scanf("%s", new_appointment.doctor_name);

        appointments[current_index] = new_appointment;
        current_index++;

        printf("\nAppointment Added Successfully!\n");
      }
    }
    else if(option == 2) // If the user chooses to edit an existing appointment 
    {
      if(current_index == 0) // If there are no appointments 
      {
        printf("\nThere are no Appointments to edit! Please add a new appointment first.\n");
      }
      else
      {
        int appointment_number;
        printf("\nEnter the Appointment Number (1-%d) that you want to Edit: ", current_index);
        scanf("%d", &appointment_number);

        if(appointment_number < 1 || appointment_number > current_index) // Check if the appointment number entered is valid 
        {
          printf("\nInvalid Appointment Number! Please enter a number between 1 and %d.\n", current_index);
        }
        else
        {
          struct Appointment edited_appointment;
          printf("\nEnter the Date of the Appointment: ");
          scanf("%s", edited_appointment.date);
          printf("Enter the Time of the Appointment: ");
          scanf("%s", edited_appointment.time);
          printf("Enter the Name of the Patient: ");
          scanf("%s", edited_appointment.patient_name);
          printf("Enter the Name of the Doctor: ");
          scanf("%s", edited_appointment.doctor_name);

          appointments[appointment_number-1] = edited_appointment;

          printf("\nAppointment Edited Successfully!\n");
        }
      }
    }
    else if(option == 3) // If the user chooses to view all appointments 
    {
      if(current_index == 0) // If there are no appointments 
      {
        printf("\nThere are no Appointments to view! Please add a new appointment first.\n");
      }
      else
      {
        printf("\nAll Appointments:\n");

        for(int i=0; i<current_index; i++)
        {
          printf("%d. Date: %s, Time: %s, Patient: %s, Doctor: %s\n", i+1, appointments[i].date, appointments[i].time, appointments[i].patient_name, appointments[i].doctor_name);
        }
      }
    }
    else if(option == 4) // If the user chooses to exit 
    {
      printf("\nExiting Appointment Scheduler! Thank you for using our Service!\n");
      exit(0);
    }
    else // If the user enters an invalid option 
    {
      printf("\nInvalid Option! Please enter a valid option (1-4).\n");
    }
  }

  return 0;
}