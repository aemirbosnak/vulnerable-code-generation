#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main() {
  char buf[1024];
  int len = read(0, buf, 1024);
  buf[len - 1] = '\0';

  int req_len = atoi(buf);
  int req_body_len = atoi(buf + req_len);

  char *req_body = malloc(req_body_len);
  read(0, req_body, req_body_len);

  printf("Request Length: %d\n", req_len);
  printf("Request Body Length: %d\n", req_body_len);
  printf("Request Body: %s\n", req_body);

  free(req_body);
  return 0;
}
