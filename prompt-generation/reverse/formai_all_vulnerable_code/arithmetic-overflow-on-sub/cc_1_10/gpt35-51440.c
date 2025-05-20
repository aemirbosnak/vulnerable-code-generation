//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFFER_SIZE 256
#define INTERVAL 1

char *read_pid_cmd = "cat /proc/stat | awk '{print $2}'";
char *stat_filename = "/proc/stat";
int done = 0;

void usage_monitor(void *arg) {
  int pid = *(int*) arg;
  char pid_cmd[BUFFER_SIZE];
  char cpu_info[BUFFER_SIZE];
  char *line;
  char *token;
  char *delim = "\n";
  FILE *stat_file;
  
  sprintf(pid_cmd, "ps -o pid,%%cpu -p %d | tail -n 1 | awk '{print $NF}'", pid);
  while (!done) {
    stat_file = fopen(stat_filename, "r");
    if (!stat_file) {
      printf("Error: Cannot open %s.\n", stat_filename);
      exit(EXIT_FAILURE);
    }
    fgets(cpu_info, BUFFER_SIZE, stat_file);
    line = strtok(cpu_info, delim);
    while (line) {
      if (strstr(line, "cpu") == line) {
	token = strtok(line, " ");
        token = strtok(NULL, " ");
        token = strtok(NULL, " ");
        printf("CPU usage of process %d: %s\n", pid, token);
        break;
      }
      line = strtok(NULL, delim);
    }
    fclose(stat_file);
    system(pid_cmd);
    sleep(INTERVAL);
  }
}

int main(int argc, char *argv[]) {
  pthread_t tid;
  int pid;
  char pid_buf[BUFFER_SIZE];
  int fd;
  char *endptr;

  if (argc != 2) {
    printf("Usage: %s <process ID>\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  pid = strtol(argv[1], &endptr, 10);
  if (*endptr != '\0') {
    printf("Error: Invalid process ID.\n");
    exit(EXIT_FAILURE);
  }

  fd = open(stat_filename, O_RDONLY);
  if (fd < 0) {
    printf("Error: Cannot open %s.\n", stat_filename);
    exit(EXIT_FAILURE);
  }
  read(fd, pid_buf, BUFFER_SIZE);
  close(fd);
  if (strstr(pid_buf, argv[1])) {
    printf("Process %d found in /proc/stat.\n", pid);
  } else {
    printf("Error: Process %d not found in /proc/stat.\n", pid);
    exit(EXIT_FAILURE);
  }

  pthread_create(&tid, NULL, &usage_monitor, &pid);
  printf("CPU usage monitoring for process %d.\n", pid);
  getchar();
  done = 1;
  pthread_join(tid, NULL);
  printf("CPU usage monitoring stopped.\n");
  return EXIT_SUCCESS;
}