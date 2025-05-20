//FormAI DATASET v1.0 Category: System process viewer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int main(int argc, char *argv[]) {
  DIR           *d;
  struct dirent *dir;
  char          path[1024];
  FILE          *fp;
  char          line[256];
  char          name[256], state[256];
  int           pid, ppid, pgrp, session, tty_nr, tpgid, exit_signal, processor;
  unsigned long int flags, minflt, cminflt, majflt, cmajflt, utime, stime, cutime, cstime, priority, nice, num_threads, starttime;

  printf("%-10s %-15s %-5s\n", "PID", "NAME", "STATE");

  d = opendir("/proc");
  if (d) {
    while ((dir = readdir(d)) != NULL) {
      // get process ID
      int is_pid = 1;
      for (int i = 0; i < strlen(dir->d_name); i++) {
        if (dir->d_name[i] < '0' || dir->d_name[i] > '9') {
          is_pid = 0;
          break;
        }
      }
      if (!is_pid) continue;
      pid = atoi(dir->d_name);

      // open process status file
      sprintf(path, "/proc/%d/status", pid);
      fp = fopen(path, "r");
      if (!fp) {
        printf("Cannot open %s\n", path);
        continue;
      }

      // parse process status file
      while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, "Name:")) {
          sscanf(line, "%*s %s", name);
        }
        else if (strstr(line, "State:")) {
          sscanf(line, "%*s %s", state);
        }
      }
      fclose(fp);

      printf("%-10d %-15s %-5s\n", pid, name, state);
    }
    closedir(d);
  }

  return 0;
}