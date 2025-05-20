//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIGNAL 100
#define MIN_SIGNAL 0

typedef struct {
    int strength;
    char* ssid;
} wifi_t;

void display_wifi_details(wifi_t wifi[], int size) {
    int i;
    printf("\nWi-Fi Details:\n");
    for (i = 0; i < size; ++i) {
        printf("SSID: %s\n", wifi[i].ssid);
        printf("Signal Strength: %d\n", wifi[i].strength);
        printf("\n");
    }
}

void display_welcome_message() {
    printf("Welcome to Wi-Fi Signal Strength Analyzer!\n\n");
    printf("This program will analyze the Wi-Fi signal strength around you and provide you with the details.\n\n");
}

void check_wifis(wifi_t wifi[], int size) {
    int i;
    printf("Checking Wi-Fis...\n\n");
    for (i = 0; i < size; ++i) {
        wifi[i].strength = rand() % (MAX_SIGNAL + 1 - MIN_SIGNAL) + MIN_SIGNAL;
    }
}

void sort_wifis(wifi_t wifi[], int size) {
    int i, j;
    wifi_t temp;
    for (i = 0; i < size; ++i) {
        for (j = i + 1; j < size; ++j) {
            if (wifi[i].strength < wifi[j].strength) {
                temp = wifi[i];
                wifi[i] = wifi[j];
                wifi[j] = temp;
            }
        }
    }
}

int main() {
    int i, num_wifi;
    wifi_t *wifi;

    srand(time(NULL));

    display_welcome_message();

    printf("How many Wi-Fi networks do you want to check? ");
    scanf("%d", &num_wifi);

    wifi = (wifi_t*) malloc(num_wifi * sizeof(wifi_t));
    if (wifi == NULL) {
        printf("Sorry, memory allocation failed.\n");
        return 1;
    }

    for (i = 0; i < num_wifi; ++i) {
        printf("Enter the SSID and press Enter: ");
        scanf("%ms", &(wifi[i].ssid));
    }

    check_wifis(wifi, num_wifi);

    display_wifi_details(wifi, num_wifi);

    sort_wifis(wifi, num_wifi);

    printf("\nWi-Fi networks sorted by signal strength:\n");
    for (i = 0; i < num_wifi; ++i) {
        printf("%s: %d\n", wifi[i].ssid, wifi[i].strength);
    }

    free(wifi);

    return 0;
}