//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: future-proof
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>

#define BAUDRATE B115200
#define DEVICE "/dev/ttyUSB0"
#define PACKET_SIZE 16

int main() {
  int fd;
  struct termios options;
  char packet[PACKET_SIZE];

  memset(&options, 0, sizeof(options));
  options.c_cflag = BAUDRATE | CS8 | CLOCAL | CREAD;
  options.c_iflag = IGNPAR | ICRNL;
  options.c_oflag = 0;
  options.c_lflag = 0;

  fd = open(DEVICE, O_RDWR | O_NOCTTY);
  if (fd == -1) {
    perror("open");
    return EXIT_FAILURE;
  }

  if (tcsetattr(fd, TCSANOW, &options) == -1) {
    perror("tcsetattr");
    close(fd);
    return EXIT_FAILURE;
  }

  while (1) {
    printf("Enter a command (w, a, s, d, q): ");
    scanf("%s", packet);

    if (strcmp(packet, "w") == 0) {
      packet[0] = 'F';
    } else if (strcmp(packet, "a") == 0) {
      packet[0] = 'L';
    } else if (strcmp(packet, "s") == 0) {
      packet[0] = 'B';
    } else if (strcmp(packet, "d") == 0) {
      packet[0] = 'R';
    } else if (strcmp(packet, "q") == 0) {
      break;
    } else {
      printf("Invalid command\n");
      continue;
    }

    if (write(fd, packet, PACKET_SIZE) == -1) {
      perror("write");
      close(fd);
      return EXIT_FAILURE;
    }

    if (read(fd, packet, PACKET_SIZE) == -1) {
      perror("read");
      close(fd);
      return EXIT_FAILURE;
    }

    printf("Received: %s\n", packet);
  }

  close(fd);
  return EXIT_SUCCESS;
}