//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
  int hour;
  int minute;
} Time;

typedef struct {
  int day;
  int month;
  int year;
} Date;

typedef struct {
  char title[MAX_SIZE];
  Date date;
  Time time;
  char description[MAX_SIZE];
  int isAvailable; // flag to check appointment availability
} Appointment;

Appointment appointmentList[MAX_SIZE]; // array of all appointments
int appointmentCount = 0; // count of total appointments added

// function to add appointment
void addAppointment() {
  Appointment newAppointment;
  printf("\nEnter appointment title: ");
  scanf("%s", newAppointment.title);
  printf("Enter appointment date (dd mm yyyy): ");
  scanf("%d %d %d", &newAppointment.date.day, &newAppointment.date.month, &newAppointment.date.year);
  printf("Enter appointment time (hh:mm): ");
  scanf("%d:%d", &newAppointment.time.hour, &newAppointment.time.minute);
  printf("Enter appointment description: ");
  scanf("%s", newAppointment.description);

  // check for appointment availability
  for(int i = 0; i < appointmentCount; i++) {
    if(appointmentList[i].date.day == newAppointment.date.day &&
       appointmentList[i].date.month == newAppointment.date.month &&
       appointmentList[i].date.year == newAppointment.date.year &&
       appointmentList[i].time.hour == newAppointment.time.hour &&
       appointmentList[i].time.minute == newAppointment.time.minute) {
         printf("\nThis time slot is not available. Please choose another time.\n");
         return;
       }
  }

  // add new appointment
  appointmentList[appointmentCount++] = newAppointment;
  printf("\nAppointment added successfully.\n");
}

// function to display all appointments
void displayAppointments() {
  printf("\nAll appointments:\n");
  for(int i = 0; i < appointmentCount; i++) {
    printf("\nTitle: %s\nDate: %02d/%02d/%02d\nTime: %02d:%02d\nDescription: %s\n", 
           appointmentList[i].title, appointmentList[i].date.day, appointmentList[i].date.month, appointmentList[i].date.year,
           appointmentList[i].time.hour, appointmentList[i].time.minute, appointmentList[i].description);
  }
}

int main() {
  int choice;
  do {
    printf("\nOptions:\n1. Add appointment\n2. Display appointments\n3. Exit\nEnter your choice: ");
    scanf("%d", &choice);
    switch(choice) {
      case 1:
        addAppointment();
        break;
      case 2:
        displayAppointments();
        break;
      case 3:
        printf("\nExiting program.\n");
        exit(0);
        break;
      default:
        printf("\nInvalid choice. Please try again.\n");
        break;
    }
  } while(choice != 3);

  return 0;
}