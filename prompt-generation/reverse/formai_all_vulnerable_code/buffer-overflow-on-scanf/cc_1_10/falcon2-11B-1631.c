//Falcon2-11B DATASET v1.0 Category: Color Code Converter ; Style: active
#include <stdio.h>

int main() {
    // Define color codes
    int black = 0;
    int red = 1;
    int green = 2;
    int yellow = 3;
    int blue = 4;
    int magenta = 5;
    int cyan = 6;
    int white = 7;

    // Read user input color code
    printf("Enter color code (0-7): ");
    int colorCode = 0;
    scanf("%d", &colorCode);

    // Convert color code to corresponding color name
    switch (colorCode) {
        case 0:
            printf("Black\n");
            break;
        case 1:
            printf("Red\n");
            break;
        case 2:
            printf("Green\n");
            break;
        case 3:
            printf("Yellow\n");
            break;
        case 4:
            printf("Blue\n");
            break;
        case 5:
            printf("Magenta\n");
            break;
        case 6:
            printf("Cyan\n");
            break;
        case 7:
            printf("White\n");
            break;
        default:
            printf("Invalid color code\n");
            break;
    }

    return 0;
}