#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[1024];
  char command[64];
  char server_response[1024];

  printf("Enter command: ");
  scanf("%s", command);

  if (strcmp(command, "STAT") == 0) {
    // Send STAT command to server
    printf("STAT\n");
    fflush(stdout);

    // Receive server response
    printf("Server response: ");
    scanf("%s", server_response);

    // Parse server response using sscanf
    sscanf(server_response, "STAT %s %s", buffer, buffer);
  } else if (strcmp(command, "LIST") == 0) {
    // Send LIST command to server
    printf("LIST\n");
    fflush(stdout);

    // Receive server response
    printf("Server response: ");
    scanf("%s", server_response);

    // Parse server response using sscanf
    sscanf(server_response, "LIST %s", buffer);
  } else {
    printf("Invalid command.\n");
  }

  return 0;
}
