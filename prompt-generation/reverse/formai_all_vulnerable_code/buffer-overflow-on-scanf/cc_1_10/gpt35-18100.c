//FormAI DATASET v1.0 Category: Smart home automation ; Style: active
#include <stdio.h>
#include <stdlib.h>

int main() {
  // Initialize variables
  int temp, light, security = 0;
  
  // Display welcome message
  printf("Welcome to Smart Home Automation Program!\n");
  
  // Loop until user quits the program
  while (1) {
    // Display main menu
    printf("\nMain Menu:\n1. Adjust Temperature\n2. Adjust Lighting\n3. Set Security\n4. Quit\n\nEnter your choice: ");
    
    // Take user input
    int choice;
    scanf("%d", &choice);
      
    // Execute user choice
    switch (choice) {
      case 1:
        // Adjust temperature
        printf("Enter temperature: ");
        scanf("%d", &temp);
        printf("Temperature set to %d degrees.\n", temp);
        break;
        
      case 2:
        // Adjust lighting
        printf("Enter light level (1-10): ");
        scanf("%d", &light);
        printf("Lighting set to level %d.\n", light);
        break;
        
      case 3:
        // Set security
        printf("Enter security level (0-3): ");
        scanf("%d", &security);
        printf("Security set to level %d.\n", security);
        break;
        
      case 4:
        // Quit program
        printf("Quitting program...\n");
        exit(0);
        break;
        
      default:
        // Invalid choice
        printf("Invalid choice. Please enter a valid choice.\n");
    }
  }
  
  return 0;
}