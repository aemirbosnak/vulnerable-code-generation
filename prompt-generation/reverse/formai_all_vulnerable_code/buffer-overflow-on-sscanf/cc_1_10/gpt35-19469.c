//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv) {

    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(0);
    }
    int port;
    sscanf(argv[1], "%d", &port);

    struct sockaddr_in si_me, si_other;
    int s, i, slen=sizeof(si_other);
    char buf[32];

    if ((s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1) {
        perror("socket");
        exit(1);
    }

    memset((char *) &si_me, 0, sizeof(si_me));
    si_me.sin_family = AF_INET;
    si_me.sin_port = htons(port);
    si_me.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(s, (struct sockaddr*)&si_me, sizeof(si_me))==-1) {
        perror("bind");
        exit(1);
    }

    while (1) {
        if (recvfrom(s, buf, 32, 0, (struct sockaddr*)&si_other, &slen)==-1) {
            perror("recvfrom()");
            exit(1);
        }
        printf("Received packet from %s:%d\nData: %s\n\n",
               inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port), buf);

        // get current time
        time_t now = time(NULL);

        // convert time to readable format
        char *time_str = ctime(&now);

        // remove newline character at the end
        time_str[strlen(time_str)-1] = '\0';

        // send time to client
        sendto(s, time_str, strlen(time_str), 0, (struct sockaddr*)&si_other, slen);
    }

    close(s);
    return 0;
}