//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/joystick.h>

#define JOYSTICK_DEV "/dev/input/js0"
#define BUF_SIZE 128
#define MAX_AXIS 6
#define MAX_BUTTON 12

// Define axis and button map
const char *axis_map[] = {"X", "Y", "Z", "RX", "RY", "RZ"};
const char *button_map[] = {"A", "B", "X", "Y", "LB", "RB", "LT", "RT", "SELECT", "START", "HOME", "POWER"};

// Function to initialize the joystick
int init_joystick(void)
{
    int fd;

    // Open the joystick device
    if ((fd = open(JOYSTICK_DEV, O_RDONLY)) < 0)
    {
        perror("open");
        return -1;
    }

    // Set non-blocking mode
    fcntl(fd, F_SETFL, O_NONBLOCK);

    return fd;
}

// Function to read the joystick state
int read_joystick(int fd, struct js_event *event)
{
    ssize_t bytes;

    // Read the joystick event
    bytes = read(fd, event, sizeof(*event));
    if (bytes < 0)
    {
        if (errno == EAGAIN)
        {
            return 0; // No data available
        }
        else
        {
            perror("read");
            return -1;
        }
    }

    return 1;
}

// Function to print the joystick state
void print_joystick(struct js_event *event)
{
    // Print the event type
    switch (event->type)
    {
    case JS_EVENT_AXIS:
        printf("Axis: %s, Value: %d\n", axis_map[event->number], event->value);
        break;
    case JS_EVENT_BUTTON:
        printf("Button: %s, Value: %d\n", button_map[event->number], event->value);
        break;
    default:
        printf("Unknown event type: %d\n", event->type);
        break;
    }
}

// Function to send a command to the drone
int send_command(const char *cmd)
{
    int sockfd;
    struct sockaddr_in addr;
    ssize_t bytes;

    // Create a UDP socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("socket");
        return -1;
    }

    // Set the socket address
    addr.sin_family = AF_INET;
    addr.sin_port = htons(5556);
    addr.sin_addr.s_addr = inet_addr("192.168.1.1");

    // Send the command
    bytes = sendto(sockfd, cmd, strlen(cmd), 0, (struct sockaddr *)&addr, sizeof(addr));
    if (bytes < 0)
    {
        perror("sendto");
        close(sockfd);
        return -1;
    }

    // Close the socket
    close(sockfd);

    return 0;
}

// Main function
int main(void)
{
    int fd;
    struct js_event event;
    char buf[BUF_SIZE];

    // Initialize the joystick
    if ((fd = init_joystick()) < 0)
    {
        return -1;
    }

    // Main loop
    while (1)
    {
        // Read the joystick state
        if (read_joystick(fd, &event) > 0)
        {
            // Print the joystick state
            print_joystick(&event);

            // Send a command to the drone
            if (event.type == JS_EVENT_BUTTON && event.value == 1)
            {
                if (event.number == 0)
                {
                    // Start the drone
                    send_command("start");
                }
                else if (event.number == 1)
                {
                    // Stop the drone
                    send_command("stop");
                }
                else if (event.number == 2)
                {
                    // Send a request for data
                    send_command("data");
                }
            }
        }

        // Check for keyboard input
        if (fgets(buf, BUF_SIZE, stdin) != NULL)
        {
            // Send a command to the drone
            send_command(buf);
        }
    }

    // Close the joystick device
    close(fd);

    return 0;
}