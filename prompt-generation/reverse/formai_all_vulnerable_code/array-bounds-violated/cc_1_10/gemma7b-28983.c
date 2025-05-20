//Gemma-7B DATASET v1.0 Category: CPU usage monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_PROC_NAME_LEN 256

typedef struct ProcInfo {
  char name[MAX_PROC_NAME_LEN];
  int pid;
  long uptime;
} ProcInfo;

ProcInfo getProcInfo() {
  ProcInfo procInfo;
  procInfo.name[0] = '\0';
  procInfo.pid = 0;
  procInfo.uptime = 0L;

  FILE *fp = fopen("/proc/stat", "r");
  if (fp) {
    char line[256];
    fgets(line, 256, fp);
    fclose(fp);

    char *fields[] = {"pid", "state", "name", "cpu", "rss", "start", "end"};
    int i = 0;
    for (char **p = line; *p; p++) {
      if (strcmp(fields[i], "name") == 0) {
        strcpy(procInfo.name, p + 1);
      } else if (strcmp(fields[i], "pid") == 0) {
        procInfo.pid = atoi(p + 1);
      } else if (strcmp(fields[i], " uptime") == 0) {
        procInfo.uptime = atol(p + 1);
      }
      i++;
    }
  }

  return procInfo;
}

int main() {
  ProcInfo procInfo = getProcInfo();

  printf("Process name: %s\n", procInfo.name);
  printf("Process ID: %d\n", procInfo.pid);
  printf("Uptime: %ld seconds\n", procInfo.uptime);

  return 0;
}