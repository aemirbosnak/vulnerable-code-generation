//GEMINI-pro DATASET v1.0 Category: Smart home automation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COMMAND_LENGTH 128
#define MAX_ARGUMENT_COUNT 16

typedef struct {
  char *name;
  char *command;
  int argument_count;
  char **arguments;
} Command;

Command commands[] = {
  { "lights on", "echo 1 > /sys/class/gpio/gpio21/value", 0, NULL },
  { "lights off", "echo 0 > /sys/class/gpio/gpio21/value", 0, NULL },
  { "temperature", "cat /sys/class/thermal/thermal_zone0/temp", 0, NULL },
  { "help", "cat /proc/self/cmdline", 0, NULL },
  { "quit", "exit", 0, NULL },
  { NULL, NULL, 0, NULL }
};

int main(int argc, char **argv) {
  char line[MAX_LINE_LENGTH];
  char command[MAX_COMMAND_LENGTH];
  char *arguments[MAX_ARGUMENT_COUNT];
  int argument_count = 0;
  int i;

  while (1) {
    printf("> ");
    fflush(stdout);
    if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL) {
      fprintf(stderr, "Error reading from stdin: %s\n", strerror(errno));
      exit(1);
    }

    if (line[strlen(line) - 1] == '\n') {
      line[strlen(line) - 1] = '\0';
    }

    if (strlen(line) == 0) {
      continue;
    }

    if (sscanf(line, "%s %s %s %s %s %s %s %s %s %s %s %s %s %s %s %s", command, arguments[0], arguments[1], arguments[2], arguments[3], arguments[4], arguments[5], arguments[6], arguments[7], arguments[8], arguments[9], arguments[10], arguments[11], arguments[12], arguments[13], arguments[14], arguments[15]) < 1) {
      fprintf(stderr, "Error parsing command: %s\n", strerror(errno));
      exit(1);
    }

    for (i = 0; commands[i].name != NULL; i++) {
      if (strcmp(command, commands[i].name) == 0) {
        break;
      }
    }

    if (commands[i].name == NULL) {
      fprintf(stderr, "Unknown command: %s\n", command);
      continue;
    }

    switch (commands[i].argument_count) {
      case 0:
        if (argument_count != 0) {
          fprintf(stderr, "Error: Command %s takes no arguments\n", command);
          continue;
        }
        break;
      case 1:
        if (argument_count != 1) {
          fprintf(stderr, "Error: Command %s takes one argument\n", command);
          continue;
        }
        break;
      default:
        if (argument_count < commands[i].argument_count || argument_count > commands[i].argument_count + 1) {
          fprintf(stderr, "Error: Command %s takes %d or %d arguments\n", command, commands[i].argument_count, commands[i].argument_count + 1);
          continue;
        }
        break;
    }

    if (fork() == 0) {
      execlp(commands[i].command, commands[i].command, arguments[0], arguments[1], arguments[2], arguments[3], arguments[4], arguments[5], arguments[6], arguments[7], arguments[8], arguments[9], arguments[10], arguments[11], arguments[12], arguments[13], arguments[14], arguments[15], NULL);
      fprintf(stderr, "Error executing command: %s\n", strerror(errno));
      exit(1);
    }

    wait(NULL);
  }

  return 0;
}