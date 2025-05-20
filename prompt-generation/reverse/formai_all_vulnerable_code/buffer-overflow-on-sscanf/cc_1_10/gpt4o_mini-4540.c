//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <ifaddrs.h>
#include <arpa/inet.h>
#include <signal.h>

#define MAX_APS 100
#define MAX_SSID_LENGTH 32
#define MAX_CMD_LENGTH 128

typedef struct {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
} AccessPoint;

AccessPoint aps[MAX_APS];
int num_aps = 0;
int running = 1;

void intHandler(int dummy) {
    running = 0;
}

void parse_line(char *line) {
    char ssid[MAX_SSID_LENGTH];
    int strength = 0;
    if (sscanf(line, "%31s %d", ssid, &strength) == 2) {
        strcpy(aps[num_aps].ssid, ssid);
        aps[num_aps].signal_strength = strength;
        num_aps++;
    }
}

void analyze_signal_strength() {
    printf("\nAnalyzing Wi-Fi Signal Strength...\n");
    printf("| %-32s | %-14s |\n", "SSID", "Signal Strength");
    printf("|----------------------------------------|----------------|\n");
    
    for (int i = 0; i < num_aps; i++) {
        printf("| %-32s | %-14d |\n", aps[i].ssid, aps[i].signal_strength);
    }
    printf("|----------------------------------------|----------------|\n");
}

void scan_wifi() {
    char command[MAX_CMD_LENGTH];
    FILE *fp;

    snprintf(command, sizeof(command), "nmcli -t -f SSID,SIGNAL dev wifi list");
    fp = popen(command, "r");
    if (fp == NULL) {
        perror("Failed to run command");
        exit(1);
    }

    char line[256];
    while (fgets(line, sizeof(line), fp) != NULL) {
        if (num_aps < MAX_APS) {
            parse_line(line);
        } else {
            printf("Maximum number of access points reached.\n");
            break;
        }
    }
    pclose(fp);
}

void print_intro() {
    printf("**************************************************\n");
    printf("*              Welcome to Wi-Fi Analyzer         *\n");
    printf("*                An original creation!           *\n");
    printf("**************************************************\n\n");
}

int main() {
    signal(SIGINT, intHandler);
    print_intro();

    while (running) {
        num_aps = 0; // Reset access points counter
        scan_wifi();
        analyze_signal_strength();
        printf("Press Ctrl+C to stop analyzing...\n");
        sleep(5); // Wait period for rescan
    }

    printf("Exiting Wi-Fi Analyzer. Goodbye!\n");
    return 0;
}