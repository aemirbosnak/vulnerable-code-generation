//MISTRAL-7B DATASET v1.0 Category: Color Code Converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 100

void convert_color(char *color, char output[MAX_LENGTH]) {
    int r, g, b, i;

    if (sscanf(color, "%s %n", "rgb(", &i) != 1) {
        strcpy(output, "Invalid color code");
        return;
    }

    if (sscanf(color + i, "%d, %d, %d%n", &r, &g, &b, &i) != 3) {
        strcpy(output, "Invalid color code");
        return;
    }

    char hex_r[3], hex_g[3], hex_b[3];
    sprintf(hex_r, "%02x", r);
    sprintf(hex_g, "%02x", g);
    sprintf(hex_b, "%02x", b);

    strcpy(output, "#");
    strcat(output, hex_r);
    strcat(output, hex_g);
    strcat(output, hex_b);
}

int main() {
    char input[MAX_LENGTH], output[MAX_LENGTH];
    printf("Enter RGB color code: ");
    scanf("%s", input);

    convert_color(input, output);
    printf("Hex color code: %s\n", output);

    // Buffer overflow vulnerability
    char *input_ptr = input;
    char *output_ptr = output;

    while (*input_ptr) {
        if (*input_ptr == ' ') {
            *output_ptr++ = '\0';
            input_ptr++;
            continue;
        }

        convert_color(input_ptr, output_ptr);
        input_ptr += strlen(input_ptr);
        output_ptr += strlen(output_ptr);
    }

    printf("Manipulated hex color code: %s\n", output);

    return 0;
}