//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <termios.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/select.h>

#define BAUDRATE B9600
#define DEVICE "/dev/ttyUSB0"

int main()
{
    int fd;
    struct termios options;
    fd_set readfds;
    char buffer[1024];
    int retval;

    fd = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1)
    {
        perror(DEVICE);
        exit(1);
    }

    if (tcgetattr(fd, &options)!= 0)
    {
        perror("tcgetattr");
        exit(1);
    }

    cfsetispeed(&options, BAUDRATE);
    cfsetospeed(&options, BAUDRATE);

    options.c_cflag |= CLOCAL | CREAD;
    options.c_cflag &= ~(PARENB | PARODD | CSIZE | CSTOPB);
    options.c_cflag |= CS8;
    options.c_iflag &= ~(IXON | IXOFF | IXANY);
    options.c_oflag &= ~OPOST;

    tcsetattr(fd, TCSANOW, &options);

    FD_ZERO(&readfds);
    FD_SET(fd, &readfds);

    while (1)
    {
        retval = select(fd + 1, &readfds, NULL, NULL, NULL);

        if (retval == -1)
        {
            perror("select");
            exit(1);
        }

        if (FD_ISSET(fd, &readfds))
        {
            retval = read(fd, buffer, 1024);

            if (retval == -1)
            {
                perror("read");
                exit(1);
            }

            buffer[retval] = '\0';
            printf("Received: %s\n", buffer);
        }
    }

    close(fd);
    return 0;
}