//FormAI DATASET v1.0 Category: Color Code Converter ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Recursive function to convert an integer to Hexadecimal color code
void convertToHexColor(int n)
{
    if (n == 0) {
        return;
    }
    // Recursively call convertToHexColor function
    convertToHexColor(n / 16);
 
    int rem = n % 16;
    if (rem < 10) {
        printf("%d", rem);
    } else {
        printf("%c", rem - 10 + 'A');
    }
}

// Recursive function to convert Hexadecimal color code to integer
int convertToDecimal(char color[], int len)
{
    // Base case
    if (len == 0) {
        return 0;
    }

    // Recursively call convertToDecimal function
    int val = convertToDecimal(color, len - 1);
 
    // extract the last character and calculate its value
    int res = color[len-1] - '0';
    if (color[len-1] >= 'A' && color[len-1] <= 'F') {
        res = color[len-1] - 'A' + 10;
    }

    // Add the value of last character to the result of remaining characters
    return val * 16 + res;
}

int main()
{
    char hexColor[8], choice;
    int r, g, b, decColor;

    do {
        printf("Enter 'c' to convert RGB to Hexadecimal color code or 'h' to convert Hexadecimal color code to RGB: ");
        scanf(" %c", &choice);

        if (choice == 'c') {
            printf("\nEnter RGB values separated by space (e.g. 255 128 0): ");
            scanf("%d %d %d", &r, &g, &b);

            printf("\nHexadecimal Color Code: #");
            convertToHexColor(r);
            convertToHexColor(g);
            convertToHexColor(b);
            printf("\n\n");
        }

        else if (choice == 'h') {
            printf("\nEnter Hexadecimal color code (e.g. FFFF00): ");
            scanf("%s", hexColor);

            decColor = convertToDecimal(hexColor, 6);

            printf("\nRGB values: %d %d %d\n\n", (decColor >> 16) & 0xFF, (decColor >> 8) & 0xFF, decColor & 0xFF);
        }

        else {
            printf("\nInvalid Choice! Try Again.\n\n");
        }

    } while (choice != 'c' && choice != 'h');

    return 0;
}