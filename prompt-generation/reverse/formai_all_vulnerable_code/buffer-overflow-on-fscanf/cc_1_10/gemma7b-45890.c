//Gemma-7B DATASET v1.0 Category: System process viewer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <pwd.h>

int main() {
  system("clear");
  char **processes = NULL;
  char **process_stats = NULL;
  FILE *fp = NULL;
  int i = 0, j = 0, k = 0, pid = 0, status = 0;
  char *username = getpwuid(geteuid())->pw_name;
  processes = (char **)malloc(1024);
  process_stats = (char **)malloc(1024);

  fp = fopen("/proc/ps", "r");
  if (fp == NULL) {
    perror("Error opening file");
    exit(1);
  }

  while (fscanf(fp, "%d %s %s", &pid, processes[i], process_stats[i]) != EOF) {
    i++;
  }

  fclose(fp);

  system("clear");

  printf("\n");
  printf("Username: %s\n", username);
  printf("Processes:**\n");

  for (j = 0; processes[j] != NULL; j++) {
    printf("  %s\n", processes[j]);
  }

  printf("Process Stats:**\n");

  for (k = 0; process_stats[k] != NULL; k++) {
    printf("  %s\n", process_stats[k]);
  }

  free(processes);
  free(process_stats);

  return 0;
}