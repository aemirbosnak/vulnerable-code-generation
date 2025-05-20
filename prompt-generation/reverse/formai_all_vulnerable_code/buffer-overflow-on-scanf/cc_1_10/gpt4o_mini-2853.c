//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <stdbool.h>

#define MAX_INPUT_SIZE 20
#define NUM_THREADS 2

typedef struct {
    char input[MAX_INPUT_SIZE];
    char output[MAX_INPUT_SIZE];
    bool isHexToRgb;
} color_conversion_t;

void* hexToRgb(void* arg) {
    color_conversion_t* conv = (color_conversion_t*)arg;
    int r, g, b;
    if (sscanf(conv->input, "#%02x%02x%02x", &r, &g, &b) == 3) {
        sprintf(conv->output, "RGB(%d, %d, %d)", r, g, b);
    } else {
        sprintf(conv->output, "Invalid HEX Color Code");
    }
    return NULL;
}

void* rgbToHex(void* arg) {
    color_conversion_t* conv = (color_conversion_t*)arg;
    int r, g, b;
    if (sscanf(conv->input, "RGB(%d, %d, %d)", &r, &g, &b) == 3) {
        sprintf(conv->output, "#%02x%02x%02x", r, g, b);
    } else {
        sprintf(conv->output, "Invalid RGB Color Code");
    }
    return NULL;
}

void convertColor(const char* input, char* output, bool isHexToRgb) {
    color_conversion_t conv;
    strncpy(conv.input, input, MAX_INPUT_SIZE);
    conv.isHexToRgb = isHexToRgb;

    pthread_t thread;
    
    if (isHexToRgb) {
        thread = pthread_create(&thread, NULL, hexToRgb, (void*)&conv);
    } else {
        thread = pthread_create(&thread, NULL, rgbToHex, (void*)&conv);
    }

    pthread_join(thread, NULL);
    strncpy(output, conv.output, MAX_INPUT_SIZE);
}

int main() {
    char input[MAX_INPUT_SIZE];
    char output[MAX_INPUT_SIZE];
    int choice;

    printf("Color Code Converter\n");
    printf("1. HEX to RGB\n");
    printf("2. RGB to HEX\n");
    printf("Choose an option (1/2): ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("Enter a HEX color code (e.g., #ff5733): ");
        scanf("%s", input);
        convertColor(input, output, true);
    } else if (choice == 2) {
        printf("Enter an RGB color code (e.g., RGB(255, 87, 51)): ");
        scanf("%s", input);
        convertColor(input, output, false);
    } else {
        printf("Invalid choice. Please restart program.\n");
        return 1;
    }

    printf("Converted color code: %s\n", output);
    return 0;
}