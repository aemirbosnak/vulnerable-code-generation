//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

#define BAUDRATE B115200
#define DATABITS CS8
#define STOPBITS 1

#define MIN_THRUST -100
#define MAX_THRUST 100
#define MIN_SPEED -100
#define MAX_SPEED 100
#define MIN_TILT -100
#define MAX_TILT 100

typedef struct {
  int thrust;
  int speed;
  int tilt;
} command_t;

void usage(char *progname)
{
  printf("Usage: %s <device>\n", progname);
  printf("  <device> is the serial device to which the drone is connected\n");
}

int main(int argc, char *argv[])
{
  if (argc != 2) {
    usage(argv[0]);
    return 1;
  }

  int fd;
  struct termios tio;

  fd = open(argv[1], O_RDWR | O_NOCTTY);
  if (fd < 0) {
    perror("open");
    return 1;
  }

  if (tcgetattr(fd, &tio) < 0) {
    perror("tcgetattr");
    return 1;
  }

  tio.c_cflag = BAUDRATE | DATABITS | STOPBITS | CLOCAL | CREAD;
  tio.c_lflag = 0;
  tio.c_oflag = 0;
  tio.c_iflag = 0;

  if (tcsetattr(fd, TCSANOW, &tio) < 0) {
    perror("tcsetattr");
    return 1;
  }

  command_t command;

  while (1) {
    printf("Enter thrust, speed, and tilt (space-separated): ");
    if (scanf("%d %d %d", &command.thrust, &command.speed, &command.tilt) != 3) {
      printf("Invalid input\n");
      continue;
    }

    if (command.thrust < MIN_THRUST || command.thrust > MAX_THRUST) {
      printf("Thrust must be between %d and %d\n", MIN_THRUST, MAX_THRUST);
      continue;
    }

    if (command.speed < MIN_SPEED || command.speed > MAX_SPEED) {
      printf("Speed must be between %d and %d\n", MIN_SPEED, MAX_SPEED);
      continue;
    }

    if (command.tilt < MIN_TILT || command.tilt > MAX_TILT) {
      printf("Tilt must be between %d and %d\n", MIN_TILT, MAX_TILT);
      continue;
    }

    if (write(fd, &command, sizeof(command)) < 0) {
      perror("write");
      return 1;
    }
  }

  return 0;
}