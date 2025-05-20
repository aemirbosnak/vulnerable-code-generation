//FormAI DATASET v1.0 Category: System process viewer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COMMAND_LENGTH 2048

void print_process_info(char* pid) {
  char command[MAX_COMMAND_LENGTH];
  sprintf(command, "ps -p %s o pid,user,cpu,command", pid);

  FILE* fp = popen(command, "r");
  if (!fp) {
    printf("Failed to execute command: %s\n", command);
    return;
  }

  char line[MAX_LINE_LENGTH];
  while (fgets(line, sizeof(line), fp)) {
    printf("%s", line);
  }

  pclose(fp);
}

void view_processes() {
  char command[MAX_COMMAND_LENGTH] = "ps -A";
  FILE* fp = popen(command, "r");
  if (!fp) {
    printf("Failed to execute command: %s\n", command);
    return;
  }

  char line[MAX_LINE_LENGTH];
  char pid[10];
  fgets(line, MAX_LINE_LENGTH, fp); // skip first line (header)

  printf("%-10s %-20s %-10s %s", "PID", "USER", "CPU", "COMMAND");
  printf("---------------------------------------------------------------------\n");

  while (fgets(line, sizeof(line), fp)) {
    sscanf(line, "%s", pid);
    print_process_info(pid);
  }

  pclose(fp);
}

int main() {
  view_processes();
  return 0;
}