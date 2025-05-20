#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void printBinaryIPv4(const char *ip) {
    unsigned int parts[4];
    if (sscanf(ip, "%u.%u.%u.%u", &parts[0], &parts[1], &parts[2], &parts[3]) != 4) {
        printf("Invalid IP format\n");
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (parts[i] > 255) {
            printf("Part %d out of range\n", i + 1);
            return;
        }
        printf("%08b ", parts[i]);
    }
    printf("\n");
}

int main() {
    const char *ip = "192.168.1.1";
    printBinaryIPv4(ip);
    return 0;
}
