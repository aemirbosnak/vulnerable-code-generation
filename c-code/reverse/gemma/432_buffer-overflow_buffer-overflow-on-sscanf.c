#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[10] = "192.168.1.1:21";
  char ip[16] = "";
  int port = 0;

  sscanf(buffer, "PASV %s:%d", ip, &port);

  printf("IP: %s, Port: %d", ip, port);

  return 0;
}
