//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void toDecimal(char* hex) {
    int i, len = strlen(hex), dec = 0;
    for (i = 0; hex[i] != '\0'; i++) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            dec += (hex[i] - 48) * pow(16, len - 1);
            len--;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F') {
            dec += (hex[i] - 55) * pow(16, len - 1);
            len--;
        }
        else if (hex[i] >= 'a' && hex[i] <= 'f') {
            dec += (hex[i] - 87) * pow(16, len - 1);
            len--;
        }
        else {
            printf("Invalid Hexadecimal Input.\n");
            return;
        }
    }
    printf("Decimal Output: %d.\n", dec);
}

void toHexadecimal(int dec) {
    char hex[100];
    int i = 0;
    while (dec != 0) {
        int curr = 0;
        curr = dec % 16;
        if (curr < 10) {
            hex[i] = curr + 48;
            i++;
        }
        else {
            hex[i] = curr + 55;
            i++;
        }
        dec = dec / 16;
    }
    printf("Hexadecimal Output: ");
    for (int j = i - 1; j >= 0; j--)
        printf("%c", hex[j]);
}

void play() {
    int choice, decimal;
    char hex[100];
    printf("Enter 1 for Decimal to Hexadecimal Conversion.\nEnter 2 for Hexadecimal to Decimal Conversion.\n");
    printf("Choice: ");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
        printf("Enter the Decimal Number: ");
        scanf("%d", &decimal);
        toHexadecimal(decimal);
        break;
    case 2:
        printf("Enter the Hexadecimal Number: ");
        scanf("%s", hex);
        toDecimal(hex);
        break;
    default:
        printf("Invalid Choice.\n");
        break;
    }
    printf("\n\n");
}

int main() {
    int n;
    do {
        play();
        printf("Enter 1 to Play Again, 0 to Exit.\nYour Choice: ");
        scanf("%d", &n);
    } while (n != 0);
    return 0;
}