//FormAI DATASET v1.0 Category: Smart home automation ; Style: enthusiastic
#include <stdio.h>

int main() {
  int temperature = 25;
  int light = 1; // 1 for ON, 0 for OFF
  int security = 0; // 1 for ON, 0 for OFF

  printf("Welcome to the Smart Home Automation System!\n\n");
  printf("Current temperature: %d°C\n", temperature);
  printf("Light status: %s\n", (light == 1) ? "ON" : "OFF");
  printf("Security status: %s\n\n", (security == 1) ? "ON" : "OFF");

  printf("What would you like to do?\n");
  printf("1. Increase temperature\n");
  printf("2. Decrease temperature\n");
  printf("3. Turn light ON\n");
  printf("4. Turn light OFF\n");
  printf("5. Turn security ON\n");
  printf("6. Turn security OFF\n");
  printf("Please enter your choice (1-6): ");
  int choice;
  scanf("%d", &choice);

  switch(choice) {
    case 1:
      temperature++;
      printf("\nTemperature increased to %d°C.\n", temperature);
      break;
    case 2:
      temperature--;
      printf("\nTemperature decreased to %d°C.\n", temperature);
      break;
    case 3:
      if (light == 0) {
        light = 1;
        printf("\nLight turned ON.\n");
      } else {
        printf("\nLight is already ON.\n");
      }
      break;
    case 4:
      if (light == 1) {
        light = 0;
        printf("\nLight turned OFF.\n");
      } else {
        printf("\nLight is already OFF.\n");
      }
      break;
    case 5:
      if (security == 0) {
        security = 1;
        printf("\nSecurity turned ON.\n");
      } else {
        printf("\nSecurity is already ON.\n");
      }
      break;
    case 6:
      if (security == 1) {
        security = 0;
        printf("\nSecurity turned OFF.\n");
      } else {
        printf("\nSecurity is already OFF.\n");
      }
      break;
    default:
      printf("\nInvalid choice.\n");
  }

  printf("\nUpdated status:\n");
  printf("Current temperature: %d°C\n", temperature);
  printf("Light status: %s\n", (light == 1) ? "ON" : "OFF");
  printf("Security status: %s\n", (security == 1) ? "ON" : "OFF");

  return 0;
}