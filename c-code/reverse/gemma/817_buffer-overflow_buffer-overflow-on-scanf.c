#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
  int choice, fan_state = 0, ac_state = 0;

  printf("Smart Home System Menu:\n");
  printf("1. Toggle Lights\n");
  printf("2. Control Fan\n");
  printf("3. Adjust AC\n");
  printf("Enter your choice: ");

  scanf("%d", &choice);

  switch (choice) {
    case 1:
      // Logic to toggle lights
      break;
    case 2:
      // Logic to control fan
      fan_state = (fan_state == 0) ? 1 : 0;
      printf("Fan is %s.\n", fan_state ? "on" : "off");
      break;
    case 3:
      // Logic to adjust AC
      ac_state = (ac_state == 0) ? 1 : 0;
      printf("AC is %s.\n", ac_state ? "on" : "off");
      break;
    default:
      printf("Invalid input.\n");
  }

  return 0;
}
