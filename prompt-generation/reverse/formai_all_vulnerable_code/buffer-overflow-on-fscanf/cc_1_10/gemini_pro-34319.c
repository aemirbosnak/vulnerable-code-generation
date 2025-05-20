//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/sysinfo.h>

int main(int argc, char **argv) {
  struct sysinfo sys;
  int i, found = 0;

  // Get system information
  sysinfo(&sys);

  // Print system information
  printf("System Information:\n");
  printf("  Processes: %d\n", sys.procs);
  printf("  Uptime: %ld seconds\n", sys.uptime);
  printf("  Load average: %f\n", sys.loads[0] / 65536.0);
  printf("  Total memory: %ld KB\n", sys.totalram);
  printf("  Free memory: %ld KB\n", sys.freeram);
  printf("  Shared memory: %ld KB\n", sys.sharedram);
  printf("  Buffer memory: %ld KB\n", sys.bufferram);
  printf("  Total swap: %ld KB\n", sys.totalswap);
  printf("  Free swap: %ld KB\n", sys.freeswap);

  // Print process information
  printf("\nProcess Information:\n");
  printf("  PID\t\tName\t\tState\t\tTime\t\tMemory\n");
  FILE *fp = fopen("/proc/", "r");
  if (fp != NULL) {
    while (!feof(fp)) {
      char line[256];
      fgets(line, sizeof(line), fp);
      if (line[0] >= '0' && line[0] <= '9') {
        pid_t pid = atoi(line);
        char path[256];
        sprintf(path, "/proc/%d/stat", pid);
        FILE *fp2 = fopen(path, "r");
        if (fp2 != NULL) {
          char name[256];
          fscanf(fp2, "%*d %s %*s %*s %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*u %*u %*d %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %*d %*d %*d %*d %*d %*d %*d", name);
          char state;
          fscanf(fp2, "%c", &state);
          unsigned long utime, stime;
          fscanf(fp2, "%*ld %*ld %*ld %*ld %lu %lu", &utime, &stime);
          unsigned long memory = 0;
          fscanf(fp2, "%*ld %*ld %*ld %*ld %*ld %*ld %*ld %*ld %*ld %*ld %*ld %*ld %*ld %*ld %*ld %*ld %*ld %*ld %lu", &memory);
          printf("  %d\t\t%s\t\t%c\t\t%ld.%02ld\t\t%ld KB\n", pid, name, state, utime / 100, utime % 100, memory / 1024);
          found++;
        }
        fclose(fp2);
      }
    }
    fclose(fp);
  }
  if (!found) {
    printf("  No processes found.\n");
  }

  return 0;
}