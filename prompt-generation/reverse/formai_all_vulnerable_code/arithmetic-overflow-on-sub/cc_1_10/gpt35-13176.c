//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_PLACE_LENGTH 50
#define MAX_NAME_LENGTH 20

typedef struct {
  char name[MAX_NAME_LENGTH];
  float longitude;
  float latitude;
} Place;

typedef struct {
  Place places[MAX_PLACE_LENGTH];
  int num_places;
} Route;

void initialize_route(Route *route) {
  route->num_places = 0;
}

void add_place(Route *route, char *name, float longitude, float latitude) {
  if (route->num_places < MAX_PLACE_LENGTH) {
    Place new_place;
    strcpy(new_place.name, name);
    new_place.longitude = longitude;
    new_place.latitude = latitude;
    route->places[route->num_places] = new_place;
    route->num_places++;
  } else {
    printf("The route is full. Cannot add more places.\n");
  }
}

float get_distance(Place place1, Place place2) {
  float x_diff = place1.longitude - place2.longitude;
  float y_diff = place1.latitude - place2.latitude;
  return sqrt(x_diff * x_diff + y_diff * y_diff);
}

void print_route(Route route) {
  printf("Route:\n");
  for (int i = 0; i < route.num_places; i++) {
    printf("%d. %s\n", i+1, route.places[i].name);
  }
}

Place get_destination(Route route) {
  int destination_index;
  printf("Enter the number of the destination: ");
  scanf("%d", &destination_index);
  destination_index--;
  
  if (destination_index < 0 || destination_index >= route.num_places) {
    printf("Invalid destination number. Program will exit now.\n");
    exit(0);
  }
  
  printf("Destination: %s\n", route.places[destination_index].name);
  return route.places[destination_index];
}

bool is_at_destination(Place current_location, Place destination, float allowed_error) {
  float distance = get_distance(current_location, destination);
  
  if (distance <= allowed_error) {
    printf("Congratulations! You have arrived at your destination: %s\n", destination.name);
    return true;
  }
  
  printf("You are %.2f meters away from %s. Keep moving.\n", distance, destination.name);
  return false;
}

int main() {
  printf("Welcome to the GPS Navigation Simulation program.\n");
  printf("Please enter the details of the route.\n");
  
  Route route;
  initialize_route(&route);
  
  char name[MAX_NAME_LENGTH];
  float longitude, latitude;
  
  printf("Enter the number of places in the route: ");
  int num_places;
  scanf("%d", &num_places);
  
  for (int i = 0; i < num_places; i++) {
    printf("Place %d:\n", i+1);
    printf("Name: ");
    scanf("%s", name);
    printf("Longitude: ");
    scanf("%f", &longitude);
    printf("Latitude: ");
    scanf("%f", &latitude);
    
    add_place(&route, name, longitude, latitude);
    printf("Added %s to the route.\n", name);
  }
  
  print_route(route);
  
  printf("Please enter your current location.\n");
  printf("Longitude: ");
  float current_longitude;
  scanf("%f", &current_longitude);
  printf("Latitude: ");
  float current_latitude;
  scanf("%f", &current_latitude);
  
  Place current_location;
  current_location.longitude = current_longitude;
  current_location.latitude = current_latitude;
  
  while (true) {
    Place destination = get_destination(route);
    
    while (!is_at_destination(current_location, destination, 10.0)) {
      printf("Please continue moving.\n");
      printf("Longitude: ");
      scanf("%f", &current_longitude);
      printf("Latitude: ");
      scanf("%f", &current_latitude);
      
      current_location.longitude = current_longitude;
      current_location.latitude = current_latitude;
    }
    
    printf("Please enter a command:\n");
    printf("1. Continue to next destination.\n");
    printf("2. End navigation.\n");
    
    int command;
    scanf("%d", &command);
    
    if (command == 1) {
      printf("Moving to next destination.\n");
    } else if (command == 2) {
      printf("Navigation ended. Thank you for using our program.\n");
      exit(0);
    } else {
      printf("Invalid command.\n");
    }
  }
}