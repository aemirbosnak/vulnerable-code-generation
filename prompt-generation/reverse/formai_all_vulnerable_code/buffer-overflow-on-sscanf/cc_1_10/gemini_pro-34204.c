//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

int main() {
  // Let's delve into the mysterious world of system processes!
  printf("Prepare to witness the symphony of processes within your system!\n\n");

  // First, we'll summon the grand overseer of the process realm: the kernel.
  struct sysinfo systemInfo;
  if (sysinfo(&systemInfo) != 0) {
    fprintf(stderr, "Oops, we stumbled upon a snag! Kernel's not cooperating.\n");
    return 1;
  }

  // Now, let's grasp the total number of processes and threads.
  printf("Behold! The total number of processes: %lu\n", systemInfo.procs);
  printf("And the threads that dance alongside them: %lu\n\n", systemInfo.totalram);

  // Curiosity compels us to explore the load average!
  double loadAvg[3];
  if (getloadavg(loadAvg, 3) != -1) {
    printf("Unveiling the average load over the past 1, 5, and 15 minutes:\n");
    for (int i = 0; i < 3; i++) {
      printf("  %-5s: %.2f\n", (i == 0) ? "1 min" : (i == 1) ? "5 min" : "15 min", loadAvg[i]);
    }
    printf("\n");
  } else {
    fprintf(stderr, "Hmm, something's amiss! We couldn't retrieve the load average.\n");
  }

  // Now, let's peer into the memory kingdom!
  printf("The grand total of physical memory: %lu kB\n", systemInfo.totalram);
  printf("The memory that remains unclaimed: %lu kB\n", systemInfo.freeram);
  printf("And the memory used by buffers: %lu kB\n\n", systemInfo.bufferram);

  // Curiosity sizzles! Let's uncover the intricacies of the file system!
  printf("The enigma of mounted file systems revealed:\n");

  FILE *mountsFile = fopen("/proc/mounts", "r");
  if (mountsFile == NULL) {
    fprintf(stderr, "Alas! We failed to access the holy grail of mounts.\n");
    return 2;
  }

  char buffer[1024];
  while (fgets(buffer, sizeof(buffer), mountsFile) != NULL) {
    // Let's dissect each line and decipher its secrets!
    char device[256], mountPoint[256], fileSystem[256], options[256];
    sscanf(buffer, "%s %s %s %s", device, mountPoint, fileSystem, options);

    // Now, let's showcase these juicy details!
    printf("Mounted Device: %s\n", device);
    printf("Mount Point: %s\n", mountPoint);
    printf("File System: %s\n", fileSystem);
    printf("Options: %s\n\n", options);
  }

  fclose(mountsFile);

  return 0;
}