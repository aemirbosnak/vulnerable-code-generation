//Code Llama-13B DATASET v1.0 Category: Port Scanner ; Style: immersive
/*
 * 🔍 Unique C Port Scanner 🔍
 *
 * A program that scans a network for open ports and displays the results.
 *
 * Usage:
 *  $ gcc port_scanner.c -o port_scanner
 *  $ ./port_scanner <IP_ADDRESS>
 *
 * Example:
 *  $ ./port_scanner 192.168.1.1
 *  Open ports: 22, 80
 *
 * Compatible with:
 *  - Linux
 *  - macOS
 *  - Windows
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT_RANGE 1024

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("Usage: %s <IP_ADDRESS>\n", argv[0]);
    return 1;
  }

  char *ip_address = argv[1];
  char *open_ports = "";

  for (int port = 0; port < PORT_RANGE; port++) {
    struct sockaddr_in address;
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0) {
      perror("socket");
      exit(1);
    }

    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    inet_pton(AF_INET, ip_address, &address.sin_addr);

    if (connect(sock, (struct sockaddr *)&address, sizeof(address)) < 0) {
      close(sock);
      continue;
    }

    close(sock);
    open_ports = strcat(open_ports, ", ");
    open_ports = strcat(open_ports, port);
  }

  if (strlen(open_ports) > 0) {
    open_ports = open_ports + 2;
  }

  printf("Open ports: %s\n", open_ports);

  return 0;
}