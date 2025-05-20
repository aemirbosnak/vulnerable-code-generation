//GEMINI-pro DATASET v1.0 Category: File system simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_SIZE 1024

typedef struct {
  char name[32];
  int size;
  char data[MAX_FILE_SIZE];
} file_t;

file_t files[MAX_FILES];
int num_files = 0;

void create_file(char *name, int size) {
  if (num_files >= MAX_FILES) {
    printf("Error: Too many files open.\n");
    return;
  }

  strcpy(files[num_files].name, name);
  files[num_files].size = size;
  memset(files[num_files].data, 0, MAX_FILE_SIZE);

  num_files++;
}

void delete_file(char *name) {
  int i;

  for (i = 0; i < num_files; i++) {
    if (strcmp(files[i].name, name) == 0) {
      break;
    }
  }

  if (i == num_files) {
    printf("Error: File not found.\n");
    return;
  }

  for (; i < num_files - 1; i++) {
    files[i] = files[i + 1];
  }

  num_files--;
}

void write_file(char *name, char *data, int size) {
  int i;

  for (i = 0; i < num_files; i++) {
    if (strcmp(files[i].name, name) == 0) {
      break;
    }
  }

  if (i == num_files) {
    printf("Error: File not found.\n");
    return;
  }

  if (size > files[i].size) {
    printf("Error: File size too large.\n");
    return;
  }

  memcpy(files[i].data, data, size);
}

void read_file(char *name, char *data, int size) {
  int i;

  for (i = 0; i < num_files; i++) {
    if (strcmp(files[i].name, name) == 0) {
      break;
    }
  }

  if (i == num_files) {
    printf("Error: File not found.\n");
    return;
  }

  if (size > files[i].size) {
    printf("Error: Buffer too small.\n");
    return;
  }

  memcpy(data, files[i].data, size);
}

int main() {
  char command[32];
  char name[32];
  char data[MAX_FILE_SIZE];
  int size;

  while (1) {
    printf("> ");
    scanf("%s", command);

    if (strcmp(command, "create") == 0) {
      scanf("%s %d", name, &size);
      create_file(name, size);
    } else if (strcmp(command, "delete") == 0) {
      scanf("%s", name);
      delete_file(name);
    } else if (strcmp(command, "write") == 0) {
      scanf("%s", name);
      size = fread(data, 1, MAX_FILE_SIZE, stdin);
      write_file(name, data, size);
    } else if (strcmp(command, "read") == 0) {
      scanf("%s", name);
      size = fread(data, 1, MAX_FILE_SIZE, stdin);
      read_file(name, data, size);
      fwrite(data, 1, size, stdout);
    } else if (strcmp(command, "quit") == 0) {
      break;
    } else {
      printf("Error: Unknown command.\n");
    }
  }

  return 0;
}