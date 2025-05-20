//Falcon2-11B DATASET v1.0 Category: Firewall ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

int main() {
    char buf[BUF_SIZE];
    char* p = NULL;
    int i = 0;
    int size = 0;
    int state = 0;
    
    while (1) {
        printf("Cyberpunk Firewall: ");
        fgets(buf, BUF_SIZE, stdin);
        
        if (buf[0] == '1') {
            printf("All packets are authorized!\n");
        } else if (buf[0] == '2') {
            printf("Packet #%d is blocked!\n", i);
            if (state == 1) {
                printf("Packet #%d is reauthorized!\n", i);
                state = 0;
            } else {
                state = 1;
            }
        } else if (buf[0] == '3') {
            printf("Packet #%d is reauthorized!\n", i);
        } else if (buf[0] == '4') {
            printf("Packet #%d is blocked!\n", i);
        } else if (buf[0] == '5') {
            printf("All packets are blocked!\n");
        } else if (buf[0] == '6') {
            printf("Packet #%d is reauthorized!\n", i);
        } else if (buf[0] == '7') {
            printf("Packet #%d is blocked!\n", i);
        } else {
            printf("Invalid command!\n");
        }
        
        size = strlen(buf);
        p = &buf[size - 1];
        if (*p == '\n') {
            i++;
        }
    }
    
    return 0;
}