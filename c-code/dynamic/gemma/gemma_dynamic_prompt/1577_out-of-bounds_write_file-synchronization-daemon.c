#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
  int fd = open("/etc/passwd", O_WRONLY);
  if (fd == -1) {
    return 1;
  }

  char buf[1024] = "Hello, world!";
  if (write(fd, buf, 1024) == -1) {
    return 1;
  }

  close(fd);
  return 0;
}
