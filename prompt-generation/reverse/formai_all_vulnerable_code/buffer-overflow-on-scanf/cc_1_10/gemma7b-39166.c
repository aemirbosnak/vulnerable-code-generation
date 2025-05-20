//Gemma-7B DATASET v1.0 Category: Appointment Scheduler ; Style: romantic
#include <stdio.h>
#include <string.h>

struct appointment {
  char name[50];
  char date[50];
  char time[50];
  char reason[50];
};

int main() {
  struct appointment appointments[100];
  int i = 0;

  // Create a loop to add appointments
  while (1) {
    printf("Enter your name: ");
    scanf("%s", appointments[i].name);

    printf("Enter the date: ");
    scanf("%s", appointments[i].date);

    printf("Enter the time: ");
    scanf("%s", appointments[i].time);

    printf("Enter the reason: ");
    scanf("%s", appointments[i].reason);

    i++;

    // Check if the user wants to add another appointment
    printf("Do you want to add another appointment? (Y/N): ");
    char answer;
    scanf("%c", &answer);

    if (answer == 'N') {
      break;
    }
  }

  // Print the appointments
  printf("Your appointments:\n");
  for (int j = 0; j < i; j++) {
    printf("Name: %s\n", appointments[j].name);
    printf("Date: %s\n", appointments[j].date);
    printf("Time: %s\n", appointments[j].time);
    printf("Reason: %s\n", appointments[j].reason);
    printf("\n");
  }

  return 0;
}