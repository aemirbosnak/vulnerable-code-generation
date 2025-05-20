//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

struct device {
    char *name;
    char *mac;
    int signal;
};

int get_devices(struct device *devices, int max_devices) {
    char *interface = "wlan0";
    FILE *fp;
    char line[1024];
    int count = 0;

    fp = popen("iwlist scan", "r");
    if (fp == NULL) {
        printf("Error: %s\n", strerror(errno));
        return -1;
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (count >= max_devices) {
            break;
        }
        if (strstr(line, "Address") && strstr(line, "SSID")) {
            char *ssid_start = strstr(line, "SSID") + 5;
            char *ssid_end = strchr(ssid_start, '\n');
            *ssid_end = '\0';
            char *mac_start = strstr(line, "Address") + 8;
            char *mac_end = strchr(mac_start, '\n');
            *mac_end = '\0';
            devices[count].name = strdup(ssid_start);
            devices[count].mac = strdup(mac_start);
            count++;
        }
    }

    pclose(fp);
    return count;
}

int main(int argc, char *argv[]) {
    int max_devices = 10;
    struct device devices[max_devices];
    int num_devices = get_devices(devices, max_devices);

    for (int i = 0; i < num_devices; i++) {
        printf("Name: %s\n", devices[i].name);
        printf("MAC: %s\n", devices[i].mac);
        printf("Signal: %d\n\n", devices[i].signal);
    }

    return 0;
}