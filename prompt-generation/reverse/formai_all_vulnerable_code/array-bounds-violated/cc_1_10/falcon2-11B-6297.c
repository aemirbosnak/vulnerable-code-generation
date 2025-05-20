//Falcon2-11B DATASET v1.0 Category: Color Code Converter ; Style: multiplayer
#include <stdio.h>
#include <string.h>

void convertColorCode(char* input, char* output) {
    int hexLength = strlen(input) - 1;
    char hex[3];
    int color = 0;
    int rgb[3] = {0};

    for (int i = 0; i < hexLength; i++) {
        hex[i % 3] = input[i];
    }

    for (int i = 0; i < hexLength; i++) {
        switch (hex[i]) {
            case '0':
                color *= 10;
                color += 0;
                break;
            case '1':
                color *= 10;
                color += 1;
                break;
            case '2':
                color *= 10;
                color += 2;
                break;
            case '3':
                color *= 10;
                color += 3;
                break;
            case '4':
                color *= 10;
                color += 4;
                break;
            case '5':
                color *= 10;
                color += 5;
                break;
            case '6':
                color *= 10;
                color += 6;
                break;
            case '7':
                color *= 10;
                color += 7;
                break;
            case '8':
                color *= 10;
                color += 8;
                break;
            case '9':
                color *= 10;
                color += 9;
                break;
        }
    }

    rgb[0] = color / 16;
    color %= 16;
    rgb[1] = color / 6;
    color %= 6;
    rgb[2] = color / 6;
    color %= 6;

    sprintf(output, "%02X%02X%02X", rgb[0], rgb[1], rgb[2]);
}

int main() {
    char input[10], output[10];
    printf("Enter the color code: ");
    fgets(input, 10, stdin);
    input[strcspn(input, "\n")] = '\0';
    convertColorCode(input, output);
    printf("RGB code: %s\n", output);
    return 0;
}