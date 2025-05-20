//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <linux/wireless.h>
#include <sys/ioctl.h>

int main(){

    // Create socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd < 0){
        perror("Error creating socket.");
        return 1;
    }

    // Define wireless interface
    char interface[10];
    printf("Enter wireless interface name: ");
    scanf("%s", interface);

    // Get interface index
    struct ifreq ifr;
    strncpy(ifr.ifr_name, interface, IFNAMSIZ);
    if(ioctl(sockfd, SIOCGIFINDEX, &ifr) < 0){
        perror("Error getting interface index.");
        return 1;
    }

    // Set up wireless request struct
    struct iwreq request;
    memset(&request, 0, sizeof(request));
    request.u.data.pointer = NULL;
    request.u.data.length = 0;
    request.u.data.flags = 1;
    request.u.data.flags |= IW_SCAN_THIS_ESSID;

    // Set interface
    strncpy(request.ifr_name, interface, IFNAMSIZ);

    // Get scan results
    if(ioctl(sockfd, SIOCSIWSCAN, &request) < 0){
        perror("Error scanning wireless network.");
        return 1;
    }

    // Gather scan results
    int max_scan_results = 10;
    int scan_result_count = 0;
    struct iw_event iwe;
    char scan_results[max_scan_results][40];
    char *current_event;
    while(1){
        current_event = (char*)&iwe;
        if(read(sockfd, &iwe, IW_EV_LCP_LEN) < 0){
            perror("Error reading wireless event.");
            return 1;
        }

        // Check for end of scan
        if(iwe.cmd == SIOCGIWSCAN){
            break;
        }

        // Gather scan result
        if(iwe.cmd == SIOCGIWFREQ){
            current_event += IW_EV_POINT_LEN;
            struct iw_freq *freq = (struct iw_freq*)current_event;
            current_event += IW_EV_POINT_LEN;
            char ssid[40];
            memset(ssid, 0, sizeof(ssid));
            int ssid_length = iwe.u.data.length - sizeof(struct iw_freq);
            memcpy(ssid, current_event, ssid_length);
            sprintf(scan_results[scan_result_count], "%s\t%.1fGHz", ssid, ((double)freq->m) / 1000);
            scan_result_count++;
            if(scan_result_count >= max_scan_results){
                break;
            }
        }
    }

    // Display scan results
    printf("\nWireless Networks:\n");
    for(int i = 0; i < scan_result_count; i++){
        printf("%s\n", scan_results[i]);
    }

    // Close socket
    close(sockfd);

    return 0;
}