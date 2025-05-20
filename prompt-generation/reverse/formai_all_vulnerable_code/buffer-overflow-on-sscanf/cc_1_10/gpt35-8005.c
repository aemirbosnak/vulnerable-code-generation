//FormAI DATASET v1.0 Category: Color Code Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>

#define COLOR_CODE_LENGTH 6

char *color;

bool isHexColorCode(char *input) {
    for(int i = 0; i < COLOR_CODE_LENGTH; i++) {
        if(!isxdigit(input[i])) {
            return false;
        }
    }
    return true;
}

void *hexToRGB(void *input) {
    char *hex = (char*)input;
    int r, g, b;

    sscanf(hex, "%02x%02x%02x", &r, &g, &b);

    printf("RGB color code for %s is (%d, %d, %d)\n", hex, r, g, b);

    return NULL;
}

void *RGBToHex(void *input) {
    int *rgb = (int*)input;
    char hex[COLOR_CODE_LENGTH + 1];

    sprintf(hex, "%02x%02x%02x", rgb[0], rgb[1], rgb[2]);

    printf("HEX color code for (%d, %d, %d) is %s\n", rgb[0], rgb[1], rgb[2], hex);

    return NULL;
}

int main() {
    printf("Enter a color code in HEX (#XXXXXX) or RGB (XXX,XXX,XXX): ");
    char input[15];
    fgets(input, 15, stdin);

    if(input[0] == '#') {
        // HEX to RGB conversion
        color = malloc(sizeof(char) * COLOR_CODE_LENGTH);
        strncpy(color, input + 1, COLOR_CODE_LENGTH);

        if(isHexColorCode(color)) {
            pthread_t tid;
            pthread_create(&tid, NULL, hexToRGB, (void*)color);
            pthread_join(tid, NULL);
        } else {
            printf("Invalid color code!\n");
        }
    } else {
        // RGB to HEX conversion
        int rgb[3];
        sscanf(input, "%d,%d,%d", &rgb[0], &rgb[1], &rgb[2]);

        if(rgb[0] >=0 && rgb[0] <= 255 && rgb[1] >=0 && rgb[1] <= 255 && rgb[2] >=0 && rgb[2] <= 255) {
            pthread_t tid;
            pthread_create(&tid, NULL, RGBToHex, (void*)rgb);
            pthread_join(tid, NULL);
        } else {
            printf("Invalid color code!\n");
        }
    }

    return 0;
}