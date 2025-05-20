//Code Llama-13B DATASET v1.0 Category: System administration ; Style: dynamic
/*
 * A program to print the system information
 * in a dynamic style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/utsname.h>
#endif

int main() {
  struct utsname uts;
  char* cpu, *memory, *disk;
  int ret;

#ifdef _WIN32
  SYSTEM_INFO si;
  GetSystemInfo(&si);
  cpu = malloc(si.dwNumberOfProcessors * sizeof(char));
  memory = malloc(si.dwTotalPhys / 1024 * sizeof(char));
  disk = malloc(si.dwTotalPhys / 1024 * sizeof(char));

  ret = GetSystemInfo(cpu, memory, disk);
  if (ret != 0) {
    printf("Error: unable to get system information\n");
    return -1;
  }
#else
  ret = uname(&uts);
  if (ret != 0) {
    printf("Error: unable to get system information\n");
    return -1;
  }

  cpu = malloc(sizeof(uts.machine));
  memory = malloc(sizeof(uts.release));
  disk = malloc(sizeof(uts.sysname));

  strcpy(cpu, uts.machine);
  strcpy(memory, uts.release);
  strcpy(disk, uts.sysname);
#endif

  printf("System Information:\n");
  printf("  CPU: %s\n", cpu);
  printf("  Memory: %s\n", memory);
  printf("  Disk: %s\n", disk);

  free(cpu);
  free(memory);
  free(disk);

  return 0;
}