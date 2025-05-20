//GEMINI-pro DATASET v1.0 Category: Smart home light control ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

// Define the smart home light control system's states
typedef enum {
  STATE_OFF,
  STATE_ON,
  STATE_DIMMED
} light_state_t;

// Define the smart home light control system's events
typedef enum {
  EVENT_TURN_ON,
  EVENT_TURN_OFF,
  EVENT_DIM,
  EVENT_BRIGHTEN
} light_event_t;

// Define the smart home light control system's data structure
typedef struct {
  light_state_t state;
  pthread_mutex_t mutex;
  pthread_cond_t cond;
} light_control_t;

// Initialize the smart home light control system
light_control_t light_control = {
  .state = STATE_OFF,
  .mutex = PTHREAD_MUTEX_INITIALIZER,
  .cond = PTHREAD_COND_INITIALIZER
};

// Define the smart home light control system's thread function
void *light_control_thread(void *arg) {
  // Lock the mutex
  pthread_mutex_lock(&light_control.mutex);

  // Wait for an event to occur
  while (true) {
    pthread_cond_wait(&light_control.cond, &light_control.mutex);

    // Get the event that occurred
    light_event_t event = (light_event_t)arg;

    // Handle the event
    switch (event) {
      case EVENT_TURN_ON:
        light_control.state = STATE_ON;
        break;
      case EVENT_TURN_OFF:
        light_control.state = STATE_OFF;
        break;
      case EVENT_DIM:
        if (light_control.state == STATE_ON) {
          light_control.state = STATE_DIMMED;
        }
        break;
      case EVENT_BRIGHTEN:
        if (light_control.state == STATE_DIMMED) {
          light_control.state = STATE_ON;
        }
        break;
    }

    // Unlock the mutex
    pthread_mutex_unlock(&light_control.mutex);
  }

  return NULL;
}

// Main function
int main(void) {
  // Create the smart home light control system's thread
  pthread_t thread;
  pthread_create(&thread, NULL, light_control_thread, NULL);

  // Start the smart home light control system's event loop
  while (true) {
    // Get the user's input
    char input[10];
    printf("Enter a command (on, off, dim, brighten): ");
    scanf("%s", input);

    // Parse the user's input
    light_event_t event;
    if (strcmp(input, "on") == 0) {
      event = EVENT_TURN_ON;
    } else if (strcmp(input, "off") == 0) {
      event = EVENT_TURN_OFF;
    } else if (strcmp(input, "dim") == 0) {
      event = EVENT_DIM;
    } else if (strcmp(input, "brighten") == 0) {
      event = EVENT_BRIGHTEN;
    } else {
      printf("Invalid command\n");
      continue;
    }

    // Lock the mutex
    pthread_mutex_lock(&light_control.mutex);

    // Signal the event to the smart home light control system's thread
    pthread_cond_signal(&light_control.cond);

    // Unlock the mutex
    pthread_mutex_unlock(&light_control.mutex);

    // Get the current state of the smart home light control system
    pthread_mutex_lock(&light_control.mutex);
    light_state_t state = light_control.state;
    pthread_mutex_unlock(&light_control.mutex);

    // Print the current state of the smart home light control system
    printf("Current state: ");
    switch (state) {
      case STATE_OFF:
        printf("off\n");
        break;
      case STATE_ON:
        printf("on\n");
        break;
      case STATE_DIMMED:
        printf("dimmed\n");
        break;
    }
  }

  // Join the smart home light control system's thread
  pthread_join(thread, NULL);

  return 0;
}