//MISTRAL-7B DATASET v1.0 Category: Drone Remote Control ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <linux/i2c.h>
#define I2C_ADDR 0x1A // Drone I2C address
#define COMMAND_LENGTH 16
#define ACK_DELAY 100000 // Acknowledgment delay in us
#define DRONE_ON 0x01
#define DRONE_OFF 0x00
int main() {
    int i2c_file;
    char command[COMMAND_LENGTH];
    int ret;
    
    if ((i2c_file = open("/dev/i2c-1", O_RDWR)) < 0) {
        perror("Failed to open i2c bus");
        return 1;
    }
    if (ioctl(i2c_file, I2C_SLAVE, I2C_ADDR) < 0) {
        perror("Failed to connect to drone");
        return 1;
    }
    
    printf("Connected to drone at address 0x%x\n", I2C_ADDR);
    
    while (1) {
        printf("Enter command (Drone ON or OFF): ");
        scanf("%s", command);
        
        if (strlen(command) > COMMAND_LENGTH - 1) {
            printf("Command too long\n");
            continue;
        }
        
        command[COMMAND_LENGTH - 1] = '\0'; // Ensure null terminated
        
        if (strcasecmp(command, "ON") == 0) {
            command[0] = DRONE_ON;
        } else if (strcasecmp(command, "OFF") == 0) {
            command[0] = DRONE_OFF;
        } else {
            printf("Invalid command\n");
            continue;
        }
        
        ret = write(i2c_file, command, COMMAND_LENGTH);
        if (ret != COMMAND_LENGTH) {
            perror("Failed to send command to drone");
            continue;
        }
        
        usleep(ACK_DELAY); // Wait for drone's acknowledgment
        
        printf("Command sent to drone\n");
    }
    
    close(i2c_file);
    return 0;
}