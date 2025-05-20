//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Function to display the schedule
void display_schedule(char *appointments[], int appointment_times[], int count) {
  printf("\nYour scheduled appointments are:\n");
  for(int i = 0; i < count; i++) {
    printf("%d. %s at %d:00\n", i+1, appointments[i], appointment_times[i]);
  }
}

int main() {
  //Initialize the arrays
  char *appointments[10];
  int appointment_times[10] = {0};
  int count = 0;

  //Greet the user!
  printf("Hi there! I'm your cheerful appointment scheduler!\n");

  //Loop to schedule or view appointments
  while(1) {
    char choice[10];
    printf("\nDo you want to schedule an appointment or view your schedule? ('schedule' or 'view')\n");
    scanf("%s", choice);

    //If user wants to schedule an appointment
    if(strcmp(choice, "schedule") == 0) {
      int time;
      char *event = malloc(50 * sizeof(char));
      printf("\nGreat! What time would you like to schedule your appointment? (Enter a number from 1 to 10)\n");
      scanf("%d", &time);
      
      //Check if time slot is available
      if(appointment_times[time-1] != 0) {
        printf("\nSorry, that time slot is already taken. Please choose another time.\n");
        free(event);
        continue;
      }
      
      printf("\nWhat is the appointment for?\n");
      scanf(" %[^\n]%*c", event);
      
      //Schedule the appointment
      appointments[count] = event;
      appointment_times[time-1] = time;
      count++;
      printf("\nYour appointment has been scheduled! See you soon!\n");
      
      //Display the updated schedule
      display_schedule(appointments, appointment_times, count);
    }
    
    //If user wants to view the schedule
    else if(strcmp(choice, "view") == 0) {
      if(count == 0) {
        printf("\nYou don't have any scheduled appointments yet.\n");
      }
      else {
        display_schedule(appointments, appointment_times, count);
      }
    }
    
    //If user enters invalid input
    else {
      printf("\nOops! That's not a valid input. Please try again.\n");
    }
  }
  return 0;
}