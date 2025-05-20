//Gemma-7B DATASET v1.0 Category: CPU usage monitor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_PROC 10

int main() {
  int pid_list[MAX_PROC] = {0};
  int cpu_usage[MAX_PROC] = {0};
  char buff[1024];

  // Spawn MAX_PROC processes
  for (int i = 0; i < MAX_PROC; i++) {
    pid_list[i] = fork();
    if (pid_list[i] == 0) {
      execl("/bin/bash", "bash", "-c", "sleep 10", NULL);
    }
  }

  // Calculate CPU usage for each process
  for (int i = 0; i < MAX_PROC; i++) {
    cpu_usage[i] = get_cpu_usage(pid_list[i]);
  }

  // Display CPU usage
  for (int i = 0; i < MAX_PROC; i++) {
    sprintf(buff, "Process ID: %d, CPU Usage: %.2f%%", pid_list[i], cpu_usage[i]);
    printf("%s\n", buff);
  }

  // Wait for processes to complete
  for (int i = 0; i < MAX_PROC; i++) {
    wait(NULL);
  }

  return 0;
}

int get_cpu_usage(int pid) {
  FILE *fp;
  char buff[1024];
  int total_user, total_system, total_idle;

  fp = fopen("/proc/stat", "r");
  fscanf(fp, "%*s %*s %*s %d %d %d", buff, buff, buff, &total_user, &total_system, &total_idle);
  fclose(fp);

  return 100 * (total_user + total_system) / (total_user + total_system + total_idle);
}