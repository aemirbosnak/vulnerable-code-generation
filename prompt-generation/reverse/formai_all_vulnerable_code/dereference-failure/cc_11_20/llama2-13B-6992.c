//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define MAX_LINE_LENGTH 1024
#define MAP_SIZE 1024 * 1024

int main() {
  char *line = NULL;
  size_t line_len = 0;
  char *map = mmap(NULL, MAP_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE, -1, 0);
  if (map == MAP_FAILED) {
    perror("mmap failed");
    return 1;
  }

  while (1) {
    printf("> ");
    fgets(line, MAX_LINE_LENGTH, stdin);
    line_len = strlen(line);
    if (line_len > 0 && line[line_len - 1] == '\n') {
      line[line_len - 1] = '\0';
    }

    // Tokenize the line and execute the commands
    char *token = strtok(line, " ");
    while (token != NULL && token[0] != '\0') {
      if (strcmp(token, "echo") == 0) {
        printf("%s\n", token + 1);
      } else if (strcmp(token, "cd") == 0) {
        char *new_dir = strtok(NULL, " ");
        if (chdir(new_dir) != 0) {
          perror("chdir failed");
          return 1;
        }
      } else if (strcmp(token, "exec") == 0) {
        char *new_program = strtok(NULL, " ");
        if (execv(new_program, NULL) == -1) {
          perror("execv failed");
          return 1;
        }
      } else {
        printf("Invalid command: %s\n", token);
      }

      token = strtok(NULL, " ");
    }
  }

  munmap(map, MAP_SIZE);
  return 0;
}