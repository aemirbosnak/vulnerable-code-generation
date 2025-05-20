//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#ifdef __MACH__
#include <mach/mach_init.h>
#include <mach/task.h>
#endif

#ifdef __linux__
#include <sys/resource.h>
#include <fcntl.h>
#endif

#ifdef __unix__
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#endif


void dump_rusage(struct rusage *rusage)
{
#ifdef __MACH__
  if (rusage->ru_maxrss != 0) {
    printf("Maximum resident set size: %lu bytes\n", rusage->ru_maxrss);
  }
#elif __linux__
  if (rusage->ru_maxrss != 0) {
    printf("Maximum resident set size: %lu bytes\n", rusage->ru_maxrss * 1024L);
  }
#endif
}

int main(int argc, char **argv)
{
  struct rusage rusage;
  int status;


#ifdef __MACH__
  task_basic_info_data_t task_info;
  mach_msg_type_number_t task_info_count = TASK_BASIC_INFO_COUNT;
  if (task_info_data(mach_task_self(), &task_info, &task_info_count) == KERN_SUCCESS) {
    rusage.ru_maxrss = task_info.resident_size;
  }
#elif __linux__
  int fd;
  char buf[1024];

  fd = open("/proc/self/status", O_RDONLY);
  if (fd != -1) {
    while (fgets(buf, sizeof(buf), fd) != NULL) {
      if (strstr(buf, "VmPeak:") != NULL) {
        sscanf(buf, "VmPeak: %lu kB", &rusage.ru_maxrss);
        break;
      }
    }
    close(fd);
  }
#endif

  status = getrusage(RUSAGE_SELF, &rusage);
  if (status == 0) {
    dump_rusage(&rusage);
  }

  return EXIT_SUCCESS;
}