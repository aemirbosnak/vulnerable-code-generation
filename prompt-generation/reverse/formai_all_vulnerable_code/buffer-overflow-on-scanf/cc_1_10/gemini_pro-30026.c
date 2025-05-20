//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

// Our FTP client is a fearless explorer, traversing the digital realm!
int main() {
  // Step 1: Fetch the server's address and port
  char server_addr[100];
  printf("Enter the FTP server address: ");
  scanf("%s", server_addr);
  int port = 21; // FTP's default port, like a pirate's code

  // Step 2: Set up our trusty socket, a gateway to the server
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("Socket creation failed. Time to check your compass...");
    exit(1);
  }

  // Step 3: Steer our socket towards the server's port
  struct hostent *host = gethostbyname(server_addr);
  if (host == NULL) {
    perror("Server not found. It's like searching for a treasure island that doesn't exist...");
    exit(1);
  }
  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(port);
  memcpy(&serv_addr.sin_addr, host->h_addr, host->h_length);

  // Step 4: Connect our socket to the server, like climbing aboard a pirate ship
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("Connection failed. The server's drawbridge is up!");
    exit(1);
  }

  // Yay, we're connected! Let's chat with the server using FTP commands
  char buffer[1024];
  char command[100];
  char filename[100];

  // Step 5: Greet the server in a friendly manner
  recv(sockfd, buffer, sizeof(buffer), 0);
  printf("%s", buffer); // Server's welcome message
  memset(buffer, 0, sizeof(buffer));

  // Step 6: Entrust the server with a username, like a secret handshake
  printf("Enter your username: ");
  scanf("%s", command);
  sprintf(buffer, "USER %s\r\n", command);
  send(sockfd, buffer, strlen(buffer), 0);
  memset(buffer, 0, sizeof(buffer));

  // Step 7: Prove our identity, like a spy passing a code
  printf("Enter your password: ");
  scanf("%s", command);
  sprintf(buffer, "PASS %s\r\n", command);
  send(sockfd, buffer, strlen(buffer), 0);
  memset(buffer, 0, sizeof(buffer));

  // Step 8: Time for adventure! Let's retrieve files
  while (1) {
    printf("Enter a command (LIST, RETR, QUIT): ");
    scanf("%s", command);

    // LIST: Display a treasure map of files on the server
    if (strcmp(command, "LIST") == 0) {
      send(sockfd, "LIST\r\n", strlen("LIST\r\n"), 0);
      recv(sockfd, buffer, sizeof(buffer), 0);
      printf("%s\n", buffer); // Server's response
      memset(buffer, 0, sizeof(buffer));
    }

    // RETR: Retrieve a prized file from the server's treasure chest
    else if (strcmp(command, "RETR") == 0) {
      printf("Enter the filename to retrieve: ");
      scanf("%s", filename);
      sprintf(buffer, "RETR %s\r\n", filename);
      send(sockfd, buffer, strlen(buffer), 0);
      FILE *fp = fopen(filename, "w"); // Open a file for writing
      while (recv(sockfd, buffer, sizeof(buffer), 0)) {
        fwrite(buffer, 1, strlen(buffer), fp); // Save the file contents
      }
      fclose(fp); // Close the file
      printf("File '%s' downloaded successfully!\n", filename);
      memset(buffer, 0, sizeof(buffer));
    }

    // QUIT: Bid farewell to the server, like a pirate setting sail for home
    else if (strcmp(command, "QUIT") == 0) {
      send(sockfd, "QUIT\r\n", strlen("QUIT\r\n"), 0);
      printf("Farewell! May your FTP adventures lead you to great treasures.\n");
      break;
    }

    // Unknown command? Back to the drawing board!
    else {
      printf("Invalid command. Please try again, matey!");
    }
  }

  // Step 9: Unplug the socket, like retracting the plank from a ship
  close(sockfd);
  return 0;
}