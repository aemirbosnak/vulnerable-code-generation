//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct appointment {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  char name[50];
  char reason[100];
};

int main() {
  struct appointment appt[10];
  int num_appts = 0;
  int choice = 0;

  printf("*** APPOINTMENT SCHEDULER ***\n\n");

  while (choice != 4) {
    printf("MAIN MENU\n");
    printf("1. Add Appointment\n");
    printf("2. Delete Appointment\n");
    printf("3. View Appointments\n");
    printf("4. Exit\n\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        if (num_appts >= 10) {
          printf("Sorry, you have reached the maximum number of appointments.\n");
        }
        else {
          printf("Enter the appointment information.\n");
          printf("Format: yyyy/mm/dd hh:mm Name Reason\n");
          scanf("%d/%d/%d %d:%d %[^\n] %[^\n]", &appt[num_appts].year, &appt[num_appts].month, &appt[num_appts].day, &appt[num_appts].hour, &appt[num_appts].minute, appt[num_appts].name, appt[num_appts].reason);
          num_appts++;
        }
        break;

      case 2:
        if (num_appts == 0) {
          printf("There are no appointments to delete.\n");
        }
        else {
          int appt_num = 0;
          printf("Enter the number of the appointment to delete (1-%d): ", num_appts);
          scanf("%d", &appt_num);

          if (appt_num < 1 || appt_num > num_appts) {
            printf("Invalid appointment number.\n");
          }
          else {
            for (int i = appt_num - 1; i < num_appts - 1; i++) {
              appt[i] = appt[i+1];
            }
            num_appts--;
            printf("Appointment deleted.\n");
          }
        }
        break;

      case 3:
        if (num_appts == 0) {
          printf("There are no appointments to view.\n");
        }
        else {
          printf("APPOINTMENTS\n");
          for (int i = 0; i < num_appts; i++) {
            printf("%d. %04d/%02d/%02d %02d:%02d %s - %s\n", i+1, appt[i].year, appt[i].month, appt[i].day, appt[i].hour, appt[i].minute, appt[i].name, appt[i].reason);
          }
        }
        break;

      case 4:
        printf("Exiting...\n");
        break;

      default:
        printf("Invalid choice.\n");
        break;
    }
  }

  return 0;
}