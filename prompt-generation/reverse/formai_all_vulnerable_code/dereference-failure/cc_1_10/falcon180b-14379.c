//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>

#define BAUD 9600
#define TRUE 1
#define FALSE 0
#define ESC 27

struct termios initial_settings, new_settings;

void setup_serial_port()
{
    tcgetattr(0, &initial_settings);
    new_settings = initial_settings;

    new_settings.c_cflag &= ~CSIZE;
    new_settings.c_cflag |= CS8;

    new_settings.c_iflag &= ~(IXON | IXOFF | IXANY);

    new_settings.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);

    new_settings.c_oflag &= ~OPOST;

    tcsetattr(0, TCSANOW, &new_settings);
}

void send_command(char *command)
{
    write(0, command, strlen(command));
    write(0, "\r", 1);
}

int main()
{
    setup_serial_port();

    while (TRUE)
    {
        char input[100];
        memset(input, 0, 100);

        read(0, input, 100);

        if (input[0] == ESC)
        {
            switch (input[1])
            {
                case 'f':
                    send_command("forward\r");
                    break;
                case 'b':
                    send_command("backward\r");
                    break;
                case 'l':
                    send_command("left\r");
                    break;
                case 'r':
                    send_command("right\r");
                    break;
                case's':
                    send_command("stop\r");
                    break;
                default:
                    send_command("invalid command\r");
                    break;
            }
        }
        else
        {
            send_command(input);
        }
    }

    return 0;
}