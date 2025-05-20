//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <signal.h>

#define BAUDRATE B9600
#define DEVICE "/dev/ttyUSB0"

int serial_port;
struct termios oldtio, newtio;

void exit_program(int signal) {
    // Restore old terminal settings
    tcsetattr(serial_port, TCSANOW, &oldtio);
    close(serial_port);
    printf("\nExiting program...\n");
    exit(0);
}

void setup_serial() {
    serial_port = open(DEVICE, O_RDWR | O_NOCTTY);
    if (serial_port < 0) {
        perror("Error opening serial port");
        exit(EXIT_FAILURE);
    }

    tcgetattr(serial_port, &oldtio); // Save current settings
    bzero(&newtio, sizeof(newtio));   // Clear new settings

    newtio.c_cflag = BAUDRATE | CS8 | CLOCAL | CREAD; // Set baud rate and other settings
    newtio.c_iflag = IGNPAR;                      // Ignore framing and parity errors
    newtio.c_lflag = 0;                           // Non-canonical mode
    newtio.c_oflag = 0;                           // Raw output
    newtio.c_cc[VMIN] = 1;                        // Minimum of 1 character read
    newtio.c_cc[VTIME] = 0;                       // No timeout

    tcflush(serial_port, TCIFLUSH);               // Flush input buffer
    tcsetattr(serial_port, TCSANOW, &newtio);    // Apply the settings
}

void send_command(const char *command) {
    write(serial_port, command, strlen(command));
    printf("Sent command: %s\n", command);
}

void print_help() {
    printf("Drone Remote Control Commands:\n");
    printf("  F: Move Forward\n");
    printf("  B: Move Backward\n");
    printf("  L: Move Left\n");
    printf("  R: Move Right\n");
    printf("  U: Ascend\n");
    printf("  D: Descend\n");
    printf("  S: Stop\n");
    printf("  H: Help\n");
    printf("  Q: Quit\n");
}

int main() {
    signal(SIGINT, exit_program); // Handle interrupt signal (CTRL+C)

    setup_serial();
    print_help();

    char command;
    while (1) {
        printf("Enter command: ");
        scanf(" %c", &command); // Read a single character

        switch (command) {
            case 'F':
                send_command("FORWARD\n");
                break;
            case 'B':
                send_command("BACKWARD\n");
                break;
            case 'L':
                send_command("LEFT\n");
                break;
            case 'R':
                send_command("RIGHT\n");
                break;
            case 'U':
                send_command("ASCEND\n");
                break;
            case 'D':
                send_command("DESCEND\n");
                break;
            case 'S':
                send_command("STOP\n");
                break;
            case 'H':
                print_help();
                break;
            case 'Q':
                exit_program(0);
                break;
            default:
                printf("Invalid command! Press H for help.\n");
        }
    }

    return 0;
}