//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>

// Function to get the current time as a string
char *get_current_time() {
  time_t rawtime;
  struct tm *timeinfo;
  time(&rawtime);
  timeinfo = localtime(&rawtime);
  return asctime(timeinfo);
}

// Function to check if a website is up
int check_website(char *hostname) {
  struct hostent *host;
  struct sockaddr_in addr;
  int sockfd;

  // Get the IP address of the hostname
  host = gethostbyname(hostname);
  if (host == NULL) {
    return -1;
  }

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    return -1;
  }

  // Set the socket address
  addr.sin_family = AF_INET;
  addr.sin_port = htons(80);
  addr.sin_addr = *(struct in_addr *)*host->h_addr_list;

  // Connect to the website
  if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    return -1;
  }

  // Close the socket
  close(sockfd);

  // Return 0 if the website is up, -1 otherwise
  return 0;
}

// Main function
int main(int argc, char *argv[]) {
  FILE *fp;
  char line[1024];
  int i, website_status;

  // Open the file containing the list of websites
  fp = fopen("websites.txt", "r");
  if (fp == NULL) {
    perror("Error opening file");
    return -1;
  }

  // Loop through the list of websites and check if they are up
  for (i = 0; fgets(line, sizeof(line), fp); i++) {
    // Remove the newline character from the website URL
    line[strlen(line) - 1] = '\0';

    // Check if the website is up
    website_status = check_website(line);

    // Print the website URL and its status
    printf("%3d %s %s", i + 1, line, (website_status == 0) ? "up" : "down");
  }

  // Close the file
  fclose(fp);

  return 0;
}