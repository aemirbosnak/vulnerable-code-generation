//FormAI DATASET v1.0 Category: Networking ; Style: mathematical
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

int main(int argc, char *argv[])
{
  int socket_desc;
  struct sockaddr_in server_addr;
  char *message, server_reply[2000];
  double num1 = 10, num2 = 5, result;   // Initializing values for mathematical operations
  
  // Create socket
  socket_desc = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_desc == -1)
  {
    printf("Could not create socket");
  }

  // Prepare the sockaddr_in structure
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
  server_addr.sin_port = htons(8080);

  // Connect to server
  if (connect(socket_desc, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
  {
    puts("connect error");
    return 1;
  }

  puts("Connected\n");

  // Send some data to server
  message = "Hello Server!";
  if (send(socket_desc, message, strlen(message), 0) < 0)
  {
    puts("Send failed");
    return 1;
  }
  puts("Data Sent\n");

  // Receive a reply from the server
  if (recv(socket_desc, server_reply, 2000, 0) < 0)
  {
    puts("recv failed");
  }
  puts("Reply received\n");
  puts(server_reply);

  // Mathematical calculations
  result = pow(num1, num2);
  printf("\nResult of num1 raised to num2 = %.1lf\n", result);

  result = sqrt(num1);
  printf("\nSquare root of num1 = %.1lf\n", result);

  result = ceil(num2);
  printf("\nCeiling value of num2 = %.1lf\n", result);

  // Closing connection
  close(socket_desc);
  return 0;
}