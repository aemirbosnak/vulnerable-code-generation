//Code Llama-13B DATASET v1.0 Category: System process viewer ; Style: authentic
// System Process Viewer

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_PROCESSES 100

typedef struct {
  char name[20];
  int pid;
  int memory;
  int cpu;
} Process;

void print_processes(Process processes[], int num_processes) {
  printf("PID\tName\tMemory\tCPU\n");
  for (int i = 0; i < num_processes; i++) {
    printf("%d\t%s\t%d\t%d\n", processes[i].pid, processes[i].name, processes[i].memory, processes[i].cpu);
  }
}

int main() {
  Process processes[MAX_PROCESSES];
  int num_processes = 0;

  FILE *fp = popen("ps -eo pid,comm,vsz,pcpu", "r");
  if (fp == NULL) {
    printf("Failed to execute command\n");
    return 1;
  }

  char line[1024];
  while (fgets(line, sizeof(line), fp) != NULL) {
    if (num_processes >= MAX_PROCESSES) {
      break;
    }

    char *ptr = line;
    char *token;
    Process process;

    token = strtok(ptr, " ");
    process.pid = atoi(token);

    token = strtok(NULL, " ");
    strcpy(process.name, token);

    token = strtok(NULL, " ");
    process.memory = atoi(token);

    token = strtok(NULL, " ");
    process.cpu = atoi(token);

    processes[num_processes++] = process;
  }

  pclose(fp);

  print_processes(processes, num_processes);

  return 0;
}