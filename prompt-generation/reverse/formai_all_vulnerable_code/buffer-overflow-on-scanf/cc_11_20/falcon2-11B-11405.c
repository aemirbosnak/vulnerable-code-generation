//Falcon2-11B DATASET v1.0 Category: Hexadecimal Converter ; Style: beginner-friendly
#include <stdio.h>

int main() {
    int num;
    char result[20];

    printf("Enter a number: ");
    scanf("%d", &num);

    // Convert the number to hexadecimal
    switch (num) {
        case 0:
            sprintf(result, "0x%02X", num);
            break;
        case 1:
            sprintf(result, "0x%02X", num + 10);
            break;
        case 2:
            sprintf(result, "0x%02X", num + 20);
            break;
        case 3:
            sprintf(result, "0x%02X", num + 30);
            break;
        case 4:
            sprintf(result, "0x%02X", num + 40);
            break;
        case 5:
            sprintf(result, "0x%02X", num + 50);
            break;
        case 6:
            sprintf(result, "0x%02X", num + 60);
            break;
        case 7:
            sprintf(result, "0x%02X", num + 70);
            break;
        case 8:
            sprintf(result, "0x%02X", num + 80);
            break;
        case 9:
            sprintf(result, "0x%02X", num + 90);
            break;
        default:
            sprintf(result, "Invalid input");
            break;
    }

    // Print the result
    printf("Hexadecimal value: %s\n", result);

    return 0;
}