//Gemma-7B DATASET v1.0 Category: Disk space analyzer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

#define KB 1024
#define MB 1024 * KB
#define GB 1024 * MB

struct stat_info {
  long long size;
  long long used;
  long long free;
  long long blocks;
  long long inodes;
  long long files;
  long long directories;
};

void analyze_disk(char *path) {
  struct stat_info info;
  stat(path, &info);

  // Calculate disk usage statistics
  long long total_size = info.size;
  long long total_used = info.used;
  long long total_free = total_size - total_used;

  // Calculate space usage percentages
  long long usage_percentage = (total_used * 100) / total_size;
  long long free_percentage = (total_free * 100) / total_size;

  // Print disk usage statistics
  printf("Disk Usage Statistics for %s:\n", path);
  printf("------------------------\n");
  printf("Total Size: %lld GB\n", total_size / GB);
  printf("Total Used Space: %lld GB (%d%%)\n", total_used / GB, usage_percentage);
  printf("Total Free Space: %lld GB (%d%%)\n", total_free / GB, free_percentage);
  printf("Blocks: %lld\n", info.blocks);
  printf("Inodes: %lld\n", info.inodes);
  printf("Files: %lld\n", info.files);
  printf("Directories: %lld\n", info.directories);
  printf("\n");
}

int main() {
  analyze_disk("/");
  analyze_disk("/home");
  return 0;
}