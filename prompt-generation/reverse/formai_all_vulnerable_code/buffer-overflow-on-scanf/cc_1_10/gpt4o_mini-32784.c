//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_COLORS 10

typedef struct {
    int r, g, b;
    char hex[8];
} Color;

void *convert_to_hex(void *arg) {
    Color *color = (Color *)arg;
    snprintf(color->hex, sizeof(color->hex), "#%02X%02X%02X", color->r, color->g, color->b);
    return NULL;
}

void print_color(Color *color) {
    printf("RGB(%d, %d, %d) -> HEX: %s\n", color->r, color->g, color->b, color->hex);
}

int main() {
    pthread_t threads[MAX_COLORS];
    Color colors[MAX_COLORS];
    int count, i;

    printf("Enter the number of colors to convert (max %d): ", MAX_COLORS);
    scanf("%d", &count);
    
    if (count > MAX_COLORS) {
        fprintf(stderr, "Exceeded maximum number of colors allowed.\n");
        return 1;
    }

    for (i = 0; i < count; i++) {
        printf("Enter RGB values for color %d (r g b): ", i + 1);
        scanf("%d %d %d", &colors[i].r, &colors[i].g, &colors[i].b);
    }

    for (i = 0; i < count; i++) {
        if (pthread_create(&threads[i], NULL, convert_to_hex, (void *)&colors[i])) {
            fprintf(stderr, "Error creating thread for color %d\n", i + 1);
            return 1;
        }
    }

    for (i = 0; i < count; i++) {
        pthread_join(threads[i], NULL);
        print_color(&colors[i]);
    }

    printf("Conversion completed successfully.\n");
    return 0;
}