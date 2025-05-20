//GEMINI-pro DATASET v1.0 Category: GPS Navigation Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Get ready for an epic GPS navigation simulation that'll make your wheels sing!

typedef struct {
  double latitude;
  double longitude;
} Location;

Location current_location = {37.422408, 122.084067}; // Starting at the Googleplex!

void print_location() {
  printf("Current location: %.6f, %.6f\n", current_location.latitude, current_location.longitude);
}

int main() {
  // Welcome aboard, my GPS adventurer! Let's embark on a thrilling journey:

  printf("** GPS Navigation Simulation **\n");
  print_location();

  // Plot your course, captain! Enter commands to navigate through the urban jungle:

  while (1) {
    char command;
    printf("Enter command (N/S/E/W/U/D/Q): ");
    scanf(" %c", &command);

    switch (command) {
      case 'N': // Northward bound!
        current_location.latitude += 0.001;
        print_location();
        break;
      case 'S': // Southward ho!
        current_location.latitude -= 0.001;
        print_location();
        break;
      case 'E': // Eastward adventures!
        current_location.longitude += 0.001;
        print_location();
        break;
      case 'W': // Westward wanderings!
        current_location.longitude -= 0.001;
        print_location();
        break;
      case 'U':
        printf("Feeling a little lofty, eh? You're now 100m higher!\n");
        // Imagine the views from this altitude!
        break;
      case 'D':
        printf("Descending like a pro. You're now 100m lower.\n");
        // Prepare for a thrilling drop!
        break;
      case 'Q': // Time to disembark!
        printf("Thank you for navigating with us! Have a stellar day.\n");
        return 0;
      default:
        printf("Invalid command. Please enter a valid direction (N/S/E/W/U/D/Q).\n");
    }
  }

  return 0;
}