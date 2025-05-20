//Gemma-7B DATASET v1.0 Category: RAM usage monitor ; Style: optimized
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>

#define MAX_RAM_SIZE 8192
#define BUFFER_SIZE 256

typedef struct RAMUsage {
  int used_space;
  int free_space;
  int total_space;
} RAMUsage;

RAMUsage ram_usage(void) {
  RAMUsage ram_usage_data;

  // Calculate used space
  ram_usage_data.used_space = get_used_ram();

  // Calculate free space
  ram_usage_data.free_space = MAX_RAM_SIZE - ram_usage_data.used_space;

  // Calculate total space
  ram_usage_data.total_space = MAX_RAM_SIZE;

  return ram_usage_data;
}

int get_used_ram(void) {
  FILE *fp;
  char buffer[BUFFER_SIZE];
  int used_space = 0;

  fp = fopen("/proc/meminfo", "r");
  if (fp) {
    fgets(buffer, BUFFER_SIZE, fp);
    fclose(fp);

    // Extract used RAM space
    used_space = atoi(buffer);
  }

  return used_space;
}

int main(void) {
  RAMUsage ram_usage_data = ram_usage();

  printf("Used space: %d KB\n", ram_usage_data.used_space);
  printf("Free space: %d KB\n", ram_usage_data.free_space);
  printf("Total space: %d KB\n", ram_usage_data.total_space);

  return 0;
}