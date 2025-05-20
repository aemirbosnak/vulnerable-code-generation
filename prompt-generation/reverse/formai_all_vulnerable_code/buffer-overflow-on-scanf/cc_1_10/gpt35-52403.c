//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct appointment{
  int day;
  int month;
  int year;
  char time[6];
  char name[50];
};

void print_appointment(struct appointment appt){
  printf("Appointment with: %s\n", appt.name);
  printf("Date: %d/%d/%d\n", appt.day, appt.month, appt.year);
  printf("Time: %s\n\n", appt.time);
}

int main(){
  struct appointment schedule[10];
  int num_appt = 0;
  char choice = ' ';

  while(choice != 'exit'){
    printf("What would you like to do? (add/view/exit) ");
    scanf(" %s", &choice);

    if(choice == 'add'){
      if(num_appt >= 10){
        printf("Sorry, the schedule is full. Please delete an appointment to make room.\n\n");
      }else{
        printf("Please enter the following information:\n");
        printf("Name: ");
        scanf(" %s", schedule[num_appt].name);
        printf("Date (dd/mm/yyyy): ");
        scanf(" %d/%d/%d", &schedule[num_appt].day, &schedule[num_appt].month, &schedule[num_appt].year);
        printf("Time (hh:mm): ");
        scanf(" %s", &schedule[num_appt].time);
        printf("Appointment added!\n\n");
        num_appt++;
      }
    }else if(choice == 'view'){
      if(num_appt <= 0){
        printf("The schedule is empty.\n\n");
      }else{
        int i;
        for(i=0; i<num_appt; i++){
          print_appointment(schedule[i]);
        }
      }
    }else if(choice == 'exit'){
      printf("Goodbye!");
    }else{
      printf("Invalid choice.\n\n");
    }
  }

  return 0;
}