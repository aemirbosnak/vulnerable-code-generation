//FormAI DATASET v1.0 Category: Smart home light control ; Style: random
#include <stdio.h>
#include <stdbool.h>

void turnOnOffLight(bool isOn) {
  if (isOn) {
    printf("The light is now on.\n");
  } else {
    printf("The light is now off.\n");
  }
}

void changeBrightness(int brightness) {
  if (brightness > 0 && brightness <= 100) {
    printf("The brightness is now set to %d%%.\n", brightness);
  } else {
    printf("Invalid brightness value. Please enter a value between 1 and 100.\n");
  }
}

void changeColor(char color[10]) {
  if (strcmp(color, "red") == 0 || strcmp(color, "green") == 0 || strcmp(color, "blue") == 0) {
    printf("The color is now set to %s.\n", color);
  } else {
    printf("Invalid color value. Please enter red, green or blue.\n");
  }
}

int main() {
  bool isOn = false;
  int brightness = 0;
  char color[10];

  printf("Welcome to the Smart Home Light Control System!\n");

  while (true) {
    printf("Please select an option:\n");
    printf("1. Turn on/off the light\n");
    printf("2. Change the brightness\n");
    printf("3. Change the color\n");
    printf("4. Quit\n");

    int option;
    scanf("%d", &option);

    if (option == 1) {
      isOn = !isOn;
      turnOnOffLight(isOn);
    } else if (option == 2) {
      printf("Enter the brightness value (1-100): ");
      scanf("%d", &brightness);
      changeBrightness(brightness);
    } else if (option == 3) {
      printf("Enter the color (red/green/blue): ");
      scanf("%s", color);
      changeColor(color);
    } else if (option == 4) {
      printf("Thank you for using the Smart Home Light Control System!\n");
      break;
    } else {
      printf("Invalid option selected.\n");
    }

    printf("\n");
  }

  return 0;
}