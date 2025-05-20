//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <string.h>
#include <math.h>

#define SPEED 9600
#define PORT "/dev/ttyAMA0"

int main()
{
    int fd, c, i;
    struct termios tty;

    fd = open(PORT, O_RDWR | O_NOCTTY);
    if (fd < 0) {
        perror("open");
        return -1;
    }

    tcgetattr(fd, &tty);
    cfsetispeed(&tty, SPEED);
    cfsetospeed(&tty, SPEED);
    tty.c_cflag |= (CLOCAL | CREAD);
    tty.c_cflag &= ~PARENB;
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;
    tty.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
    tty.c_oflag &= ~OPOST;
    tcsetattr(fd, TCSANOW, &tty);

    printf("Remote control vehicle simulation\n");
    printf("Commands:\n");
    printf("w: forward\n");
    printf("a: left\n");
    printf("d: right\n");
    printf("s: stop\n");
    printf("q: quit\n");
    
    while (c != 'q') {
        //c = getchar();
        scanf("%c", &c);
        switch (c) {
            case 'w':
                printf("Forward\n");
                for (i = 0; i < 100; i++) {
                    write(fd, "w", 1);
                    usleep(10000);
                }
                break;
            case 'a':
                printf("Left\n");
                for (i = 0; i < 100; i++) {
                    write(fd, "a", 1);
                    usleep(10000);
                }
                break;
            case 'd':
                printf("Right\n");
                for (i = 0; i < 100; i++) {
                    write(fd, "d", 1);
                    usleep(10000);
                }
                break;
            case 's':
                printf("Stop\n");
                write(fd, "s", 1);
                break;
            case 'q':
                printf("Quit\n");
                break;
            default:
                printf("Invalid command\n");
                break;
        }
    }

    close(fd);
}