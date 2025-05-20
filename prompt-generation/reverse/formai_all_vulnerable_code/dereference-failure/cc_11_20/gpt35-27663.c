//FormAI DATASET v1.0 Category: File Synchronizer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_FILES 1024

void sync(char* src_dir, char* dest_dir);

int main(int argc, char** argv) {
  if (argc != 3) {
    printf("Usage: %s <source directory> <destination directory>\n", argv[0]);
    return 1;
  }

  sync(argv[1], argv[2]);

  return 0;
}

void sync(char* src_dir, char* dest_dir) {
  DIR* dir;
  struct dirent* ent;
  struct stat st;
  char* src_file_path = malloc(sizeof(char) * 1024);
  char* dest_file_path = malloc(sizeof(char) * 1024);
  char* src_sub_dir = malloc(sizeof(char) * 1024);
  char* dest_sub_dir = malloc(sizeof(char) * 1024);
  char* file_name = malloc(sizeof(char) * 256);
  char* src_dir_name = malloc(sizeof(char) * 1024);
  char* dest_dir_name = malloc(sizeof(char) * 1024);
  char* src_rel_path = malloc(sizeof(char) * 1024);
  char* dest_rel_path = malloc(sizeof(char) * 1024);
  char** files = malloc(sizeof(char*) * MAX_FILES);
  int src_count = 0;
  int dest_count = 0;
  int i, j;
  int found;
  FILE* src_file;
  FILE* dest_file;

  // Get source file list
  dir = opendir(src_dir);
  if (dir == NULL) {
    printf("Error: failed to open directory '%s'\n", src_dir);
    return;
  }
  while ((ent = readdir(dir)) != NULL) {
    if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
      continue;
    }
    sprintf(src_file_path, "%s/%s", src_dir, ent->d_name);
    if (stat(src_file_path, &st) == -1) {
      printf("Error: failed to stat '%s'\n", src_file_path);
      continue;
    }
    if (S_ISDIR(st.st_mode)) {
      // Recurse into subdirectory
      sprintf(src_sub_dir, "%s/%s", src_dir, ent->d_name);
      sprintf(dest_sub_dir, "%s/%s", dest_dir, ent->d_name);
      sync(src_sub_dir, dest_sub_dir);
    }
    else if (S_ISREG(st.st_mode)) {
      // Add file to list of source files
      files[src_count] = malloc(sizeof(char) * 1024);
      sprintf(files[src_count], "%s", ent->d_name);
      src_count++;
    }
  }
  closedir(dir);

  // Get destination file list
  dir = opendir(dest_dir);
  if (dir != NULL) {
    while ((ent = readdir(dir)) != NULL) {
      if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
        continue;
      }
      sprintf(dest_file_path, "%s/%s", dest_dir, ent->d_name);
      if (stat(dest_file_path, &st) == -1) {
        printf("Error: failed to stat '%s'\n", dest_file_path);
        continue;
      }
      if (S_ISDIR(st.st_mode)) {
        // Ignore directories
      }
      else if (S_ISREG(st.st_mode)) {
        // Add file to list of destination files
        dest_count++;
      }
    }
    closedir(dir);
  }

  // Copy files
  for (i = 0; i < src_count; i++) {
    found = 0;
    for (j = 0; j < dest_count; j++) {
      if (strcmp(files[i], files[j]) == 0) {
        found = 1;
        break;
      }
    }
    if (!found) {
      // Copy file from source to destination
      sprintf(src_rel_path, "%s/%s", src_dir, files[i]);
      sprintf(dest_rel_path, "%s/%s", dest_dir, files[i]);
      src_file = fopen(src_rel_path, "rb");
      dest_file = fopen(dest_rel_path, "wb");
      if (src_file == NULL) {
        printf("Error: failed to open file '%s'\n", src_rel_path);
        continue;
      }
      if (dest_file == NULL) {
        printf("Error: failed to open file '%s'\n", dest_rel_path);
        continue;
      }
      while (!feof(src_file)) {
        fputc(fgetc(src_file), dest_file);
      }
      fclose(src_file);
      fclose(dest_file);
      printf("Copied '%s' to '%s'\n", src_rel_path, dest_rel_path);
    }
  }

  // Free memory
  for (i = 0; i < src_count; i++) {
    free(files[i]);
  }
  free(files);
  free(src_file_path);
  free(dest_file_path);
  free(src_sub_dir);
  free(dest_sub_dir);
  free(file_name);
  free(src_dir_name);
  free(dest_dir_name);
  free(src_rel_path);
  free(dest_rel_path);
}