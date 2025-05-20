//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/select.h>
#include <sys/time.h>

#define BAUDRATE B9600
#define DEVICE_PATH "/dev/ttyUSB0"

int main() {
    int fd;
    struct termios options;

    fd = open(DEVICE_PATH, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    if (tcgetattr(fd, &options)!= 0) {
        perror("tcgetattr");
        exit(2);
    }

    cfsetispeed(&options, BAUDRATE);
    cfsetospeed(&options, BAUDRATE);

    options.c_cflag |= (CLOCAL | CREAD);
    options.c_cflag &= ~(CSIZE | PARENB);
    options.c_cflag |= CS8;
    options.c_cflag |= CRTSCTS;
    options.c_iflag |= (IGNBRK | IGNPAR);
    options.c_oflag = 0;
    options.c_lflag = 0;

    if (tcsetattr(fd, TCSANOW, &options)!= 0) {
        perror("tcsetattr");
        exit(3);
    }

    char *command = "AT\r";
    write(fd, command, strlen(command));

    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(fd, &readfds);

    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;

    int ret = select(fd + 1, &readfds, NULL, NULL, &tv);
    if (ret == -1) {
        perror("select");
        exit(4);
    }

    if (FD_ISSET(fd, &readfds)) {
        char buffer[100];
        int bytes_read = read(fd, buffer, sizeof(buffer));
        if (bytes_read <= 0) {
            perror("read");
            exit(5);
        }
        buffer[bytes_read - 1] = '\0';
        printf("Received: %s", buffer);
    }

    close(fd);
    return 0;
}