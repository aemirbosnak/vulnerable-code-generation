//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: retro
#include <stdio.h>
#include <stdlib.h>

int main() {
  system("clear"); // Clear screen command for Linux
  printf("RETRO RAM USAGE MONITOR\n\n");

  FILE *fp = fopen("/proc/meminfo", "r"); // Open the memory info file
  if (fp == NULL) { // Ensure file opening success
    perror("Error opening file.\n");
    exit(EXIT_FAILURE);
  }

  char buffer[256];
  int mem_total, mem_free, mem_buff, mem_cache, mem_sreclaimable, mem_shmem, mem_available, mem_used;

  while (fgets(buffer, sizeof(buffer), fp)) { // Read each line of the file
    if (sscanf(buffer, "MemTotal: %d kB", &mem_total) == 1) { // Extract total memory value
      printf("Total memory:\t%d kB\n", mem_total);
    }
    else if (sscanf(buffer, "MemFree: %d kB", &mem_free) == 1) { // Extract free memory value
      printf("Free memory:\t%d kB\n", mem_free);
    }
    else if (sscanf(buffer, "Buffers: %d kB", &mem_buff) == 1) { // Extract buffer memory value
      printf("Buffer memory:\t%d kB\n", mem_buff);
    }
    else if (sscanf(buffer, "Cached: %d kB", &mem_cache) == 1) { // Extract cache memory value
      printf("Cache memory:\t%d kB\n", mem_cache);
    }
    else if (sscanf(buffer, "SReclaimable: %d kB", &mem_sreclaimable) == 1) { // Extract reclaimable memory value
      printf("Reclaimable memory:\t%d kB\n", mem_sreclaimable);
    }
    else if (sscanf(buffer, "Shmem: %d kB", &mem_shmem) == 1) { // Extract shared memory value
      printf("Shared memory:\t%d kB\n", mem_shmem);
    }
    else if (sscanf(buffer, "MemAvailable: %d kB", &mem_available) == 1) { // Extract available memory value
      printf("Available memory:\t%d kB\n", mem_available);
    }
  }

  fclose(fp); // Close file

  mem_used = mem_total - mem_free; // Calculate used memory
  printf("\nUsed memory:\t%d kB\n", mem_used);

  int bar_length = 20; // Length of the progress bar
  int used_bar = (float) mem_used / mem_total * bar_length; // Calculate used bar length
  printf("Current usage:\t[");
  for (int i = 0; i < bar_length; i++) {
    if (i < used_bar) {
      printf("=");
    } else {
      printf(" ");
    }
  }
  printf("] %.1f%%\n", (float) mem_used / mem_total * 100);

  printf("\nPress ENTER to exit.");
  getchar(); // Wait for user to press enter to exit
  return 0;
}