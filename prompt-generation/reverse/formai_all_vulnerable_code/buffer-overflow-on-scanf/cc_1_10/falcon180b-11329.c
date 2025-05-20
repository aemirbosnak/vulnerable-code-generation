//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <pthread.h>
#include <sys/time.h>

#define BAUDRATE B9600
#define SERIAL_PORT "/dev/ttyS0"
#define MAX_COMMAND_LENGTH 64

typedef struct {
    int throttle;
    int yaw;
    int pitch;
    int roll;
} drone_command_t;

drone_command_t current_command = {0};

void* send_commands(void* arg) {
    FILE* serial_port;
    serial_port = fopen(SERIAL_PORT, "w");

    if(serial_port == NULL) {
        printf("Error opening serial port\n");
        exit(1);
    }

    while(1) {
        usleep(100000); // sleep for 100ms

        if(current_command.throttle!= 0) {
            char command[MAX_COMMAND_LENGTH] = "AT*REF=";
            sprintf(command + strlen(command), "%d,%d,%d,%d\r", current_command.throttle, current_command.yaw, current_command.pitch, current_command.roll);

            fwrite(command, strlen(command), 1, serial_port);
        }
    }

    fclose(serial_port);
    return NULL;
}

int main() {
    pthread_t thread_id;
    pthread_create(&thread_id, NULL, send_commands, NULL);

    while(1) {
        printf("Enter command (throttle yaw pitch roll): ");
        scanf("%d %d %d %d", &current_command.throttle, &current_command.yaw, &current_command.pitch, &current_command.roll);
    }

    return 0;
}