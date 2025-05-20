//GPT-4o-mini DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define MAX_INTERFACES 10
#define MAX_SSID_LENGTH 32
#define MAX_CMD_LENGTH 256

typedef struct WifiSignal {
    char ssid[MAX_SSID_LENGTH];
    int signal_strength;
} WifiSignal;

void trim_whitespace(char *str) {
    char *end;

    while (isspace((unsigned char) *str)) str++;
    if (*str == 0) return;

    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char) *end)) end--;

    end[1] = '\0';
}

void exec_command(const char *cmd, char *output, size_t size) {
    FILE *fp;
    fp = popen(cmd, "r");
    if (fp == NULL) {
        perror("popen failed");
        return;
    }

    fgets(output, size, fp);
    pclose(fp);
}

void parse_signal_strength(const char *output, WifiSignal *wifi) {
    char *line = strtok((char *)output, "\n");
    while (line) {
        trim_whitespace(line);
        if (line[0] != '\0') {
            sscanf(line, "%s %d", wifi->ssid, &wifi->signal_strength);
        }
        line = strtok(NULL, "\n");
    }
}

void display_signal_strength(WifiSignal *wifi_signals, int count) {
    printf("\nWi-Fi Signal Strength Analyzer\n");
    printf("-----------------------------------\n");
    printf("%-30s %s\n", "SSID", "Signal Strength (dBm)");
    printf("-----------------------------------\n");
    for (int i = 0; i < count; ++i) {
        printf("%-30s %d\n", wifi_signals[i].ssid, wifi_signals[i].signal_strength);
    }
    printf("-----------------------------------\n");
}

int main() {
    char cmd[MAX_CMD_LENGTH] = "nmcli -f SSID,SIGNAL dev wifi";
    char output[1024];
    
    WifiSignal wifi_signals[MAX_INTERFACES];
    int count = 0;

    exec_command(cmd, output, sizeof(output));

    parse_signal_strength(output, wifi_signals);

    for (int i = 0; i < MAX_INTERFACES; ++i) {
        if (strlen(wifi_signals[i].ssid) > 0) {
            count++;
        }
    }

    display_signal_strength(wifi_signals, count);
    return 0;
}