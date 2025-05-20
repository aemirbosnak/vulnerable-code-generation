//FormAI DATASET v1.0 Category: Network Ping Test ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netdb.h>

#define PORT 6969

int main() {
    int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_ICMP);
    if (sock < 0) {
        printf("Oops, couldn't create socket, better call the doctor!\n");
        exit(0);
    }
    printf("Your amazing ping test is starting in 3, 2, 1 .....\n");

    struct sockaddr_in srv_address;
    srv_address.sin_family = AF_INET;
    srv_address.sin_port = htons(PORT);
    srv_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    struct timeval tv;
    tv.tv_sec = 2;
    tv.tv_usec = 0;

    if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof(tv)) < 0) {
        printf("Oops, something went wrong with setsockopt. You are doomed!\n");
        exit(0);
    }

    int count = 0;
    for (int i = 0; i < 10; i++) {
        char buffer[32];
        snprintf(buffer, sizeof(buffer), "Hello server, this is ping #%d", i);
        int start = gettimeofday(NULL, NULL);
        sendto(sock, buffer, sizeof(buffer), 0, (struct sockaddr*)&srv_address, sizeof(srv_address));
        recvfrom(sock, buffer, sizeof(buffer), 0, NULL, NULL);
        int end = gettimeofday(NULL, NULL);
        printf("Ping %d: Elapsed time is %ld microseconds. The server says: %s\n", i, end-start, buffer);
        count++;
        sleep(1);
    }

    printf("Your ping test is complete! You sent %d requests.\n", count);
    close(sock);
    return 0;
}