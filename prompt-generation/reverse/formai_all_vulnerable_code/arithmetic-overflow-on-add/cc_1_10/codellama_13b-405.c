//Code Llama-13B DATASET v1.0 Category: Task Scheduler ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define TASK_SCHEDULER_FILE "task_scheduler.txt"

typedef struct {
  int pid;
  char* name;
  time_t start_time;
  time_t end_time;
} Task;

void create_task_scheduler_file() {
  int fd = open(TASK_SCHEDULER_FILE, O_CREAT | O_WRONLY, 0666);
  if (fd == -1) {
    perror("Failed to create task scheduler file");
    exit(1);
  }
  close(fd);
}

void add_task_to_scheduler(char* name, time_t start_time, time_t end_time) {
  int fd = open(TASK_SCHEDULER_FILE, O_RDWR, 0666);
  if (fd == -1) {
    perror("Failed to open task scheduler file");
    exit(1);
  }

  Task task;
  task.pid = getpid();
  task.name = name;
  task.start_time = start_time;
  task.end_time = end_time;

  if (write(fd, &task, sizeof(Task)) == -1) {
    perror("Failed to write task to scheduler file");
    exit(1);
  }

  close(fd);
}

void run_task(Task task) {
  printf("Running task %s\n", task.name);
  sleep(task.end_time - task.start_time);
  printf("Task %s finished\n", task.name);
}

void run_task_scheduler() {
  create_task_scheduler_file();

  Task task1;
  task1.name = "Task 1";
  task1.start_time = time(NULL);
  task1.end_time = task1.start_time + 5;
  add_task_to_scheduler(task1.name, task1.start_time, task1.end_time);

  Task task2;
  task2.name = "Task 2";
  task2.start_time = task1.end_time;
  task2.end_time = task2.start_time + 10;
  add_task_to_scheduler(task2.name, task2.start_time, task2.end_time);

  Task task3;
  task3.name = "Task 3";
  task3.start_time = task2.end_time;
  task3.end_time = task3.start_time + 15;
  add_task_to_scheduler(task3.name, task3.start_time, task3.end_time);

  while (1) {
    Task task;
    int fd = open(TASK_SCHEDULER_FILE, O_RDONLY, 0666);
    if (fd == -1) {
      perror("Failed to open task scheduler file");
      exit(1);
    }

    if (read(fd, &task, sizeof(Task)) == -1) {
      perror("Failed to read task from scheduler file");
      exit(1);
    }

    close(fd);

    if (task.pid == getpid()) {
      run_task(task);
    }

    sleep(1);
  }
}

int main() {
  run_task_scheduler();
  return 0;
}