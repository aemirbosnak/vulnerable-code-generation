//FormAI DATASET v1.0 Category: System process viewer ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main() {
  DIR *dir = opendir("/proc");
  struct dirent *entry;

  if (dir == NULL) {
    printf("Unable to open directory /proc\n");
    exit(EXIT_FAILURE);
  }

  printf("PID\tSTATUS\t\tCOMMAND\n");

  while ((entry = readdir(dir)) != NULL) {
    if (entry->d_type != DT_DIR) {
      continue;
    }

    char path[256];
    char status_path[256];

    snprintf(path, sizeof(path), "/proc/%s/comm", entry->d_name);
    snprintf(status_path, sizeof(status_path), "/proc/%s/status", entry->d_name);

    FILE *fp = fopen(path, "r");
    FILE *fp_status = fopen(status_path, "r");

    if (fp == NULL || fp_status == NULL) {
      continue;
    }

    char command[256];
    char status[256];

    if (fgets(command, sizeof(command), fp) == NULL || fgets(status, sizeof(status), fp_status) == NULL) {
      fclose(fp);
      fclose(fp_status);
      continue;
    }

    fclose(fp);
    fclose(fp_status);

    const char *delim = " \t\n";
    char *tok = strtok(status, delim);
    char *pid = NULL;

    while (tok != NULL) {
      if (pid != NULL) {
        if (strcmp(tok, "S") == 0) {
          printf("%s\tSURREAL\t\t%s", pid, command);
        } else {
          printf("%s\t%s\t\t%s", pid, tok, command);
        }
        break;
      }

      if (strcmp(tok, "Pid:") == 0) {
        pid = strtok(NULL, delim);
      }

      tok = strtok(NULL, delim);
    }
  }

  closedir(dir);

  return EXIT_SUCCESS;
}