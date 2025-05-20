//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>
#include<termios.h>
#include<sys/ioctl.h>

#define BAUDRATE B115200
#define DEVICE "/dev/ttyUSB0"

int main()
{
    int fd;
    struct termios options;

    //Open the serial port
    fd = open(DEVICE, O_RDWR | O_NOCTTY | O_NDELAY);
    if(fd < 0)
    {
        perror("Error opening port");
        exit(1);
    }

    //Get the current options for the port
    if(tcgetattr(fd, &options) < 0)
    {
        perror("Error getting attributes");
        exit(1);
    }

    //Set the baud rate
    cfsetispeed(&options, BAUDRATE);
    cfsetospeed(&options, BAUDRATE);

    //Set the options for the port
    options.c_cflag = CS8 | CREAD | CLOCAL;
    options.c_iflag = IGNPAR;
    options.c_oflag = 0;
    options.c_lflag = 0;
    options.c_cc[VMIN] = 1;
    options.c_cc[VTIME] = 0;

    //Set the new options for the port
    if(tcsetattr(fd, TCSANOW, &options) < 0)
    {
        perror("Error setting attributes");
        exit(1);
    }

    //Loop to read data from the port and process it
    while(1)
    {
        char buffer[100];
        int bytes_read = read(fd, buffer, 100);
        if(bytes_read < 0)
        {
            perror("Error reading from port");
            exit(1);
        }
        else if(bytes_read == 0)
        {
            printf("No data available\n");
        }
        else
        {
            buffer[bytes_read] = '\0';
            printf("Received data: %s\n", buffer);
        }
    }

    close(fd);
    return 0;
}