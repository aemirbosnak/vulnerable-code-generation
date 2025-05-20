//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
  // Open the /proc/stat file
  int fd = open("/proc/stat", O_RDONLY);
  if (fd == -1) {
    perror("open");
    return EXIT_FAILURE;
  }

  // Read the first line of the file
  char buf[1024];
  if (read(fd, buf, sizeof(buf) - 1) == -1) {
    perror("read");
    return EXIT_FAILURE;
  }

  // Close the file
  close(fd);

  // Parse the first line of the file
  char *ptr = buf;
  char *endptr;
  unsigned long long user, nice, system, idle, iowait, irq, softirq, steal, guest, guest_nice;
  user = strtoull(ptr, &endptr, 10);
  ptr = endptr;
  nice = strtoull(ptr, &endptr, 10);
  ptr = endptr;
  system = strtoull(ptr, &endptr, 10);
  ptr = endptr;
  idle = strtoull(ptr, &endptr, 10);
  ptr = endptr;
  iowait = strtoull(ptr, &endptr, 10);
  ptr = endptr;
  irq = strtoull(ptr, &endptr, 10);
  ptr = endptr;
  softirq = strtoull(ptr, &endptr, 10);
  ptr = endptr;
  steal = strtoull(ptr, &endptr, 10);
  ptr = endptr;
  guest = strtoull(ptr, &endptr, 10);
  ptr = endptr;
  guest_nice = strtoull(ptr, &endptr, 10);

  // Calculate the total CPU time
  unsigned long long total = user + nice + system + idle + iowait + irq + softirq + steal + guest + guest_nice;

  // Calculate the CPU usage
  double usage = (double)(user + nice + system + irq + softirq + steal) / total * 100.0;

  // Print the CPU usage
  printf("CPU usage: %.2f%%\n", usage);

  return EXIT_SUCCESS;
}