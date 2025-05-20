#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[1024];
  char pasv_response[1024];

  // Receive PASV response
  fgets(pasv_response, 1024, stdin);

  // Extract data port from response
  int data_port;
  sscanf(pasv_response, "PORT %d", &data_port);

  // Check for buffer overflow
  if (strlen(pasv_response) >= 1024 - 1) {
    printf("Error: Buffer overflow.\n");
  } else {
    printf("Data port: %d\n", data_port);
  }

  return 0;
}
