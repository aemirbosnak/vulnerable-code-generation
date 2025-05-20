//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SSID_LEN 32
#define MAX_SSID_NUM 10
#define MAX_RSSI_NUM 10
#define MAX_TOTAL_NUM 100

typedef struct {
    char ssid[MAX_SSID_LEN];
    int rssi;
} WIFI_SIGNAL;

void add_wifi_signal(WIFI_SIGNAL *list, int num, char *ssid, int rssi) {
    if (num >= MAX_SSID_NUM) {
        printf("Error: SSID number exceeds maximum limit.\n");
        return;
    }
    strcpy(list[num].ssid, ssid);
    list[num].rssi = rssi;
}

void sort_wifi_signal(WIFI_SIGNAL *list, int num) {
    for (int i = 0; i < num - 1; i++) {
        for (int j = i + 1; j < num; j++) {
            if (list[j].rssi < list[i].rssi) {
                WIFI_SIGNAL temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}

void print_wifi_signal(WIFI_SIGNAL *list, int num) {
    printf("SSID\tRSSI\n");
    for (int i = 0; i < num; i++) {
        printf("%s\t%d\n", list[i].ssid, list[i].rssi);
    }
}

int main() {
    WIFI_SIGNAL wifi_list[MAX_SSID_NUM];
    int total_num = 0;
    char input[MAX_SSID_LEN];
    int rssi;

    printf("Enter SSID and RSSI (in format SSID:RSSI):\n");
    while (total_num < MAX_TOTAL_NUM && scanf("%s:%d", input, &rssi) == 2) {
        add_wifi_signal(wifi_list, total_num, input, rssi);
        total_num++;
    }

    sort_wifi_signal(wifi_list, total_num);
    printf("Sorted by RSSI:\n");
    print_wifi_signal(wifi_list, total_num);

    return 0;
}