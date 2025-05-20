#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void process_packet(char *packet) {
    char *data = (char *)malloc(BUFFER_SIZE);
    if (data == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    strcpy(data, packet);
    printf("Packet data: %s\n", data);
    free(data);

    // Use-after-free vulnerability
    printf("Use-after-free data: %s\n", data); // This line will cause undefined behavior
}

int main() {
    char packet[BUFFER_SIZE];
    while (1) {
        printf("Enter packet data (or 'exit' to quit): ");
        fgets(packet, sizeof(packet), stdin);
        packet[strcspn(packet, "\n")] = '\0';

        if (strcmp(packet, "exit") == 0) {
            break;
        }

        process_packet(packet);
    }
    return 0;
}
