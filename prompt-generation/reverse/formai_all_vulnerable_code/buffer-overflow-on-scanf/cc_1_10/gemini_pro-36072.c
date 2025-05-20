//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: Dennis Ritchie
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define MAX_TIME_TRIPS 10

typedef struct {
  time_t start_time;
  time_t end_time;
  char *destination;
} time_trip;

int main() {
  time_t current_time;
  time(&current_time);

  time_trip trips[MAX_TIME_TRIPS];

  int num_trips = 0;

  while (num_trips < MAX_TIME_TRIPS) {
    printf("Enter the start time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", &trips[num_trips].start_time);

    printf("Enter the end time (YYYY-MM-DD HH:MM:SS): ");
    scanf("%s", &trips[num_trips].end_time);

    printf("Enter the destination: ");
    scanf("%s", &trips[num_trips].destination);

    num_trips++;
  }

  for (int i = 0; i < num_trips; i++) {
    printf("Trip %d:\n", i + 1);
    printf("  Start time: %s\n", ctime(&trips[i].start_time));
    printf("  End time: %s\n", ctime(&trips[i].end_time));
    printf("  Destination: %s\n", trips[i].destination);

    time_t duration = trips[i].end_time - trips[i].start_time;
    printf("  Duration: %ld seconds\n", duration);

    if (duration < 0) {
      printf("  Error: End time cannot be before start time\n");
    } else if (trips[i].start_time < current_time) {
      printf("  Error: Start time cannot be in the past\n");
    } else if (trips[i].end_time > current_time) {
      printf("  Error: End time cannot be in the future\n");
    } else {
      printf("  Time travel successful!\n");
      sleep(duration);
      printf("  You have arrived at your destination: %s\n", trips[i].destination);
    }
  }

  return 0;
}