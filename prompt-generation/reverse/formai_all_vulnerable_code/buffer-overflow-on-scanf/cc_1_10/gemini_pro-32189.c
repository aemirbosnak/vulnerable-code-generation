//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <limits.h>

// A helper function to calculate the factorial of a number
int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factorial(n - 1);
  }
}

int main() {
  // Create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);

  // Define the server address
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(8080);
  server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

  // Connect to the server
  connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr));

  // Get the input from the user
  int n;
  printf("Enter a number: ");
  scanf("%d", &n);

  // Send the input to the server
  send(sock, &n, sizeof(n), 0);

  // Receive the factorial from the server
  int factorial;
  recv(sock, &factorial, sizeof(factorial), 0);

  // Print the factorial
  printf("The factorial of %d is %d\n", n, factorial);

  // Close the socket
  close(sock);

  return 0;
}