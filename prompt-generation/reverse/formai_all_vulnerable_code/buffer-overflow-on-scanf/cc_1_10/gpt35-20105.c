//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <errno.h>

// Function to set the attributes of serial port
void set_interface_attribs (int fd, int speed, int parity)
{
  struct termios tty;
  memset (&tty, 0, sizeof tty);
  if (tcgetattr (fd, &tty) != 0)
  {
    printf ("Error %d from tcgetattr: %s\n", errno, strerror (errno));
    return;
  }

  cfsetospeed (&tty, speed);
  cfsetispeed (&tty, speed);

  tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;     // 8-bit chars
  // disable IGNBRK for mismatched speed tests; otherwise receive break
  // as \000 chars
  tty.c_iflag &= ~IGNBRK;         // ignore break signal
  tty.c_lflag = 0;                // no signaling chars, no echo,
                                  // no canonical processing
  tty.c_oflag = 0;                // no remapping, no delays
  tty.c_cc[VMIN]  = 0;            // read doesn't block
  tty.c_cc[VTIME] = 5;            // 0.5 seconds read timeout

  tty.c_iflag &= ~(IXON | IXOFF | IXANY); // shut off xon/xoff ctrl

  tty.c_cflag |= (CLOCAL | CREAD);// ignore modem controls,
                                  // enable reading
  tty.c_cflag &= ~(PARENB | PARODD);      // no parity
  tty.c_cflag |= parity;
  tty.c_cflag &= ~CSTOPB;
  tty.c_cflag &= ~CRTSCTS;

  if (tcsetattr (fd, TCSANOW, &tty) != 0)
    printf ("Error %d from tcsetattr: %s\n", errno, strerror (errno));
}

void set_blocking (int fd, int should_block)
{
  struct termios tty;
  memset (&tty, 0, sizeof tty);
  if (tcgetattr (fd, &tty) != 0)
  {
    printf ("Error %d from tggetattr: %s\n", errno, strerror (errno));
    return;
  }

  tty.c_cc[VMIN]  = should_block ? 1 : 0;
  tty.c_cc[VTIME] = 5;            // 0.5 seconds read timeout

  if (tcsetattr (fd, TCSANOW, &tty) != 0)
    printf ("Error %d setting term attributes: %s\n", errno, strerror (errno));
}

// Main function
int main()
{
    int fd = open ("/dev/ttyACM0", O_RDWR | O_NOCTTY | O_SYNC);
    if (fd < 0)
    {
        printf ("Error opening device: %s\n", strerror (errno));
        return -1;
    }

    set_interface_attribs (fd, B115200, 0);     // set speed to 115200 bps, 8n1 (no parity)
    set_blocking (fd, 0);                // set no blocking

    unsigned char s[3];
    memset (s, 0, sizeof(char)*3);

    // Code to control the drone
    while (1)
    {
        // Read command from user
        printf("\nEnter command: ");
        scanf("%c%c", &s[0], &s[1]);

        // Exit if command is 'QQ'
        if(s[0] == 'Q' && s[1] == 'Q')
        break;

        // Write command to serial port
        write (fd, s, sizeof(char)*2);

        // Wait for response from drone
        usleep(10000);

        // Read response from drone
        char buf[256];
        int n = read (fd, buf, sizeof(buf)-1);

        if (n > 0)
        printf ("%s", buf);
    }

    // Close serial port
    close(fd);
    return 0;
}