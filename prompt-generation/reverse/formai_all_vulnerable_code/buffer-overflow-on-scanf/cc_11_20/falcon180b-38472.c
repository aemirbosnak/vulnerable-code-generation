//Falcon-180B DATASET v1.0 Category: File handling ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    FILE *file;
    int choice, n, i, j, k;
    float arr[100], sum = 0;
    char filename[50];

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("File not found\n");
        return 0;
    }

    printf("Enter the number of elements in the file: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        fscanf(file, "%f", &arr[i]);
    }

    printf("Enter the operation to be performed:\n");
    printf("1. Sum\n2. Average\n3. Product\n4. Square\n5. Cube\n");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            for (i = 0; i < n; i++) {
                sum += arr[i];
            }
            printf("Sum = %.2f\n", sum);
            break;
        case 2:
            sum = 0;
            for (i = 0; i < n; i++) {
                sum += arr[i];
            }
            printf("Average = %.2f\n", sum / n);
            break;
        case 3:
            sum = 1;
            for (i = 0; i < n; i++) {
                sum *= arr[i];
            }
            printf("Product = %.2f\n", sum);
            break;
        case 4:
            sum = 0;
            for (i = 0; i < n; i++) {
                sum += pow(arr[i], 2);
            }
            printf("Square = %.2f\n", sum);
            break;
        case 5:
            sum = 0;
            for (i = 0; i < n; i++) {
                sum += pow(arr[i], 3);
            }
            printf("Cube = %.2f\n", sum);
            break;
        default:
            printf("Invalid choice\n");
    }

    fclose(file);

    return 0;
}