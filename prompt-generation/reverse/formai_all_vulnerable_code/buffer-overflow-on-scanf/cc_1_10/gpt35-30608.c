//FormAI DATASET v1.0 Category: Color Code Converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printMenu() {
    printf("Welcome to the C Color Code Converter\n");
    printf("Choose from the following options:\n");
    printf("1. Convert RGB to Hexadecimal\n");
    printf("2. Convert Hexadecimal to RGB\n");
    printf("3. Exit Program\n>> ");
}

int main() {
    int choice = 0;
    char hex[7];
    char *ptr;
    int r, g, b;
    while (choice != 3) {
        printMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the Red Value (0-255): ");
                scanf("%d", &r);
                printf("Enter the Green Value (0-255): ");
                scanf("%d", &g);
                printf("Enter the Blue Value (0-255): ");
                scanf("%d", &b);
                sprintf(hex, "#%02x%02x%02x", r, g, b);
                printf("Hexadecimal Code: %s\n", hex);
                break;
            case 2:
                printf("Enter the Hexadecimal Code: ");
                scanf("%s", hex);
                if (strlen(hex) != 7 || hex[0] != '#') {
                    printf("Invalid Hexadecimal Code!\n");
                    break;
                }
                r = strtol(&hex[1], &ptr, 16);
                g = strtol(&hex[3], &ptr, 16);
                b = strtol(&hex[5], &ptr, 16);
                printf("RGB Code: (%d, %d, %d)\n", r, g, b);
                break;
            case 3:
                printf("Exiting Program...\n");
                break;
            default:
                printf("Invalid Choice!\n");
                break;
        }
    }
    return 0;
}