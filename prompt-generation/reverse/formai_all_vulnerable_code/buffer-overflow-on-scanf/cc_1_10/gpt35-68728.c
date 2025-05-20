//FormAI DATASET v1.0 Category: Color Code Converter ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>

void* rgb_to_hex(void *args);
void* hex_to_rgb(void *args);

int main() {
    pthread_t thread1, thread2;
    char choice;
    
    printf("Enter R for RGB to Hex conversion or H for Hex to RGB conversion: ");
    scanf("%c", &choice);
    
    if (choice == 'R' || choice == 'r') {
        int rgb[3];
        printf("Enter RGB values between 0 and 255:\n");
        for (int i=0; i<3; i++) {
            scanf("%d", &rgb[i]);
        }
        pthread_create(&thread1, NULL, rgb_to_hex, (void*)rgb);
        pthread_join(thread1, NULL);
    }
    else if (choice == 'H' || choice == 'h') {
        char hex[7];
        printf("Enter hex value: ");
        scanf("%s", hex);
        pthread_create(&thread2, NULL, hex_to_rgb, (void*)hex);
        pthread_join(thread2, NULL);
    }
    else {
        printf("Invalid choice!\n");
    }
    
    return 0;
}

void* rgb_to_hex(void *args) {
    int *rgb = (int*)args;
    char hex[7];
    sprintf(hex, "#%02x%02x%02x", rgb[0], rgb[1], rgb[2]);
    printf("Hex code: %s\n", hex);
    pthread_exit(NULL);
}

void* hex_to_rgb(void *args) {
    char *hex = (char*)args;
    int r, g, b;
    sscanf(hex, "#%02x%02x%02x", &r, &g, &b);
    printf("RGB code: %d, %d, %d\n", r, g, b);
    pthread_exit(NULL);
}