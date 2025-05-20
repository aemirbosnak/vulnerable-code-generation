//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Colors for terminal output
#define BLUE "\x1b[34m"
#define GREEN "\x1b[32m"
#define RESET "\x1b[0m"

// Function to get the file size in human-readable format
char *human_readable_size(long long size) {
  char *units[] = {"B", "KiB", "MiB", "GiB", "TiB", "PiB", "EiB", "ZiB", "YiB"};
  int unit_index = 0;
  while (size >= 1024 && unit_index < 8) {
    size /= 1024;
    unit_index++;
  }
  static char result[16];
  snprintf(result, sizeof(result), "%.2f %s", (double)size, units[unit_index]);
  return result;
}

// Function to analyze a directory and print its size
void analyze_directory(char *path) {
  struct dirent *entry;
  DIR *dir = opendir(path);
  if (dir == NULL) {
    perror("Error opening directory");
    return;
  }
  long long total_size = 0;
  printf("Analyzing directory: %s\n", path);
  while ((entry = readdir(dir)) != NULL) {
    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
      continue;
    }
    char full_path[strlen(path) + strlen(entry->d_name) + 2];
    sprintf(full_path, "%s/%s", path, entry->d_name);
    struct stat statbuf;
    if (lstat(full_path, &statbuf) == -1) {
      perror("Error getting file stats");
      continue;
    }
    if (S_ISDIR(statbuf.st_mode)) {
      // Recursively analyze subdirectories
      analyze_directory(full_path);
    } else {
      // Add the file size to the total
      total_size += statbuf.st_size;
    }
  }
  closedir(dir);
  printf("Total size: %s\n", human_readable_size(total_size));
}

int main() {
  printf(BLUE "\nHello! Welcome to the C Disk Space Analyzer!\n" RESET);
  printf(GREEN "Let's find out how much space your files are taking up.\n\n" RESET);
  char path[1024];
  printf("Enter the path to the directory you want to analyze: ");
  scanf("%s", path);
  analyze_directory(path);
  printf(GREEN "\nAnalysis complete! You're all set.\n" RESET);
  return 0;
}