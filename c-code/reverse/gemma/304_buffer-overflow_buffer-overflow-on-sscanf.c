#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>

int main() {
  char buffer[10];
  char ip[16];
  int port;

  FILE *fp = fopen("ftp.txt", "r");
  fscanf(fp, "%s %d", ip, &port);
  fclose(fp);

  sprintf(buffer, "CONNECT %s:%d", ip, port);
  system(buffer);

  return 0;
}
