//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>

int main() {
  char c;
  DIR *dir;
  struct dirent *ent;
  int fd;
  char *filename = "/proc/";
  char *process_info;
  size_t process_info_size = 1024;
  char *process_name;
  char *process_state;
  int pid = 0;
  char *process_cwd;
  char *process_exe;
  char *process_cmdline;
  int i, j, k;

  printf("Welcome to the Ultimate System Process Viewer!\n");
  printf("===============================================\n\n");
  printf("Get ready to dive into the depths of your system's processes and discover their secrets!\n\n");

  if ((dir = opendir(filename)) == NULL) {
    perror("Error opening /proc directory");
    exit(1);
  }

  while ((ent = readdir(dir)) != NULL) {
    if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
      continue;
    }

    pid = atoi(ent->d_name);
    if (pid == 0) {
      continue;
    }

    filename[strlen(filename)] = '/';
    filename[strlen(filename) + 1] = '\0';
    strcat(filename, ent->d_name);
    process_info = malloc(process_info_size);

    if ((fd = open(filename, O_RDONLY)) == -1) {
      perror("Error opening /proc/[pid]/stat file");
      exit(1);
    }

    if (read(fd, process_info, process_info_size) == -1) {
      perror("Error reading /proc/[pid]/stat file");
      exit(1);
    }

    close(fd);
    process_name = strtok(process_info, " ");
    process_state = strtok(NULL, " ");
    process_cmdline = strtok(NULL, "\n");
    process_cmdline = process_cmdline + 2;

    printf("Process Information for PID: %d\n", pid);
    printf("------------------------------------------\n");
    printf("Name: %s\n", process_name);
    printf("State: %s\n", process_state);
    printf("Command Line: %s\n", process_cmdline);

    filename[strlen(filename) - strlen(ent->d_name)] = '\0';
    strcat(filename, "cwd");

    if ((fd = open(filename, O_RDONLY)) == -1) {
      perror("Error opening /proc/[pid]/cwd file");
      exit(1);
    }

    process_cwd = malloc(1024);

    if (read(fd, process_cwd, 1024) == -1) {
      perror("Error reading /proc/[pid]/cwd file");
      exit(1);
    }

    close(fd);
    printf("Current Working Directory: %s\n", process_cwd);

    filename[strlen(filename) - 3] = '\0';
    strcat(filename, "exe");

    if ((fd = open(filename, O_RDONLY)) == -1) {
      perror("Error opening /proc/[pid]/exe file");
      exit(1);
    }

    process_exe = malloc(1024);

    if (read(fd, process_exe, 1024) == -1) {
      perror("Error reading /proc/[pid]/exe file");
      exit(1);
    }

    close(fd);
    printf("Executable Path: %s\n\n", process_exe);

    free(process_info);
    free(process_cwd);
    free(process_exe);
  }

  closedir(dir);
  return 0;
}