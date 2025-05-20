//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_LOCATIONS 1000
#define MAX_ROUTE_LENGTH 10000

// Define structures
typedef struct {
  char name[100];
  double latitude;
  double longitude;
} Location;

typedef struct {
  Location locations[MAX_ROUTE_LENGTH];
  int length;
} Route;

// Define functions
void addLocation(Location* locations, int* numLocations);
void plotRoute(Route* route);
void printInstructions(void);
char* getInput(char* prompt);

// Define the main function
int main(void) {
  // Initialize variables
  Location locations[MAX_LOCATIONS];
  int numLocations = 0;
  char* input;

  // Print instructions
  printInstructions();

  // Start loop to get user input
  while(1) {
    // Get input from user
    input = getInput("> ");

    if(strcmp(input, "q") == 0) {
      // Quit program
      printf("Exiting program...\n");
      break;
    } else if(strcmp(input, "a") == 0) {
      // Add a location
      addLocation(locations, &numLocations);
    } else if(strcmp(input, "p") == 0) {
      // Plot the route
      Route route = { .length = numLocations };
      memcpy(&route.locations, &locations, sizeof(Location) * numLocations);
      plotRoute(&route);
    } else {
      // Invalid input
      printf("Invalid input.\n");
    }
  }

  return 0;
}

void addLocation(Location* locations, int* numLocations) {
  // Declare variables
  char* name;
  double latitude;
  double longitude;
  char* input;

  // Get name
  printf("Enter name: ");
  name = getInput("> ");

  // Get latitude
  printf("Enter latitude: ");
  input = getInput("> ");
  latitude = atof(input);

  // Get longitude
  printf("Enter longitude: ");
  input = getInput("> ");
  longitude = atof(input);

  // Add location to list
  Location location = { .latitude = latitude, .longitude = longitude };
  strcpy(location.name, name);
  locations[*numLocations] = location;
  *numLocations += 1;

  printf("Location added successfully.\n");
}

void plotRoute(Route* route) {
  // Output information about the route
  printf("Plotting route...\n");
  printf("Route length: %d\n", route->length);

  // Output each location on the route
  for(int i = 0; i < route->length; i++) {
    printf("%d: %s (%.2f, %.2f)\n", i + 1, route->locations[i].name, route->locations[i].latitude, route->locations[i].longitude);
  }
}

void printInstructions(void) {
  printf("Welcome to the GPS Navigation Simulation Program!\n");
  printf("\n");
  printf("Commands:\n");
  printf("a - add location\n");
  printf("p - plot route\n");
  printf("q - quit program\n");
  printf("\n");
}

char* getInput(char* prompt) {
  // Declare variables
  char buffer[1000];

  // Get input from user
  printf("%s", prompt);
  fgets(buffer, sizeof(buffer), stdin);

  // Remove newline character
  buffer[strlen(buffer) - 1] = '\0';

  // Return input
  return strdup(buffer);
}