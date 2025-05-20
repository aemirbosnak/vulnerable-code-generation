//GPT-4o-mini DATASET v1.0 Category: Color Code Converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_usage() {
    printf("Welcome to the Color Code Converter.\n");
    printf("This program will take you on a romantic journey through RGB and HEX color codes.\n");
    printf("Usage:\n");
    printf("1. Convert RGB to HEX: enter 'rgb r g b'\n");
    printf("2. Convert HEX to RGB: enter 'hex #RRGGBB'\n");
    printf("3. Type 'exit' to leave this serene place.\n");
}

void rgb_to_hex(int r, int g, int b) {
    printf("In the romantically vibrant world of color, the RGB (%d, %d, %d) ", r, g, b);
    printf("translates to HEX as: #%02X%02X%02X\n", r, g, b);
}

void hex_to_rgb(char* hex) {
    int r, g, b;
    
    if (strlen(hex) != 7 || hex[0] != '#') {
        printf("Alas! Your HEX input should start with '#' and contain 6 characters following it. Try again.\n");
        return;
    }

    sscanf(hex + 1, "%02X%02X%02X", &r, &g, &b);
    printf("In this beautiful tango of colors, the HEX %s ", hex);
    printf("translates to RGB (%d, %d, %d).\n", r, g, b);
}

int main() {
    char input[100];
    print_usage();

    while (1) {
        printf("\nEnter your heartfelt inquiry (or type 'exit'): ");
        fgets(input, sizeof(input), stdin);
        
        // Remove newline character from input if it exists
        input[strcspn(input, "\n")] = 0;
        
        // Check for exit command
        if (strcmp(input, "exit") == 0) {
            printf("Thank you for your tender moments spent here. Farewell!\n");
            break;
        }

        char command[4];
        int r, g, b;
        char hex[8];

        if (sscanf(input, "%s %d %d %d", command, &r, &g, &b) == 4) {
            if (strcmp(command, "rgb") == 0) {
                rgb_to_hex(r, g, b);
            } else {
                printf("In this world of passion and color, we didn't quite understand your request. Please try again.\n");
            }
        } else if (sscanf(input, "%s %s", command, hex) == 2) {
            if (strcmp(command, "hex") == 0) {
                hex_to_rgb(hex);
            } else {
                printf("In this dance of codes, you have misstepped with an incorrect command. Please try again.\n");
            }
        } else {
            printf("Oh, dear! The words you penned did not match our love's request. Please check your input.\n");
        }
    }

    return 0;
}