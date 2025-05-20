//FormAI DATASET v1.0 Category: Smart home light control ; Style: high level of detail
#include <stdio.h>
#include <string.h>

// Define the maximum number of lights and their default status
#define MAX_LIGHTS 5
#define DEFAULT_STATUS "off"

// Define a struct to store information about each light
typedef struct {
  char name[20];          // The name of the light
  char status[5];         // The current status of the light (on/off)
  int brightness;         // The current brightness level of the light (0-10)
} Light;

// Define an array to store all the lights
Light lights[MAX_LIGHTS];

// Declare function prototypes
void initializeLights();
void printLights();
void turnOn();
void turnOff();
void setBrightness();

int main() {
  // Initialize the lights
  initializeLights();
  
  // Print the current status of the lights
  printf("Initial light status:\n");
  printLights();
  
  // Turn on the lights
  turnOn();
  
  // Print the updated status of the lights
  printf("Lights turned on:\n");
  printLights();
  
  // Set the brightness of the lights
  setBrightness();
  
  // Print the updated status of the lights
  printf("Brightness level updated:\n");
  printLights();
  
  // Turn off the lights
  turnOff();
  
  // Print the final status of the lights
  printf("Lights turned off:\n");
  printLights();
  
  return 0;
}

void initializeLights() {
  // Initialize each light with a name and default status
  strcpy(lights[0].name, "Living Room");
  strcpy(lights[0].status, DEFAULT_STATUS);
  lights[0].brightness = 0;
  
  strcpy(lights[1].name, "Kitchen");
  strcpy(lights[1].status, DEFAULT_STATUS);
  lights[1].brightness = 0;
  
  strcpy(lights[2].name, "Bedroom");
  strcpy(lights[2].status, DEFAULT_STATUS);
  lights[2].brightness = 0;
  
  strcpy(lights[3].name, "Bathroom");
  strcpy(lights[3].status, DEFAULT_STATUS);
  lights[3].brightness = 0;
  
  strcpy(lights[4].name, "Office");
  strcpy(lights[4].status, DEFAULT_STATUS);
  lights[4].brightness = 0;
}

void printLights() {
  // Print the current status of each light
  for (int i = 0; i < MAX_LIGHTS; i++) {
    printf("%s: %s at brightness level %d\n", lights[i].name, lights[i].status, lights[i].brightness);
  }
}

void turnOn() {
  // Turn on all the lights
  for (int i = 0; i < MAX_LIGHTS; i++) {
    strcpy(lights[i].status, "on");
    lights[i].brightness = 10;
  }
}

void turnOff() {
  // Turn off all the lights
  for (int i = 0; i < MAX_LIGHTS; i++) {
    strcpy(lights[i].status, "off");
    lights[i].brightness = 0;
  }
}

void setBrightness() {
  // Set the brightness level of each light
  for (int i = 0; i < MAX_LIGHTS; i++) {
    // Ask the user for the desired brightness level
    printf("Enter the brightness level (0-10) for %s: ", lights[i].name);
    scanf("%d", &lights[i].brightness);
    
    // Make sure the brightness level is within the valid range
    if (lights[i].brightness < 0) {
      lights[i].brightness = 0;
    } else if (lights[i].brightness > 10) {
      lights[i].brightness = 10;
    }
  }
}