//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>

#define BAUDRATE B9600
#define DEVICE "/dev/ttyUSB0"

static int fd;
static struct termios oldtio, newtio;

void init_serial(void) {
    if ((fd = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY)) == -1) {
        printf("Error opening %s: %s\n", DEVICE, strerror(errno));
        exit(1);
    }

    if (tcgetattr(fd, &oldtio)!= 0) {
        printf("Error tcgetattr: %s\n", strerror(errno));
        exit(1);
    }

    newtio = oldtio;
    newtio.c_cflag = BAUDRATE | CS8 | CLOCAL | CREAD;

    if (tcsetattr(fd, TCSANOW, &newtio)!= 0) {
        printf("Error tcsetattr: %s\n", strerror(errno));
        exit(1);
    }
}

void send_command(char *cmd) {
    write(fd, cmd, strlen(cmd));
    write(fd, "\r", 1);
}

void close_serial(void) {
    tcsetattr(fd, TCSANOW, &oldtio);
    close(fd);
}

int main(int argc, char *argv[]) {
    init_serial();

    while (1) {
        send_command("AT\r");
        usleep(100000);
        char response[64];
        int n = read(fd, response, sizeof(response));
        response[n] = '\0';
        printf("Response: %s\n", response);

        if (strcmp(response, "OK") == 0) {
            break;
        }
    }

    send_command("AT+CIPMUX=1\r");
    usleep(100000);

    send_command("AT+CIPSERVER=1,80\r");
    usleep(100000);

    send_command("AT+CIPSTART=1,TCP,127.0.0.1,8080\r");
    usleep(100000);

    char *msg = "Hello, World!\n";
    send_command(msg);
    usleep(100000);

    close_serial();

    return 0;
}