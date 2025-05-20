//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: complex
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>

#define BAUDRATE B115200
#define PORT "/dev/ttyUSB0"

int main() {
    int fd;
    struct termios options;

    fd = open(PORT, O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) {
        perror("open");
        return EXIT_FAILURE;
    }

    tcgetattr(fd, &options);
    cfsetspeed(&options, BAUDRATE);
    cfmakeraw(&options);
    tcsetattr(fd, TCSANOW, &options);

    uint8_t buffer[8];
    memset(buffer, 0, sizeof(buffer));
    buffer[0] = 0x55; // Start byte
    buffer[1] = 0x00; // Command ID
    buffer[2] = 0x00; // Payload length
    buffer[3] = 0x00; // Payload
    buffer[4] = 0x00; // Payload
    buffer[5] = 0x00; // Payload
    buffer[6] = 0x00; // Payload
    buffer[7] = 0x55; // End byte

    while (1) {
        int bytes_written = write(fd, buffer, sizeof(buffer));
        if (bytes_written == -1) {
            perror("write");
            return EXIT_FAILURE;
        }
        
        int bytes_read = read(fd, buffer, sizeof(buffer));
        if (bytes_read == -1) {
            perror("read");
            return EXIT_FAILURE;
        }
        
        if (buffer[0] != 0x55 || buffer[7] != 0x55) {
            printf("Invalid packet received\n");
            continue;
        }
        
        int command_id = buffer[1];
        int payload_length = buffer[2];
        if (payload_length > 0) {
            printf("Payload: ");
            for (int i = 0; i < payload_length; i++) {
                printf("%02X ", buffer[3 + i]);
            }
            printf("\n");
        }
    }

    close(fd);
    return EXIT_SUCCESS;
}