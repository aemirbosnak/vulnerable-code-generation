//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024
#define MAX_HOST_LENGTH 256

int main(int argc, char **argv) {
  int sock = 0;
  struct sockaddr_in server_addr;
  struct hostent *server_host;
  char *host_name = NULL;
  char *port_name = NULL;
  int port_number = 0;

  if (argc < 2) {
    printf("Usage: %s <host_name>\n", argv[0]);
    return 1;
  }

  host_name = argv[1];

  // Initialize socket
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("Socket creation failed");
    exit(1);
  }

  // Set up server address
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(0);
  server_addr.sin_addr.s_addr = inet_addr(host_name);

  // Resolve host address
  server_host = gethostbyname(host_name);
  if (server_host == NULL) {
    perror("Host name resolution failed");
    exit(1);
  }

  // Set up port number
  port_number = atoi(port_name);
  if (port_number < 0 || port_number > PORT_RANGE) {
    printf("Invalid port number: %d\n", port_number);
    exit(1);
  }

  // Connect to server
  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Connect failed");
    exit(1);
  }

  // Scan for open ports
  for (int i = 0; i < PORT_RANGE; i++) {
    // Create a socket for the current port
    int curr_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (curr_sock < 0) {
      perror("Socket creation failed");
      exit(1);
    }

    // Set up current port address
    server_addr.sin_port = htons(i);

    // Connect to the current port
    if (connect(curr_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
      perror("Connect failed");
      exit(1);
    }

    // Send a packet and receive a response
    char send_buf[1024];
    char recv_buf[1024];
    send_buf[0] = 'A';
    send_buf[1] = 'B';
    send_buf[2] = 'C';
    send_buf[3] = 'D';
    send_buf[4] = 'E';
    send_buf[5] = 'F';
    send_buf[6] = 'G';
    send_buf[7] = 'H';
    send_buf[8] = 'I';
    send_buf[9] = 'J';
    send_buf[10] = 'K';
    send_buf[11] = 'L';
    send_buf[12] = 'M';
    send_buf[13] = 'N';
    send_buf[14] = 'O';
    send_buf[15] = 'P';
    send_buf[16] = 'Q';
    send_buf[17] = 'R';
    send_buf[18] = 'S';
    send_buf[19] = 'T';
    send_buf[20] = 'U';
    send_buf[21] = 'V';
    send_buf[22] = 'W';
    send_buf[23] = 'X';
    send_buf[24] = 'Y';
    send_buf[25] = 'Z';
    send_buf[26] = '\0';

    recv_buf[0] = '\0';

    send(curr_sock, send_buf, 26, 0);
    recv(curr_sock, recv_buf, 26, 0);

    // Check for errors
    if (recv_buf[0] == '\0') {
      perror("Recv failed");
      exit(1);
    }

    // Print the port number and host name
    printf("Port %d open on %s\n", i, host_name);

    // Close the current socket
    close(curr_sock);
  }

  // Close the original socket
  close(sock);

  return 0;
}