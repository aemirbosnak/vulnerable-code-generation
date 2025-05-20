//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BAUDRATE B9600
#define DEVICE "/dev/ttyUSB0"

int main() {
    int fd;
    struct termios options;

    fd = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) {
        printf("Error opening %s: %s\n", DEVICE, strerror(errno));
        return 1;
    }

    memset(&options, 0, sizeof(options));
    options.c_cflag = BAUDRATE | CS8 | CREAD | CLOCAL;
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    options.c_cc[VTIME] = 5;
    options.c_cc[VMIN] = 0;

    if (tcsetattr(fd, TCSANOW, &options)!= 0) {
        printf("Error setting attributes for %s: %s\n", DEVICE, strerror(errno));
        return 1;
    }

    char command[10];
    sprintf(command, "AT\r");
    write(fd, command, strlen(command));

    char response[100];
    int bytes_read = read(fd, response, sizeof(response));
    if (bytes_read <= 0) {
        printf("Error reading from %s: %s\n", DEVICE, strerror(errno));
        return 1;
    }

    response[bytes_read - 1] = '\0';
    printf("Response: %s\n", response);

    close(fd);
    return 0;
}