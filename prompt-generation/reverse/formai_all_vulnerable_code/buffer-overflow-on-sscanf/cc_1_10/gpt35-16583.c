//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 512
#define MAX_AP 10

typedef struct AccessPoint {
    char ssid[32];
    int signal_strength;
} AccessPoint;

void clear_buffer() {
    while (getchar() != '\n');
}

void trim_string(char *str) {
    int i = 0, j = strlen(str) - 1;
    while (isspace(str[i])) i++;
    while (isspace(str[j])) j--;
    str[j + 1] = '\0';
    memmove(str, str + i, j - i + 2);
}

int read_access_points(AccessPoint *aps) {
    int n = 0;
    char buf[MAX_LINE];
    printf("Enter the number of access points you want to check (max %d): ", MAX_AP);
    if (!fgets(buf, MAX_LINE, stdin)) return -1;
    sscanf(buf, "%d", &n);
    if (n > MAX_AP) n = MAX_AP;
    for (int i = 0; i < n; i++) {
        printf("Enter the SSID for access point %d: ", i + 1);
        if (!fgets(aps[i].ssid, 32, stdin)) return -1;
        trim_string(aps[i].ssid);
        printf("Enter the signal strength (dBm) for access point %d: ", i + 1);
        if (!fgets(buf, MAX_LINE, stdin)) return -1;
        sscanf(buf, "%d", &aps[i].signal_strength);
    }
    return n;
}

void print_signal_strength(int signal_strength) {
    if (signal_strength > -50) printf("Excellent");
    else if (signal_strength > -60) printf("Good");
    else if (signal_strength > -70) printf("Fair");
    else if (signal_strength > -80) printf("Weak");
    else printf("Very Weak");
}

void display_access_points(AccessPoint *aps, int n) {
    printf("%-32s %s\n", "SSID", "Signal Strength");
    for (int i = 0; i < n; i++) {
        printf("%-32s ", aps[i].ssid);
        if (aps[i].signal_strength == -99) printf("Not Available\n");
        else {
            printf("%d dBm (", aps[i].signal_strength);
            print_signal_strength(aps[i].signal_strength);
            printf(")\n");
        }
    }
}

int main() {
    AccessPoint aps[MAX_AP];
    int num_aps = read_access_points(aps);
    if (num_aps <= 0) {
        printf("Error: Invalid number of access points\n");
        return -1;
    }
    display_access_points(aps, num_aps);
    return 0;
}