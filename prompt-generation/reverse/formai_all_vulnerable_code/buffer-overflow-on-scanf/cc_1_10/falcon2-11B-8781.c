//Falcon2-11B DATASET v1.0 Category: Smart home automation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <termios.h>
#include <ctype.h>
#include <time.h>
#include <pthread.h>

#define SLEEP_TIME 2
#define PORT "/dev/ttyACM0"
#define BAUD_RATE 9600

#define LIGHT_ON '1'
#define LIGHT_OFF '0'
#define FAN_ON '2'
#define FAN_OFF '3'
#define AC_ON '4'
#define AC_OFF '5'

int control(int light, int fan, int ac) {
    char cmd[4] = {LIGHT_ON, FAN_ON, AC_ON};
    int fd = open(PORT, O_WRONLY);
    if (fd == -1) {
        printf("Error: Could not open port %s\n", PORT);
        return -1;
    }
    
    char c = '\0';
    for (int i = 0; i < 3; i++) {
        c = cmd[i];
        if (c == '1') {
            write(fd, &c, 1);
        } else if (c == '2') {
            write(fd, &c, 1);
        } else if (c == '3') {
            write(fd, &c, 1);
        } else if (c == '4') {
            write(fd, &c, 1);
        } else if (c == '5') {
            write(fd, &c, 1);
        } else {
            printf("Error: Invalid command\n");
            return -1;
        }
        sleep(SLEEP_TIME);
    }
    close(fd);
    return 0;
}

int main() {
    printf("Welcome to the smart home automation program!\n");
    printf("Enter command: ");
    char cmd[4] = {'\0'};
    scanf("%s", cmd);
    int light = atoi(cmd);
    if (light == 1) {
        printf("Light turned on\n");
    } else if (light == 0) {
        printf("Light turned off\n");
    } else {
        printf("Error: Invalid command\n");
    }
    printf("Enter command: ");
    scanf("%s", cmd);
    int fan = atoi(cmd);
    if (fan == 2) {
        printf("Fan turned on\n");
    } else if (fan == 3) {
        printf("Fan turned off\n");
    } else {
        printf("Error: Invalid command\n");
    }
    printf("Enter command: ");
    scanf("%s", cmd);
    int ac = atoi(cmd);
    if (ac == 4) {
        printf("AC turned on\n");
    } else if (ac == 5) {
        printf("AC turned off\n");
    } else {
        printf("Error: Invalid command\n");
    }
    printf("Thank you for using the smart home automation program!\n");
    return 0;
}