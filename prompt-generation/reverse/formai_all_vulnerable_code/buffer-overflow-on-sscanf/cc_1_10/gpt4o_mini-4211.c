//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <signal.h>

#define MAX_SSID_LEN 32
#define MAX_AP_COUNT 100

typedef struct {
    char ssid[MAX_SSID_LEN];
    int signal_strength;
} AccessPoint;

AccessPoint access_points[MAX_AP_COUNT];
int ap_count = 0;

void handle_signal(int signal) {
    if (signal == SIGINT) {
        printf("\nExiting Wi-Fi Signal Strength Analyzer...\n");
        exit(0);
    }
}

void parse_command_output(char *output) {
    char *line = strtok(output, "\n");
    while (line != NULL) {
        char ssid[MAX_SSID_LEN];
        int strength;

        if (sscanf(line, "%31s %d", ssid, &strength) == 2) {
            // Add to access points list if below max count
            if (ap_count < MAX_AP_COUNT) {
                strncpy(access_points[ap_count].ssid, ssid, MAX_SSID_LEN);
                access_points[ap_count].signal_strength = strength;
                ap_count++;
            } else {
                printf("Warning: Maximum Access Point count reached.\n");
            }
        }
        line = strtok(NULL, "\n");
    }
}

void display_signal_strength() {
    printf("\nAccess Point Signal Strength\n");
    printf("-----------------------------\n");
    for (int i = 0; i < ap_count; i++) {
        printf("SSID: %-32s Signal Strength: %d dBm\n", access_points[i].ssid, access_points[i].signal_strength);
    }
}

void sort_access_points() {
    for (int i = 0; i < ap_count - 1; i++) {
        for (int j = 0; j < ap_count - i - 1; j++) {
            if (access_points[j].signal_strength < access_points[j + 1].signal_strength) {
                AccessPoint temp = access_points[j];
                access_points[j] = access_points[j + 1];
                access_points[j + 1] = temp;
            }
        }
    }
}

void run_signal_analysis() {
    char command_output[1024];
    FILE *fp;

    fp = popen("nmcli -f ssid,signal device wifi list", "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to run command\n");
        exit(1);
    }

    fread(command_output, sizeof(char), sizeof(command_output) - 1, fp);
    command_output[sizeof(command_output) - 1] = '\0'; // Null-terminate

    parse_command_output(command_output);
    pclose(fp);
}

int main() {
    signal(SIGINT, handle_signal);

    while (1) {
        ap_count = 0; // Reset access point count
        run_signal_analysis();
        sort_access_points();
        display_signal_strength();
        
        printf("\nAnalyzing signal strength every 5 seconds...\n");
        sleep(5);
    }
    
    return 0;
}