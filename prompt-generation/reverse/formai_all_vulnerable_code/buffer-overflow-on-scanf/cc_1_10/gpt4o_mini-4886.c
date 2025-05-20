//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip_icmp.h>
#include <errno.h>
#include <signal.h>

#define PACKET_SIZE 64
#define PING_INTERVAL 1
#define TIMEOUT 1
#define MAX_PINGS 5

typedef struct {
    struct sockaddr_in addr;
    pid_t pid;
} Player;

Player players[10];
int player_count = 0;

void handle_sigint(int sig) {
    printf("\nExiting ping test...\n");
    exit(0);
}

unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2)
        sum += *buf++;
    if (len == 1)
        sum += *(unsigned char *)buf;
    
    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

void add_player(const char *ip_address) {
    if (player_count < 10) {
        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(0);
        inet_pton(AF_INET, ip_address, &addr.sin_addr);
        
        players[player_count].addr = addr;
        players[player_count].pid = getpid();
        
        printf("Added player with IP: %s\n", ip_address);
        player_count++;
    } else {
        printf("Max number of players reached.\n");
    }
}

void ping_player(Player *player) {
    int sockfd;
    char packet[PACKET_SIZE];
    struct icmphdr *icmp_hdr = (struct icmphdr *)packet;
    struct sockaddr_in r_addr;
    socklen_t addr_len = sizeof(r_addr);
    int sent, received;
   
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return;
    }

    memset(packet, 0, PACKET_SIZE);
    
    icmp_hdr->type = ICMP_ECHO;
    icmp_hdr->un.echo.id = player->pid;
    icmp_hdr->un.echo.sequence = 1;
    icmp_hdr->checksum = checksum(packet, PACKET_SIZE);
    
    for (received = 0; received < MAX_PINGS; received++) {
        sent = sendto(sockfd, packet, PACKET_SIZE, 0, (struct sockaddr *)&player->addr, sizeof(player->addr));
        if (sent < 0) {
            perror("Send failed");
            close(sockfd);
            return;
        }
        
        printf("Ping sent to %s\n", inet_ntoa(player->addr.sin_addr));
        
        if (recvfrom(sockfd, packet, PACKET_SIZE, 0, (struct sockaddr *)&r_addr, &addr_len) < 0) {
            printf("Ping to %s failed: %s\n", inet_ntoa(player->addr.sin_addr), strerror(errno));
        } else {
            printf("Ping response received from %s\n", inet_ntoa(r_addr.sin_addr));
        }
        sleep(PING_INTERVAL);
    }

    close(sockfd);
}

int main() {
    char ip_address[16];
    int choice;

    signal(SIGINT, handle_sigint);
    
    while (1) {
        printf("1. Add Player IP\n2. Start Ping Test\n3. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter IP address to add: ");
            scanf("%s", ip_address);
            add_player(ip_address);
            break;
        case 2:
            for (int i = 0; i < player_count; i++) {
                ping_player(&players[i]);
            }
            break;
        case 3:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid option. Try again.\n");
        }
    }

    return 0;
}