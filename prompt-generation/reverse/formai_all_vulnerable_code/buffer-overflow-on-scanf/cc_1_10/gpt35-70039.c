//FormAI DATASET v1.0 Category: Color Code Converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to convert a color name to its hexadecimal code
char* convertToHexCode(char* colorName) {
    char* hexCode = (char*)malloc(sizeof(char) * 7);
    int i = 0;

    // checks for some common color names
    if (strcmp(colorName, "red") == 0) {
        strcpy(hexCode, "#FF0000");
    }
    else if (strcmp(colorName, "green") == 0) {
        strcpy(hexCode, "#008000");
    }
    else if (strcmp(colorName, "blue") == 0) {
        strcpy(hexCode, "#0000FF");
    }

    // handles other color names using a switch case
    else {
        switch (colorName[0]) {
        case 'a': // aqua, azure, aliceblue, etc.
            if (strcmp(colorName, "aqua") == 0) {
                strcpy(hexCode, "#00FFFF");
            }
            else if (strcmp(colorName, "azure") == 0) {
                strcpy(hexCode, "#F0FFFF");
            }
            // more cases can be added here
            break;

        case 'b': // black, brown, beige, etc.
            if (strcmp(colorName, "black") == 0) {
                strcpy(hexCode, "#000000");
            }
            else if (strcmp(colorName, "brown") == 0) {
                strcpy(hexCode, "#A52A2A");
            }
            else if (strcmp(colorName, "beige") == 0) {
                strcpy(hexCode, "#F5F5DC");
            }
            // more cases can be added here
            break;

        // more cases can be added here

        default:
            strcpy(hexCode, "not found");
            break;
        }
    }

    return hexCode;
}

int main() {
    char colorName[20];
    printf("Enter a color name: ");
    scanf("%s", colorName);

    char* hexCode = convertToHexCode(colorName);
    printf("%s: %s\n", colorName, hexCode);

    free(hexCode);
    return 0;
}