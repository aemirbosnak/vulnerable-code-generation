//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_SSIDS 10
#define MAX_SSID_LEN 32
#define MAX_SAMPLE_SIZE 100

struct {
    char ssid[MAX_SSID_LEN];
    int signal_strength;
} ssids[MAX_SSIDS];

int num_ssids = 0;

void add_ssid(char* ssid, int signal_strength) {
    if (num_ssids >= MAX_SSIDS) {
        printf("Error: Maximum number of SSIDs reached.\n");
        return;
    }

    strncpy(ssids[num_ssids].ssid, ssid, MAX_SSID_LEN);
    ssids[num_ssids].signal_strength = signal_strength;

    num_ssids++;
}

void print_ssids() {
    printf("SSIDs:\n");

    for (int i = 0; i < num_ssids; i++) {
        printf("%s: %d\n", ssids[i].ssid, ssids[i].signal_strength);
    }
}

void clear_ssids() {
    num_ssids = 0;
}

int main() {
    printf("Wi-Fi Signal Strength Analyzer\n");

    char input[MAX_SSID_LEN];
    int signal_strength;

    while (1) {
        printf("Enter SSID or type 'list' to view SSIDs: ");
        scanf("%s", input);

        if (strcmp(input, "list") == 0) {
            print_ssids();
        } else {
            signal_strength = atoi(input);

            if (signal_strength < 0 || signal_strength > 100) {
                printf("Invalid signal strength.\n");
            } else {
                add_ssid(input, signal_strength);
            }
        }
    }

    return 0;
}