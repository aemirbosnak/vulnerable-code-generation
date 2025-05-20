//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rows, cols;
    char choice;
    srand(time(0));

    do {
        printf("Enter the number of rows: ");
        scanf("%d", &rows);
        printf("Enter the number of columns: ");
        scanf("%d", &cols);
    } while (rows <= 0 || cols <= 0);

    int arr[rows][cols];
    printf("\nEnter the array elements:\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    system("clear");

    printf("\nEnter the pattern:\n");
    scanf("%c", &choice);

    switch (choice) {
        case '1':
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    printf("%d ", arr[i][j]);
                }
                printf("\n");
            }
            break;
        case '2':
            for (int i = 0; i < cols; i++) {
                for (int j = 0; j < rows; j++) {
                    printf("%d ", arr[j][i]);
                }
                printf("\n");
            }
            break;
        case '3':
            for (int i = rows - 1; i >= 0; i--) {
                for (int j = cols - 1; j >= 0; j--) {
                    printf("%d ", arr[i][j]);
                }
                printf("\n");
            }
            break;
        case '4':
            for (int i = cols - 1; i >= 0; i--) {
                for (int j = 0; j < rows; j++) {
                    printf("%d ", arr[j][i]);
                }
                printf("\n");
            }
            break;
        case '5':
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (i == j) {
                        printf("%d ", arr[i][j]);
                    } else {
                        printf("0 ");
                    }
                }
                printf("\n");
            }
            break;
        case '6':
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    if (i + j == rows - 1) {
                        printf("%d ", arr[i][j]);
                    } else {
                        printf("0 ");
                    }
                }
                printf("\n");
            }
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}