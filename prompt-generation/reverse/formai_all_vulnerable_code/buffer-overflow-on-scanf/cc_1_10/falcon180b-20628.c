//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLOR_NAME_LENGTH 100

struct color_code {
    char name[MAX_COLOR_NAME_LENGTH];
    int hex_code;
};

int main() {
    int num_color_codes = 0;
    struct color_code color_codes[100];

    char input[MAX_COLOR_NAME_LENGTH];
    while (1) {
        printf("Enter a color name (or type 'q' to quit): ");
        scanf("%s", input);

        if (strcmp(input, "q") == 0) {
            break;
        }

        if (num_color_codes >= 100) {
            printf("Error: too many color codes.\n");
            continue;
        }

        int i;
        for (i = 0; i < num_color_codes; i++) {
            if (strcmp(color_codes[i].name, input) == 0) {
                printf("Duplicate color name.\n");
                break;
            }
        }

        if (i == num_color_codes) {
            strcpy(color_codes[num_color_codes].name, input);
            printf("Enter the hex code for %s: ", input);
            scanf("%x", &color_codes[num_color_codes].hex_code);
            num_color_codes++;
        }
    }

    printf("\nColor Name\t\tHex Code\n");
    for (int i = 0; i < num_color_codes; i++) {
        printf("%s\t\t%x\n", color_codes[i].name, color_codes[i].hex_code);
    }

    return 0;
}