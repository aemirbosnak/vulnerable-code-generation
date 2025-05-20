//Gemma-7B DATASET v1.0 Category: System administration ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_USER_NAME_LENGTH 255

int main() {
  char username[MAX_USER_NAME_LENGTH];
  char password[MAX_USER_NAME_LENGTH];
  char command[MAX_USER_NAME_LENGTH];

  printf("Enter username: ");
  scanf("%s", username);

  printf("Enter password: ");
  scanf("%s", password);

  if (strcmp(username, "admin") == 0 && strcmp(password, "secret") == 0) {
    printf("Welcome, administrator!\n");
    printf("Enter command: ");
    scanf("%s", command);

    if (strcmp(command, "create user") == 0) {
      printf("Enter new user's name: ");
      scanf("%s", username);

      printf("Enter new user's password: ");
      scanf("%s", password);

      FILE *fp = fopen("/etc/passwd", "a");
      fprintf(fp, "%s:%s:1001:1001::/home/%s\n", username, password, username);
      fclose(fp);

      printf("User created successfully.\n");
    } else if (strcmp(command, "delete user") == 0) {
      printf("Enter user's name: ");
      scanf("%s", username);

      FILE *fp = fopen("/etc/passwd", "r");
      char *line = NULL;
      int line_number = 0;

      while ((line = fgets(line, MAX_USER_NAME_LENGTH, fp)) != NULL) {
        if (strcmp(line, username) == 0) {
          line_number++;
        }
      }

      fclose(fp);

      if (line_number > 0) {
        FILE *fp = fopen("/etc/passwd", "w");
        char *new_lines = malloc(line_number * MAX_USER_NAME_LENGTH);

        fp = fopen("/etc/passwd", "r");
        line = NULL;
        int i = 0;

        while ((line = fgets(new_lines, MAX_USER_NAME_LENGTH, fp)) != NULL) {
          if (strcmp(line, username) != 0) {
            fprintf(fp, "%s", new_lines[i]);
            i++;
          }
        }

        fclose(fp);

        free(new_lines);

        printf("User deleted successfully.\n");
      } else {
        printf("User not found.\n");
      }
    } else if (strcmp(command, "modify user") == 0) {
      printf("Enter user's name: ");
      scanf("%s", username);

      printf("Enter new user's password: ");
      scanf("%s", password);

      FILE *fp = fopen("/etc/passwd", "r");
      char *line = NULL;
      int line_number = 0;

      while ((line = fgets(line, MAX_USER_NAME_LENGTH, fp)) != NULL) {
        if (strcmp(line, username) == 0) {
          line_number++;
        }
      }

      fclose(fp);

      if (line_number > 0) {
        FILE *fp = fopen("/etc/passwd", "w");
        char *new_lines = malloc(line_number * MAX_USER_NAME_LENGTH);

        fp = fopen("/etc/passwd", "r");
        line = NULL;
        int i = 0;

        while ((line = fgets(new_lines, MAX_USER_NAME_LENGTH, fp)) != NULL) {
          if (strcmp(line, username) != 0) {
            fprintf(fp, "%s", new_lines[i]);
            i++;
          }
        }

        fclose(fp);

        free(new_lines);

        printf("User modified successfully.\n");
      } else {
        printf("User not found.\n");
      }
    } else {
      printf("Invalid command.\n");
    }
  } else {
    printf("Invalid credentials.\n");
  }

  return 0;
}