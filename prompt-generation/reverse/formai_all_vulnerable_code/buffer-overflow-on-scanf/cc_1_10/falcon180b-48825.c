//Falcon-180B DATASET v1.0 Category: Smart home automation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

#define BAUDRATE B9600
#define DEVICE "/dev/ttyUSB0"

int main(int argc, char *argv[])
{
    int fd;
    struct termios options;

    fd = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);

    if(fd == -1)
    {
        printf("Error: Unable to open %s\n", DEVICE);
        exit(1);
    }

    memset(&options, 0, sizeof(options));

    options.c_cflag = BAUDRATE | CS8 | CREAD | CLOCAL;
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;

    tcsetattr(fd, TCSANOW, &options);

    while(1)
    {
        char command[100];
        printf("Enter command: ");
        scanf("%s", command);

        if(strcmp(command, "ON") == 0)
        {
            write(fd, "1", 1);
        }
        else if(strcmp(command, "OFF") == 0)
        {
            write(fd, "0", 1);
        }
        else if(strcmp(command, "QUIT") == 0)
        {
            break;
        }
        else
        {
            printf("Invalid command\n");
        }
    }

    close(fd);
    return 0;
}