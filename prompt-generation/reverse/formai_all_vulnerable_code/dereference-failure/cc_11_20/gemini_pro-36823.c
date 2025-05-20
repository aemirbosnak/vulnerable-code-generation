//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  // Welcome the user to Sherlock Holmes' Log Analysis Emporium

  printf("Welcome to Sherlock Holmes' Log Analysis Emporium!\n");
  printf("We can help you find the answers you seek in the most enigmatic of logs.\n\n");

  // Get the log file from the user

  char *log_file;
  printf("Enter the path to the log file: ");
  scanf("%s", log_file);

  // Open the log file

  FILE *fp = fopen(log_file, "r");
  if (fp == NULL) {
    printf("Error: could not open log file.\n");
    return 1;
  }

  // Read the log file into a buffer

  char *log_buffer;
  long log_size;
  fseek(fp, 0, SEEK_END);
  log_size = ftell(fp);
  fseek(fp, 0, SEEK_SET);
  log_buffer = malloc(log_size + 1);
  fread(log_buffer, log_size, 1, fp);
  fclose(fp);

  // Analyze the log file

  // Find all the unique IP addresses in the log file

  char **ip_addresses;
  int num_ip_addresses = 0;
  char *ip_address;
  while ((ip_address = strtok(log_buffer, " ")) != NULL) {
    if (ip_address[0] >= '0' && ip_address[0] <= '9') {
      ip_addresses[num_ip_addresses++] = strdup(ip_address);
    }
    log_buffer = NULL;
  }

  // Find all the unique URLs in the log file

  char **urls;
  int num_urls = 0;
  char *url;
  while ((url = strtok(log_buffer, " ")) != NULL) {
    if (url[0] == '/' || url[0] == 'h') {
      urls[num_urls++] = strdup(url);
    }
    log_buffer = NULL;
  }

  // Find all the unique user agents in the log file

  char **user_agents;
  int num_user_agents = 0;
  char *user_agent;
  while ((user_agent = strtok(log_buffer, " ")) != NULL) {
    if (user_agent[0] == 'M' || user_agent[0] == 'F') {
      user_agents[num_user_agents++] = strdup(user_agent);
    }
    log_buffer = NULL;
  }

  // Print the results

  printf("Unique IP addresses:\n");
  for (int i = 0; i < num_ip_addresses; i++) {
    printf("%s\n", ip_addresses[i]);
  }

  printf("\nUnique URLs:\n");
  for (int i = 0; i < num_urls; i++) {
    printf("%s\n", urls[i]);
  }

  printf("\nUnique user agents:\n");
  for (int i = 0; i < num_user_agents; i++) {
    printf("%s\n", user_agents[i]);
  }

  // Free the allocated memory

  free(log_buffer);
  for (int i = 0; i < num_ip_addresses; i++) {
    free(ip_addresses[i]);
  }
  free(ip_addresses);
  for (int i = 0; i < num_urls; i++) {
    free(urls[i]);
  }
  free(urls);
  for (int i = 0; i < num_user_agents; i++) {
    free(user_agents[i]);
  }
  free(user_agents);

  return 0;
}