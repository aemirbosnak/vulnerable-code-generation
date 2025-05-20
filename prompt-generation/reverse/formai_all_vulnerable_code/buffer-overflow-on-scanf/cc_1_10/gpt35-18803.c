//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: complete
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<math.h>

#define MAX_SSID 100
#define MAX_VALUE 1000
#define MAX_FREQUENCY 300
#define MAX_SIGNAL_STRENGTH 100

struct wifi_signal_strength {
    char ssid[MAX_SSID];
    int frequency;
    int signal_strength;
};

struct wifi_signal_strength wifi[MAX_VALUE];

int main() {
    int num_signals;

    printf("Enter the number of signals present: ");
    scanf("%d", &num_signals);

    printf("\n");

    for (int i = 0; i < num_signals; i++) {
        printf("Enter the SSID of the Wifi signal: ");
        scanf("%s", &wifi[i].ssid);

        printf("Enter the frequency of the Wifi signal: ");
        scanf("%d", &wifi[i].frequency);

        printf("Enter the signal strength of the Wifi signal: ");
        scanf("%d", &wifi[i].signal_strength);

        printf("\n");
    }

    printf("The Wifi signals present are:\n");
    for (int i = 0; i < num_signals; i++) {
        printf("%d. %s\n", i+1, wifi[i].ssid);
    }
    printf("\n");

    int choice;

    printf("Enter the number of the Wifi signal for which you want to analyze the signal strength: ");
    scanf("%d", &choice);

    printf("\n");
    float dBm = -1 * (MAX_SIGNAL_STRENGTH - wifi[choice - 1].signal_strength);

    printf("The signal strength of the Wifi signal %d: %.2f dBm\n", choice, dBm);

    printf("\n");

    return 0;
}