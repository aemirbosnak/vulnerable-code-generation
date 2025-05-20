#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <arpa/inet.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hexDump(unsigned char *buffer, int len) {
    for (int i = 0; i < len; ++i) {
        printf("%02X ", buffer[i]);
        if ((i + 1) % 16 == 0)
            printf("\n");
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    char buffer[10];
    struct iphdr *ip_hdr;
    int packet_len, iplen;

    while (1) {
        printf("Enter packet data (Ctrl+C to exit): ");
        fscanf(stdin, "%s", buffer);

        packet_len = strlen(buffer);
        ip_hdr = (struct iphdr *)calloc(1, packet_len);
        iplen = ntohs(ip_hdr->tot_len);

        memcpy(ip_hdr, buffer, iplen);
        hexDump(buffer, packet_len);
        hexDump((unsigned char *)ip_hdr, iplen);

        free(ip_hdr);
    }

    return 0;
}
