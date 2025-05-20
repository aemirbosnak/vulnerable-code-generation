//FormAI DATASET v1.0 Category: Color Code Converter ; Style: beginner-friendly
#include<stdio.h>

int main(){
    int red, green, blue;
    float hue, saturation, value;

    // Getting RGB values as input
    printf("Enter the value of Red, Green and Blue: ");
    scanf("%d %d %d", &red, &green, &blue);

    // Converting RGB to HSV color space
    float r = red / 255.0f;
    float g = green / 255.0f;
    float b = blue / 255.0f;
    float cmax = fmaxf(r, fmaxf(g, b));
    float cmin = fminf(r, fminf(g, b));
    float chroma = cmax - cmin;

    if(chroma == 0){
        hue = 0;
    }
    else if(cmax == r){
        hue = fmodf(((g - b) / chroma), 6);
    }
    else if(cmax == g){
        hue = ((b - r) / chroma) + 2;
    }
    else{
        hue = ((r - g) / chroma) + 4;
    }
    hue = hue * 60;
    if(hue < 0){
        hue = hue + 360;
    }

    value = cmax;
    if(cmax == 0){
        saturation = 0;
    }
    else{
        saturation = chroma / cmax;
    }

    // Converting hue, saturation and value to degrees
    int H = (int) hue;
    int S = (int) (saturation * 100);
    int V = (int) (value * 100);

    // Displaying HSV values
    printf("\nHSV values: H = %d, S = %d%%, V = %d%%\n", H, S, V);

    return 0;
}