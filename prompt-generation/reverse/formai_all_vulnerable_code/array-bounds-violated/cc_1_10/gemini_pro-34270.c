//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <glob.h>

#define MAX_LINE 1024
#define MAX_ARGS 64

typedef struct job_struct {
  pid_t pid;
  char *cmd;
  struct job_struct *next;
} job;

job *jobs = NULL;

void add_job(pid_t pid, char *cmd) {
  job *new_job = malloc(sizeof(job));
  new_job->pid = pid;
  new_job->cmd = strdup(cmd);
  new_job->next = jobs;
  jobs = new_job;
}

void remove_job(pid_t pid) {
  job *prev = NULL;
  job *curr = jobs;

  while (curr && curr->pid != pid) {
    prev = curr;
    curr = curr->next;
  }

  if (curr) {
    if (prev) {
      prev->next = curr->next;
    } else {
      jobs = curr->next;
    }
    free(curr->cmd);
    free(curr);
  }
}

void print_jobs() {
  job *curr = jobs;

  while (curr) {
    printf("[%d] %s\n", curr->pid, curr->cmd);
    curr = curr->next;
  }
}

void handle_sigchld(int signo) {
  pid_t pid;
  int status;

  while ((pid = waitpid(-1, &status, WNOHANG)) > 0) {
    remove_job(pid);
  }
}

void execute_cmd(char *cmd) {
  char *argv[MAX_ARGS];
  int argc = 0;
  char *token;

  token = strtok(cmd, " ");
  while (token && argc < MAX_ARGS) {
    argv[argc++] = token;
    token = strtok(NULL, " ");
  }
  argv[argc] = NULL;

  if (argc == 0) {
    return;
  }

  if (!strcmp(argv[0], "jobs")) {
    print_jobs();
    return;
  }

  pid_t pid = fork();
  if (pid == 0) {
    execvp(argv[0], argv);
    fprintf(stderr, "execvp failed: %s\n", strerror(errno));
    exit(1);
  } else {
    add_job(pid, cmd);
  }
}

int main() {
  char line[MAX_LINE];
  int running = 1;

  signal(SIGCHLD, handle_sigchld);

  while (running) {
    printf("sh> ");
    fflush(stdout);

    if (fgets(line, MAX_LINE, stdin) == NULL) {
      break;
    }

    if (line[strlen(line) - 1] == '\n') {
      line[strlen(line) - 1] = '\0';
    }

    execute_cmd(line);
  }

  return 0;
}