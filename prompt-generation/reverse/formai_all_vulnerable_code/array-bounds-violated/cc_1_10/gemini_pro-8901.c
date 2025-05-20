//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysinfo.h>
#include <time.h>

int main() {
  // Let's get some juicy system information!
  struct sysinfo info;
  if (sysinfo(&info) == -1) {
    perror("sysinfo");
    return EXIT_FAILURE;
  }

  // Show off our system's stats like a boss!
  printf("Behold, the stats of your mighty system:\n\n");

  // Total RAM: the playground for your programs
  printf("Total RAM: %.2f GB\n", (float)info.totalram / 1024 / 1024 / 1024);

  // Free RAM: the breathing space for your system
  printf("Free RAM: %.2f GB\n", (float)info.freeram / 1024 / 1024 / 1024);

  // Number of processes: a bustling city of tasks
  printf("Number of processes: %d\n", info.procs);

  // Uptime: how long your system's been rockin'
  time_t uptime = info.uptime;
  printf("Uptime: %d days, %d hours, %d minutes, %d seconds\n\n",
         uptime / 86400, (uptime % 86400) / 3600, (uptime % 3600) / 60, uptime % 60);

  // Let's peek into the bustling world of processes!
  FILE *proc = fopen("/proc/stat", "r");
  if (proc == NULL) {
    perror("fopen");
    return EXIT_FAILURE;
  }

  // Prepare to witness the process parade!
  char line[256];
  int pid, ppid, state;
  long unsigned int utime, stime;
  printf("----------------------------------------------------------------------------------\n");
  printf("| PID | PPID | STATE | USER TIME | SYSTEM TIME | COMMAND                 |\n");
  printf("----------------------------------------------------------------------------------\n");

  // Grab each process one by one
  while (fgets(line, sizeof(line), proc)) {
    // Let's dissect the process info!
    if (sscanf(line, "%d %*s %c %*d %*d %*d %*d %*d %*u %*u %u %u %*u %*u"
                 "%*u %*u %*u %*u %*u %*u %*u",
               &pid, &state, &utime, &stime) == 4) {
      // Convert state to something we can understand
      switch (state) {
        case 'R':
          state = 'Running';
          break;
        case 'S':
          state = 'Sleeping';
          break;
        case 'D':
          state = 'Uninterruptible Sleep';
          break;
        case 'Z':
          state = 'Zombie';
          break;
        default:
          state = 'Unknown';
          break;
      }

      // Find out which program is behind the process
      char cmd[256];
      sprintf(cmd, "/proc/%d/comm", pid);
      FILE *cmdline = fopen(cmd, "r");
      if (cmdline) {
        fgets(cmd, sizeof(cmd), cmdline);
        fclose(cmdline);
        // Trim trailing newline
        cmd[strlen(cmd) - 1] = '\0';
      }

      // Display the process info in a neat format
      printf("| %5d | %5d | %7s | %10lu | %11lu | %22s |\n",
             pid, ppid, state, utime, stime, cmd);
    }
  }
  printf("----------------------------------------------------------------------------------\n");

  // Finished observing the process parade!
  fclose(proc);

  return EXIT_SUCCESS;
}