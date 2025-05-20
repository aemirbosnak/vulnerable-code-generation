//Falcon-180B DATASET v1.0 Category: Bitwise operations ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int n, i, choice, pos, value;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\n");
        printf("1. Display array\n");
        printf("2. Reverse array\n");
        printf("3. Shift array elements\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Array elements are: ");
                for (i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 2:
                for (i = 0; i < n / 2; i++) {
                    value = arr[i];
                    arr[i] = arr[n - i - 1];
                    arr[n - i - 1] = value;
                }
                printf("Reversed array elements are: ");
                for (i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 3:
                printf("Enter the number of positions to shift: ");
                scanf("%d", &pos);

                for (i = 0; i < n - pos; i++) {
                    value = arr[i];
                    arr[i] = arr[i + pos];
                    arr[i + pos] = value;
                }

                printf("Shifted array elements are: ");
                for (i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice!= 4);

    return 0;
}