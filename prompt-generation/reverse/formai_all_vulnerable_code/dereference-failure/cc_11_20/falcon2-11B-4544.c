//Falcon2-11B DATASET v1.0 Category: Smart home light control ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <sys/time.h>
#include <time.h>
#include <signal.h>
#include <poll.h>
#include <termios.h>

#define I2C_ADDR 0x70
#define I2C_BUS 1
#define SLEEP_TIME 0.1

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct pollfd pfd;
    char buf[1024];
    struct timeval tv;
    int fd, ret;
    struct termios oldtio, newtio;
    int brightness = 0;
    int red = 0;
    int green = 0;
    int blue = 0;
    int color = 0;

    // Check command line arguments
    if (argc!= 5) {
        fprintf(stderr, "Usage: %s <brightness> <red> <green> <blue>\n", argv[0]);
        exit(1);
    }
    brightness = atoi(argv[1]);
    red = atoi(argv[2]);
    green = atoi(argv[3]);
    blue = atoi(argv[4]);

    // Initialize I2C communication
    fd = open("/dev/i2c-1", O_RDWR);
    if (fd < 0) {
        perror("Error opening I2C device");
        exit(1);
    }
    ioctl(fd, I2C_SLAVE, I2C_ADDR);

    // Configure serial port for command line input
    tcgetattr(STDIN_FILENO, &oldtio);
    newtio = oldtio;
    newtio.c_iflag &= ~(IXON | IXOFF | IXANY);
    newtio.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newtio);

    // Create socket and connect to server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8888);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Send brightness and color values to server
    snprintf(buf, sizeof(buf), "brightness %d red %d green %d blue %d\n", brightness, red, green, blue);
    n = write(sockfd, buf, strlen(buf));
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    // Set up pollfd structure for reading from socket
    pfd.fd = sockfd;
    pfd.events = POLLIN;

    // Main loop
    while (1) {
        // Read command from user
        ret = read(STDIN_FILENO, buf, sizeof(buf));
        if (ret < 0) {
            perror("Error reading from stdin");
            exit(1);
        }
        buf[ret] = 0;

        // Send command to server
        n = write(sockfd, buf, strlen(buf));
        if (n < 0) {
            perror("Error writing to socket");
            exit(1);
        }

        // Process server response
        tv.tv_sec = SLEEP_TIME;
        tv.tv_usec = 0;
        poll(&pfd, 1, &tv);
        if (pfd.revents & POLLIN) {
            ret = read(sockfd, buf, sizeof(buf));
            if (ret < 0) {
                perror("Error reading from socket");
                exit(1);
            }
            buf[ret] = 0;

            // Parse server response
            int brightness_val, red_val, green_val, blue_val;
            sscanf(buf, "brightness %d red %d green %d blue %d\n", &brightness_val, &red_val, &green_val, &blue_val);
            if (brightness_val!= brightness || red_val!= red || green_val!= green || blue_val!= blue) {
                // Update LED strip with new brightness and color values
                ioctl(fd, I2C_SLAVE, I2C_ADDR);
                usleep(SLEEP_TIME * 1000);
            }
        }
    }

    return 0;
}