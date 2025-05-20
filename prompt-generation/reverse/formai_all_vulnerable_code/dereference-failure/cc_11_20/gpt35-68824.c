//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024  // size of the buffer for reading from files
#define THRESHOLD 5        // threshold for number of failed login attempts

// struct to hold login information
struct LoginInfo {
  char *username;
  char *password;
  int attempts;
};

int main(int argc, char **argv) {
  // check if file argument is provided
  if(argc < 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  // open file for reading
  FILE *file = fopen(argv[1], "r");
  if(!file) {
    printf("Error opening file.\n");
    return 1;
  }

  // initialize array of LoginInfo structs
  struct LoginInfo login_info[100];
  int num_logins = 0;

  // read lines from file
  char buffer[BUFFER_SIZE];
  while(fgets(buffer, BUFFER_SIZE, file)) {
    // parse username and password from line
    char *username = strtok(buffer, " ");
    char *password = strtok(NULL, "\n");

    // convert username and password to lowercase
    for(int i = 0; username[i]; i++) {
      username[i] = tolower(username[i]);
    }
    for(int i = 0; password[i]; i++) {
      password[i] = tolower(password[i]);
    }

    // check if login info already exists
    int login_exists = 0;
    for(int i = 0; i < num_logins; i++) {
      if(strcmp(login_info[i].username, username) == 0 &&
         strcmp(login_info[i].password, password) == 0) {
        login_exists = 1;
        login_info[i].attempts++;
        if(login_info[i].attempts >= THRESHOLD) {
          printf("Intrusion detection: %s %s\n", login_info[i].username, login_info[i].password);
        }
        break;
      }
    }

    // add new login info
    if(!login_exists) {
      login_info[num_logins].username = strdup(username);
      login_info[num_logins].password = strdup(password);
      login_info[num_logins].attempts = 1;
      num_logins++;
    }
  }

  // close file
  fclose(file);

  return 0;
}