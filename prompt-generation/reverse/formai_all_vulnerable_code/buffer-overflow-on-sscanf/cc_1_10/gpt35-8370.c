//FormAI DATASET v1.0 Category: Color Code Converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 2

// function that converts RGB to hexadecimal color code
void* rgb_to_hex(void* arg) {
    int i, r, g, b;
    char hex[7];
    sscanf((char*)arg, "%d,%d,%d", &r, &g, &b);
    sprintf(hex, "%02X%02X%02X", r, g, b);
    printf("RGB code: (%d, %d, %d) -> Hex code: #%s\n", r, g, b, hex);
    return NULL;
}

// function that converts hexadecimal color code to RGB
void* hex_to_rgb(void* arg) {
    int i, r, g, b;
    char hex[7];
    sscanf((char*)arg, "#%02X%02X%02X", &r, &g, &b);
    printf("Hex code: #%s -> RGB code: (%d, %d, %d)\n", (char*)arg, r, g, b);
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    char hex[7], rgb[11];
    int i, rgb_values[NUM_THREADS][3] = {{255, 0, 0}, {0, 255, 0}};
    
    // convert RGB codes to hexadecimal codes using multi-threading
    for (i = 0; i < NUM_THREADS; ++i) {
        sprintf(rgb, "%d,%d,%d", rgb_values[i][0], rgb_values[i][1], rgb_values[i][2]);
        pthread_create(&threads[i], NULL, rgb_to_hex, rgb);
    }
    for (i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }
    
    // convert hexadecimal codes to RGB codes using multi-threading
    sprintf(hex, "#FFA500");
    pthread_create(&threads[0], NULL, hex_to_rgb, hex);
    sprintf(hex, "#008080");
    pthread_create(&threads[1], NULL, hex_to_rgb, hex);
    for (i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }
    
    return 0;
}