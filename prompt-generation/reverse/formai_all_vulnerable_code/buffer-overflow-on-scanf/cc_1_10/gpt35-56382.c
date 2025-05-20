//FormAI DATASET v1.0 Category: System administration ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  printf("Welcome to the automatic food delivery system!\n");
  printf("Admin password: ");
  char password[10];
  scanf("%s", password);

  if (atoi(password) != 1234) {
    printf("Permission denied!\n");
    return 0;
  }

  printf("Access granted! System starting up...\n");
  sleep(3);

  printf("Checking for hungry users...\n");
  sleep(2);

  int numUsers = rand() % 10;
  if (numUsers == 0) {
    printf("No users found... returning to sleep mode\n");
    return 0;
  }

  printf("%d hungry users detected! Starting food delivery system...\n", numUsers);
  sleep(2);

  char* foods[4] = {"Pizza", "Burger", "Taco", "Sushi"};

  for (int i = 0; i < numUsers; i++) {
    int randFoodIndex = rand() % 4;
    char* foodChoice = foods[randFoodIndex];

    printf("User %d getting %s delivered... ", i+1, foodChoice);
    sleep(3);

    int success = rand() % 2;
    if (success) {
      printf("Success!\n");
    } else {
      printf("Delivery failed!\n");
    }

    sleep(2);
  }

  printf("All deliveries complete! System shutting down...\n");
  sleep(2);
  printf("Goodbye!\n");

  return 0;
}