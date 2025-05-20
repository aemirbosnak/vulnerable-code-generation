#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void process_packet(char *packet) {
    int packet_length = strlen(packet);
    char *new_buffer;
    
    // Integer overflow vulnerability here
    new_buffer = (char *)malloc(packet_length * 2); // Overflow if packet_length is very large
    
    if (new_buffer == NULL) {
        perror("Failed to allocate memory");
        return;
    }
    
    strcpy(new_buffer, packet);
    strcat(new_buffer, " processed");
    
    printf("Processed packet: %s\n", new_buffer);
    
    free(new_buffer);
}

int main() {
    char buffer[BUFFER_SIZE];
    
    while (1) {
        printf("Enter packet data (or 'exit' to quit): ");
        fgets(buffer, BUFFER_SIZE, stdin);
        
        if (strncmp(buffer, "exit", 4) == 0) {
            break;
        }
        
        process_packet(buffer);
    }
    
    return 0;
}
