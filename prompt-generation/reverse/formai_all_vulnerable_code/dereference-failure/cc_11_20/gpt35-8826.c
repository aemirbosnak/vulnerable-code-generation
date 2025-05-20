//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ifaddrs.h>
#include <net/if.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_IFS 64
#define IP_BUF 16

struct interfaces {
    char name[IF_NAMESIZE];
    char ip[IP_BUF];
    char netmask[IP_BUF];
};

struct wireless_networks {
    char ssid[32];
    char bssid[18];
    int channel;
    int strength;
};

int main() {
    struct ifaddrs *addrs, *ifap;
    struct wireless_networks *wifis;
    struct interfaces *ifs;
    int i, j, iw=0, total_ifs=0;
    char cmd[128];
    FILE *fp;

    // allocate memory for interfaces and wifi networks
    ifs = (struct interfaces*) malloc(sizeof(struct interfaces) * MAX_IFS);
    wifis = (struct wireless_networks*) malloc(sizeof(struct wireless_networks) * 32);

    // get all interfaces
    if (getifaddrs(&addrs) == -1) {
        printf("Error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // iterate through each interface
    for (ifap = addrs; ifap != NULL; ifap = ifap->ifa_next) {

        // check for ipv4, up and running interfaces
        if (ifap->ifa_addr->sa_family == AF_INET && (ifap->ifa_flags & IFF_UP) && (ifap->ifa_flags & IFF_RUNNING)) {

            // copy interface name
            strncpy(ifs[total_ifs].name, ifap->ifa_name, IF_NAMESIZE);

            // get string representation of interface ip and copy to ifs[ip]
            inet_ntop(AF_INET, &((struct sockaddr_in*)ifap->ifa_addr)->sin_addr, ifs[total_ifs].ip, IP_BUF);

            // get string representation of interface netmask and copy to ifs[netmask]
            inet_ntop(AF_INET, &((struct sockaddr_in*)ifap->ifa_netmask)->sin_addr, ifs[total_ifs].netmask, IP_BUF);

            total_ifs += 1;
            if (total_ifs >= MAX_IFS) {
                break;
            }
        }
    }

    printf("STATISTICS:\n\nInterfaces Found:\t\t%d\n\n", total_ifs);

    // print all interfaces with their ips and netmasks
    printf("INTERFACE NAME\t\tIP ADDRESS\t\tNETMASK\n");
    for (i=0; i<total_ifs; ++i) {
        printf("%-20s\t%-20s\t%-20s\n", ifs[i].name, ifs[i].ip, ifs[i].netmask);
    }
    printf("\n");

    // loop through all interfaces to check for any wireless interfaces
    for (i=0; i<total_ifs; ++i) {
        snprintf(cmd, 128, "iwconfig %s 2>/dev/null", ifs[i].name);

        // execute iwconfig command and read output to file pointer
        fp = popen(cmd, "r");

        if (fp != NULL) {
            char line[256] = {0};
            char ssid[32] = {0};
            char bssid[18] = {0};
            int channel = 0;
            int strength = 0;

            // read output line by line
            while(fgets(line, sizeof(line), fp) != NULL) {
                char* token = NULL;

                // get ssid and bssid if available
                if ((token = strstr(line, "ESSID:\"")) != NULL) {
                    token += 7;
                    strncpy(ssid, token, strlen(token)-2);
                }
                if ((token = strstr(line, "Access Point:")) != NULL) {
                    token += 15;
                    strncpy(bssid, token, strlen(token)-1);
                }

                // get channel if available
                if ((token = strstr(line, "Frequency:")) != NULL) {
                    token += 11;
                    channel = (int) strtol(token, &token, 10);
                }
                if ((token = strstr(line, "Channel:")) != NULL) {
                    token += 9;
                    channel = (int) strtol(token, &token, 10);
                }

                // get strength if available
                if ((token = strstr(line, "Signal level=")) != NULL) {
                    token += 13;
                    strength = (int) strtol(token, &token, 10);
                }
            }

            // update wifi networks array if ssid is not null
            if (strlen(ssid) > 0) {
                strncpy(wifis[iw].ssid, ssid, 32);
                strncpy(wifis[iw].bssid, bssid, 18);
                wifis[iw].channel = channel;
                wifis[iw].strength = strength;
                iw += 1;
            }

            fclose(fp);
        }
    }

    printf("Wireless Networks Found:\t%d\n\n", iw);

    // print all wireless networks with their ssid, bssid, channel and strength
    printf("SSID\t\t\tBSSID\t\t\tCHANNEL\t\tSTRENGTH\n");
    for (j=0; j<iw; ++j) {
        printf("%-20s\t%-20s\t%-8d\t%-8d\n", wifis[j].ssid, wifis[j].bssid, wifis[j].channel, wifis[j].strength);
    }

    // free up memory
    free(ifs);
    free(wifis);
    freeifaddrs(addrs);

    return EXIT_SUCCESS;
}