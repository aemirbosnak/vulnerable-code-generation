//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <time.h>
#include <unistd.h>
#include <arpa/inet.h>

// A quirky, curious little function to determine the size of a file
int fileSize(const char *filename) {
  // Let's open the file, shall we?
  FILE *file = fopen(filename, "r");
  if (!file) {
    // Oh dear, it seems the file is as elusive as a unicorn's horn.
    return -1;
  }
  // We'll use fseek to magically transport ourselves to the end of the file.
  fseek(file, 0, SEEK_END);
  // And then we can use ftell to uncover the mystical truth of its size.
  int size = ftell(file);
  // Don't forget to close the door behind us!
  fclose(file);
  // Now we have the knowledge of the file's size, ready to be shared.
  return size;
}

// A sprightly function to calculate the speed of our internet connection
int internetSpeed(const char *host, int port) {
  // Let's conjure up a socket, a magical portal for data to flow
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    // Alas, the socket creation spell has failed...
    return -1;
  }
  // Now, let's establish a connection with our chosen host
  struct hostent *server = gethostbyname(host);
  if (!server) {
    // Oh dear, the hostname seems to be a figment of our imagination!
    close(sock);
    return -1;
  }
  // We need to prepare the address structure for our connection
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  memcpy(&addr.sin_addr.s_addr, server->h_addr, server->h_length);
  addr.sin_port = htons(port);
  // Time to make the connection happen!
  if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
    // The connection spell has gone awry!
    close(sock);
    return -1;
  }
  // Now, let's download a file of known size to measure our speed
  char filename[] = "test-file";
  int size = fileSize(filename);
  if (size < 0) {
    // Alas, the file is as elusive as a phantom!
    close(sock);
    return -1;
  }
  // Prepare a buffer to store the file data
  char buffer[1024];
  // Let's start the timer to measure the download time
  clock_t start = clock();
  // Now, let's download the file chunk by chunk
  int total = 0;
  while (total < size) {
    int bytes = recv(sock, buffer, sizeof(buffer), 0);
    if (bytes <= 0) {
      // The data flow has ceased...
      close(sock);
      return -1;
    }
    total += bytes;
  }
  // The download is complete! Time to stop the timer
  clock_t end = clock();
  // Calculate the download time in seconds
  double time = (double)(end - start) / CLOCKS_PER_SEC;
  // Now, let's calculate the speed in bytes per second
  int speed = (int)(total / time);
  // Don't forget to close the socket connection
  close(sock);
  // And return the speed, a measure of our internet's swiftness
  return speed;
}

// The main function, where the magic begins
int main() {
  // Let's test our speed against Google's trusty servers
  const char *host = "google.com";
  int port = 80;
  // Let's ask our curious function to measure our internet's speed
  int speed = internetSpeed(host, port);
  if (speed < 0) {
    printf("Oh no! Our speed-testing adventure has hit a snag.\n");
  } else {
    printf("Eureka! Your internet connection gallops at a speed of %d bytes per second.\n", speed);
  }
  return 0;
}