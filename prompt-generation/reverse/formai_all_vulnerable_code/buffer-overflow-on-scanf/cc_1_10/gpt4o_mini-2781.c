//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <ctype.h>

#define MAX_COLOR_CODE_LENGTH 10
#define THREAD_COUNT 2

typedef struct {
    char input[MAX_COLOR_CODE_LENGTH];
    char output[MAX_COLOR_CODE_LENGTH];
} ColorCode;

void *convertToRGB(void *arg) {
    ColorCode *colorCode = (ColorCode *)arg;
    if (colorCode->input[0] == '#') {
        int r, g, b;
        if (sscanf(colorCode->input, "#%02x%02x%02x", &r, &g, &b) == 3) {
            sprintf(colorCode->output, "RGB(%d, %d, %d)", r, g, b);
        } else {
            sprintf(colorCode->output, "Invalid HEX format");
        }
    } else {
        sprintf(colorCode->output, "Input not in HEX format");
    }
    return NULL;
}

void *convertToHex(void *arg) {
    ColorCode *colorCode = (ColorCode *)arg;
    int r, g, b;
    if (sscanf(colorCode->input, "RGB(%d, %d, %d)", &r, &g, &b) == 3) {
        sprintf(colorCode->output, "#%02x%02x%02x", r, g, b);
    } else {
        sprintf(colorCode->output, "Invalid RGB format");
    }
    return NULL;
}

int main() {
    pthread_t threads[THREAD_COUNT];
    ColorCode colorCode;
    char type[10];

    printf("Enter 'HEX' to convert HEX to RGB or 'RGB' to convert RGB to HEX: ");
    scanf("%s", type);

    printf("Enter color code: ");
    scanf("%s", colorCode.input);

    if (strcasecmp(type, "HEX") == 0) {
        pthread_create(&threads[0], NULL, convertToRGB, &colorCode);
        pthread_join(threads[0], NULL);
        printf("Converted: %s\n", colorCode.output);
    } else if (strcasecmp(type, "RGB") == 0) {
        pthread_create(&threads[1], NULL, convertToHex, &colorCode);
        pthread_join(threads[1], NULL);
        printf("Converted: %s\n", colorCode.output);
    } else {
        printf("Invalid type specified\n");
    }

    return 0;
}