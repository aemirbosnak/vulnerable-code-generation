//GEMINI-pro DATASET v1.0 Category: System administration ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

#define MAX_PATH_LEN 256
#define MAX_CMD_LEN 128

int main(int argc, char **argv)
{
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <command>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char cmd[MAX_CMD_LEN];
  strcpy(cmd, argv[1]);

  for (int i = 2; i < argc; i++) {
    strcat(cmd, " ");
    strcat(cmd, argv[i]);
  }

  int fd[2];
  pipe(fd);

  pid_t child_pid = fork();
  if (child_pid == 0) {
    // Child process
    close(fd[0]);
    dup2(fd[1], STDOUT_FILENO);
    dup2(fd[1], STDERR_FILENO);
    close(fd[1]);

    execlp("/bin/sh", "sh", "-c", cmd, NULL);
    perror("execlp");
    exit(EXIT_FAILURE);
  } else if (child_pid > 0) {
    // Parent process
    close(fd[1]);

    char path[MAX_PATH_LEN];
    getcwd(path, MAX_PATH_LEN);

    DIR *dir = opendir(path);
    if (dir == NULL) {
      perror("opendir");
      return EXIT_FAILURE;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
      if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
        continue;
      }

      char full_path[MAX_PATH_LEN];
      snprintf(full_path, MAX_PATH_LEN, "%s/%s", path, entry->d_name);

      struct stat st;
      if (stat(full_path, &st) == -1) {
        perror("stat");
        continue;
      }

      if (S_ISREG(st.st_mode)) {
        // Regular file
        FILE *f = fopen(full_path, "r");
        if (f == NULL) {
          perror("fopen");
          continue;
        }

        char line[MAX_CMD_LEN];
        while (fgets(line, MAX_CMD_LEN, f) != NULL) {
          if (strstr(line, cmd) != NULL) {
            printf("%s:%s", full_path, line);
          }
        }

        fclose(f);
      } else if (S_ISDIR(st.st_mode)) {
        // Directory
        char subdir[MAX_PATH_LEN];
        snprintf(subdir, MAX_PATH_LEN, "%s/%s", path, entry->d_name);

        if (chdir(subdir) == -1) {
          perror("chdir");
          continue;
        }

        main(argc, argv);

        if (chdir(path) == -1) {
          perror("chdir");
          return EXIT_FAILURE;
        }
      }
    }

    closedir(dir);

    close(fd[0]);

    int status;
    waitpid(child_pid, &status, 0);
    if (WIFEXITED(status)) {
      return WEXITSTATUS(status);
    } else {
      return EXIT_FAILURE;
    }
  } else {
    // Error
    perror("fork");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}