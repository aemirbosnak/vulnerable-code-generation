//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <sys/select.h>
#include <sys/time.h>

#define BAUDRATE B9600
#define SERIAL_PORT "/dev/ttyS0"
#define MAX_COMMAND_LENGTH 100

int serial_fd;
struct termios oldtio, newtio;
char serial_port[20] = SERIAL_PORT;
char command[MAX_COMMAND_LENGTH];
int command_length;

void setup_serial_port()
{
    serial_fd = open(serial_port, O_RDWR | O_NOCTTY);

    if (serial_fd == -1)
    {
        printf("Error opening serial port: %s\n", strerror(errno));
        exit(1);
    }

    memset(&oldtio, 0, sizeof(oldtio));
    memset(&newtio, 0, sizeof(newtio));

    if (tcgetattr(serial_fd, &oldtio)!= 0)
    {
        printf("Error getting serial port attributes: %s\n", strerror(errno));
        exit(1);
    }

    newtio.c_cflag = BAUDRATE | CS8 | CLOCAL | CREAD;
    newtio.c_iflag = IGNPAR;
    newtio.c_oflag = 0;
    newtio.c_lflag = 0;
    newtio.c_cc[VMIN] = 1;
    newtio.c_cc[VTIME] = 0;

    if (tcsetattr(serial_fd, TCSANOW, &newtio)!= 0)
    {
        printf("Error setting serial port attributes: %s\n", strerror(errno));
        exit(1);
    }
}

void send_command(char* cmd)
{
    write(serial_fd, cmd, strlen(cmd));
}

int main()
{
    setup_serial_port();

    while (1)
    {
        printf("Enter command: ");
        scanf("%s", command);
        command_length = strlen(command);

        if (command_length > 0)
        {
            send_command(command);
        }
    }

    close(serial_fd);
    return 0;
}