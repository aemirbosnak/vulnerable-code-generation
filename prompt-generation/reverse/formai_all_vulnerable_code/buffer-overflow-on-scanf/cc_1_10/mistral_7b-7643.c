//MISTRAL-7B DATASET v1.0 Category: Drone Remote Control ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <termios.h>
#include <math.h>

#define DRONE_PORT "/dev/drone"
#define BAUD_RATE 9600

struct termios old_settings, new_settings;
int drone_fd;

void drone_control(char cmd) {
    write(drone_fd, &cmd, sizeof(cmd));
}

void init_serial() {
    tcgetattr(STDIN_FILENO, &old_settings);
    bzero(&new_settings, sizeof(struct termios));
    new_settings.c_cflag = BAUD_RATE | CS8 | CLOCAL | CREAD;
    new_settings.c_iflag = IGNPAR;
    new_settings.c_oflag = 0;
    new_settings.c_lflag = 0;
    tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);

    drone_fd = open(DRONE_PORT, O_RDWR | O_NOCTTY);
    if (drone_fd == -1) {
        perror("Couldn't open the port");
        exit(1);
    }

    tcsetattr(drone_fd, TCSANOW, &new_settings);
}

void cleanup() {
    tcsetattr(STDIN_FILENO, TCSANOW, &old_settings);
    close(drone_fd);
}

int main() {
    init_serial();

    printf("Welcome to the Drone Remote Control!\n");
    printf("Available commands:\n");
    printf("- F: Fly up\n");
    printf("- B: Fly down\n");
    printf("- L: Fly left\n");
    printf("- R: Fly right\n");
    printf("- X: Take a picture\n");
    printf("- Q: Land\n");

    char cmd;
    while (1) {
        scanf("%c", &cmd);
        switch (cmd) {
            case 'F':
                drone_control('u');
                break;
            case 'B':
                drone_control('d');
                break;
            case 'L':
                drone_control('l');
                break;
            case 'R':
                drone_control('r');
                break;
            case 'X':
                drone_control('c');
                break;
            case 'Q':
                drone_control('g');
                sleep(2); // Wait for drone to land
                cleanup();
                return 0;
            default:
                printf("Invalid command\n");
        }
    }

    cleanup();
    return 0;
}