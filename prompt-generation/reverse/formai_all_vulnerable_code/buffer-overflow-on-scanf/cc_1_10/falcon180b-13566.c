//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void convert(int value, int base);
int get_base(char *string);

int main() {
    char string[100];
    printf("Enter a color code: ");
    scanf("%s", string);

    // Get the base of the color code
    int base = get_base(string);

    // Convert the color code to RGB
    convert(0, base);

    return 0;
}

// Recursive function to convert color code to RGB
void convert(int value, int base) {
    if (value == 0) {
        return;
    }

    int digit = value % base;
    value /= base;

    if (digit == 0) {
        printf("0");
    } else if (digit == 1) {
        printf("1");
    } else {
        printf("2");
    }

    convert(value, base);
}

// Function to get the base of the color code
int get_base(char *string) {
    int length = strlen(string);

    if (string[0] == '#') {
        return 16;
    } else if (length == 6 && string[0] == 'r' && string[1] == 'g' && string[2] == 'b') {
        return 10;
    } else {
        return -1;
    }
}