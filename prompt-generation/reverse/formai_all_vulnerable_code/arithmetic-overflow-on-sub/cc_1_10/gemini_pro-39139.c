//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// The Time Capsule struct stores a message and a timestamp.
typedef struct TimeCapsule {
  char *message;
  time_t timestamp;
} TimeCapsule;

// The Time Traveler struct stores a collection of Time Capsules.
typedef struct TimeTraveler {
  TimeCapsule *capsules;
  int num_capsules;
} TimeTraveler;

// Create a new TimeCapsule.
TimeCapsule *create_time_capsule(char *message) {
  TimeCapsule *capsule = malloc(sizeof(TimeCapsule));
  capsule->message = message;
  capsule->timestamp = time(NULL);
  return capsule;
}

// Add a TimeCapsule to the TimeTraveler.
void add_time_capsule(TimeTraveler *traveler, TimeCapsule *capsule) {
  traveler->capsules = realloc(traveler->capsules, (traveler->num_capsules + 1) * sizeof(TimeCapsule));
  traveler->capsules[traveler->num_capsules++] = *capsule;
}

// Travel to the past and retrieve a TimeCapsule.
TimeCapsule *travel_to_past(TimeTraveler *traveler, time_t timestamp) {
  for (int i = 0; i < traveler->num_capsules; i++) {
    if (traveler->capsules[i].timestamp == timestamp) {
      return &traveler->capsules[i];
    }
  }
  return NULL;
}

// Print the message from a TimeCapsule.
void print_time_capsule(TimeCapsule *capsule) {
  printf("Message from the past: %s\n", capsule->message);
}

// Free the memory allocated for a TimeCapsule.
void free_time_capsule(TimeCapsule *capsule) {
  free(capsule->message);
  free(capsule);
}

// Free the memory allocated for a TimeTraveler.
void free_time_traveler(TimeTraveler *traveler) {
  for (int i = 0; i < traveler->num_capsules; i++) {
    free_time_capsule(&traveler->capsules[i]);
  }
  free(traveler->capsules);
  free(traveler);
}

// The main function creates a TimeTraveler, adds a TimeCapsule, travels to the past, and prints the message.
int main() {
  TimeTraveler *traveler = malloc(sizeof(TimeTraveler));
  traveler->capsules = NULL;
  traveler->num_capsules = 0;

  TimeCapsule *capsule = create_time_capsule("Hello from the future!");
  add_time_capsule(traveler, capsule);

  time_t past_timestamp = time(NULL) - 3600;  // Travel back 1 hour
  TimeCapsule *past_capsule = travel_to_past(traveler, past_timestamp);
  if (past_capsule != NULL) {
    print_time_capsule(past_capsule);
  } else {
    printf("No message found in the past.\n");
  }

  free_time_traveler(traveler);
  return 0;
}