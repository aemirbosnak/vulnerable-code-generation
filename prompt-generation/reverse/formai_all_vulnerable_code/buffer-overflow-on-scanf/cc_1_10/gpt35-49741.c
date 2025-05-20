//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <termios.h>
#include <string.h>
#include <stdbool.h>

#define BAUDRATE B9600
#define MODEMDEVICE "/dev/ttyUSB0"
#define _POSIX_SOURCE 1
#define FALSE 0
#define TRUE 1

volatile int STOP = FALSE;

void signal_handler_IO(int status);  // interrupt handler
int char_to_int(char c);

int fd;  // file descriptor for the serial port
struct termios oldtio,newtio;  // old and new termios settings
struct sigaction saio;  // signal action for interrupt handling

int main(int argc, char *argv[])
{
    char *command = malloc(20);  // allocate memory for command string
    char *buf = malloc(255);  // allocate memory for input buffer
    char *output = malloc(255);  // allocate memory for output buffer

    /* Open the serial port */
    fd = open(MODEMDEVICE, O_RDWR | O_NOCTTY);
    if (fd < 0) { perror(MODEMDEVICE); exit(-1); }

    /* Set the new attributes for the serial port */
    tcgetattr(fd,&oldtio);
    bzero(&newtio, sizeof(newtio));
    newtio.c_cflag = BAUDRATE | CS8 | CLOCAL | CREAD;
    newtio.c_iflag = IGNPAR;
    newtio.c_oflag = 0;
    /* set input mode (non-canonical, no echo,...) */
    newtio.c_lflag = 0;
    newtio.c_cc[VTIME] = 0;  // inter-character timer unused
    newtio.c_cc[VMIN] = 1;  // blocking read until 1 character arrives
    tcflush(fd, TCIFLUSH);
    tcsetattr(fd, TCSANOW, &newtio);

    /* Install the interrupt handler */
    saio.sa_handler = signal_handler_IO;
    saio.sa_flags = 0;

    sigemptyset(&saio.sa_mask);
    sigaction(SIGIO, &saio, NULL);

    /* Allow process to receive SIGIO signals */
    fcntl(fd, F_SETOWN, getpid());
    fcntl(fd, F_SETFL, O_ASYNC);

    printf("Starting C drone remote control...\n");
    printf("Enter 'help' for a list of available commands\n");

    /* Loop until the user exits */
    while (!STOP) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "help") == 0) {
            printf("Available commands:\n");
            printf("  takeoff\n");
            printf("  land\n");
            printf("  up [distance]\n");
            printf("  down [distance]\n");
            printf("  left [distance]\n");
            printf("  right [distance]\n");
            printf("  forward [distance]\n");
            printf("  backward [distance]\n");
        }
        else if (strcmp(command, "takeoff") == 0) {
            printf("Sending takeoff command...\n");
            write(fd, "t\n", 2);
        }
        else if (strcmp(command, "land") == 0) {
            printf("Sending land command...\n");
            write(fd, "l\n", 2);
        }
        else if (strcmp(command, "up") == 0) {
            scanf("%s", buf);
            int distance = char_to_int(buf);
            printf("Sending up command with distance %d...\n", distance);
            sprintf(output, "u%d\n", distance);
            write(fd, output, strlen(output));
        }
        else if (strcmp(command, "down") == 0) {
            scanf("%s", buf);
            int distance = char_to_int(buf);
            printf("Sending down command with distance %d...\n", distance);
            sprintf(output, "d%d\n", distance);
            write(fd, output, strlen(output));
        }
        else if (strcmp(command, "left") == 0) {
            scanf("%s", buf);
            int distance = char_to_int(buf);
            printf("Sending left command with distance %d...\n", distance);
            sprintf(output, "a%d\n", distance);
            write(fd, output, strlen(output));
        }
        else if (strcmp(command, "right") == 0) {
            scanf("%s", buf);
            int distance = char_to_int(buf);
            printf("Sending right command with distance %d...\n", distance);
            sprintf(output, "r%d\n", distance);
            write(fd, output, strlen(output));
        }
        else if (strcmp(command, "forward") == 0) {
            scanf("%s", buf);
            int distance = char_to_int(buf);
            printf("Sending forward command with distance %d...\n", distance);
            sprintf(output, "f%d\n", distance);
            write(fd, output, strlen(output));
        }
        else if (strcmp(command, "backward") == 0) {
            scanf("%s", buf);
            int distance = char_to_int(buf);
            printf("Sending backward command with distance %d...\n", distance);
            sprintf(output, "b%d\n", distance);
            write(fd, output, strlen(output));
        }
        else {
            printf("Unknown command: %s\n", command);
            printf("Enter 'help' for a list of available commands\n");
        }

        /* Clear the input buffer */
        fgets(buf, 255, stdin);
    }

    /* Close the serial port */
    close(fd);
    printf("C drone remote control stopped.\n");

    return 0;
}

void signal_handler_IO(int status)
{
    char buffer[255];
    int i = 0, n = 0;

    while ((n = read(fd, &buffer[i], 1)) > 0 && i < 255) {
        if (buffer[i] == '\n') {
            buffer[i] = '\0';
            printf("Received message: %s\n", buffer);
            i = 0;
        } else {
            i++;
        }
    }
}

int char_to_int(char c)
{
    return (int) c - '0';
}