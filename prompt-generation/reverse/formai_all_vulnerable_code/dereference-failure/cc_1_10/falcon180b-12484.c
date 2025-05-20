//Falcon-180B DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_SSID_LENGTH 32
#define MAX_SIGNAL_STRENGTH 100

struct SSID_SIGNAL {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
};

void print_ssids(struct SSID_SIGNAL *ssids, int count) {
    printf("SSID\t\tSignal Strength\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t\t%d\n", ssids[i].ssid, ssids[i].signal_strength);
    }
}

int main() {
    FILE *fp;
    char line[1024];
    char delimiter = '\t';
    struct SSID_SIGNAL ssids[100];
    int count = 0;

    fp = popen("iwlist scan", "r");

    if (fp == NULL) {
        printf("Error: Failed to run iwlist scan.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (count >= 100) {
            printf("Error: Maximum number of SSIDs reached.\n");
            break;
        }

        char *token = strtok(line, &delimiter);
        if (token == NULL)
            continue;

        strcpy(ssids[count].ssid, token);

        token = strtok(NULL, &delimiter);
        if (token == NULL)
            continue;

        ssids[count].signal_strength = atoi(token);

        count++;
    }

    pclose(fp);

    if (count == 0) {
        printf("No SSIDs found.\n");
        return 1;
    }

    print_ssids(ssids, count);

    return 0;
}