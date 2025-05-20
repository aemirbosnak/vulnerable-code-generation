//FormAI DATASET v1.0 Category: Smart home automation ; Style: unmistakable
#include <stdio.h>

// Declare variables for each room's light status and temperature
int livingRoomLight = 0;
int bedroomLight = 0;
int kitchenLight = 0;
int livingRoomTemp = 70;
int bedroomTemp = 68;
int kitchenTemp = 72;

// Function to turn lights on/off
void toggleLight(int *light) {
  if (*light == 0) {
    *light = 1;
    printf("Light turned on.\n");
  } else {
    *light = 0;
    printf("Light turned off.\n");
  }
}

// Function to adjust temperature
void adjustTemp(int *temp, int change) {
  *temp += change;
  printf("Temperature adjusted to %d degrees.\n", *temp);
}

int main() {
  int userInput;
  
  printf("Welcome to the Smart Home Automation System.\n");
  
  while (1) {
    printf("\n---MENU---\n");
    printf("1. Living Room Light Status\n");
    printf("2. Bedroom Light Status\n");
    printf("3. Kitchen Light Status\n");
    printf("4. Living Room Temperature\n");
    printf("5. Bedroom Temperature\n");
    printf("6. Kitchen Temperature\n");
    printf("7. Toggle Living Room Light\n");
    printf("8. Toggle Bedroom Light\n");
    printf("9. Toggle Kitchen Light\n");
    printf("10. Adjust Living Room Temperature\n");
    printf("11. Adjust Bedroom Temperature\n");
    printf("12. Adjust Kitchen Temperature\n");
    printf("13. Exit Program\n");
    printf("Enter selection: ");
    scanf("%d", &userInput);
    
    switch (userInput) {
      case 1:
        printf("Living Room Light Status: %s\n", livingRoomLight == 1 ? "ON" : "OFF");
        break;
      case 2:
        printf("Bedroom Light Status: %s\n", bedroomLight == 1 ? "ON" : "OFF");
        break;
      case 3:
        printf("Kitchen Light Status: %s\n", kitchenLight == 1 ? "ON" : "OFF");
        break;
      case 4:
        printf("Living Room Temperature: %d degrees\n", livingRoomTemp);
        break;
      case 5:
        printf("Bedroom Temperature: %d degrees\n", bedroomTemp);
        break;
      case 6:
        printf("Kitchen Temperature: %d degrees\n", kitchenTemp);
        break;
      case 7:
        toggleLight(&livingRoomLight);
        break;
      case 8:
        toggleLight(&bedroomLight);
        break;
      case 9:
        toggleLight(&kitchenLight);
        break;
      case 10:
        printf("Enter temperature change (positive or negative integer): ");
        scanf("%d", &userInput);
        adjustTemp(&livingRoomTemp, userInput);
        break;
      case 11:
        printf("Enter temperature change (positive or negative integer): ");
        scanf("%d", &userInput);
        adjustTemp(&bedroomTemp, userInput);
        break;
      case 12:
        printf("Enter temperature change (positive or negative integer): ");
        scanf("%d", &userInput);
        adjustTemp(&kitchenTemp, userInput);
        break;
      case 13:
        printf("Exiting program...");
        return 0;
      default:
        printf("Invalid selection. Try again.\n");
        break;
    }
  }
}