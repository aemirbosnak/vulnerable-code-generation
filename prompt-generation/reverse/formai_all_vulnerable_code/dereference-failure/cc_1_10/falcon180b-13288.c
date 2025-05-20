//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>

#define BAUDRATE B9600
#define DEV "/dev/ttyUSB0"

int fd;
struct termios options;

void init(void)
{
    fd = open(DEV, O_RDWR | O_NOCTTY | O_NDELAY);

    if (fd < 0)
    {
        printf("Error opening %s: %s\n", DEV, strerror(errno));
        exit(1);
    }

    memset(&options, 0, sizeof(options));

    options.c_cflag = BAUDRATE | CS8 | CREAD | CLOCAL;
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    options.c_cc[VMIN] = 1;
    options.c_cc[VTIME] = 10;

    tcsetattr(fd, TCSANOW, &options);
}

int main(void)
{
    init();

    char buffer[100];

    while (1)
    {
        memset(buffer, 0, sizeof(buffer));

        printf("Enter command: ");
        fgets(buffer, sizeof(buffer), stdin);

        if (strcmp(buffer, "light on") == 0)
        {
            char command[10] = "1";
            write(fd, command, strlen(command));
        }
        else if (strcmp(buffer, "light off") == 0)
        {
            char command[10] = "0";
            write(fd, command, strlen(command));
        }
        else if (strcmp(buffer, "door open") == 0)
        {
            char command[10] = "2";
            write(fd, command, strlen(command));
        }
        else if (strcmp(buffer, "door close") == 0)
        {
            char command[10] = "3";
            write(fd, command, strlen(command));
        }
        else
        {
            printf("Invalid command\n");
        }
    }

    return 0;
}