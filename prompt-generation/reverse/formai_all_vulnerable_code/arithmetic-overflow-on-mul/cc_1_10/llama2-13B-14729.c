//LLAMA2-13B DATASET v1.0 Category: RAM usage monitor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <unistd.h>

#define RAM_USAGE_THRESHOLD 80

int main() {
  // Get current RAM usage
  struct sysinfo si;
  sysinfo(&si);
  int current_ram_usage = (int) (si.totalram / 1024) * 100;

  // Print current RAM usage
  printf("Current RAM usage: %d%%\n", current_ram_usage);

  // Check if RAM usage is above threshold
  if (current_ram_usage > RAM_USAGE_THRESHOLD) {
    // Print warning message
    printf(" Warning! RAM usage is above threshold (%d%%).\n", RAM_USAGE_THRESHOLD);
  }

  // Wait for 1 second and check RAM usage again
  sleep(1);
  sysinfo(&si);
  current_ram_usage = (int) (si.totalram / 1024) * 100;

  // Print new RAM usage
  printf("New RAM usage: %d%%\n", current_ram_usage);

  // Check if RAM usage is still above threshold
  if (current_ram_usage > RAM_USAGE_THRESHOLD) {
    // Print warning message again
    printf(" Warning! RAM usage is still above threshold (%d%%).\n", RAM_USAGE_THRESHOLD);
  }

  // Repeat until user presses Ctrl+C
  while (1) {
    sleep(1);
    sysinfo(&si);
    current_ram_usage = (int) (si.totalram / 1024) * 100;

    // Print new RAM usage
    printf("New RAM usage: %d%%\n", current_ram_usage);

    // Check if RAM usage is above threshold
    if (current_ram_usage > RAM_USAGE_THRESHOLD) {
      // Print warning message
      printf(" Warning! RAM usage is above threshold (%d%%).\n", RAM_USAGE_THRESHOLD);
    }
  }

  return 0;
}