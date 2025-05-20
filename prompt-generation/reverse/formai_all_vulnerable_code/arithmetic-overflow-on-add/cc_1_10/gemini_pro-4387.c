//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <sys/select.h>
#include <fcntl.h>

#define SERDEV "/dev/ttyS0"
#define BAUDRATE B115200

int main() {
    int fd;
    struct termios tio;

    // Open serial port
    fd = open(SERDEV, O_RDWR | O_NOCTTY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    // Set serial port attributes
    tcgetattr(fd, &tio);
    cfsetispeed(&tio, BAUDRATE);
    cfsetospeed(&tio, BAUDRATE);
    tio.c_cflag |= (CLOCAL | CREAD);
    tio.c_cflag &= ~PARENB;
    tio.c_cflag &= ~CSTOPB;
    tio.c_cflag &= ~CSIZE;
    tio.c_cflag |= CS8;
    tio.c_lflag &= ~ICANON;
    tio.c_lflag &= ~ECHO;
    tcsetattr(fd, TCSANOW, &tio);

    // Main loop
    while (1) {
        fd_set rfds;
        FD_ZERO(&rfds);
        FD_SET(fd, &rfds);

        int n = select(fd+1, &rfds, NULL, NULL, NULL);
        if (n < 0) {
            perror("select");
            return 1;
        }

        if (FD_ISSET(fd, &rfds)) {
            unsigned char buf[16];
            int n = read(fd, buf, sizeof(buf));
            if (n > 0) {
                // Process data
                printf("Received %d bytes: ", n);
                for (int i = 0; i < n; i++) {
                    printf("%02X ", buf[i]);
                }
                printf("\n");
            } else if (n == 0) {
                // Connection closed
                printf("Connection closed\n");
                return 0;
            } else {
                // Error
                perror("read");
                return 1;
            }
        }
    }

    return 0;
}