//Code Llama-13B DATASET v1.0 Category: System administration ; Style: random
/*
 * C System Administration Example Program
 *
 * This program is a simple example of a C program that can be used
 * to perform system administration tasks. It has been written in a
 * random style to demonstrate how C code can be used for this purpose.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>

/* Function declarations */
void print_help();
void list_files(const char* dir);
void list_directories(const char* dir);
void create_file(const char* file);
void delete_file(const char* file);
void create_directory(const char* dir);
void delete_directory(const char* dir);

int main(int argc, char* argv[]) {
  /* Check if the user has provided a command */
  if (argc < 2) {
    print_help();
    return 1;
  }

  /* Parse the command and execute the appropriate function */
  if (strcmp(argv[1], "list") == 0) {
    if (argc < 3) {
      print_help();
      return 1;
    }
    list_files(argv[2]);
  } else if (strcmp(argv[1], "ls") == 0) {
    if (argc < 3) {
      print_help();
      return 1;
    }
    list_directories(argv[2]);
  } else if (strcmp(argv[1], "create") == 0) {
    if (argc < 3) {
      print_help();
      return 1;
    }
    create_file(argv[2]);
  } else if (strcmp(argv[1], "rm") == 0) {
    if (argc < 3) {
      print_help();
      return 1;
    }
    delete_file(argv[2]);
  } else if (strcmp(argv[1], "mkdir") == 0) {
    if (argc < 3) {
      print_help();
      return 1;
    }
    create_directory(argv[2]);
  } else if (strcmp(argv[1], "rmdir") == 0) {
    if (argc < 3) {
      print_help();
      return 1;
    }
    delete_directory(argv[2]);
  } else {
    print_help();
    return 1;
  }

  return 0;
}

void print_help() {
  printf("Usage: cadmin [list|ls|create|rm|mkdir|rmdir] <path>\n");
}

void list_files(const char* dir) {
  DIR* directory;
  struct dirent* entry;
  struct stat statbuf;

  /* Open the directory */
  directory = opendir(dir);
  if (directory == NULL) {
    perror("cadmin: failed to open directory");
    return;
  }

  /* List the files in the directory */
  while ((entry = readdir(directory)) != NULL) {
    if (entry->d_type == DT_REG) {
      printf("%s\n", entry->d_name);
    }
  }

  /* Close the directory */
  closedir(directory);
}

void list_directories(const char* dir) {
  DIR* directory;
  struct dirent* entry;
  struct stat statbuf;

  /* Open the directory */
  directory = opendir(dir);
  if (directory == NULL) {
    perror("cadmin: failed to open directory");
    return;
  }

  /* List the directories in the directory */
  while ((entry = readdir(directory)) != NULL) {
    if (entry->d_type == DT_DIR) {
      printf("%s\n", entry->d_name);
    }
  }

  /* Close the directory */
  closedir(directory);
}

void create_file(const char* file) {
  int fd;

  /* Create the file */
  fd = open(file, O_CREAT | O_WRONLY, 0644);
  if (fd == -1) {
    perror("cadmin: failed to create file");
    return;
  }

  /* Close the file */
  close(fd);
}

void delete_file(const char* file) {
  if (unlink(file) == -1) {
    perror("cadmin: failed to delete file");
    return;
  }
}

void create_directory(const char* dir) {
  if (mkdir(dir, 0755) == -1) {
    perror("cadmin: failed to create directory");
    return;
  }
}

void delete_directory(const char* dir) {
  if (rmdir(dir) == -1) {
    perror("cadmin: failed to delete directory");
    return;
  }
}