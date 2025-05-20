//MISTRAL-7B DATASET v1.0 Category: Log analysis ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAX_LINE_LEN 1024
#define LOG_FILE "access.log"
int main(int argc, char **argv) {
  FILE *log_file;
  char line[MAX_LINE_LEN];
  char *token, *token2, *token3;
  int ip_count[4] = {0};
  int access_count[3] = {0};
  int i, j;
  log_file = fopen(LOG_FILE, "r");
  if (log_file == NULL) {
    perror("Error opening log file");
    return 1;
  }
  while (fgets(line, MAX_LINE_LEN, log_file) != NULL) {
    token = strtok(line, " ");
    if (strcmp(token, "[") != 0) continue;
    token = strtok(NULL, "]");
    token2 = strtok(NULL, " ");
    if (strcmp(token2, "127.0.0.1") != 0) {
      sscanf(token, "%d.%d.%d.%d", &ip_count[0], &ip_count[1], &ip_count[2], &ip_count[3]);
    }
    token = strtok(NULL, " ");
    if (strcmp(token, "GET") != 0 && strcmp(token, "POST") != 0) continue;
    token3 = strtok(NULL, " ");
    if (strcmp(token3, "/login") == 0) access_count[0]++;
    if (strcmp(token3, "/register") == 0) access_count[1]++;
    if (strcmp(token3, "/admin") == 0) access_count[2]++;
  }
  fclose(log_file);
  printf("IP Addresses:\n");
  for (i = 0; i < 4; i++) printf("%d.", ip_count[i]);
  printf("\n");
  printf("Access Counts:\n");
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3 - i; j++) {
      if (access_count[j] < access_count[j + 1]) {
        int temp = access_count[j];
        access_count[j] = access_count[j + 1];
        access_count[j + 1] = temp;
      }
    }
  }
  for (i = 0; i < 3; i++) {
    printf("%s: %d\n", token3[i + 3], access_count[i]);
  }
  return 0;
}