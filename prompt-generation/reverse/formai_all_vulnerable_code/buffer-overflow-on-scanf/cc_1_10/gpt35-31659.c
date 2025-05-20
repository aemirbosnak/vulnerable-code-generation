//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(NULL));
  int year = 2021;
  int option;

  printf("Welcome to the Time Travel Simulator!\n");
  printf("-------------------------------------\n\n");

  do {
    printf("What would you like to do?\n");
    printf("------------------------\n");
    printf("1. Jump Forward in Time\n");
    printf("2. Jump Backward in Time\n");
    printf("3. Exit\n");

    printf("\nEnter your choice: ");
    scanf("%d", &option);
    printf("\n");

    switch(option) {
      case 1:
        printf("How many years would you like to jump forward? ");
        int yearsForward;
        scanf("%d", &yearsForward);

        if(year + yearsForward > 2021) {
          printf("You cannot jump beyond the present year.\n");
        } else {
          year += yearsForward;
          printf("You have jumped %d years forward. The current year is now %d.\n", yearsForward, year);
        }
        break;
      
      case 2:
        printf("How many years would you like to jump backward? ");
        int yearsBackward;
        scanf("%d", &yearsBackward);

        if(year - yearsBackward < 0) {
          printf("You can only jump back to the year 0 or later.\n");
        } else {
          year -= yearsBackward;
          printf("You have jumped %d years backward. The current year is now %d.\n", yearsBackward, year);
        }
        break;

      case 3:
        printf("Thank you for using the Time Travel Simulator!\n");
        break;

      default:
        printf("Invalid option. Please try again.\n");
        break;
    }

    printf("\n");
  } while(option != 3);

  return 0;
}