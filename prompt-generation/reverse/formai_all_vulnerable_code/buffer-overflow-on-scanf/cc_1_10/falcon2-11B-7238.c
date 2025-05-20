//Falcon2-11B DATASET v1.0 Category: Smart home light control ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <sys/ioctl.h>

// Function to get input from user
void getInput() {
    int input;
    printf("Enter input (1-10): ");
    scanf("%d", &input);
    return;
}

// Function to turn on or off light
void turnLightOn(int light) {
    int fd = open("/dev/ttyS0", O_RDWR); // Open serial port
    if (fd < 0) {
        perror("Error opening serial port");
        exit(EXIT_FAILURE);
    }

    // Set serial port to 115200 baud rate and 8 data bits
    struct termios options;
    tcgetattr(fd, &options);
    options.c_cflag |= (CLOCAL | CREAD); // Ignore ctrl-s and ctrl-q
    options.c_cflag &= ~CSIZE; // Use 8 data bits
    options.c_cflag |= CS8;
    options.c_cflag &= ~PARENB; // No parity bit
    options.c_cflag &= ~CSTOPB; // No stop bit
    options.c_cflag |= CREAD | CLOCAL;
    options.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL);
    options.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
    options.c_oflag &= ~OPOST;
    tcsetattr(fd, TCSANOW, &options);

    int command = 0;
    if (light == 1) {
        command |= 1; // Turn on light
    } else {
        command |= 2; // Turn off light
    }
    write(fd, &command, 1);
    close(fd);

    return;
}

int main() {
    int light = 0; // Default light state
    int input;

    while (1) {
        getInput();
        turnLightOn(light);
        printf("Light turned on or off.\n");
        sleep(1);
    }

    return 0;
}