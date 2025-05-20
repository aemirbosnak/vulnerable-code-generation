//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: creative
#include <stdio.h>
#include <stdlib.h>

void rgbToHex(int r, int g, int b) {
    printf("Hexadecimal Color Code: #%02X%02X%02X\n", r, g, b);
}

void hexToRgb(const char *hex) {
    int r, g, b;
    if (sscanf(hex + 1, "%02x%02x%02x", &r, &g, &b) == 3) {
        printf("RGB Color Code: (%d, %d, %d)\n", r, g, b);
    } else {
        printf("Invalid Hexadecimal Color Code!\n");
    }
}

void displayMenu() {
    printf("===================================\n");
    printf("     Color Code Converter          \n");
    printf("===================================\n");
    printf("1. Convert RGB to Hexadecimal\n");
    printf("2. Convert Hexadecimal to RGB\n");
    printf("3. Exit\n");
    printf("===================================\n");
}

int main() {
    int choice;
    
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            int r, g, b;
            printf("Enter Red value (0-255): ");
            scanf("%d", &r);
            printf("Enter Green value (0-255): ");
            scanf("%d", &g);
            printf("Enter Blue value (0-255): ");
            scanf("%d", &b);
            
            if (r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255) {
                rgbToHex(r, g, b);
            } else {
                printf("Invalid RGB values! Please enter values between 0-255.\n");
            }
        } else if (choice == 2) {
            char hex[8];
            printf("Enter Hexadecimal Color Code (e.g. #FF5733): ");
            scanf("%s", hex);
            
            if (hex[0] == '#' && (strlen(hex) == 7 || strlen(hex) == 9)) {
                hexToRgb(hex);
            } else {
                printf("Invalid Hexadecimal Color Code! Make sure it starts with '#' and has 6 characters after.\n");
            }
        } else if (choice == 3) {
            printf("Exiting the Color Code Converter. Goodbye!\n");
            break;
        } else {
            printf("Invalid choice! Please choose again.\n");
        }
    }
    
    return 0;
}