//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_STR_LEN 100
#define MAX_NUM_SSIDS 10
#define MAX_NUM_CHANNELS 14

struct SSID {
    char name[MAX_STR_LEN];
    int channel;
};

struct SSID ssids[MAX_NUM_SSIDS];
int num_ssids;

void add_ssid(char* name, int channel) {
    struct SSID* last_ssid = &ssids[num_ssids - 1];
    if (strcmp(last_ssid->name, name) == 0) {
        last_ssid->channel = channel;
    } else {
        num_ssids++;
        strcpy(ssids[num_ssids - 1].name, name);
        ssids[num_ssids - 1].channel = channel;
    }
}

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[1024];
    char line[MAX_STR_LEN];
    char* token;
    int num_tokens;
    char* ssid_name;
    int ssid_channel;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(1234);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr));

    while (fgets(line, MAX_STR_LEN, stdin)!= NULL) {
        num_tokens = sscanf(line, "%s %d", ssid_name, &ssid_channel);
        if (num_tokens == 2) {
            add_ssid(ssid_name, ssid_channel);
        }
    }

    close(sock);

    for (int i = 0; i < num_ssids; i++) {
        printf("SSID: %s, Channel: %d\n", ssids[i].name, ssids[i].channel);
    }

    return 0;
}