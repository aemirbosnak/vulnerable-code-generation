//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <sys/select.h>

#define DEV_TTYS0 "/dev/ttyS0"
#define BAUD_RATE B115200

int main() {
    int fd;
    struct termios options;

    // Open the serial port
    fd = open(DEV_TTYS0, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) {
        printf("Error opening serial port\n");
        return 1;
    }

    // Configure the serial port
    tcgetattr(fd, &options);
    cfsetispeed(&options, BAUD_RATE);
    cfsetospeed(&options, BAUD_RATE);
    options.c_cflag |= CS8 | CREAD | CLOCAL;
    options.c_iflag |= IGNPAR;
    options.c_oflag = 0;
    tcsetattr(fd, TCSANOW, &options);

    // Main loop
    char buffer[1024];
    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(fd, &readfds);

    while (1) {
        select(fd + 1, &readfds, NULL, NULL, NULL);

        if (FD_ISSET(fd, &readfds)) {
            int bytes_read = read(fd, buffer, sizeof(buffer));
            if (bytes_read > 0) {
                buffer[bytes_read] = '\0';
                printf("Received: %s", buffer);
            }
        }
    }

    close(fd);
    return 0;
}