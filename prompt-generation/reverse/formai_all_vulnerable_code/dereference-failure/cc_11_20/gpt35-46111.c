//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: decentralized
// C Simple HTTP Proxy Example Program (Decentralized)

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[])
{
  int local_port, dest_port, sock_fd, new_sock_fd, cli_len, n;
  char proxy_buffer[BUFFER_SIZE], server_buffer[BUFFER_SIZE];
  struct sockaddr_in proxy_addr, server_addr, cli_addr;
  struct hostent *server;

  // Check for correct number of arguments
  if (argc != 3)
  {
    fprintf(stderr, "Usage: %s <local port> <destination port>\n", argv[0]);
    exit(1);
  }

  // Get local port and destination port from arguments
  local_port = atoi(argv[1]);
  dest_port = atoi(argv[2]);

  // Create socket for proxy server
  sock_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (sock_fd < 0)
  {
    perror("ERROR opening socket");
    exit(1);
  }

  // Initialize proxy server address struct
  bzero((char *) &proxy_addr, sizeof(proxy_addr));
  proxy_addr.sin_family = AF_INET;
  proxy_addr.sin_addr.s_addr = INADDR_ANY;
  proxy_addr.sin_port = htons(local_port);

  // Bind socket to local address and port
  if (bind(sock_fd, (struct sockaddr *) &proxy_addr, sizeof(proxy_addr)) < 0) 
  {
    perror("ERROR on binding");
    exit(1);
  }

  printf("Proxy server started on port %d\n", local_port);

  // Start listening for incoming connections
  listen(sock_fd, 5);
  cli_len = sizeof(cli_addr);

  while (1)
  {
    // Wait for incoming connection
    new_sock_fd = accept(sock_fd, (struct sockaddr *) &cli_addr, &cli_len);
    if (new_sock_fd < 0)
    {
      perror("ERROR on accept");
      exit(1);
    }

    // Create a new process for handling the client request
    if (fork() == 0) 
    {
      // Close original socket
      close(sock_fd);

      // Read client request
      bzero(proxy_buffer, BUFFER_SIZE);
      n = read(new_sock_fd, proxy_buffer, BUFFER_SIZE);
      if (n < 0)
      {
        perror("ERROR reading from client");
        exit(1);
      }

      // Extract destination host from request
      char *host_start, *host_end;
      host_start = strstr(proxy_buffer, "Host: ") + 6;
      host_end = strstr(host_start, "\r\n");
      char dest_host[host_end - host_start + 1];
      strncpy(dest_host, host_start, host_end - host_start);
      dest_host[host_end - host_start] = '\0';

      printf("Request for %s\n", dest_host);

      // Get destination host IP address
      server = gethostbyname(dest_host);
      if (server == NULL) 
      {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
      }

      // Initialize server address struct
      bzero((char *) &server_addr, sizeof(server_addr));
      server_addr.sin_family = AF_INET;
      bcopy((char *)server->h_addr, 
            (char *)&server_addr.sin_addr.s_addr,
            server->h_length);
      server_addr.sin_port = htons(dest_port);

      // Create socket for connection to destination host
      int server_sock_fd = socket(AF_INET, SOCK_STREAM, 0);
      if (server_sock_fd < 0)
      {
        perror("ERROR opening socket");
        exit(1);
      }

      // Connect to destination host
      if (connect(server_sock_fd,(struct sockaddr *) &server_addr,sizeof(server_addr)) < 0) 
      {
        perror("ERROR connecting");
        exit(1);
      }

      // Forward client request to destination server
      n = write(server_sock_fd, proxy_buffer, strlen(proxy_buffer));
      if (n < 0)
      {
        perror("ERROR writing to server");
        exit(1);
      }

      // Forward server response to client
      while (1)
      {
        bzero(server_buffer, BUFFER_SIZE);
        n = read(server_sock_fd, server_buffer, BUFFER_SIZE);
        if (n <= 0)
        {
          break;
        }
        n = write(new_sock_fd, server_buffer, n);
        if (n < 0)
        {
          perror("ERROR writing to client");
          exit(1);
        }
      }

      // Close client and server sockets
      close(new_sock_fd);
      close(server_sock_fd);
      exit(0);
    }
    else 
    {
      // Close new socket in parent process
      close(new_sock_fd);
    }
  }

  return 0; 
}