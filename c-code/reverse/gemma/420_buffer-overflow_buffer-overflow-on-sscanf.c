#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main() {
  char pasv_response[] = "PASV 212,10,10,10";
  int data_port;
  sscanf(pasv_response, "PASV %d,%,%,%", &data_port);
  printf("Data port: %d\n", data_port);
  return 0;
}
