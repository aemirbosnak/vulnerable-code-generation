//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <sys/select.h>

#define BAUDRATE B9600
#define DEVICE "/dev/ttyS0"

int master, slave;

void init() {
    struct termios conf;

    tcgetattr(master, &conf);
    cfsetispeed(&conf, BAUDRATE);
    cfsetospeed(&conf, BAUDRATE);
    tcsetattr(master, TCSANOW, &conf);

    tcgetattr(slave, &conf);
    cfsetispeed(&conf, BAUDRATE);
    cfsetospeed(&conf, BAUDRATE);
    tcsetattr(slave, TCSANOW, &conf);
}

void send_cmd(char *cmd) {
    write(master, cmd, strlen(cmd));
    write(master, "\r", 1);
}

char recv_resp() {
    char c;
    read(slave, &c, 1);
    return c;
}

int main() {
    int n;

    if ((master = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY)) == -1) {
        perror(DEVICE);
        exit(1);
    }

    if ((slave = open(DEVICE, O_RDWR | O_NOCTTY)) == -1) {
        perror(DEVICE);
        exit(1);
    }

    if (ioctl(master, TIOCSCTTY, (void *) 0) == -1) {
        perror("TIOCSCTTY");
        exit(1);
    }

    init();

    while (1) {
        system("clear");
        printf("Smart Home Light Control\n");
        printf("1. Turn on light\n");
        printf("2. Turn off light\n");
        printf("3. Dim light\n");
        printf("4. Brighten light\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &n);

        switch (n) {
        case 1:
            send_cmd("AT+CREG=1\r");
            break;
        case 2:
            send_cmd("AT+CREG=2\r");
            break;
        case 3:
            send_cmd("AT+CREG=3\r");
            break;
        case 4:
            send_cmd("AT+CREG=4\r");
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}