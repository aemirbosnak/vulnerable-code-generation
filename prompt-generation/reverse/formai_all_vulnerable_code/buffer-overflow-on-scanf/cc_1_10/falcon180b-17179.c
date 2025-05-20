//Falcon-180B DATASET v1.0 Category: Color Code Converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 10000

int main() {
    char hex[MAX_LENGTH];
    char rgb[MAX_LENGTH];
    char c;
    int i = 0;
    int j = 0;
    int len;

    printf("Enter a hex color code: ");
    scanf("%s", hex);

    len = strlen(hex);

    if (len!= 6 && len!= 8) {
        printf("Invalid hex color code.\n");
        return 0;
    }

    if (len == 8) {
        hex[6] = '\0';
    }

    for (i = 0; i < strlen(hex); i++) {
        c = toupper(hex[i]);

        if (c >= '0' && c <= '9') {
            rgb[j] = c;
            j++;
        } else if (c >= 'A' && c <= 'F') {
            rgb[j] = c;
            j++;
        } else {
            printf("Invalid hex color code.\n");
            return 0;
        }
    }

    rgb[j] = '\0';

    printf("RGB color code: %s\n", rgb);

    return 0;
}