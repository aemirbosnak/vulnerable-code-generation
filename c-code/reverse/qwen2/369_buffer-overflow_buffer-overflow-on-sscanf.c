#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP> <subnet_mask>\n", argv[0]);
        return 1;
    }

    struct in_addr ip, subnet_mask, broadcast;

    inet_pton(AF_INET, argv[1], &ip);
    inet_pton(AF_INET, argv[2], &subnet_mask);

    for (int i = 0; i < 4; i++) {
        broadcast.s_addr |= (ip.s_addr & subnet_mask.s_addr) | (~subnet_mask.s_addr);
    }

    printf("Broadcast Address: %s\n", inet_ntoa(broadcast));

    return 0;
}
