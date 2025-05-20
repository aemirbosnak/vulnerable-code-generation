//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// Define the GPIO pin numbers for the lights
#define LIGHT_1 4
#define LIGHT_2 17
#define LIGHT_3 27

// Define the states for the lights
#define OFF 0
#define ON 1

// Initialize the lights to be off
int lights[3] = {OFF, OFF, OFF};

// Define the command line arguments
char *argv[4];

// Define the main function
int main(int argc, char *argv[]) {
  // Check if the correct number of arguments have been provided
  if (argc != 4) {
    printf("Usage: %s <light number> <on/off> <duration>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Parse the command line arguments
  int light_number = atoi(argv[1]);
  int state = atoi(argv[2]);
  int duration = atoi(argv[3]);

  // Check if the light number is valid
  if (light_number < 1 || light_number > 3) {
    printf("Invalid light number\n");
    return EXIT_FAILURE;
  }

  // Check if the state is valid
  if (state != OFF && state != ON) {
    printf("Invalid state\n");
    return EXIT_FAILURE;
  }

  // Check if the duration is valid
  if (duration < 0) {
    printf("Invalid duration\n");
    return EXIT_FAILURE;
  }

  // Set the light state
  lights[light_number - 1] = state;

  // Open the GPIO pin for the light
  int fd = open("/sys/class/gpio/gpio" + light_number, O_WRONLY);
  if (fd < 0) {
    perror("open");
    return EXIT_FAILURE;
  }

  // Write the light state to the GPIO pin
  if (write(fd, state == ON ? "1" : "0", 1) < 0) {
    perror("write");
    return EXIT_FAILURE;
  }

  // Close the GPIO pin
  if (close(fd) < 0) {
    perror("close");
    return EXIT_FAILURE;
  }

  // Sleep for the specified duration
  sleep(duration);

  // Set the light state to off
  lights[light_number - 1] = OFF;

  // Open the GPIO pin for the light
  fd = open("/sys/class/gpio/gpio" + light_number, O_WRONLY);
  if (fd < 0) {
    perror("open");
    return EXIT_FAILURE;
  }

  // Write the light state to the GPIO pin
  if (write(fd, "0", 1) < 0) {
    perror("write");
    return EXIT_FAILURE;
  }

  // Close the GPIO pin
  if (close(fd) < 0) {
    perror("close");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}