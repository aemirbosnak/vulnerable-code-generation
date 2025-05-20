//Code Llama-13B DATASET v1.0 Category: File Synchronizer ; Style: scientific
// FileSynchronizer.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>

#define MAX_FILE_PATH_LEN 256
#define MAX_FILE_NAME_LEN 128
#define MAX_FILE_SIZE 1024 * 1024 * 1024

typedef struct {
  char path[MAX_FILE_PATH_LEN];
  char name[MAX_FILE_NAME_LEN];
  unsigned long size;
  time_t modified_time;
} file_info_t;

int compare_files(const void *a, const void *b) {
  const file_info_t *f1 = (const file_info_t *)a;
  const file_info_t *f2 = (const file_info_t *)b;
  return strcmp(f1->name, f2->name);
}

void get_file_info(file_info_t *info, const char *path) {
  struct stat st;
  if (stat(path, &st) == -1) {
    fprintf(stderr, "Error: could not stat file %s\n", path);
    exit(1);
  }
  info->size = st.st_size;
  info->modified_time = st.st_mtime;
}

void print_file_info(const file_info_t *info) {
  printf("File name: %s\n", info->name);
  printf("File size: %lu\n", info->size);
  printf("Last modified: %s", ctime(&info->modified_time));
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
    exit(1);
  }

  DIR *dir = opendir(argv[1]);
  if (dir == NULL) {
    fprintf(stderr, "Error: could not open directory %s\n", argv[1]);
    exit(1);
  }

  file_info_t files[MAX_FILE_SIZE];
  int num_files = 0;

  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    if (entry->d_type == DT_REG) {
      file_info_t *info = &files[num_files];
      strcpy(info->path, argv[1]);
      strcat(info->path, "/");
      strcat(info->path, entry->d_name);
      strcpy(info->name, entry->d_name);
      get_file_info(info, info->path);
      num_files++;
    }
  }

  closedir(dir);

  qsort(files, num_files, sizeof(file_info_t), compare_files);

  for (int i = 0; i < num_files; i++) {
    print_file_info(&files[i]);
  }

  return 0;
}