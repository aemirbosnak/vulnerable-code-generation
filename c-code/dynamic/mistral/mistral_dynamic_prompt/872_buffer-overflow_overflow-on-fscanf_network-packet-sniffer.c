#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <arpa/inet.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define MAX_PACKETS 10

int main(int argc, char *argv[]) {
    char buffer[BUFFER_SIZE];
    int packets_captured = 0;

    printf("Packet Sniffer - Running...\n");

    while (packets_captured < MAX_PACKETS) {
        printf("Capture packet %d: ", packets_captured + 1);
        fscanf(stdin, "%s", buffer);

        // Here lies the buffer overflow vulnerability
        char *packet_data = buffer;
        int length = strlen(buffer) + 1;

        // Print packet data
        printf("Packet Data: %s\n", packet_data);

        packets_captured++;
    }

    printf("Exiting Packet Sniffer...\n");

    return 0;
}
