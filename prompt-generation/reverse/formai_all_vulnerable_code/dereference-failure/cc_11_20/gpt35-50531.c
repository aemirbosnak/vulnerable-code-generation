//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_INTERFACE_NAME_LEN 40
#define MAX_IP_ADDR_LEN 40
#define MAX_SSID_LEN 32
#define MAX_SIGNAL_STRENGTH_LEN 5

struct wifi_info {
    char ifname[MAX_INTERFACE_NAME_LEN];
    char ip_addr[MAX_IP_ADDR_LEN];
    char ssid[MAX_SSID_LEN];
    char signal_strength[MAX_SIGNAL_STRENGTH_LEN];
};

int main() {
    struct ifaddrs *ifaddr, *ifa;
    int family, s, n;
    char host[MAX_IP_ADDR_LEN];

    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }

    printf("Wi-Fi Networks Signal Strength Analyzer\n\n");
    printf("%-20s %-20s %-20s %s\n", "Interface", "IP Address", "SSID", "Signal Strength");
    for (ifa = ifaddr, n = 0; ifa != NULL; ifa = ifa->ifa_next, n++) {
        if (ifa->ifa_addr == NULL) {
            continue;
        }

        family = ifa->ifa_addr->sa_family;

        if (family == AF_INET || family == AF_INET6) {
            s = getnameinfo(ifa->ifa_addr, (family == AF_INET) ? sizeof(struct sockaddr_in) :
                                               sizeof(struct sockaddr_in6),
                            host, MAX_IP_ADDR_LEN, NULL, 0, NI_NUMERICHOST);
            if (s != 0) {
                printf("getnameinfo() failed: %s\n", gai_strerror(s));
                exit(EXIT_FAILURE);
            }

            struct wifi_info wifi;
            strncpy(wifi.ifname, ifa->ifa_name, MAX_INTERFACE_NAME_LEN);
            strncpy(wifi.ip_addr, host, MAX_IP_ADDR_LEN);

            if (family == AF_INET) {
                FILE *fp;
                char command[100];
                char wifi_info[100];
                sprintf(command, "/sbin/iwconfig %s", wifi.ifname);
                fp = popen(command, "r");
                if (fp == NULL) {
                    perror("Error opening pipe");
                    exit(EXIT_FAILURE);
                }

                while (fgets(wifi_info, sizeof(wifi_info)-1, fp) != NULL) {
                    if (strstr(wifi_info, "ESSID") != NULL) {
                        sscanf(wifi_info, "%*s %*s \"%[^\"]", wifi.ssid);
                    } else if (strstr(wifi_info, "Signal level") != NULL) {
                        char *p = strstr(wifi_info, "=");
                        p += 2;
                        char *q = strstr(p, "/");
                        q[0] = '\0';
                        strncpy(wifi.signal_strength, p, MAX_SIGNAL_STRENGTH_LEN);
                    }
                }
                pclose(fp);
            }

            printf("%-20s %-20s %-20s %s\n", wifi.ifname, wifi.ip_addr, wifi.ssid, wifi.signal_strength);
        }
    }

    freeifaddrs(ifaddr);
    exit(EXIT_SUCCESS);
}