//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: modular
#include <stdio.h>
#include <math.h>

// Function to print a pattern
void print_pattern(int rows, int cols, int pattern_num) {
    int i, j, k;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            switch (pattern_num) {
                case 1:
                    printf("*");
                    break;
                case 2:
                    printf("#");
                    break;
                case 3:
                    printf("@");
                    break;
                case 4:
                    printf("$");
                    break;
                case 5:
                    printf("%");
                    break;
                case 6:
                    printf("&");
                    break;
                case 7:
                    printf("~");
                    break;
                case 8:
                    printf("^");
                    break;
                case 9:
                    printf("+");
                    break;
                case 10:
                    printf("=");
                    break;
                default:
                    printf(" ");
                    break;
            }
        }
        printf("\n");
    }
}

// Main function
int main() {
    int rows, cols, pattern_num;

    // Get user input for number of rows and columns
    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Get user input for pattern number
    printf("Enter the pattern number (1-10): ");
    scanf("%d", &pattern_num);

    // Call print_pattern function
    print_pattern(rows, cols, pattern_num);

    return 0;
}