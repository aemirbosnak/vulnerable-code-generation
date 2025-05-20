//Gemma-7B DATASET v1.0 Category: System administration ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main() {
  system("clear");
  system("echo \"Welcome to the C Shell, my friend!\n");

  char cmd[1024] = "";
  printf("Enter your command: ");
  fgets(cmd, 1024, stdin);

  // Split the command into words
  char **words = NULL;
  int num_words = 0;
  char *word = strtok(cmd, " ");
  while (word) {
    words = realloc(words, (num_words + 1) * sizeof(char *));
    words[num_words++] = word;
    word = strtok(NULL, " ");
  }

  // Check if the command is a built-in command
  if (strcmp(words[0], "exit") == 0) {
    exit(0);
  } else if (strcmp(words[0], "who") == 0) {
    system("who");
  } else if (strcmp(words[0], "pwd") == 0) {
    system("pwd");
  } else if (strcmp(words[0], "ls") == 0) {
    system("ls");
  } else if (strcmp(words[0], "touch") == 0) {
    system("touch");
  } else if (strcmp(words[0], "mv") == 0) {
    system("mv");
  } else if (strcmp(words[0], "cp") == 0) {
    system("cp");
  } else if (strcmp(words[0], "rm") == 0) {
    system("rm");
  } else if (strcmp(words[0], "chmod") == 0) {
    system("chmod");
  } else if (strcmp(words[0], "chown") == 0) {
    system("chown");
  } else if (strcmp(words[0], "sudo") == 0) {
    system("sudo");
  } else {
    system("echo \"Command not found.\n");
  }

  return 0;
}