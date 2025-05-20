//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIFI_NETWORKS 10
#define MAX_WIFI_DATA_SIZE 1024

struct wifi_network {
    char ssid[32];
    int signal_strength;
    int channel;
    int security_type;
};

struct wifi_data {
    int num_networks;
    struct wifi_network networks[MAX_WIFI_NETWORKS];
};

void get_wifi_data(struct wifi_data* data) {
    FILE* fp = fopen("/proc/net/wireless", "r");
    if (fp == NULL) {
        printf("Error: could not open /proc/net/wireless\n");
        exit(1);
    }

    char line[MAX_WIFI_DATA_SIZE];
    while (fgets(line, MAX_WIFI_DATA_SIZE, fp)!= NULL) {
        if (strncmp(line, "wlan", 4) == 0) {
            struct wifi_network* network = &data->networks[data->num_networks++];
            sscanf(line, "wlan%d: %s %d %d %d %d %d\n",
                &network->channel,
                network->ssid,
                &network->signal_strength,
                &network->security_type);
        }
    }

    fclose(fp);
}

void print_wifi_data(const struct wifi_data* data) {
    printf("Number of networks: %d\n", data->num_networks);
    for (int i = 0; i < data->num_networks; i++) {
        const struct wifi_network* network = &data->networks[i];
        printf("Network %d:\n", i+1);
        printf("  SSID: %s\n", network->ssid);
        printf("  Channel: %d\n", network->channel);
        printf("  Signal strength: %d\n", network->signal_strength);
        printf("  Security type: %d\n\n", network->security_type);
    }
}

int main() {
    struct wifi_data data;
    get_wifi_data(&data);
    print_wifi_data(&data);
    return 0;
}