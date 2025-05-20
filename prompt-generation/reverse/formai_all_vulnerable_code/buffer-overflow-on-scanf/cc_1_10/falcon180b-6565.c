//Falcon-180B DATASET v1.0 Category: Smart home light control ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_DEVICES 10
#define MAX_DEVICE_NAME 20
#define MAX_COMMAND_LENGTH 50
#define MAX_RESPONSE_LENGTH 100

struct device {
    char name[MAX_DEVICE_NAME];
    int fd;
};

void send_command(int fd, char *command) {
    write(fd, command, strlen(command));
}

char *receive_response(int fd) {
    char response[MAX_RESPONSE_LENGTH];
    memset(response, 0, MAX_RESPONSE_LENGTH);
    read(fd, response, MAX_RESPONSE_LENGTH);
    return response;
}

int main() {
    int i, j;
    struct device devices[MAX_DEVICES];
    char input[MAX_COMMAND_LENGTH];
    char command[MAX_COMMAND_LENGTH];
    char *response;

    for (i = 0; i < MAX_DEVICES; i++) {
        printf("Enter device name for device %d: ", i + 1);
        scanf("%s", devices[i].name);
        devices[i].fd = open(devices[i].name, O_RDWR);
        if (devices[i].fd < 0) {
            printf("Error opening device %s: %s\n", devices[i].name, strerror(errno));
            exit(1);
        }
    }

    while (1) {
        printf("\nEnter command: ");
        scanf("%s", input);

        for (i = 0; i < MAX_DEVICES; i++) {
            if (strncmp(input, devices[i].name, strlen(devices[i].name)) == 0) {
                strcpy(command, &input[strlen(devices[i].name) + 1]);
                send_command(devices[i].fd, command);
                response = receive_response(devices[i].fd);
                printf("Response from device %s: %s\n", devices[i].name, response);
                break;
            }
        }

        if (i == MAX_DEVICES) {
            printf("Invalid device name\n");
        }
    }

    return 0;
}