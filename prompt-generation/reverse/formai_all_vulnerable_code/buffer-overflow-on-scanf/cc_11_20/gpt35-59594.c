//FormAI DATASET v1.0 Category: Color Code Converter ; Style: funny
#include <stdio.h>

int main(){
    printf("Welcome to the Funny C Color Code Converter!\n\n");
    printf("Enter the hex code of your desired color (in the form #RRGGBB): ");
    char hex[8]; // Maximum of 7 characters plus null terminator
    scanf("%s", hex);

    // Ensure that the hex code is valid
    int i;
    for(i = 0; hex[i] != '\0'; i++){
        if(!((hex[i] >= '0' && hex[i] <= '9') || (hex[i] >= 'A' && hex[i] <= 'F') || (hex[i] >= 'a' && hex[i] <= 'f') || hex[i] == '#')){
            printf("Invalid hex code. Please try again.\n");
            return 1;
        }
    }
    if(i != 7){
        printf("Invalid hex code. Please try again.\n");
        return 1;
    }

    // Convert hex code to RGB values
    unsigned int r, g, b;
    sscanf(hex, "#%02x%02x%02x", &r, &g, &b);

    // Print out RGB values
    printf("\nRGB values: (%u, %u, %u)\n", r, g, b);

    // Convert RGB values to ANSI color code
    unsigned int code = ((r & 0xFF) << 16) | ((g & 0xFF) << 8) | (b & 0xFF);
    printf("ANSI color code: \033[38;2;%u;%u;%um%d\033[0m\n", r, g, b, code);

    // Convert RGB values to CMYK values
    float c, m, y, k;
    c = 1 - (float)r/255;
    m = 1 - (float)g/255;
    y = 1 - (float)b/255;
    k = c < m ? c : m;
    k = k < y ? k : y;
    if(k == 1.0){
        c = m = y = 0;
    }else{
        c = (c - k)/(1 - k);
        m = (m - k)/(1 - k);
        y = (y - k)/(1 - k);
    }

    // Print out CMYK values
    printf("\nCMYK values: (%.2f, %.2f, %.2f, %.2f)\n", c, m, y, k);

    printf("\nThank you for using the Funny C Color Code Converter!\n");

    return 0;
}