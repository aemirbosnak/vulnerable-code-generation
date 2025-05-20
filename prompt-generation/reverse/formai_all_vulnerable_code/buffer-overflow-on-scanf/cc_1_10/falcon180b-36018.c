//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// Romantic color names
char* colors[] = {
    "Passionate Red",
    "Loving Pink",
    "Admirable Purple",
    "Envious Green",
    "Peaceful Blue",
    "Joyful Yellow",
    "Elegant White",
    "Dazzling Black"
};

// Function to convert color name to hex code
void nameToHex(char* name) {
    int i;
    for (i = 0; i < 8; i++) {
        if (strcmp(name, colors[i]) == 0) {
            printf("%s -> %s\n", name, "#FF0000"); // Red for all colors for now
            return;
        }
    }
}

// Function to convert hex code to color name
void hexToName(char* hex) {
    int i;
    for (i = 0; i < 8; i++) {
        if (strcmp(hex, "#FF0000") == 0) {
            printf("%s -> %s\n", hex, colors[i]);
            return;
        }
    }
}

int main() {
    // Ask user for input
    char input[100];
    printf("Enter a romantic color name or hex code: ");
    scanf("%s", input);

    // Convert input to uppercase
    int i;
    for (i = 0; i < strlen(input); i++) {
        input[i] = toupper(input[i]);
    }

    // Check if input is a color name
    if (isalpha(input[0])) {
        nameToHex(input);
    } else if (strlen(input) == 7 && input[0] == '#') { // Check if input is a hex code
        hexToName(input);
    } else {
        printf("Invalid input.\n");
    }

    return 0;
}