//FormAI DATASET v1.0 Category: Color Code Converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hex_to_dec(char hex[]);
void dec_to_hex(int dec, char hex[]);

int main() {
    char input[20];
    char output[20];
    int choice;
    printf("Welcome to the Color Code Converter\n");
    do {
        printf("\nEnter 1 to convert Hexadecimal to Decimal\n");
        printf("Enter 2 to convert Decimal to Hexadecimal\n");
        printf("Enter 0 to exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("\nEnter the Hexadecimal color code: #");
                scanf("%s", input);
                if (strlen(input) != 6) {
                    printf("Invalid format. Please enter 6 characters.\n");
                    break;
                }
                int red = hex_to_dec(strncpy(output, input, 2));
                int green = hex_to_dec(strncpy(output, input+2, 2));
                int blue = hex_to_dec(strncpy(output, input+4, 2));
                printf("The RGB values are: (%d, %d, %d)\n", red, green, blue);
                break;
            case 2:
                printf("\nEnter the red, green, and blue values (0-255):\n");
                int r, g, b;
                scanf("%d %d %d", &r, &g, &b);
                if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
                    printf("Invalid input. Please enter values between 0 and 255.\n");
                    break;
                }
                dec_to_hex(r, strncpy(output, "", 1));
                dec_to_hex(g, strncpy(output+2, "", 1));
                dec_to_hex(b, strncpy(output+4, "", 1));
                printf("The hexadecimal color code is: #%s\n", output);
                break;
            case 0:
                printf("\nProgram Exiting\n");
                break;
            default:
                printf("\nInvalid Choice. Please try again.\n");
                break;
        }
    } while (choice != 0);
    return 0;
}

int hex_to_dec(char hex[]) {
    int i, len, val, dec = 0;
    len = strlen(hex);
    for (i = 0; hex[i] != '\0'; i++) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            val = hex[i] - 48;
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f') {
            val = hex[i]- 97 + 10;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F') {
            val = hex[i]- 65+ 10;
        }
        dec += val * pow(16, len - 1 - i);
    }
    return dec;
}

void dec_to_hex(int dec, char hex[]) {
    int i, j, temp;
    for (i = 0; dec != 0; i++) {
        temp = dec % 16;
        if (temp < 10) {
            hex[i] = temp + 48;
        }
        else {
            hex[i] = temp + 87;
        }
        dec /= 16;
    }
    for (j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
}