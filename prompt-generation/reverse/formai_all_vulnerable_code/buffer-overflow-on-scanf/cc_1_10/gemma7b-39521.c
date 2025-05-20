//Gemma-7B DATASET v1.0 Category: System process viewer ; Style: Cyberpunk
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROC_NUM 1024

typedef struct Process {
  char name[256];
  int pid;
  struct Process* next;
} Process;

Process* process_head = NULL;

void display_processes() {
  Process* current = process_head;
  printf("Current Processes:\n");
  while (current) {
    printf("  - %s (PID: %d)\n", current->name, current->pid);
    current = current->next;
  }
}

int main() {
  system("clear");
  system("echo '---------------------------------------------------' > processes.txt");
  system("echo '           /dev/null > processes.txt' >> processes.txt");
  system("echo '---------------------------------------------------' >> processes.txt");
  display_processes();

  int num_processes = 0;
  char proc_name[256];

  printf("Enter process name: ");
  scanf("%s", proc_name);

  Process* new_process = malloc(sizeof(Process));
  strcpy(new_process->name, proc_name);
  new_process->pid = fork();

  if (new_process->pid == 0) {
    system("bash");
  } else {
    process_head = new_process;
    num_processes++;
  }

  display_processes();

  wait(NULL);

  return 0;
}