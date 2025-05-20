//Code Llama-13B DATASET v1.0 Category: System process viewer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>

#define MAX_PROCESSES 10
#define MAX_COMMAND_LENGTH 256

typedef struct Process {
  int pid;
  char command[MAX_COMMAND_LENGTH];
  int status;
} Process;

void print_process_table(Process *processes, int num_processes) {
  printf("PID\tCommand\tStatus\n");
  for (int i = 0; i < num_processes; i++) {
    printf("%d\t%s\t%d\n", processes[i].pid, processes[i].command, processes[i].status);
  }
}

int main(int argc, char **argv) {
  Process processes[MAX_PROCESSES];
  int num_processes = 0;
  char command[MAX_COMMAND_LENGTH];
  char *token;

  while (1) {
    printf("Enter a command: ");
    fgets(command, MAX_COMMAND_LENGTH, stdin);
    token = strtok(command, " ");
    if (strcmp(token, "quit") == 0) {
      break;
    } else if (strcmp(token, "ps") == 0) {
      print_process_table(processes, num_processes);
    } else {
      int pid = fork();
      if (pid == 0) {
        execl("/bin/sh", "/bin/sh", "-c", command, NULL);
        exit(1);
      } else {
        Process p;
        p.pid = pid;
        strcpy(p.command, token);
        p.status = 0;
        processes[num_processes++] = p;
      }
    }
  }

  return 0;
}