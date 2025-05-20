//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <sys/utsname.h>

int main() {
  struct sysinfo si;
  struct utsname os;
  int num_procs;
  int i;

  // Get system information
  if (sysinfo(&si) == -1) {
    perror("sysinfo");
    return EXIT_FAILURE;
  }

  // Get operating system information
  if (uname(&os) == -1) {
    perror("uname");
    return EXIT_FAILURE;
  }

  // Print system information
  printf("System Information\n");
  printf("---------------------\n");
  printf("Hostname: %s\n", os.nodename);
  printf("Operating System: %s %s\n", os.sysname, os.release);
  printf("Total RAM: %ld KB\n", si.totalram / 1024);
  printf("Free RAM: %ld KB\n", si.freeram / 1024);
  printf("Number of processes: %d\n", si.procs);

  // Print process information
  printf("\nProcess Information\n");
  printf("---------------------\n");
  printf("PID\tPPID\tState\tName\n");
  for (i = 0; i < si.procs; i++) {
    // Get process information
    FILE *fp;
    char buf[1024];
    sprintf(buf, "/proc/%d/status", i);
    fp = fopen(buf, "r");
    if (fp == NULL) {
      perror("fopen");
      continue;
    }

    // Read process status
    char state;
    int ppid;
    char name[1024];
    while (fgets(buf, sizeof(buf), fp) != NULL) {
      if (sscanf(buf, "Name:\t%s", name) == 1) {
        break;
      } else if (sscanf(buf, "State:\t%c", &state) == 1) {
        break;
      } else if (sscanf(buf, "PPid:\t%d", &ppid) == 1) {
        break;
      }
    }
    fclose(fp);

    // Print process information
    printf("%d\t%d\t%c\t%s\n", i, ppid, state, name);
  }

  return EXIT_SUCCESS;
}