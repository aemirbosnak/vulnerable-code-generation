//FormAI DATASET v1.0 Category: Color Code Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>

void rgb_to_hex(int r, int g, int b);
void hex_to_rgb(char *hex);

int main()
{
    int choice;

    printf("1. Convert RGB to HEX\n");
    printf("2. Convert HEX to RGB\n");
    printf("Choose your option: ");
    scanf("%d", &choice);

    if (choice == 1) {
        int r, g, b;
        printf("Enter the RGB values (0-255): ");
        scanf("%d %d %d", &r, &g, &b);
        rgb_to_hex(r, g, b);
    } else if (choice == 2) {
        char hex[7];
        printf("Enter the HEX value (example: FF00FF): ");
        scanf("%s", hex);
        hex_to_rgb(hex);
    } else {
        printf("Invalid choice!\n");
        exit(1);
    }

    return 0;
}

void rgb_to_hex(int r, int g, int b)
{
    char hex[7];
    sprintf(hex, "%02X%02X%02X", r, g, b);

    printf("HEX value: #%s\n", hex);
}

void hex_to_rgb(char *hex)
{
    if (hex[0] == '#') hex++;

    int r, g, b;
    sscanf(hex, "%02x%02x%02x", &r, &g, &b);

    printf("RGB values: %d %d %d\n", r, g, b);
}