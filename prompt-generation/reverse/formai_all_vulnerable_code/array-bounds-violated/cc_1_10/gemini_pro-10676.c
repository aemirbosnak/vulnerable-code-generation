//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>

int main() {
  // Open the /proc directory
  DIR *proc = opendir("/proc");
  if (proc == NULL) {
    perror("opendir");
    return EXIT_FAILURE;
  }

  // Iterate over the entries in the /proc directory
  struct dirent *entry;
  while ((entry = readdir(proc)) != NULL) {
    // Check if the entry is a directory
    struct stat statbuf;
    if (stat(entry->d_name, &statbuf) == -1) {
      perror("stat");
      continue;
    }
    if (!S_ISDIR(statbuf.st_mode)) {
      continue;
    }

    // Get the process ID from the entry name
    int pid = atoi(entry->d_name);

    // Open the /proc/[pid]/stat file
    char stat_file[256];
    snprintf(stat_file, sizeof(stat_file), "/proc/%d/stat", pid);
    FILE *stat_fp = fopen(stat_file, "r");
    if (stat_fp == NULL) {
      perror("fopen");
      continue;
    }

    // Read the first line of the /proc/[pid]/stat file
    char line[1024];
    if (fgets(line, sizeof(line), stat_fp) == NULL) {
      perror("fgets");
      fclose(stat_fp);
      continue;
    }

    // Parse the first line of the /proc/[pid]/stat file
    char *fields[10];
    int num_fields = 0;
    char *field = strtok(line, " ");
    while (field != NULL) {
      fields[num_fields++] = field;
      field = strtok(NULL, " ");
    }

    // Print the process information
    printf("PID: %d\n", pid);
    printf("Name: %s\n", fields[1]);
    printf("State: %s\n", fields[2]);
    printf("PPID: %s\n", fields[3]);
    printf("Threads: %s\n", fields[19]);
    printf("Memory: %s\n", fields[22]);
    printf("CPU Time: %s\n", fields[13]);

    // Close the /proc/[pid]/stat file
    fclose(stat_fp);
  }

  // Close the /proc directory
  closedir(proc);

  return EXIT_SUCCESS;
}