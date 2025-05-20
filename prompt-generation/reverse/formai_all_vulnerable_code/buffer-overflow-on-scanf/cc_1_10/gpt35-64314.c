//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

int main() {
  // initialize variables
  float lat, lon;
  int choice, quit = 0;
  
  // loop until user wants to quit
  while(!quit) {
    printf("What would you like to do?\n");
    printf("1. Enter GPS coordinates\n");
    printf("2. Display coordinates on map\n");
    printf("3. Get directions\n");
    printf("4. Quit\n");
    printf("Please enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
      case 1:
        // prompt user for latitude and longitude
        printf("Please enter latitude: ");
        scanf("%f", &lat);
        printf("Please enter longitude: ");
        scanf("%f", &lon);
        printf("GPS coordinates (%.2f, %.2f) saved.\n", lat, lon);
        break;
        
      case 2:
        // display map with saved coordinates
        printf("Map displayed with GPS coordinates (%.2f, %.2f).\n", lat, lon);
        break;
        
      case 3:
        // get directions from current location to saved coordinates
        printf("Directions from current location to GPS coordinates (%.2f, %.2f):\n", lat, lon);
        printf("1. Turn left onto Main St.\n");
        printf("2. Turn right onto Elm St.\n");
        printf("3. Turn left onto Maple St.\n");
        printf("4. Turn right onto Oak St.\n");
        printf("5. Destination on the right.\n");
        break;
        
      case 4:
        // user wants to quit program
        printf("Quitting program.\n");
        quit = 1;
        break;
        
      default:
        // invalid choice
        printf("Invalid choice. Please try again.\n");
        break;
    }
  }
  
  return 0;
}