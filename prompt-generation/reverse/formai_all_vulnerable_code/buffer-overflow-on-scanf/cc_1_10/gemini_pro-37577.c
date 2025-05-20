//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <signal.h>

static bool running = true;

void handle_sigint(int signum) {
    running = false;
}

int main(void) {
    signal(SIGINT, handle_sigint);

    int fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_SYNC);
    if (fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    struct termios settings;
    if (tcgetattr(fd, &settings) == -1) {
        perror("tcgetattr");
        close(fd);
        return EXIT_FAILURE;
    }

    settings.c_cflag |= (CLOCAL | CREAD);
    settings.c_cflag &= ~(PARENB | CSTOPB | CSIZE | CRTSCTS);
    settings.c_cflag &= ~CSIZE;
    settings.c_cflag |= CS8;
    settings.c_iflag &= ~(INPCK | ISTRIP | INLCR | IGNCR | ICRNL | IXON | IXOFF | IXANY);
    settings.c_oflag &= ~(OPOST | ONLCR);
    settings.c_lflag &= ~(ISIG | ICANON | ECHO | ECHOE | ECHOK | ECHONL);

    if (tcsetattr(fd, TCSANOW, &settings) == -1) {
        perror("tcsetattr");
        close(fd);
        return EXIT_FAILURE;
    }

    while (running) {
        char command;
        scanf(" %c", &command);
        switch (command) {
            case 'w':
                write(fd, "forward", 7);
                break;
            case 'a':
                write(fd, "left", 5);
                break;
            case 's':
                write(fd, "backward", 8);
                break;
            case 'd':
                write(fd, "right", 6);
                break;
            case 'q':
                running = false;
                break;
            default:
                printf("Invalid command\n");
                break;
        }
        usleep(100000);
    }

    close(fd);
    return EXIT_SUCCESS;
}