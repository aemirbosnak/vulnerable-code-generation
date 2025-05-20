//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <sys/statvfs.h>
#include <time.h>

// Romeo's function to get the disk space usage
long long get_disk_usage(const char *path) {
  struct statvfs stat;
  if (statvfs(path, &stat) != 0) {
    perror("statvfs");
    return -1;
  }
  return (stat.f_blocks - stat.f_bfree) * stat.f_bsize;
}

// Juliet's function to format the disk space usage
char *format_disk_usage(long long bytes) {
  char *units[] = {"B", "KB", "MB", "GB", "TB"};
  int unit_index = 0;
  while (bytes >= 1024 && unit_index < 5) {
    bytes /= 1024;
    unit_index++;
  }
  static char buffer[64];
  snprintf(buffer, sizeof(buffer), "%.2f %s", (double)bytes, units[unit_index]);
  return buffer;
}

// Their forbidden love (main function)
int main(void) {
  time_t now = time(NULL);
  printf(
      "Romeo and Juliet, a forbidden love, but their passion for each other, like the "
      "disk space usage on my computer, is immeasurable.\n");
  printf("As the clock strikes %s, let's explore the depths of my hard drive.\n",
         ctime(&now));

  const char *paths[] = {"/", "/home", "/usr", "/var", "/tmp"};
  for (int i = 0; i < 5; i++) {
    long long usage = get_disk_usage(paths[i]);
    if (usage < 0) {
      perror("get_disk_usage");
      return EXIT_FAILURE;
    }
    char *formatted_usage = format_disk_usage(usage);
    printf("%s: %s\n", paths[i], formatted_usage);
  }

  printf(
      "Like Romeo and Juliet, our love for each other and the quest for free disk space "
      "will forever be a tale of unrequited passion.\n");
  return EXIT_SUCCESS;
}