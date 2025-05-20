//FormAI DATASET v1.0 Category: Color Code Converter ; Style: genious
#include <stdio.h>
#include <stdlib.h>

char* hexToRGB(char* hexCode) {
    int red, green, blue;
    sscanf(hexCode, "#%02x%02x%02x", &red, &green, &blue);
    char* rgb = malloc(sizeof(char) * 12);
    sprintf(rgb, "%d,%d,%d", red, green, blue);
    return rgb;
}

char* RGBToHex(int red, int green, int blue) {
    char* hexCode = malloc(sizeof(char) * 8);
    sprintf(hexCode, "#%02x%02x%02x", red, green, blue);
    return hexCode;
}

int main() {
    int choice;
    do {
        printf("Choose an option:\n1) Convert Hexadecimal to RGB\n2) Convert RGB to Hexadecimal\n3) Quit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                char* hexCode = malloc(sizeof(char) * 8);
                printf("Enter hexadecimal color code (e.g. #ff0000): ");
                scanf("%s", hexCode);
                char* rgb = hexToRGB(hexCode);
                printf("RGB equivalent: %s\n", rgb);
                free(hexCode);
                free(rgb);
                break;
            }
            case 2: {
                int red, green, blue;
                printf("Enter red value (0-255): ");
                scanf("%d", &red);
                printf("Enter green value (0-255): ");
                scanf("%d", &green);
                printf("Enter blue value (0-255): ");
                scanf("%d", &blue);
                char* hexCode = RGBToHex(red, green, blue);
                printf("Hexadecimal equivalent: %s\n", hexCode);
                free(hexCode);
                break;
            }
            case 3:
                printf("Program exited successfully.\n");
                break;
            default:
                printf("Invalid option chosen, please try again.\n");
                break;
        }
    } while (choice != 3);
    return 0;
}