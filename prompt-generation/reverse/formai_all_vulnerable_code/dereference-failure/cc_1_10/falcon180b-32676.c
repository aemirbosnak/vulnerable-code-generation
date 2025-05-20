//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <termios.h>

#define BUFFER_SIZE 1024
#define GPS_DEVICE "/dev/ttyUSB0"
#define GPS_BAUD_RATE 9600

int gps_fd;
char gps_buffer[BUFFER_SIZE];

void initialize_gps() {
    gps_fd = open(GPS_DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);
    if (gps_fd == -1) {
        printf("Error opening GPS device: %s\n", strerror(errno));
        exit(1);
    }

    struct termios gps_settings;
    memset(&gps_settings, 0, sizeof(gps_settings));
    gps_settings.c_cflag = B9600 | CS8 | CREAD | CLOCAL;
    gps_settings.c_iflag = IGNPAR;
    gps_settings.c_oflag = 0;
    gps_settings.c_lflag = 0;
    tcsetattr(gps_fd, TCSANOW, &gps_settings);
}

void read_gps_data() {
    int bytes_read = read(gps_fd, gps_buffer, BUFFER_SIZE);
    if (bytes_read > 0) {
        gps_buffer[bytes_read] = '\0';
        printf("GPS data: %s\n", gps_buffer);
    }
}

int main() {
    initialize_gps();

    while (1) {
        read_gps_data();
        usleep(100000); // Sleep for 100ms
    }

    close(gps_fd);
    return 0;
}