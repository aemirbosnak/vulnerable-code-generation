//Gemma-7B DATASET v1.0 Category: Intrusion detection system ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 2048

typedef struct Sensor {
  char sensor_name[256];
  int sensor_id;
  int current_state;
  int threshold;
  char last_state_change_time[MAX_BUFFER_SIZE];
} Sensor;

Sensor sensors[] = {
  {"Kitchen Door Sensor", 1, 0, 5, "10:00:00"},
  {"Living Room Door Sensor", 2, 0, 5, "10:00:00"},
  {"Main Hall Sensor", 3, 0, 5, "10:00:00"}
};

int main() {
  char input[MAX_BUFFER_SIZE];
  int sensor_index = 0;
  int i = 0;

  printf("**Immersive Intrusion Detection System**\n\n");

  for (i = 0; i < 3; i++) {
    printf("Sensor Name: %s\n", sensors[i].sensor_name);
    printf("Sensor ID: %d\n", sensors[i].sensor_id);
    printf("Current State: %d\n", sensors[i].current_state);
    printf("Threshold: %d\n", sensors[i].threshold);
    printf("Last State Change Time: %s\n\n", sensors[i].last_state_change_time);
  }

  printf("Enter sensor ID: ");
  scanf("%s", input);

  sensor_index = atoi(input) - 1;

  if (sensors[sensor_index].current_state != sensors[sensor_index].threshold) {
    printf("Intrusion Detected! Sensor ID: %d\n", sensors[sensor_index].sensor_id);
    printf("Time: %s\n", sensors[sensor_index].last_state_change_time);
  } else {
    printf("No intrusion detected.\n");
  }

  return 0;
}