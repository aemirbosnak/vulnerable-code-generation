//Code Llama-13B DATASET v1.0 Category: RAM usage monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>

int main(void) {
  struct rlimit rlim;
  int rc;
  long long used_ram;
  long long total_ram;

  rc = getrlimit(RLIMIT_DATA, &rlim);
  if (rc == -1) {
    perror("getrlimit");
    exit(EXIT_FAILURE);
  }

  total_ram = rlim.rlim_max;

  while (1) {
    used_ram = 0;

    // Iterate over all processes and calculate the total used RAM
    for (int i = 0; i < 1024; i++) {
      char path[128];
      snprintf(path, sizeof(path), "/proc/%d/statm", i);
      FILE *f = fopen(path, "r");
      if (f == NULL) {
        continue;
      }

      long long size;
      if (fscanf(f, "%lld", &size) != 1) {
        fclose(f);
        continue;
      }

      used_ram += size;
      fclose(f);
    }

    // Calculate the percentage of used RAM
    double percentage = (double)used_ram / total_ram * 100.0;

    // Print the usage information
    printf("RAM usage: %lld/%lld (%.2f%%)\n", used_ram, total_ram, percentage);

    // Sleep for 1 second before checking again
    sleep(1);
  }

  return 0;
}