//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

void hex2dec(char* hex, int hex_len, char* dec) {
    int i, j = 0;
    for (i = hex_len - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            dec[j++] = hex[i];
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            dec[j++] = hex[i] - 'A' + 10;
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            dec[j++] = hex[i] - 'a' + 10;
        } else {
            printf("Invalid hexadecimal character: %c\n", hex[i]);
            exit(1);
        }
    }
    dec[j] = '\0';
}

void dec2hex(char* dec, int dec_len, char* hex) {
    int i, j = 0;
    for (i = dec_len - 1; i >= 0; i--) {
        sprintf(&hex[j], "%02X", dec[i]);
        j += 2;
    }
    hex[j] = '\0';
}

int main() {
    char input[MAX_LENGTH];
    char output[MAX_LENGTH];
    int choice;

    printf("Welcome to the Hexadecimal Converter!\n\n");
    printf("Enter 1 to convert from hexadecimal to decimal.\n");
    printf("Enter 2 to convert from decimal to hexadecimal.\n\n");
    scanf("%d", &choice);

    printf("Enter the input string: ");
    fgets(input, MAX_LENGTH, stdin);

    if (choice == 1) {
        hex2dec(input, strlen(input), output);
        printf("The decimal representation of %s is: %s\n", input, output);
    } else if (choice == 2) {
        dec2hex(input, strlen(input), output);
        printf("The hexadecimal representation of %s is: %s\n", input, output);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}