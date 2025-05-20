//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 20
#define MAX_COLS 40

void print_pattern(int rows, int cols) {
    srand(time(NULL));
    int num_patterns = rand() % 7 + 1;
    for (int i = 0; i < num_patterns; i++) {
        for (int j = 0; j < rows; j++) {
            for (int k = 0; k < cols; k++) {
                if (i == 0) {
                    printf("*");
                } else if (i == 1) {
                    printf(".");
                } else if (i == 2) {
                    printf("#");
                } else if (i == 3) {
                    printf("@");
                } else if (i == 4) {
                    printf("%");
                } else if (i == 5) {
                    printf("&");
                } else if (i == 6) {
                    printf("~");
                }
            }
            printf("\n");
        }
    }
}

int main() {
    int rows, cols;
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    if (rows > MAX_ROWS || cols > MAX_COLS) {
        printf("Error: Input values are too large.\n");
        return 1;
    }

    print_pattern(rows, cols);

    return 0;
}