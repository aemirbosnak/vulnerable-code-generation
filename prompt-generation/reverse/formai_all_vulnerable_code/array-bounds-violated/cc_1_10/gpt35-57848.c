//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <ifaddrs.h>

#define MAX_DEVICES 100

int devs_found = 0;

typedef struct device {
    char name[50];
    char ip[50];
    char mac[50];
} device;

device devices[MAX_DEVICES];

int scan_network(char *subnet_mask) {
    int sockfd;
    struct ifaddrs *ifaddr, *ifa;
    struct sockaddr_in *sin;
    char *addr;
    char broadcast_address[50];
    int flag, i;

    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }

    for (ifa = ifaddr, i = 0; ifa != NULL; ifa = ifa->ifa_next, i++) {
        if (ifa->ifa_addr == NULL) continue;

        sockfd = socket(AF_INET, SOCK_DGRAM, 0);

        if (sockfd < 0) {
            perror("socket");
            exit(EXIT_FAILURE);
        }

        sin = (struct sockaddr_in *)ifa->ifa_addr;
        addr = inet_ntoa(sin->sin_addr);

        if (strcmp(ifa->ifa_name, "lo") == 0 || strchr(ifa->ifa_name, ':') != NULL) {
            close(sockfd);
            continue;
        }

        sprintf(broadcast_address, "%s/%s", addr, subnet_mask);

        flag = fcntl(sockfd, F_GETFL, 0);
        fcntl(sockfd, F_SETFL, flag | O_NONBLOCK);

        struct timeval tv;
        tv.tv_sec = 1;
        tv.tv_usec = 0;

        if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv) < 0) {
            perror("setsockopt");
            exit(EXIT_FAILURE);
        }

        struct sockaddr_in broadcast_addr;
        memset(&broadcast_addr, 0, sizeof broadcast_addr);
        broadcast_addr.sin_family = AF_INET;
        broadcast_addr.sin_port = htons(1900);
        inet_aton("239.255.255.250", &broadcast_addr.sin_addr);

        int sent = sendto(sockfd, "M-SEARCH * HTTP/1.1\r\nHOST: 239.255.255.250:1900\r\nST: ssdp:all\r\nMAN: \"ssdp:discover\"\r\nMX: 1\r\n\r\n", 155, 0, (struct sockaddr *)&broadcast_addr, sizeof(broadcast_addr));

        if (sent < 155) {
            perror("sendto");
            exit(EXIT_FAILURE);
        }

        char buf[2500];

        while (1) {
            struct sockaddr_in from;
            socklen_t fromlen = sizeof(from);
            int len = recvfrom(sockfd, buf, sizeof buf - 1, 0, (struct sockaddr *)&from, &fromlen);

            if (len < 0) {
                if (errno == EWOULDBLOCK) {
                    break;
                }

                perror("recvfrom");
                exit(EXIT_FAILURE);
            }

            buf[len] = '\0';

            if (strstr(buf, "LOCATION:") != NULL) {
                char *ptr1 = buf + 10;
                char *ptr2 = strstr(ptr1, "\n");
                *ptr2 = '\0';

                char xml_url[500];
                sprintf(xml_url, "%s", ptr1);

                ptr1 = strstr(xml_url, "http://");
                ptr2 = strstr(xml_url, "/description");
                *ptr2 = '\0';

                char xml[2500], command[2500];
                sprintf(xml, "%s/igd.xml", xml_url);

                sprintf(command, "curl --silent %s | grep '<friendlyName>.*</friendlyName><manufacturer>.*</manufacturer><modelDescription>.*</modelDescription><serialNumber>.*</serialNumber><modelNumber>.*</modelNumber><presentationURL>' | sed \"s/.*<friendlyName>\\(.*\\)<\\/friendlyName><manufacturer>\\(.*\\)<\\/manufacturer><modelDescription>\\(.*\\)<\\/modelDescription><serialNumber>\\(.*\\)<\\/serialNumber><modelNumber>\\(.*\\)<\\/modelNumber><presentationURL>\\(.*\\)<\\/presentationURL>/\\1,\\2,\\3,\\4,\\5,\\6/\" | awk -F ',' '{print $1,$2,$3,$4,$5,$6}'", xml);

                FILE *fp = popen(command, "r");
                char response[2500], output[2500];

                while (fgets(response, sizeof response, fp) != NULL) {
                    sprintf(output, "%s", response);
                }

                pclose(fp);

                char friendlyName[50], manufacturer[50], modelDescription[50], serialNumber[50], modelNumber[50], presentationURL[500];
                sscanf(output, "%[^,],%[^,],%[^,],%[^,],%[^,],%s", friendlyName, manufacturer, modelDescription, serialNumber, modelNumber, presentationURL);

                struct hostent *he;
                struct in_addr ipv4addr;

                inet_pton(AF_INET, addr, &ipv4addr);
                he = gethostbyaddr(&ipv4addr, sizeof ipv4addr, AF_INET);

                if (he == NULL) {
                    close(sockfd);
                    continue;
                }

                strcpy(devices[devs_found].name, friendlyName);
                strcpy(devices[devs_found].ip, addr);
                strcpy(devices[devs_found].mac, "NA");

                printf("Device Found:\n");
                printf("Name: %s\n", devices[devs_found].name);
                printf("IP Address: %s\n", devices[devs_found].ip);
                printf("MAC Address: %s\n", devices[devs_found].mac);

                char arp_command[1000], arp_output[1000];
                sprintf(arp_command, "arp -a %s | awk '{print $4}'", devices[devs_found].ip);

                FILE *arp_fp = popen(arp_command, "r");
                fgets(arp_output, sizeof arp_output, arp_fp);
                pclose(arp_fp);

                strcpy(devices[devs_found].mac, arp_output);

                printf("Device Found:\n");
                printf("Name: %s\n", devices[devs_found].name);
                printf("IP Address: %s\n", devices[devs_found].ip);
                printf("MAC Address: %s\n", devices[devs_found].mac);

                devs_found++;

                if (devs_found >= MAX_DEVICES) {
                    close(sockfd);
                    break;
                }
            }
        }

        close(sockfd);
    }

    freeifaddrs(ifaddr);

    return devs_found;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Incorrect usage. Usage: %s <subnet-mask>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int num_devs = scan_network(argv[1]);

    printf("\nTotal Devices Found: %d\n", num_devs);

    return 0;
}