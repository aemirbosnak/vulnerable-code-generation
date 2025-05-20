//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define MAX_SSID_LENGTH 32

struct wifi_data {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
};

int main() {
    char iface[10] = "wlan0";
    char cmd[50];
    FILE *fp;
    char line[BUFFER_SIZE];
    int count = 0;
    struct wifi_data wifis[10];

    sprintf(cmd, "iwlist %s scan | grep ESSID", iface);

    fp = popen(cmd, "r");

    if (fp == NULL) {
        printf("Error: Failed to run command.\n");
        exit(1);
    }

    while (fgets(line, BUFFER_SIZE, fp)!= NULL) {
        if (count >= 10) {
            printf("Error: Maximum number of Wi-Fi networks reached.\n");
            exit(1);
        }

        if (sscanf(line, "ESSID:\"%[^\"]", wifis[count].ssid) == 1) {
            wifis[count].signal_strength = atoi(strtok(line, " "));
            count++;
        }
    }

    pclose(fp);

    printf("Wi-Fi Network SSID\tSignal Strength\n");

    for (int i = 0; i < count; i++) {
        printf("%s\t\t%d\n", wifis[i].ssid, wifis[i].signal_strength);
    }

    return 0;
}