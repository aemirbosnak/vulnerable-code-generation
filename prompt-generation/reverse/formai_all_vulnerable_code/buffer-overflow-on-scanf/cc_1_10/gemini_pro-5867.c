//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <string.h>

// Romeo and Juliet style
#define RC_FORWARD "ON FWD"
#define RC_BACKWARD "ON BWD"
#define RC_LEFT "ON L"
#define RC_RIGHT "ON R"
#define RC_STOP "ON E"

int main() {
  int fd;
  struct termios oldtio, newtio;
  char buf[255];

  // Open the serial port
  fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY);
  if (fd < 0) {
    perror("open");
    return -1;
  }

  // Get the current serial port settings
  tcgetattr(fd, &oldtio);

  // Set the new serial port settings
  memset(&newtio, 0, sizeof(newtio));
  newtio.c_cflag = B9600 | CS8 | CLOCAL | CREAD;
  newtio.c_iflag = IGNPAR;
  newtio.c_oflag = 0;
  newtio.c_lflag = 0;
  newtio.c_cc[VMIN] = 1;
  newtio.c_cc[VTIME] = 0;

  // Apply the new serial port settings
  tcsetattr(fd, TCSANOW, &newtio);

  // Send the RC commands
  while (1) {
    printf("Enter a command (forward, backward, left, right, stop): ");
    scanf("%s", buf);

    if (strcmp(buf, RC_FORWARD) == 0) {
      write(fd, RC_FORWARD, strlen(RC_FORWARD));
    } else if (strcmp(buf, RC_BACKWARD) == 0) {
      write(fd, RC_BACKWARD, strlen(RC_BACKWARD));
    } else if (strcmp(buf, RC_LEFT) == 0) {
      write(fd, RC_LEFT, strlen(RC_LEFT));
    } else if (strcmp(buf, RC_RIGHT) == 0) {
      write(fd, RC_RIGHT, strlen(RC_RIGHT));
    } else if (strcmp(buf, RC_STOP) == 0) {
      write(fd, RC_STOP, strlen(RC_STOP));
    } else {
      printf("Invalid command.\n");
    }
  }

  // Restore the old serial port settings
  tcsetattr(fd, TCSANOW, &oldtio);

  // Close the serial port
  close(fd);

  return 0;
}