#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    char device[10];
    printf("Enter device to toggle (light, fan, ac): ");
    scanf("%s", device);
    if (strcmp(device, "light") == 0) {
        printf("Light toggled.\n");
    } else if (strcmp(device, "fan") == 0) {
        printf("Fan toggled.\n");
    } else if (strcmp(device, "ac") == 0) {
        printf("AC toggled.\n");
    } else {
        printf("Unknown device.\n");
    }
    return 0;
}
