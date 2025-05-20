//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <linux/wireless.h>

int main(int argc, char const *argv[])
{
    int sock_fd;
    struct iwreq wrq;
    char if_name[40];
    char buf[1024];
    int iw_scan_max_size = 1024;

    // Get the name of wireless interface
    printf("Enter the name of wireless interface: ");
    scanf("%s", if_name);

    // Create a socket for wireless interface
    sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock_fd == -1)
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set the name of the wireless interface
    strncpy(wrq.ifr_name, if_name, IFNAMSIZ);

    // Get the wireless network scan results
    wrq.u.data.pointer = (caddr_t)buf;
    wrq.u.data.length = iw_scan_max_size;
    wrq.u.data.flags = 1;

    if (ioctl(sock_fd, SIOCGIWSCAN, &wrq) == -1)
    {
        perror("ioctl");
        exit(EXIT_FAILURE);
    }

    // Print the wireless network scan results
    struct iw_event *event;
    event = (struct iw_event *) buf;

    while ((char *)event < buf + wrq.u.data.length)
    {
        char ssid[32] = {0};
        short freq = 0, level = 0;
        while (IW_EV_LCP_PK_LEN <= (char *)event - buf + event->len)
        {
            switch (event->cmd)
            {
            case SIOCGIWAP:
                printf("MAC address: %02X:%02X:%02X:%02X:%02X:%02X\n",
                        (unsigned char)event->u.ap_addr.sa_data[0],
                        (unsigned char)event->u.ap_addr.sa_data[1],
                        (unsigned char)event->u.ap_addr.sa_data[2],
                        (unsigned char)event->u.ap_addr.sa_data[3],
                        (unsigned char)event->u.ap_addr.sa_data[4],
                        (unsigned char)event->u.ap_addr.sa_data[5]);
                break;
            case SIOCGIWESSID:
                strncpy(ssid, (const char *)event->u.essid.pointer, event->u.essid.length);
                printf("SSID: %s\n", ssid);
                break;
            case SIOCGIWFREQ:
                freq = event->u.freq.m;
                printf("Frequency: %d.%d GHz\n", freq / 1000, freq % 1000);
                break;
            case SIOCGIWSENS:
                level = event->u.sens.value;
                printf("Signal level: %d dBm\n", level);
                break;
            default:
                break;
            }
            event = (struct iw_event *)((char *)event + event->len);
        }
    }

    close(sock_fd);

    return 0;
}