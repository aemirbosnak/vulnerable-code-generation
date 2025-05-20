//FormAI DATASET v1.0 Category: Appointment Scheduler ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

struct appointment {
  char name[50];
  char date[20];
  char time[10];
};

int main() {
  int choice, i, n = 0;
  struct appointment a[10];

  do {
    printf("\n===== Appointment Scheduler =====");
    printf("\n1. Add new appointment");
    printf("\n2. Display all appointments");
    printf("\n0. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("\nEnter name: ");
        scanf("%s", a[n].name);
        printf("Enter date (dd/mm/yyyy): ");
        scanf("%s", a[n].date);
        printf("Enter time (hh:mmam/pm): ");
        scanf("%s", a[n].time);
        n++;
        printf("\nAppointment added successfully!");
        break;

      case 2:
        if(n == 0)
          printf("\nNo appointments found.");
        else {
          printf("\nAll appointments:\n");
          for(i=0; i<n; i++) {
            printf("\nName: %s", a[i].name);
            printf("\nDate: %s", a[i].date);
            printf("Time: %s\n", a[i].time);
          }
        }
        break;

      case 0:
        printf("\nExiting program...");
        exit(0);

      default:
        printf("\nInvalid choice. Please try again.");
    }
  } while(choice != 0);

  return 0;
}