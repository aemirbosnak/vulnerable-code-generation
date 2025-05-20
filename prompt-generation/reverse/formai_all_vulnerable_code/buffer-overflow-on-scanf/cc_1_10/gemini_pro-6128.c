//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

#define BAUDRATE B115200
#define DEVICE "/dev/ttyUSB0"

struct rc_car {
    int fd;
    struct termios oldtio;
};

void rc_car_init(struct rc_car *car)
{
    car->fd = open(DEVICE, O_RDWR | O_NOCTTY);
    if (car->fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    struct termios newtio;
    tcgetattr(car->fd, &car->oldtio);
    newtio = car->oldtio;

    newtio.c_cflag = BAUDRATE | CS8 | CLOCAL | CREAD;
    newtio.c_iflag = IGNPAR;
    newtio.c_oflag = 0;
    newtio.c_lflag = 0;

    tcflush(car->fd, TCIFLUSH);
    tcsetattr(car->fd, TCSANOW, &newtio);
}

void rc_car_cleanup(struct rc_car *car)
{
    tcsetattr(car->fd, TCSANOW, &car->oldtio);
    close(car->fd);
}

void rc_car_send_command(struct rc_car *car, char *command)
{
    int len = strlen(command);
    write(car->fd, command, len);
}

int main(void)
{
    struct rc_car car;
    rc_car_init(&car);

    while (1) {
        char command[10];
        printf("> ");
        scanf("%s", command);

        rc_car_send_command(&car, command);
    }

    rc_car_cleanup(&car);

    return 0;
}