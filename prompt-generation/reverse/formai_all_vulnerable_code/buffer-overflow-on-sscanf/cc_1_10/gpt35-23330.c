//FormAI DATASET v1.0 Category: System administration ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

// Function to print system statistics
void printSystemStats() {
  // Get system uptime
  FILE* uptimeFile = fopen("/proc/uptime", "r");
  if (!uptimeFile) {
    perror("Error opening /proc/uptime");
    exit(1);
  }
  
  double uptimeSec;
  fscanf(uptimeFile, "%lf", &uptimeSec);
  fclose(uptimeFile);
  
  int uptimeDays = (int)uptimeSec / 86400;
  int uptimeHours = (int)uptimeSec / 3600 % 24;
  int uptimeMins = (int)uptimeSec / 60 % 60;
  int uptimeSecs = (int)uptimeSec % 60;
  printf("System Uptime: %d days, %d:%02d:%02d\n", uptimeDays, uptimeHours, uptimeMins, uptimeSecs);
  
  // Get system load average, 1-minute, 5-minutes, 15-minutes
  double loadavg[3];
  if (getloadavg(loadavg, 3) != -1) {
    printf("System Load Average: %.2f, %.2f, %.2f\n", loadavg[0], loadavg[1], loadavg[2]);
  } else {
    perror("Error getting system load average");
  }
  
  // Get system memory usage
  FILE* meminfoFile = fopen("/proc/meminfo", "r");
  if (!meminfoFile) {
    perror("Error opening /proc/meminfo");
    exit(1);
  }
  
  int memTotal, memFree, memAvailable;
  char line[256];
  while (fgets(line, sizeof(line), meminfoFile)) {
    if (sscanf(line, "MemTotal: %d kB", &memTotal) == 1) {
      printf("System Memory: %d kB total\n", memTotal);
    }
    if (sscanf(line, "MemFree: %d kB", &memFree) == 1) {
      printf("  %d kB free\n", memFree);
    }
    if (sscanf(line, "MemAvailable: %d kB", &memAvailable) == 1) {
      printf("  %d kB available\n", memAvailable);
    }
  }
  fclose(meminfoFile);
}

// Function to execute command with arguments using execvp()
void executeCommand(char* command, char** args) {
  printf("Executing command: %s\n", command);
  pid_t childPid = fork();
  if (childPid < 0) {
    perror("Error forking child process");
    exit(1);
  } else if (childPid == 0) {
    // Child process
    execvp(command, args);
    perror("Error executing command");
    exit(1);
  } else {
    // Parent process
    int childStatus;
    waitpid(childPid, &childStatus, 0);
    if (WIFEXITED(childStatus)) {
      printf("Command exited with status %d\n", WEXITSTATUS(childStatus));
    } else {
      printf("Command did not exit normally\n");
    }
  }
}

int main() {
  printf("System Statistics:\n");
  printSystemStats();
  
  printf("\nExecuting commands:\n");
  char* lsArgs[] = {"ls", "-la", NULL};
  executeCommand("/bin/ls", lsArgs);
  
  char* dfArgs[] = {"df", "-h", NULL};
  executeCommand("/bin/df", dfArgs);
  
  char* psArgs[] = {"ps", "aux", NULL};
  executeCommand("/bin/ps", psArgs);
  
  printf("Done.\n");
  return 0;
}