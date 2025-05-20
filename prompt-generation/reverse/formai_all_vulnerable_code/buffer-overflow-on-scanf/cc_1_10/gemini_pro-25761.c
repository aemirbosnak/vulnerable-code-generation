//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: visionary
// Embark on a visionary journey to control the celestial sentinel with precision.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <signal.h>

#define BAUDRATE B115200
#define DEVICE_PATH "/dev/ttyUSB0"

// Declare the spectral commands for the drone's aerial maneuvers.
enum Command {
    TAKEOFF,
    LAND,
    HOVER,
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
    ROTATE_LEFT,
    ROTATE_RIGHT,
    FLIP,
    CALIBRATE
};

// Map the spectral commands to their celestial symphonies.
const char *commands[] = {
    "takeoff",
    "land",
    "hover",
    "forward",
    "backward",
    "left",
    "right",
    "rotate_left",
    "rotate_right",
    "flip",
    "calibrate"
};

// Establish a celestial connection with the drone.
int fd;
struct termios tty;

void init_connection();
void close_connection();
void send_command(enum Command command);

int main() {
    // Initiate the celestial connection.
    init_connection();

    while (1) {
        // Translate human intentions into the drone's celestial language.
        printf("Enter celestial command (takeoff, land, hover, forward, backward, left, right, rotate_left, rotate_right, flip, calibrate, exit): ");
        char input[256];
        scanf("%s", input);

        // Determine the spectral command from the human's request.
        enum Command command;
        for (int i = 0; i < sizeof(commands) / sizeof(char *); i++) {
            if (strcmp(input, commands[i]) == 0) {
                command = i;
                break;
            }
        }

        // Exit the ethereal connection if the human desires to return to earth.
        if (strcmp(input, "exit") == 0) {
            break;
        }

        // Send the celestial command to the drone, guiding its aerial dance.
        send_command(command);

        // Allow the drone a respite before its next celestial pirouette.
        sleep(1);
    }

    // Sever the celestial connection.
    close_connection();

    return 0;
}

void init_connection() {
    // Open the ethereal gateway to the drone's realm.
    fd = open(DEVICE_PATH, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) {
        perror("Unable to open device");
        exit(EXIT_FAILURE);
    }

    // Configure the celestial communication channel.
    tcgetattr(fd, &tty);
    cfsetispeed(&tty, BAUDRATE);
    cfsetospeed(&tty, BAUDRATE);

    tty.c_cflag &= ~PARENB;
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;

    tty.c_cflag &= ~CRTSCTS;

    tty.c_lflag &= ~ICANON;
    tty.c_lflag &= ~ECHO;
    tty.c_lflag &= ~ISIG;

    tty.c_oflag &= ~OPOST;

    tcsetattr(fd, TCSANOW, &tty);

    // Welcome the drone to the communion of the heavens.
    printf("Celestial connection established.\n");
}

void close_connection() {
    // Sever the ethereal gateway to the drone's realm.
    close(fd);

    // Bid farewell to the drone, may its flights be forever celestial.
    printf("Celestial connection closed.\n");
}

void send_command(enum Command command) {
    // Compose the celestial symphony to guide the drone's celestial dance.
    char buf[16];
    sprintf(buf, "%s\r\n", commands[command]);

    // Transmit the celestial symphony to the drone.
    write(fd, buf, strlen(buf));
}