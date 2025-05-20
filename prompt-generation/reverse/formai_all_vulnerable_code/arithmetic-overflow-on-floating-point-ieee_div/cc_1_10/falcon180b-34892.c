//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/statvfs.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

struct rusage usage;

/* Function to get the total amount of RAM in bytes */
long long int getTotalRAM() {
  struct statvfs buf;
  if (statvfs("/", &buf) == 0) {
    return (long long int) buf.f_blocks * buf.f_frsize;
  }
  return -1;
}

/* Function to get the available amount of RAM in bytes */
long long int getFreeRAM() {
  struct statvfs buf;
  if (statvfs("/", &buf) == 0) {
    return (long long int) buf.f_bavail * buf.f_frsize;
  }
  return -1;
}

/* Function to get the used amount of RAM in bytes */
long long int getUsedRAM() {
  struct statvfs buf;
  if (statvfs("/", &buf) == 0) {
    return (long long int) (buf.f_blocks - buf.f_bavail) * buf.f_frsize;
  }
  return -1;
}

/* Function to get the percentage of RAM usage */
float getRAMUsage() {
  long long int totalRAM = getTotalRAM();
  long long int freeRAM = getFreeRAM();
  long long int usedRAM = getUsedRAM();

  if (totalRAM == -1 || freeRAM == -1 || usedRAM == -1) {
    return -1;
  }

  float usagePercentage = ((float) usedRAM / (float) totalRAM) * 100.0;
  return usagePercentage;
}

/* Function to print the RAM usage information */
void printRAMUsage() {
  float usagePercentage = getRAMUsage();

  if (usagePercentage == -1) {
    printf("Error: Unable to retrieve RAM usage information.\n");
    return;
  }

  printf("Total RAM: %lld bytes\n", getTotalRAM());
  printf("Free RAM: %lld bytes\n", getFreeRAM());
  printf("Used RAM: %lld bytes\n", getUsedRAM());
  printf("RAM usage: %.2f%%\n", usagePercentage);
}

int main() {
  while (1) {
    printRAMUsage();
    sleep(5);
  }
  return 0;
}