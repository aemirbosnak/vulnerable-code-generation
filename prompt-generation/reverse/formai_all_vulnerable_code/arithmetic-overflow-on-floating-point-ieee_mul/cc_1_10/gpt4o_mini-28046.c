//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

void rgb_to_hex(int r, int g, int b) {
    printf("HEX: #%02X%02X%02X\n", r, g, b);
}

void hex_to_rgb(const char *hex) {
    int r, g, b;
    if (sscanf(hex + 1, "%2x%2x%2x", &r, &g, &b) == 3) {
        printf("RGB: (%d, %d, %d)\n", r, g, b);
    } else {
        printf("Invalid HEX code.\n");
    }
}

void rgb_to_cmyk(int r, int g, int b) {
    float c, m, y, k;
    float r_norm = r / 255.0;
    float g_norm = g / 255.0;
    float b_norm = b / 255.0;

    k = 1 - fmaxf(fmaxf(r_norm, g_norm), b_norm);
    
    if (k < 1) {
        c = (1 - r_norm - k) / (1 - k);
        m = (1 - g_norm - k) / (1 - k);
        y = (1 - b_norm - k) / (1 - k);
    } else {
        c = m = y = 0;
    }

    printf("CMYK: (%.2f, %.2f, %.2f, %.2f)\n", c, m, y, k);
}

void cmyk_to_rgb(float c, float m, float y, float k) {
    int r = (int)((1 - c) * (1 - k) * 255);
    int g = (int)((1 - m) * (1 - k) * 255);
    int b = (int)((1 - y) * (1 - k) * 255);
    
    printf("RGB: (%d, %d, %d)\n", r, g, b);
}

void display_menu() {
    printf("Color Code Converter\n");
    printf("1. RGB to HEX\n");
    printf("2. HEX to RGB\n");
    printf("3. RGB to CMYK\n");
    printf("4. CMYK to RGB\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                int r, g, b;
                printf("Enter RGB values (r g b): ");
                scanf("%d %d %d", &r, &g, &b);
                rgb_to_hex(r, g, b);
                break;
            }
            case 2: {
                char hex[8];
                printf("Enter HEX code (e.g., #FFFFFF): ");
                scanf("%s", hex);
                hex_to_rgb(hex);
                break;
            }
            case 3: {
                int r, g, b;
                printf("Enter RGB values (r g b): ");
                scanf("%d %d %d", &r, &g, &b);
                rgb_to_cmyk(r, g, b);
                break;
            }
            case 4: {
                float c, m, y, k;
                printf("Enter CMYK values (c m y k): ");
                scanf("%f %f %f %f", &c, &m, &y, &k);
                cmyk_to_rgb(c, m, y, k);
                break;
            }
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}