//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct appointment {
  char name[20];
  char time[20];
  char date[20];
};

int main() {
  struct appointment appointments[MAX];
  int i = 0;
  int choice;
  char name[20];
  char time[20];
  char date[20];

  while (1) {
    system("cls");
    printf("**Appointment Scheduler**\n");
    printf("1. Create New Appointment\n");
    printf("2. View Appointments\n");
    printf("3. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter your name: ");
        scanf("%s", appointments[i].name);

        printf("Enter the time: ");
        scanf("%s", appointments[i].time);

        printf("Enter the date: ");
        scanf("%s", appointments[i].date);

        i++;
        break;

      case 2:
        system("cls");
        printf("Your appointments:\n");
        for (int j = 0; j < i; j++) {
          printf("Name: %s\n", appointments[j].name);
          printf("Time: %s\n", appointments[j].time);
          printf("Date: %s\n", appointments[j].date);
          printf("\n");
        }
        break;

      case 3:
        exit(0);
    }
  }

  return 0;
}