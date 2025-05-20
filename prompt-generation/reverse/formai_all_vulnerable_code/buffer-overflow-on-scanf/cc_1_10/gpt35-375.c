//FormAI DATASET v1.0 Category: Color Code Converter ; Style: safe
#include <stdio.h>
#include <stdlib.h>

int main() {
    int r, g, b, c;
    char choice;
    float cyan, magenta, yellow, black;

    printf("Enter your RGB color code:\n");
    printf("R: ");
    scanf("%d", &r);
    printf("G: ");
    scanf("%d", &g);
    printf("B: ");
    scanf("%d", &b);

    printf("Your RGB color code is: RGB(%d,%d,%d)\n", r, g, b);
    
    //Conversion from RGB to CMYK Color Model
    cyan = 1 - ((float)r/255);
    magenta = 1 - ((float)g/255);
    yellow = 1 - ((float)b/255);
    black = cyan < magenta ? (cyan < yellow ? cyan : yellow) : (magenta < yellow ? magenta : yellow);
    cyan = (cyan - black) / (1 - black);
    magenta = (magenta - black) / (1 - black);
    yellow = (yellow - black) / (1 - black);

    printf("Your CMYK color code is: CMYK(%.3f,%.3f,%.3f,%.3f)\n", cyan, magenta, yellow, black);

    //Conversion from CMYK to RGB Color Model
    printf("Do you want to try to convert it from CMYK to RGB? (y/n): ");
    scanf(" %c", &choice);

    if(choice == 'Y' || choice == 'y') {
        printf("Enter your CMYK color code:\n");
        printf("C: ");
        scanf("%f", &cyan);
        printf("M: ");
        scanf("%f", &magenta);
        printf("Y: ");
        scanf("%f", &yellow);
        printf("K: ");
        scanf("%f", &black);

        printf("Your CMYK color code is: CMYK(%.3f,%.3f,%.3f,%.3f)\n", cyan, magenta, yellow, black);

        r = (int)(255 * (1 - cyan) * (1 - black));
        g = (int)(255 * (1 - magenta) * (1 - black));
        b = (int)(255 * (1 - yellow) * (1 - black));

        printf("Your RGB color code is: RGB(%d,%d,%d)\n", r, g, b);
    }

    return 0;
}