//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <netinet/if_ether.h>
#include <linux/wireless.h>
#include <sys/ioctl.h>
#include <fcntl.h>

void analyze_networks(const char *interface) {
    int sockfd;
    struct iwreq req;
    struct iw_event event;
    char buffer[4096];
    
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed!");
        exit(EXIT_FAILURE);
    }
    
    strncpy(req.ifr_name, interface, IFNAMSIZ);
    
    if (ioctl(sockfd, SIOCGIWAP, &req) < 0) {
        perror("Failed to get access point information!");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    
    printf("Ah, what do we have here? A plethora of Wi-Fi networks successfully uncovered.\n");
    printf("== Wi-Fi Signal Strength Analysis ==\n");
    printf("%-40s %-10s\n", "Network Name", "Signal (dBm)");
    printf("=====================================\n");

    FILE *fp = popen("nmcli dev wifi", "r");
    if (fp == NULL) {
        perror("Error running nmcli command!");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        char ssid[50];
        int signal_strength;
        if (sscanf(buffer, " %49[^ ] %d", ssid, &signal_strength) == 2) {
            printf("%-40s %-10d\n", ssid, signal_strength);
        }
    }
    
    pclose(fp);
    close(sockfd);
    printf("=====================================\n");
    printf("Elementary, my dear Watson! We have gathered sufficient intelligence.\n");
}

int main() {
    printf("Sherlock Holmes Wi-Fi Signal Strength Analyzer\n");
    printf("===============================================\n\n");
    
    char interface[IFNAMSIZ] = "wlan0";
    printf("Alas! My electromagnetic field detector will be scanning on the interface: %s\n\n", interface);
    
    analyze_networks(interface);
    
    printf("Our investigation yields actionable insights.\n");
    printf("Until the next case, we shall enjoy our findings!\n");
    
    return 0;
}