//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_SSID_LEN 32
#define MAX_SCAN_RESULTS 10

typedef struct {
    char ssid[MAX_SSID_LEN];
    int signal_strength;
} wifi_info;

void clear_screen() {
    printf("\033[2J\033[1;1H");
}

void print_header() {
    printf("   █████╗ ████████╗████████╗██╗  ██╗ █████╗ ███████╗\n");
    printf("  ██╔══██╗╚══██╔══╝╚══██╔══╝██║  ██║██╔══██╗██╔════╝\n");
    printf("  ███████║   ██║      ██║   ███████║███████║███████╗\n");
    printf("  ██╔══██║   ██║      ██║   ██╔══██║██╔══██║╚════██║\n");
    printf("  ██║  ██║   ██║      ██║   ██║  ██║██║  ██║███████║\n");
    printf("  ╚═╝  ╚═╝   ╚═╝      ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝\n");
    printf("\n------------------------v1.0.0------------------------\n");
    printf("         Wi-Fi Signal Strength Analyzer for Paranoids\n\n");
}

char *get_ssid_info(char *cmd) {
    FILE *fp;
    char path[1035];
    char *info = malloc(MAX_SSID_LEN * sizeof(char));
    
    memset(path, 0x00, sizeof(path));
    fp = popen(cmd, "r");
    if (fp == NULL) {
        printf("[Error] Could not get SSID info\n");
        return NULL;
    }

    while (fgets(path, sizeof(path)-1, fp) != NULL) {
        strncpy(info, path, MAX_SSID_LEN);
    }

    if (strlen(info) == 0) {
        printf("[Error] Could not get SSID info\n");
        return NULL;
    }

    pclose(fp);
    return info;
}

int get_signal_strength(char *ssid) {
    char cmd[100];
    memset(cmd, 0x00, sizeof(cmd));
    sprintf(cmd, "airport -I | grep \"%s\" | sed 's/.*: //'", ssid);
    char *info = get_ssid_info(cmd);
    if (info == NULL) {
        return -1;
    }

    int signal_strength = atoi(info);
    free(info);
    return signal_strength;
}

int find_wifi_info(wifi_info *scan_results, int num_results, char *ssid) {
    for (int i = 0; i < num_results; i++) {
        if (strcmp(scan_results[i].ssid, ssid) == 0) {
            return i;
        }
    }
    return -1;
}

void update_scan_results(wifi_info *scan_results, int *num_results, char *ssid, int signal_strength) {
    int index = find_wifi_info(scan_results, *num_results, ssid);
    if (index == -1) {
        if (*num_results < MAX_SCAN_RESULTS) {
            strncpy(scan_results[*num_results].ssid, ssid, MAX_SSID_LEN);
            scan_results[*num_results].signal_strength = signal_strength;
            (*num_results)++;
        } else {
            printf("[Warning] Maximum number of results reached. Ignoring new SSID\n");
        }
    } else {
        scan_results[index].signal_strength = signal_strength;
    }
}

void print_scan_results(wifi_info *scan_results, int num_results) {
    printf("SSID\t\tSignal Strength\n");
    printf("------------------------------------------------------\n");
    for (int i = 0; i < num_results; i++) {
        printf("%s\t\t%d dBm\n", scan_results[i].ssid, scan_results[i].signal_strength);
    }
    printf("\n");
}

void sort_scan_results(wifi_info *scan_results, int num_results) {
    for (int i = 0; i < num_results-1; i++) {
        for (int j = 0; j < num_results-i-1; j++) {
            if (scan_results[j].signal_strength < scan_results[j+1].signal_strength) {
                wifi_info temp = scan_results[j];
                scan_results[j] = scan_results[j+1];
                scan_results[j+1] = temp;
            }
        }
    }
}

void print_help() {
    printf("Wi-Fi Signal Strength Analyzer for Paranoids Help\n\n");
    printf("Commands:\n");
    printf("  s - Scan for Wi-Fi Networks and Signal Strengths\n");
    printf("  p - Print Previously Scanned Wi-Fi Networks and Signal Strengths\n");
    printf("  h - Print Help\n");
    printf("  q - Quit\n\n");
}

int main() {
    clear_screen();
    print_header();
    print_help();

    wifi_info scan_results[MAX_SCAN_RESULTS];
    int num_results = 0;
    char command;

    while (1) {
        printf(">> ");
        scanf("%c", &command);
        while (getchar() != '\n') {}

        if (tolower(command) == 'q') {
            break;
        } else if (tolower(command) == 's') {
            printf("Scanning for Wi-Fi Networks and Signal Strengths...\n\n");
            char *ssid = get_ssid_info("airport -s | awk '{print $1}'");
            if (ssid == NULL) {
                continue;
            }

            char *token = strtok(ssid, "\n");
            while (token != NULL) {
                int signal_strength = get_signal_strength(token);
                if (signal_strength == -1) {
                    continue;
                }
                update_scan_results(scan_results, &num_results, token, signal_strength);
                token = strtok(NULL, "\n");
            }

            sort_scan_results(scan_results, num_results);
            print_scan_results(scan_results, num_results);
            free(ssid);
        } else if (tolower(command) == 'p') {
            if (num_results == 0) {
                printf("No previously scanned Wi-Fi networks\n\n");
            } else {
                sort_scan_results(scan_results, num_results);
                print_scan_results(scan_results, num_results);
            }
        } else if (tolower(command) == 'h') {
            print_help();
        } else {
            printf("[Error] Invalid Command\n");
        }
    }

    printf("Exiting Wi-Fi Signal Strength Analyzer for Paranoids...\n");

    return 0;
}