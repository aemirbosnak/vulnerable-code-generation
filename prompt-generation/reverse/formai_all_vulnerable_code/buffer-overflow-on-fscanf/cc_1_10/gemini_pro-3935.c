//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/utsname.h>
#include <fcntl.h>
#include <dirent.h>

#define PROC_DIR "/proc"

int main(int argc, char *argv[]) {
  DIR *proc_dir;
  struct dirent *proc_entry;
  struct stat proc_stat;
  struct utsname uname_info;
  int pid, mem_kb, status;
  char proc_path[256], cmdline_path[256], status_path[256], cmdline[256];
  FILE *cmdline_file, *status_file;

  // Open the /proc directory
  proc_dir = opendir(PROC_DIR);
  if (proc_dir == NULL) {
    perror("opendir");
    return EXIT_FAILURE;
  }

  // Get the system information
  uname(&uname_info);

  // Print the system information
  printf("System Information\n");
  printf("------------------\n");
  printf("OS: %s\n", uname_info.sysname);
  printf("Release: %s\n", uname_info.release);
  printf("Version: %s\n", uname_info.version);
  printf("Machine: %s\n", uname_info.machine);
  printf("\n");

  // Print the process list
  printf("Process List\n");
  printf("------------\n");
  printf("%-5s  %-16s  %-8s  %-8s  %-8s  %-s\n", "PID", "Name", "State", "Mem KB", "Status", "Cmdline");

  while ((proc_entry = readdir(proc_dir)) != NULL) {
    // Ignore non-numeric directories
    if (sscanf(proc_entry->d_name, "%d", &pid) != 1) {
      continue;
    }

    // Get the process status
    snprintf(status_path, sizeof(status_path), "%s/%d/status", PROC_DIR, pid);
    status_file = fopen(status_path, "r");
    if (status_file == NULL) {
      perror("fopen");
      continue;
    }
    fscanf(status_file, "Name:\t%s\n", cmdline);
    fscanf(status_file, "State:\t%c\n", &status);
    fscanf(status_file, "VmSize:\t%d kB\n", &mem_kb);
    fclose(status_file);

    // Get the process command line
    snprintf(cmdline_path, sizeof(cmdline_path), "%s/%d/cmdline", PROC_DIR, pid);
    cmdline_file = fopen(cmdline_path, "r");
    if (cmdline_file == NULL) {
      perror("fopen");
      strcpy(cmdline, "(unknown)");
    } else {
      fread(cmdline, sizeof(cmdline), 1, cmdline_file);
      fclose(cmdline_file);
    }

    // Print the process information
    printf("%-5d  %-16s  %-8c  %-8d  %-8s  %s\n", pid, cmdline, status, mem_kb, proc_entry->d_name, cmdline);
  }

  // Close the /proc directory
  closedir(proc_dir);

  return EXIT_SUCCESS;
}