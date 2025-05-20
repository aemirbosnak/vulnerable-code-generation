//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <limits.h>
#include <signal.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/resource.h>
#include <fcntl.h>
#include <dirent.h>

#define MAX_PROCESSES 1024
#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
  int i, j, status;
  struct dirent *dirent;
  DIR *dir;
  char path[PATH_MAX];
  char line[MAX_LINE_LENGTH];
  char *fields[10];
  pid_t pids[MAX_PROCESSES];
  unsigned long rss;
  unsigned long long utime, stime, cutime, cstime;
  int vmsize, ppid;
  char state;
  float cpu_usage;

  // Get the list of processes
  dir = opendir("/proc");
  if (dir == NULL) {
    perror("opendir");
    return EXIT_FAILURE;
  }
  i = 0;
  while ((dirent = readdir(dir)) != NULL) {
    if (strcmp(dirent->d_name, ".") == 0 || strcmp(dirent->d_name, "..") == 0) {
      continue;
    }
    pids[i] = strtol(dirent->d_name, NULL, 10);
    i++;
  }
  closedir(dir);

  // Print the header
  printf("%-10s %-10s %-10s %-10s %-10s %-10s %-10s %-10s %-10s\n", "PID", "USER", "PPID", "STATE", "RSS", "VM SIZE", "%CPU", "%MEM", "COMMAND");

  // Get the information for each process
  for (i = 0; i < MAX_PROCESSES && pids[i] != 0; i++) {
    // Get the process status
    snprintf(path, PATH_MAX, "/proc/%d/status", pids[i]);
    FILE *fp = fopen(path, "r");
    if (fp == NULL) {
      perror("fopen");
      continue;
    }
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
      if (strncmp(line, "Name:", 5) == 0) {
        char *command = line + 6;
        while (*command == ' ') {
          command++;
        }
        fields[9] = command;
      } else if (strncmp(line, "State:", 6) == 0) {
        state = line[9];
      } else if (strncmp(line, "Uid:", 4) == 0) {
        fields[7] = line + 5;
      } else if (strncmp(line, "VmSize:", 7) == 0) {
        vmsize = strtol(line + 8, NULL, 10);
      } else if (strncmp(line, "VmRSS:", 6) == 0) {
        rss = strtol(line + 7, NULL, 10);
      } else if (strncmp(line, "Utime:", 6) == 0) {
        utime = strtoull(line + 7, NULL, 10);
      } else if (strncmp(line, "Stime:", 6) == 0) {
        stime = strtoull(line + 7, NULL, 10);
      } else if (strncmp(line, "Cutime:", 7) == 0) {
        cutime = strtoull(line + 8, NULL, 10);
      } else if (strncmp(line, "Cstime:", 7) == 0) {
        cstime = strtoull(line + 8, NULL, 10);
      } else if (strncmp(line, "Ppid:", 5) == 0) {
        ppid = strtol(line + 6, NULL, 10);
      }
    }
    fclose(fp);

    // Calculate the CPU usage
    cpu_usage = (float)(utime + stime + cutime + cstime) / sysconf(_SC_CLK_TCK) / (float)(sysconf(_SC_CLK_TCK) * 100);

    // Print the process information
    printf("%-10d %-10s %-10d %-10c %-10ld %-10d %-10.2f %-10.2f %s", pids[i], fields[7], ppid, state, rss, vmsize, cpu_usage, (float)rss / sysconf(_SC_PHYS_PAGES) * 100, fields[9]);
  }

  return EXIT_SUCCESS;
}