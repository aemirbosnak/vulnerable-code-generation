//GEMINI-pro DATASET v1.0 Category: Traffic Light Controller ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Constants representing the different light colors
#define RED     1
#define GREEN   2
#define YELLOW  3

// Global variable representing the current light color
int current_light = RED;

// Mutex to protect the critical section
pthread_mutex_t light_mutex;

// Condition variable to signal a change in light color
pthread_cond_t light_cond;

// Function to simulate a traffic light
void *traffic_light(void *arg) {
  // Lock the mutex
  pthread_mutex_lock(&light_mutex);

  // Loop forever
  while (1) {
    // Display the current light color
    switch (current_light) {
      case RED:
        printf("Red light is on!\n");
        break;
      case GREEN:
        printf("Green light is on!\n");
        break;
      case YELLOW:
        printf("Yellow light is on!\n");
        break;
    }

    // Wait for a signal to change the light color
    pthread_cond_wait(&light_cond, &light_mutex);

    // Change the light color
    current_light = (current_light % 3) + 1;

    // Unlock the mutex
    pthread_mutex_unlock(&light_mutex);
  }

  return NULL;
}

int main() {
  // Initialize the mutex and condition variable
  pthread_mutex_init(&light_mutex, NULL);
  pthread_cond_init(&light_cond, NULL);

  // Create a thread to simulate the traffic light
  pthread_t light_thread;
  pthread_create(&light_thread, NULL, traffic_light, NULL);

  // Loop forever, simulating user input
  while (1) {
    // Get user input
    char input;
    printf("Press any key to change the light color: ");
    scanf(" %c", &input);

    // Lock the mutex
    pthread_mutex_lock(&light_mutex);

    // Signal the traffic light thread to change the light color
    pthread_cond_signal(&light_cond);

    // Unlock the mutex
    pthread_mutex_unlock(&light_mutex);
  }

  // Cleanup
  pthread_join(light_thread, NULL);
  pthread_mutex_destroy(&light_mutex);
  pthread_cond_destroy(&light_cond);

  return 0;
}