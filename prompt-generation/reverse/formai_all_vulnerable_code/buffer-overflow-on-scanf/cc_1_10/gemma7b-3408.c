//Gemma-7B DATASET v1.0 Category: System process viewer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#define MAX_PROC_NAME_LEN 256

typedef struct Process {
  char name[MAX_PROC_NAME_LEN];
  int pid;
  struct Process* next;
} Process;

Process* createProcess(char* name, int pid) {
  Process* newProcess = (Process*)malloc(sizeof(Process));
  strcpy(newProcess->name, name);
  newProcess->pid = pid;
  newProcess->next = NULL;
  return newProcess;
}

void printProcesses(Process* processes) {
  while (processes) {
    printf("%s (PID: %d)\n", processes->name, processes->pid);
    processes = processes->next;
  }
}

int main() {
  Process* processes = NULL;
  char buffer[MAX_PROC_NAME_LEN];

  // Get the process name and pid from the user
  printf("Enter the process name: ");
  scanf("%s", buffer);

  // Get the process pid
  int pid = getpid();

  // Create a new process
  Process* newProcess = createProcess(buffer, pid);

  // Add the new process to the list
  if (processes) {
    newProcess->next = processes;
  } else {
    processes = newProcess;
  }

  // Print the processes
  printProcesses(processes);

  return 0;
}