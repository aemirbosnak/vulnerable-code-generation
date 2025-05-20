//Falcon-180B DATASET v1.0 Category: Hexadecimal Converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void romeo_to_hex(char *string);
void juliet_to_hex(char *string);

int main() {
    char string[100];
    int choice;

    printf("Enter a string to convert to hexadecimal: ");
    scanf("%s", string);

    printf("\nChoose the conversion method:\n");
    printf("1. Romeo's method\n");
    printf("2. Juliet's method\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            romeo_to_hex(string);
            break;
        case 2:
            juliet_to_hex(string);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}

// Romeo's method to convert string to hexadecimal
void romeo_to_hex(char *string) {
    int length = strlen(string);
    char hex[length * 3];
    int i, j;

    for(i = 0, j = 0; i < length; i++, j += 3) {
        sprintf(&hex[j], "%02X", (unsigned char)string[i]);
    }

    printf("\n%s\n", hex);
}

// Juliet's method to convert string to hexadecimal
void juliet_to_hex(char *string) {
    int length = strlen(string);
    char hex[length * 3];
    int i, j;

    for(i = 0, j = 0; i < length; i++, j += 3) {
        sprintf(&hex[j], "%02X", (unsigned char)string[i]);
    }

    printf("\n%s\n", hex);
}