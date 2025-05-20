//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define MAX 100

// Function to get SSID and signal strength
void get_ssid_strength(char *ssid, int *strength) {
    FILE *fp;
    char line[MAX];
    int found = 0;

    fp = popen("iwconfig wlan0 | grep ESSID", "r");
    if (fp == NULL) {
        printf("Error: Unable to open pipe.\n");
        exit(1);
    }

    while (fgets(line, MAX, fp)!= NULL) {
        if (strstr(line, "ESSID")) {
            sscanf(line, "ESSID:%[^:]", ssid);
            found = 1;
        }
    }

    pclose(fp);

    if (!found) {
        printf("Error: Unable to find ESSID.\n");
        exit(1);
    }

    fp = popen("iwconfig wlan0 | grep Quality", "r");
    if (fp == NULL) {
        printf("Error: Unable to open pipe.\n");
        exit(1);
    }

    while (fgets(line, MAX, fp)!= NULL) {
        if (strstr(line, "Quality")) {
            sscanf(line, "Quality=%d/100", strength);
        }
    }

    pclose(fp);
}

// Function to get IP address
void get_ip_address(char *ip) {
    struct hostent *host;
    char hostname[MAX];

    gethostname(hostname, MAX);
    host = gethostbyname(hostname);

    if (host == NULL) {
        printf("Error: Unable to get host by name.\n");
        exit(1);
    }

    memcpy(ip, host->h_addr, host->h_length);
}

// Function to get signal strength as a percentage
int get_signal_strength(int strength) {
    return (strength * 100) / 70;
}

int main() {
    char ssid[MAX];
    int strength;
    char ip[MAX];

    get_ssid_strength(ssid, &strength);
    get_ip_address(ip);

    printf("SSID: %s\n", ssid);
    printf("Signal Strength: %d%%\n", get_signal_strength(strength));
    printf("IP Address: %s\n", ip);

    return 0;
}