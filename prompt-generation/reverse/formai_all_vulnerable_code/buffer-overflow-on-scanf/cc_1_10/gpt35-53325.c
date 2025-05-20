//FormAI DATASET v1.0 Category: Smart home automation ; Style: enthusiastic
#include <stdio.h>

int main() {
  // Declare and initialize variables
  int lights = 0;
  int fans = 0;
  int ac = 0;
  
  // Loop for user input
  while (1) {
    // Print menu options
    printf("Select an option:\n");
    printf("1. Turn lights on/off\n");
    printf("2. Turn fans on/off\n");
    printf("3. Turn AC on/off\n");
    printf("4. Exit program\n");
    
    // Read user input
    int option = 0;
    scanf("%d", &option);
    
    // Execute selected option
    switch(option) {
      case 1:
        lights = !lights; // Toggle lights state
        printf("Lights turned %s\n", lights ? "on" : "off");
        break;
      
      case 2:
        fans = !fans; // Toggle fans state
        printf("Fans turned %s\n", fans ? "on" : "off");
        break;
      
      case 3:
        ac = !ac; // Toggle AC state
        printf("AC turned %s\n", ac ? "on" : "off");
        break;
      
      case 4:
        printf("Exiting program...\n");
        return 0;
      
      default:
        printf("Invalid option selected\n");
        break;
    }
    
    // Sleep for a second to allow user to read output
    sleep(1);
    
    // Print separator for output readability
    printf("--------------------------\n");
  }
}