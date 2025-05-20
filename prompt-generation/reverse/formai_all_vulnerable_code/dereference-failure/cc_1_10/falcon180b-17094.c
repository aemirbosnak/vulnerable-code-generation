//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>

#define BAUDRATE B115200
#define DEV_TTYS0 "/dev/ttyS0"

int main(int argc, char *argv[]) {
    int fd;
    struct termios options;

    fd = open(DEV_TTYS0, O_RDWR | O_NOCTTY | O_NDELAY);

    if (fd < 0) {
        printf("Error opening %s: %s\n", DEV_TTYS0, strerror(errno));
        exit(1);
    }

    memset(&options, 0, sizeof(options));
    options.c_cflag = BAUDRATE | CS8 | CLOCAL | CREAD;
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    options.c_cc[VMIN] = 1;
    options.c_cc[VTIME] = 10;

    if (tcsetattr(fd, TCSANOW, &options)!= 0) {
        printf("Error setting termios: %s\n", strerror(errno));
        exit(1);
    }

    char *command = "AT\r";
    write(fd, command, strlen(command));

    char buffer[1024];
    int bytes_read = read(fd, buffer, sizeof(buffer));

    if (bytes_read <= 0) {
        printf("Error reading from %s: %s\n", DEV_TTYS0, strerror(errno));
        exit(1);
    }

    printf("Received: %s", buffer);

    close(fd);

    return 0;
}