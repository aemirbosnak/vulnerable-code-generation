//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <sys/ioctl.h>
#include <linux/wireless.h>
#include <linux/if_packet.h>
#include <linux/if_arp.h>

int main()
{
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if(sock == -1)
    {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(1234);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    char* interface = "wlan0";
    int s = socket(AF_INET, SOCK_DGRAM, 0);
    struct ifreq ifr;
    strcpy(ifr.ifr_name, interface);
    ioctl(s, SIOCGIFINDEX, &ifr);
    close(s);

    int i = ifr.ifr_ifindex;
    char buffer[1024];
    sprintf(buffer, "iw dev %s info | grep signal", interface);
    FILE *fp = popen(buffer, "r");
    char line[1024];
    while (fgets(line, sizeof(line), fp)!= NULL)
    {
        sscanf(line, "Signal level=%*d dBm", &i);
    }
    pclose(fp);

    while(1)
    {
        int n = sendto(sock, "Hello", strlen("Hello"), 0, (struct sockaddr *)&server, sizeof(server));
        if(n == -1)
        {
            printf("Error sending message\n");
            exit(1);
        }
        usleep(500000);
    }

    close(sock);
    return 0;
}