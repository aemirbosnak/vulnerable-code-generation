//MISTRAL-7B DATASET v1.0 Category: Smart home light control ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <stdlib.h>
#include <sys/select.h>
#include <time.h>

#define SERIAL_PORT "/dev/ttyUSB0"
#define BAUD_RATE 9600
#define MAX_LEN 100

struct termios old_settings, new_settings;
int fd;

void setupSerial() {
    tcgetattr(fd, &old_settings);
    new_settings = old_settings;

    cfsetispeed(&new_settings, BAUD_RATE);
    cfsetospeed(&new_settings, BAUD_RATE);

    new_settings.c_cflag &= ~PARENB;
    new_settings.c_cflag &= ~CSTOPB;
    new_settings.c_cflag &= ~CSIZE;
    new_settings.c_cflag |= CS8;

    new_settings.c_cflag |= (1 << CREAD);
    new_settings.c_cflag |= (1 << CLOCAL);
    new_settings.c_cflag &= ~CRTSCTS;

    new_settings.c_iflag &= ~(IXON | IXOFF | IXANY);
    new_settings.c_iflag &= ~(ICANON | ECHO | ECHOE | ISIG);

    tcsetattr(fd, TCSANOW, &new_settings);
}

void sendCommand(char *command) {
    write(fd, command, strlen(command) + 1);
}

int readSerial() {
    fd_set read_fds;
    struct timeval timeout;
    char buffer[MAX_LEN];
    int result = 0;

    FD_ZERO(&read_fds);
    FD_SET(fd, &read_fds);
    timeout.tv_sec = 0;
    timeout.tv_usec = 50;

    result = select(fd + 1, &read_fds, NULL, NULL, &timeout);

    if (result > 0) {
        int bytes = read(fd, buffer, MAX_LEN);
        if (bytes > 0) {
            printf("Received: %s\n", buffer);
            // process the received data here
        }
    }
}

void controlLight(int lightNumber, int state) {
    char command[MAX_LEN];
    sprintf(command, "L%d %s\r", lightNumber, state ? "ON" : "OFF");
    sendCommand(command);
}

int main() {
    fd = open(SERIAL_PORT, O_RDWR | O_NOCTTY);
    if (fd < 0) {
        perror("Failed to open serial port.");
        exit(1);
    }

    setupSerial();

    int lights[] = {1, 2, 3};
    int numLights = sizeof(lights) / sizeof(int);

    while (1) {
        for (int i = 0; i < numLights; i++) {
            controlLight(lights[i], !!(rand() % 2));
            usleep(500000); // sleep for 500ms
        }
        readSerial();
    }

    close(fd);

    return 0;
}