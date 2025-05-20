//Code Llama-13B DATASET v1.0 Category: Building a SMTP Client ; Style: satisfied
#include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <unistd.h>
  #include <sys/socket.h>
  #include <sys/types.h>
  #include <netinet/in.h>
  #include <arpa/inet.h>
  #include <netdb.h>

  #define MAXDATASIZE 1024

  void build_smtp_client(char *address, char *port, char *recipient, char *message) {
    int sock;
    struct sockaddr_in server_addr;
    struct hostent *server;

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
      perror("Could not create socket");
      exit(1);
    }

    // Get the server address
    server = gethostbyname(address);
    if (server == NULL) {
      fprintf(stderr, "Could not get host address\n");
      exit(1);
    }

    // Fill in the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *((struct in_addr *)server->h_addr);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
      perror("Could not connect to server");
      exit(1);
    }

    // Send the email message
    send(sock, message, strlen(message), 0);

    // Close the socket
    close(sock);
  }

  int main(int argc, char *argv[]) {
    char *address = "smtp.example.com";
    char *port = "25";
    char *recipient = "recipient@example.com";
    char *message = "Subject: Test email\n\nHello, this is a test email.";

    build_smtp_client(address, port, recipient, message);

    return 0;
  }