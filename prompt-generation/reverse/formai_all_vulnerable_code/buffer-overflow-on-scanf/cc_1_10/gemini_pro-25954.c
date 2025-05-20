//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

int main(int argc, char **argv)
{
    int fd = -1;
    struct termios tios;
    char buf[64];
    int x = 0, y = 0, z = 0, r = 0;

    // Open the serial port
    fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    // Get the current termios settings
    tcgetattr(fd, &tios);

    // Set the baud rate to 9600
    cfsetispeed(&tios, B9600);
    cfsetospeed(&tios, B9600);

    // Set the stop bits to 1
    tios.c_cflag &= ~CSTOPB;

    // Set the parity to none
    tios.c_cflag &= ~PARENB;

    // Set the data bits to 8
    tios.c_cflag &= ~CSIZE;
    tios.c_cflag |= CS8;

    // Set the local mode
    tios.c_lflag |= ICANON;
    tios.c_lflag &= ~ECHO;

    // Set the timeout to 100 milliseconds
    tios.c_cc[VTIME] = 1;
    tios.c_cc[VMIN] = 0;

    // Set the termios settings
    tcsetattr(fd, TCSANOW, &tios);

    // Loop forever
    while (1) {
        // Read the input from the user
        printf("Enter the x, y, z, and r values (separated by spaces): ");
        scanf("%d %d %d %d", &x, &y, &z, &r);

        // Send the input to the drone
        sprintf(buf, "%d %d %d %d\n", x, y, z, r);
        write(fd, buf, strlen(buf));

        // Read the response from the drone
        read(fd, buf, sizeof(buf));

        // Print the response from the drone
        printf("%s", buf);
    }

    // Close the serial port
    close(fd);

    return 0;
}