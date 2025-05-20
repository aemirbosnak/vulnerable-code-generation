//FormAI DATASET v1.0 Category: Smart home light control ; Style: dynamic
#include <stdio.h>

int main() {
  int numberOfLights = 5;
  int lightStatus[5] = {0, 0, 0, 0, 0}; // 0 for OFF, 1 for ON
  
  printf("Welcome to Smart Home Light Control:\n\n");
  
  while(1) { // continuous loop until program is manually stopped
    printf("What would you like to do?\n");
    printf("1. Turn on a specific light\n");
    printf("2. Turn off a specific light\n");
    printf("3. Check the status of all lights\n");
    printf("4. Exit program\n");
    
    int choice;
    scanf("%d", &choice);
    
    if(choice == 1) { // turn on a specific light
      printf("Which light would you like to turn on? (1-%d)\n", numberOfLights);
      int lightNumber;
      scanf("%d", &lightNumber);
      
      if(lightNumber < 1 || lightNumber > numberOfLights) {
        printf("Invalid light number. Please try again.\n\n");
        continue;
      }
      
      lightStatus[lightNumber-1] = 1;
      printf("Light %d has been turned on.\n\n", lightNumber);
    }
    else if(choice == 2) { // turn off a specific light
      printf("Which light would you like to turn off? (1-%d)\n", numberOfLights);
      int lightNumber;
      scanf("%d", &lightNumber);
      
      if(lightNumber < 1 || lightNumber > numberOfLights) {
        printf("Invalid light number. Please try again.\n\n");
        continue;
      }
      
      lightStatus[lightNumber-1] = 0;
      printf("Light %d has been turned off.\n\n", lightNumber);
    }
    else if(choice == 3) { // check status of all lights
      printf("Current status of all lights:\n");
      
      for(int i = 0; i < numberOfLights; i++) {
        printf("Light %d is %s\n", i+1, (lightStatus[i] == 0) ? "OFF" : "ON");
      }
      
      printf("\n");
    }
    else if(choice == 4) { // exit program
      printf("Thank you for using Smart Home Light Control. Goodbye!\n");
      break;
    }
    else { // invalid choice
      printf("Invalid choice. Please try again.\n\n");
    }
  }
  
  return 0;
}