//GEMINI-pro DATASET v1.0 Category: Chat server ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

struct chat_protocol {
    uint8_t type;
    uint16_t length;
    char data[0];
};

#define CHAT_TYPE_MESSAGE 0x01
#define CHAT_TYPE_JOIN 0x02
#define CHAT_TYPE_LEAVE 0x03
#define CHAT_TYPE_PING 0x04

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip> <port>\n", argv[0]);
        return 1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &addr.sin_addr) <= 0) {
        perror("inet_pton");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        return 1;
    }

    char buf[1024];
    struct chat_protocol *proto;
    int len;

    while (1) {
        if ((len = read(sockfd, buf, sizeof(buf))) <= 0) {
            if (len == 0)
                printf("Server closed connection.\n");
            else
                perror("read");
            break;
        }

        proto = (struct chat_protocol *)buf;
        switch (proto->type) {
            case CHAT_TYPE_MESSAGE:
                printf("%s", proto->data);
                break;
            case CHAT_TYPE_JOIN:
                printf("User %s joined.\n", proto->data);
                break;
            case CHAT_TYPE_LEAVE:
                printf("User %s left.\n", proto->data);
                break;
            case CHAT_TYPE_PING:
                // Send a PING response
                proto->type = CHAT_TYPE_PING;
                if (write(sockfd, proto, sizeof(*proto)) <= 0) {
                    perror("write");
                    break;
                }
                break;
            default:
                printf("Unknown protocol type %d.\n", proto->type);
                break;
        }
    }

    close(sockfd);
    return 0;
}