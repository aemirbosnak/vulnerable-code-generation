//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <signal.h>

#define DRONE_SUCCESS 0
#define DRONE_FAIL -1

typedef struct {
    char *port;
    int baud;
    int fd;
} Drone;

void handle_signal(int sig) {
    if (sig == SIGINT) {
        printf("\nExiting Drone Control. Goodbye!\n");
        exit(0);
    }
}

int open_serial_port(Drone *drone) {
    drone->fd = open(drone->port, O_RDWR | O_NOCTTY | O_NDELAY);
    if (drone->fd == -1) {
        perror("Failed to open the serial port");
        return DRONE_FAIL;
    }
    return DRONE_SUCCESS;
}

void configure_serial_port(Drone *drone) {
    struct termios options;
    tcgetattr(drone->fd, &options);
    cfsetispeed(&options, drone->baud);
    cfsetospeed(&options, drone->baud);
    options.c_cflag |= (CLOCAL | CREAD);
    options.c_cflag &= ~PARENB; // No parity
    options.c_cflag &= ~CSTOPB; // 1 stop bit
    options.c_cflag &= ~CSIZE;   // Clear current char size
    options.c_cflag |= CS8;      // 8 data bits
    
    options.c_cc[VMIN] = 0;  // Non-blocking reads
    options.c_cc[VTIME] = 1; // 0.1 seconds read timeout

    tcsetattr(drone->fd, TCSANOW, &options);
}

void send_command(Drone *drone, const char *command) {
    write(drone->fd, command, strlen(command));
}

void read_response(Drone *drone) {
    char buffer[255];
    int n = read(drone->fd, buffer, sizeof(buffer));
    if (n > 0) {
        buffer[n] = '\0'; // Null terminate the string
        printf("Drone Response: %s\n", buffer);
    } else {
        printf("No response from drone.\n");
    }
}

void take_off(Drone *drone) {
    printf("Sending take-off command to drone...\n");
    send_command(drone, "TAKE_OFF\n");
    read_response(drone);
}

void land(Drone *drone) {
    printf("Sending land command to drone...\n");
    send_command(drone, "LAND\n");
    read_response(drone);
}

void move_forward(Drone *drone) {
    printf("Sending move forward command to drone...\n");
    send_command(drone, "MOVE_FORWARD\n");
    read_response(drone);
}

void move_backward(Drone *drone) {
    printf("Sending move backward command to drone...\n");
    send_command(drone, "MOVE_BACKWARD\n");
    read_response(drone);
}

void turn_left(Drone *drone) {
    printf("Sending turn left command to drone...\n");
    send_command(drone, "TURN_LEFT\n");
    read_response(drone);
}

void turn_right(Drone *drone) {
    printf("Sending turn right command to drone...\n");
    send_command(drone, "TURN_RIGHT\n");
    read_response(drone);
}

void display_menu() {
    printf("Drone Remote Control:\n");
    printf("1. Take Off\n");
    printf("2. Land\n");
    printf("3. Move Forward\n");
    printf("4. Move Backward\n");
    printf("5. Turn Left\n");
    printf("6. Turn Right\n");
    printf("7. Exit\n");
    printf("Choose an option: ");
}

int main() {
    signal(SIGINT, handle_signal);

    Drone myDrone;
    myDrone.port = "/dev/ttyS0"; // Change as necessary for your system
    myDrone.baud = B9600; // Baud rate for communication

    if (open_serial_port(&myDrone) == DRONE_FAIL) {
        return EXIT_FAILURE;
    }

    configure_serial_port(&myDrone);

    int choice;
    while (1) {
        display_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: take_off(&myDrone); break;
            case 2: land(&myDrone); break;
            case 3: move_forward(&myDrone); break;
            case 4: move_backward(&myDrone); break;
            case 5: turn_left(&myDrone); break;
            case 6: turn_right(&myDrone); break;
            case 7: 
                printf("Exiting Drone Control.\n");
                close(myDrone.fd);
                return EXIT_SUCCESS;
            default: 
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    close(myDrone.fd);
    return EXIT_SUCCESS;
}