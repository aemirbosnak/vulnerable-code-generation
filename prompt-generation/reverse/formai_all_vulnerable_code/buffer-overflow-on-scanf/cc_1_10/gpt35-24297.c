//FormAI DATASET v1.0 Category: Smart home light control ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main() {
  int light_1 = 0;
  int light_2 = 0;
  int light_3 = 0;

  printf("Welcome to the Smart Home Light Control!\n\n");

  while (1) {
    printf("Please choose which light you would like to control (1-3): ");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        if (light_1 == 0) {
          light_1 = 1;
          printf("Light 1 has been turned on!\n");
        } else {
          light_1 = 0;
          printf("Light 1 has been turned off!\n");
        }
        break;

      case 2:
        if (light_2 == 0) {
          light_2 = 1;
          printf("Light 2 has been turned on!\n");
        } else {
          light_2 = 0;
          printf("Light 2 has been turned off!\n");
        }
        break;

      case 3:
        if (light_3 == 0) {
          light_3 = 1;
          printf("Light 3 has been turned on!\n");
        } else {
          light_3 = 0;
          printf("Light 3 has been turned off!\n");
        }
        break;

      default:
        printf("Invalid choice. Please select a number between 1 and 3.\n");
    }

    printf("\n");
  }

  return 0;
}