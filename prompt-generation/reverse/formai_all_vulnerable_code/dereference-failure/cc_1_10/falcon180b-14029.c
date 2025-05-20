//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define TRUE 1
#define FALSE 0
#define MAX 100

struct wifi_data {
    char ssid[MAX];
    int signal_strength;
};

void get_wifi_data(struct wifi_data *wifi_data) {
    FILE *fp;
    char line[MAX];
    char delim[] = " ";
    char *token;

    fp = popen("iwconfig wlan0 | grep 'Link Quality'", "r");
    if (fp == NULL) {
        printf("Error: Failed to run command.\n");
        exit(1);
    }

    while (fgets(line, MAX, fp)!= NULL) {
        token = strtok(line, delim);
        strcpy(wifi_data->ssid, token);

        token = strtok(NULL, delim);
        sscanf(token, "%d", &wifi_data->signal_strength);
    }

    pclose(fp);
}

void print_wifi_data(struct wifi_data wifi_data) {
    printf("SSID: %s\n", wifi_data.ssid);
    printf("Signal Strength: %d\n", wifi_data.signal_strength);
}

int main() {
    struct wifi_data wifi_data;

    get_wifi_data(&wifi_data);
    print_wifi_data(wifi_data);

    return 0;
}