//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_WIFI_NETWORKS 50

struct wifi_network {
    char ssid[32];
    int signal_strength;
    time_t last_seen;
};

void add_wifi_network(struct wifi_network *networks, int count, const char *ssid, int signal_strength) {
    if(count >= MAX_WIFI_NETWORKS) {
        printf("Error: maximum number of wifi networks reached.\n");
        return;
    }

    int i;
    for(i = 0; i < count; i++) {
        if(strcmp(networks[i].ssid, ssid) == 0) {
            networks[i].signal_strength = signal_strength;
            networks[i].last_seen = time(NULL);
            return;
        }
    }

    strcpy(networks[count].ssid, ssid);
    networks[count].signal_strength = signal_strength;
    networks[count].last_seen = time(NULL);
    count++;
}

void print_wifi_networks(struct wifi_network *networks, int count) {
    printf("Wifi networks:\n");
    printf("--------------------\n");

    int i;
    for(i = 0; i < count; i++) {
        printf("%-32s %-6d %s\n", networks[i].ssid, networks[i].signal_strength, ctime(&networks[i].last_seen));
    }
}

int main() {
    struct wifi_network networks[MAX_WIFI_NETWORKS];
    int count = 0;

    while(1) {
        int signal_strength;
        char ssid[32];

        printf("Enter wifi network SSID (or type 'exit' to quit): ");
        scanf("%s", ssid);

        if(strcmp(ssid, "exit") == 0) {
            break;
        }

        signal_strength = rand() % 101;
        add_wifi_network(networks, count, ssid, signal_strength);

        printf("Wifi network '%s' added with signal strength %d.\n", ssid, signal_strength);
    }

    print_wifi_networks(networks, count);

    return 0;
}