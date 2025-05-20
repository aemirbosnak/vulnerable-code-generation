//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: romantic
#include <stdio.h>

void convertToAscii(char image[10][10], char ascii[10][10]) {
    char ascii_chars[] = {' ', '.', ',', ':', ';', 'o', 'x', '%', '&', '#'};
    int num_chars = sizeof(ascii_chars) / sizeof(char);
    float interval = 255.0 / (num_chars - 1);

    for (int row = 0; row < 10; row++) {
        for (int col = 0; col < 10; col++) {
            int pixel = image[row][col];
            int ascii_index = pixel / interval;
            ascii[row][col] = ascii_chars[ascii_index];
        }
    }
}

int main() {
    char image[10][10] = {
        {200, 150, 100,  50,  0,   0,   0,   0,   0,   0},
        {200, 200, 150, 100, 50,   0,   0,   0,   0,   0},
        {255, 255, 255, 200, 150, 100,  50,   0,   0,   0},
        {255, 255, 255, 255, 200, 150, 100,  50,   0,   0},
        {255, 255, 255, 255, 255, 200, 150, 100,  50,   0},
        {255, 255, 255, 255, 255, 255, 200, 150, 100,  50},
        {255, 255, 255, 255, 255, 255, 255, 200, 150, 100},
        {255, 255, 255, 255, 255, 255, 255, 255, 200, 150},
        {255, 255, 255, 255, 255, 255, 255, 255, 255, 200},
        {255, 255, 255, 255, 255, 255, 255, 255, 255, 255}
    };

    char ascii[10][10];
    convertToAscii(image, ascii);

    printf("               .,,,,,.     .,,,,,,,,.\n");
    printf("             .......,,.....    ..... \n");
    printf("           ,******* **  ..,.******** \n");
    printf("          ,***%&%%%***,.........,,**,\n");
    printf("         ,,*******  ..,************* \n");
    printf("      ,,,,*******.,***************** \n");
    printf("    .....*************************** \n");
    printf("   ...*****************************,\n");
    printf("   ...*****************************,\n");
    printf("     ..*****   %s    *****.\n", ascii[0]);
    printf("         ,***    %s     ***.\n", ascii[1]);
    printf("               ,,,.  %s   ,,,,\n", ascii[2]);
    printf("         .,,.....,,,,,,,...........,\n");
    printf("         ,%%%%%%%%%%%%%%%%%%%&%**,\n");
    printf("        ***********************.\n");
    printf("        **********************..\n");
    printf("      ,,,,**********,,,,,,,.   \n");
    printf(",********        ,**             \n");
    printf("%%%%%%**%%&%&&&&%**%%%%%%         \n");
    printf("************((//*,,************   \n");
    printf("         ,////////****          \n");

    return 0;
}