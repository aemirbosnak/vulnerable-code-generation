//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_APPOINTMENTS 10
#define MAX_NAME_LENGTH 20

struct appointment {
  char name[MAX_NAME_LENGTH];
  int day;
  int month;
  int year;
  int hour;
  int minute;
};

struct appointment appointment_list[MAX_APPOINTMENTS];
int num_appointments = 0;

bool is_valid_date(int day, int month, int year) {
  if (year < 2022) {
    return false;
  }
  if (month < 1 || month > 12) {
    return false;
  }
  if (day < 1 || day > 31) {
    return false;
  }
  if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31) {
    return false;
  }
  if (month == 2) {
    bool leap_year = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    if (day > 29 || (day == 29 && !leap_year)) {
      return false;
    }
  }
  return true;
}

bool is_valid_time(int hour, int minute) {
  if (hour < 0 || hour > 23) {
    return false;
  }
  if (minute < 0 || minute > 59) {
    return false;
  }
  return true;
}

void add_appointment() {
  if (num_appointments >= MAX_APPOINTMENTS) {
    printf("Sorry, the appointment book is full.\n");
    return;
  }
  
  struct appointment a;
  
  printf("Enter the name of the appointment: ");
  fgets(a.name, MAX_NAME_LENGTH, stdin);
  printf("Enter the date of the appointment (YYYY-MM-DD): ");
  scanf("%d-%d-%d", &a.year, &a.month, &a.day);
  if (!is_valid_date(a.day, a.month, a.year)) {
    printf("Invalid date.\n");
    return;
  }
  printf("Enter the time of the appointment (HH:MM): ");
  scanf("%d:%d", &a.hour, &a.minute);
  if (!is_valid_time(a.hour, a.minute)) {
    printf("Invalid time.\n");
    return;
  }
  
  appointment_list[num_appointments] = a;
  num_appointments++;
  
  printf("Appointment added.\n");
}

void view_appointments() {
  if (num_appointments == 0) {
    printf("There are no appointments.\n");
    return;
  }
  
  printf("Appointments:\n");
  for (int i = 0; i < num_appointments; i++) {
    struct appointment a = appointment_list[i];
    printf("- %s on %04d-%02d-%02d at %02d:%02d\n",
           a.name, a.year, a.month, a.day, a.hour, a.minute);
  }
}

void delete_appointment() {
  if (num_appointments == 0) {
    printf("There are no appointments.\n");
    return;
  }
  
  printf("Enter the index of the appointment to delete (1-%d): ", num_appointments);
  int index;
  scanf("%d", &index);
  if (index < 1 || index > num_appointments) {
    printf("Invalid index.\n");
    return;
  }
  
  for (int i = index-1; i < num_appointments-1; i++) {
    appointment_list[i] = appointment_list[i+1];
  }
  num_appointments--;
  
  printf("Appointment deleted.\n");
}

int main() {
  while (true) {
    printf("\nWhat would you like to do?\n");
    printf("1. Add appointment\n");
    printf("2. View appointments\n");
    printf("3. Delete appointment\n");
    printf("4. Quit\n");
    printf("> ");
    
    int choice;
    scanf("%d", &choice);
    getchar(); // consume newline left over from scanf
    
    switch (choice) {
      case 1:
        add_appointment();
        break;
      case 2:
        view_appointments();
        break;
      case 3:
        delete_appointment();
        break;
      case 4:
        return 0;
      default:
        printf("Invalid choice.\n");
    }
  }
}