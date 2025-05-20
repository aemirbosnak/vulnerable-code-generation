//FormAI DATASET v1.0 Category: Color Code Converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 7

char* hex_to_rgb(char* hex_code);
char* rgb_to_hex(char* rgb_code);

int main() {
    int choice;
    char input[MAX_LENGTH];
    char* output;

    printf("Welcome to the Color Code Converter!\n");
    printf("-------------------------------------\n");
    printf("What do you want to convert?\n");
    printf("1. HEX to RGB\n");
    printf("2. RGB to HEX\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    fflush(stdin);

    if (choice == 1) {
        printf("\nEnter the HEX code (without the # symbol): ");
        fgets(input, MAX_LENGTH, stdin);
        output = hex_to_rgb(input);
        printf("RGB code: %s\n", output);
    } else if (choice == 2) {
        printf("\nEnter the RGB code (e.g. 255,255,255): ");
        fgets(input, MAX_LENGTH, stdin);
        output = rgb_to_hex(input);
        printf("HEX code: %s\n", output);
    } else {
        printf("\nInvalid choice. Please try again.\n");
        return 1;
    }

    free(output);
    return 0;
}

char* hex_to_rgb(char* hex_code) {
    char* rgb_code = (char*)malloc(12);
    int r, g, b;
    sscanf(hex_code, "%02x%02x%02x", &r, &g, &b);
    sprintf(rgb_code, "%d,%d,%d", r, g, b);
    return rgb_code;
}

char* rgb_to_hex(char* rgb_code) {
    char* hex_code = (char*)malloc(8);
    int r, g, b;
    sscanf(rgb_code, "%d,%d,%d", &r, &g, &b);
    sprintf(hex_code, "#%02x%02x%02x", r, g, b);
    return hex_code;
}