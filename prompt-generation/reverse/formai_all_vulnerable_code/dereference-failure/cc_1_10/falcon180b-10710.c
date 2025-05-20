//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <errno.h>

#define BAUDRATE B9600
#define MODEMDEVICE "/dev/ttyUSB0"

int main() {
    int fd;
    struct termios options;

    // Open the serial port
    fd = open(MODEMDEVICE, O_RDWR | O_NOCTTY);
    if (fd == -1) {
        printf("Error opening %s: %s\n", MODEMDEVICE, strerror(errno));
        return 1;
    }

    // Get the current options for the serial port
    if (tcgetattr(fd, &options)!= 0) {
        printf("Error tcgetattr: %s\n", strerror(errno));
        return 1;
    }

    // Set the baud rate
    cfsetispeed(&options, BAUDRATE);
    cfsetospeed(&options, BAUDRATE);

    // Set the serial port options
    options.c_cflag = CS8 | CLOCAL | CREAD;
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;

    // Set the input mode flags
    options.c_iflag |= INPCK | ISTRIP;

    // Set the output mode flags
    options.c_oflag |= OPOST;

    // Set the control mode flags
    options.c_cflag |= CREAD | CLOCAL;

    // Set the local mode flags
    options.c_lflag |= ECHO | ECHOE | ISIG;

    // Set the new options for the serial port
    if (tcsetattr(fd, TCSANOW, &options)!= 0) {
        printf("Error tcsetattr: %s\n", strerror(errno));
        return 1;
    }

    // Read data from the serial port
    char buffer[1024];
    int bytes_read;
    while (1) {
        bytes_read = read(fd, buffer, sizeof(buffer));
        if (bytes_read <= 0) {
            printf("Error reading from %s: %s\n", MODEMDEVICE, strerror(errno));
            return 1;
        }
        buffer[bytes_read] = '\0';
        printf("Received: %s\n", buffer);
    }

    // Close the serial port
    close(fd);
    return 0;
}