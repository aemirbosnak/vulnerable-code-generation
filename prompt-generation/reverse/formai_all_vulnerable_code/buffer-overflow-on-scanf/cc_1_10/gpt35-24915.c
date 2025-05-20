//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Welcome user and start scheduling appointment
  printf("Welcome to the Crazy Clinic appointment scheduler!\n");
  printf("Please enter your name: ");
  char name[50];
  scanf("%s", name);
  
  // Generate random appointment time
  srand(time(NULL));
  int hour = rand() % 24;
  int minute = rand() % 60;
  
  // Print out appointment details
  printf("\nHi %s, your appointment is: \n", name);
  
  if(hour == 12) {
    printf("12:%02d PM\n", minute);
  } else if(hour > 12) {
    printf("%d:%02d PM\n", hour - 12, minute);
  } else {
    printf("%d:%02d AM\n", hour, minute);
  }
  
  // Ask user if they are okay with the appointment time
  printf("\nAre you okay with this time? (y/n) ");
  char response;
  scanf(" %c", &response);
  
  if(response == 'n') {
    // Generate new appointment time
    printf("\nRescheduling...\n");
    hour = rand() % 24;
    minute = rand() % 60;
    
    // Print out new appointment details
    printf("\nHi %s, your new appointment is: \n", name);
    
    if(hour == 12) {
      printf("12:%02d PM\n", minute);
    } else if(hour > 12) {
      printf("%d:%02d PM\n", hour - 12, minute);
    } else {
      printf("%d:%02d AM\n", hour, minute);
    }
    
    // Thank user for rescheduling
    printf("\nThank you for rescheduling, %s!\n", name);
  } else {
    // Thank user for scheduling
    printf("\nThank you for scheduling, %s!\n", name);
  }
  
  return 0;
}