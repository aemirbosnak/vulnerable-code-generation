//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: funny
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

// The CPU usage meter.
void cpu_meter() {
  // Get the current CPU usage.
  FILE *fp = fopen("/proc/stat", "r");
  if (fp == NULL) {
    perror("fopen");
    exit(EXIT_FAILURE);
  }
  char buf[1024];
  if (fgets(buf, sizeof(buf), fp) == NULL) {
    perror("fgets");
    exit(EXIT_FAILURE);
  }
  fclose(fp);

  // Parse the CPU usage.
  char *p = buf;
  while (*p != ' ') {
    p++;
  }
  while (*p == ' ') {
    p++;
  }
  int user_time = atoi(p);
  while (*p != ' ') {
    p++;
  }
  while (*p == ' ') {
    p++;
  }
  int nice_time = atoi(p);
  while (*p != ' ') {
    p++;
  }
  while (*p == ' ') {
    p++;
  }
  int system_time = atoi(p);
  while (*p != ' ') {
    p++;
  }
  while (*p == ' ') {
    p++;
  }
  int idle_time = atoi(p);

  // Calculate the CPU usage.
  double cpu_usage = (double)(user_time + nice_time + system_time) / (user_time + nice_time + system_time + idle_time);

  // Draw the CPU usage meter.
  printf("CPU usage: %.2f%%\n", cpu_usage * 100);
  int meter_length = 20;
  int meter_filled_length = (int)(cpu_usage * meter_length);
  for (int i = 0; i < meter_filled_length; i++) {
    printf("#");
  }
  for (int i = meter_filled_length; i < meter_length; i++) {
    printf("-");
  }
  printf("\n");
}

int main(void) {
  // Loop forever.
  while (1) {
    // Get the current time.
    time_t now = time(NULL);

    // Clear the screen.
    printf("\033[2J");

    // Draw the CPU usage meter.
    cpu_meter();

    // Sleep for one second.
    sleep(1);
  }

  return 0;
}