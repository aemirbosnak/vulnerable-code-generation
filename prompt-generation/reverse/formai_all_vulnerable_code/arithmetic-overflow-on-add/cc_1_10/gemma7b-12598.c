//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TRAFFIC_LIGHT_NUMBER 5
#define MAX_LANE_NUMBER 3

typedef struct TrafficLight {
  int current_state;
  int next_state;
  int timer;
} TrafficLight;

typedef struct Lane {
  int current_vehicle_number;
  TrafficLight *traffic_light;
} Lane;

TrafficLight traffic_lights[MAX_TRAFFIC_LIGHT_NUMBER];
Lane lanes[MAX_LANE_NUMBER];

void initialize_traffic_lights() {
  for (int i = 0; i < MAX_TRAFFIC_LIGHT_NUMBER; i++) {
    traffic_lights[i].current_state = 0;
    traffic_lights[i].next_state = 1;
    traffic_lights[i].timer = 0;
  }
}

void initialize_lanes() {
  for (int i = 0; i < MAX_LANE_NUMBER; i++) {
    lanes[i].current_vehicle_number = 0;
    lanes[i].traffic_light = &traffic_lights[0];
  }
}

void simulate_traffic_flow() {
  time_t start_time = time(NULL);
  time_t end_time = start_time + 10;

  while (time(NULL) < end_time) {
    for (int i = 0; i < MAX_TRAFFIC_LIGHT_NUMBER; i++) {
      traffic_lights[i].timer++;

      if (traffic_lights[i].timer == traffic_lights[i].next_state) {
        traffic_lights[i].current_state = traffic_lights[i].next_state;
        traffic_lights[i].timer = 0;
      }
    }

    for (int i = 0; i < MAX_LANE_NUMBER; i++) {
      if (lanes[i].current_vehicle_number > 0) {
        lanes[i].traffic_light->current_state = 1;
      }
    }

    sleep(1);
  }

  for (int i = 0; i < MAX_TRAFFIC_LIGHT_NUMBER; i++) {
    printf("Traffic Light %d is currently in state %d\n", i, traffic_lights[i].current_state);
  }

  for (int i = 0; i < MAX_LANE_NUMBER; i++) {
    printf("Lane %d has %d vehicles\n", i, lanes[i].current_vehicle_number);
  }
}

int main() {
  initialize_traffic_lights();
  initialize_lanes();
  simulate_traffic_flow();

  return 0;
}