//FormAI DATASET v1.0 Category: Color Code Converter ; Style: ephemeral
#include <stdio.h>
#include <string.h>

char* convert_color_code(char* color_code) {
    char* hex_color_code = malloc(sizeof(char) * 8);
    
    if (color_code[0] == '#') {
        char* rgb_values[3];
        int i = 0;
        rgb_values[i] = strtok(color_code + 1, ",");
        
        while (rgb_values[i] != NULL && i < 3) {  
            i++;
            rgb_values[i] = strtok(NULL, ",");
        }
        
        int red = atoi(rgb_values[0]);
        int green = atoi(rgb_values[1]);
        int blue = atoi(rgb_values[2]);
        
        sprintf(hex_color_code, "#%02x%02x%02x", red, green, blue);
    } else if (color_code[0] == 'r') {
        char* rgb_values[4];
        int i = 0;
        rgb_values[i] = strtok(color_code + 4, ",");
        
        while (rgb_values[i] != NULL && i < 3) {
            i++;
            rgb_values[i] = strtok(NULL, ",");
        }
        
        int red = atoi(rgb_values[0]);
        int green = atoi(rgb_values[1]);
        int blue = atoi(rgb_values[2]);
        
        sprintf(hex_color_code, "#%02x%02x%02x", red, green, blue);
    } else if (color_code[0] == 'h') {
        char* hsl_values[3];
        int i = 0;
        hsl_values[i] = strtok(color_code + 4, ",");
        
        while (hsl_values[i] != NULL && i < 2) {
            i++;
            hsl_values[i] = strtok(NULL, ",");
        }
        
        int hue = atoi(hsl_values[0]);
        int saturation = atoi(hsl_values[1]);
        int luminosity = atoi(hsl_values[2]);
        
        int c = (1 - abs(2 * luminosity - 1)) * saturation;
        int x = c * (1 - abs((hue / 60) % 2 - 1));
        int m = luminosity - c / 2;
        int r, g, b;
        
        if (hue >= 0 && hue < 60) {
            r = c;
            g = x;
            b = 0;
        } else if (hue >= 60 && hue < 120) {
            r = x;
            g = c;
            b = 0;
        } else if (hue >= 120 && hue < 180) {
            r = 0;
            g = c;
            b = x;
        } else if (hue >= 180 && hue < 240) {
            r = 0;
            g = x;
            b = c;
        } else if (hue >= 240 && hue < 300) {
            r = x;
            g = 0;
            b = c;
        } else if (hue >= 300 && hue < 360) {
            r = c;
            g = 0;
            b = x;
        }
        
        sprintf(hex_color_code, "#%02x%02x%02x", (r + m) * 255, (g + m) * 255, (b + m) * 255);
    }
    
    return hex_color_code;
}

int main() {
    char* color_code1 = "#FF5733";
    char* color_code2 = "rgb(255, 87, 51)";
    char* color_code3 = "hsl(17, 100%, 50%)";
    
    char* hex_color_code1 = convert_color_code(color_code1);
    char* hex_color_code2 = convert_color_code(color_code2);
    char* hex_color_code3 = convert_color_code(color_code3);
    
    printf("%s\n", hex_color_code1); // output: #ff5733
    printf("%s\n", hex_color_code2); // output: #ff5733
    printf("%s\n", hex_color_code3); // output: #ff5733
}