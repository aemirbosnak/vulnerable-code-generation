//Code Llama-13B DATASET v1.0 Category: System administration ; Style: calm
// System administration example program in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <sys/stat.h>

int main(void) {
  // Get system information
  struct utsname uts;
  uname(&uts);

  // Print system information
  printf("System: %s %s %s %s\n", uts.sysname, uts.nodename, uts.release, uts.version);
  printf("Hostname: %s\n", uts.nodename);
  printf("Architecture: %s\n", uts.machine);
  printf("Operating System: %s\n", uts.sysname);
  printf("Release: %s\n", uts.release);
  printf("Version: %s\n", uts.version);

  // Get system uptime
  struct sysinfo info;
  sysinfo(&info);

  // Print system uptime
  printf("Uptime: %ld days, %ld hours, %ld minutes, %ld seconds\n",
         info.uptime / (60 * 60 * 24),
         (info.uptime / (60 * 60)) % 24,
         (info.uptime / 60) % 60,
         info.uptime % 60);

  // Get system load
  long cpu_load[3];
  getloadavg(cpu_load, 3);

  // Print system load
  printf("Load average: %.2f, %.2f, %.2f\n", cpu_load[0], cpu_load[1], cpu_load[2]);

  // Get memory information
  long mem_total, mem_free, mem_available;
  mem_total = sysconf(_SC_PHYS_PAGES) * sysconf(_SC_PAGESIZE);
  mem_free = sysconf(_SC_AVPHYS_PAGES) * sysconf(_SC_PAGESIZE);
  mem_available = sysconf(_SC_AVPHYS_PAGES) * sysconf(_SC_PAGESIZE);

  // Print memory information
  printf("Memory: %.2f MB total, %.2f MB free, %.2f MB available\n",
         mem_total / 1024.0 / 1024.0,
         mem_free / 1024.0 / 1024.0,
         mem_available / 1024.0 / 1024.0);

  return 0;
}