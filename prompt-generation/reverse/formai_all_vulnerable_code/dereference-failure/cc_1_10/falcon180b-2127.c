//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <string.h>
#include <signal.h>

#define BAUD 9600
#define TRUE 1
#define FALSE 0
#define ESC 27
#define UP_ARROW 'A'
#define DOWN_ARROW 'B'
#define LEFT_ARROW 'D'
#define RIGHT_ARROW 'C'
#define MAX_COMMAND_LENGTH 100
#define MAX_COMMANDS 10

char commands[MAX_COMMANDS][MAX_COMMAND_LENGTH];
int num_commands = 0;

void read_config_file(char *filename) {
    FILE *config_file;
    char line[MAX_COMMAND_LENGTH];
    int i = 0;

    config_file = fopen(filename, "r");
    if (config_file == NULL) {
        printf("Error: could not open config file.\n");
        exit(1);
    }

    while (fgets(line, MAX_COMMAND_LENGTH, config_file)!= NULL) {
        if (i >= MAX_COMMANDS) {
            printf("Error: too many commands in config file.\n");
            exit(1);
        }
        strcpy(commands[i], line);
        i++;
    }

    fclose(config_file);
}

int main(int argc, char **argv) {
    int fd;
    struct termios oldtio, newtio;
    char c;
    int i;

    if (argc!= 2) {
        printf("Usage: %s <config_file>\n", argv[0]);
        exit(1);
    }

    read_config_file(argv[1]);

    fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) {
        printf("Error: could not open serial port.\n");
        exit(1);
    }

    tcgetattr(fd, &oldtio);
    newtio = oldtio;
    newtio.c_cflag = BAUD | CS8 | CLOCAL | CREAD;
    tcsetattr(fd, TCSANOW, &newtio);

    while (TRUE) {
        for (i = 0; i < num_commands; i++) {
            write(fd, commands[i], strlen(commands[i]));
            write(fd, "\r\n", 2);
        }

        while (read(fd, &c, 1) > 0) {
            if (c == ESC) {
                break;
            }

            switch (c) {
                case UP_ARROW:
                    printf("Up arrow pressed.\n");
                    break;
                case DOWN_ARROW:
                    printf("Down arrow pressed.\n");
                    break;
                case LEFT_ARROW:
                    printf("Left arrow pressed.\n");
                    break;
                case RIGHT_ARROW:
                    printf("Right arrow pressed.\n");
                    break;
                default:
                    printf("Unknown key pressed: %c\n", c);
                    break;
            }
        }
    }

    close(fd);
    return 0;
}