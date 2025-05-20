//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 1000

int main() {
    int arr[MAX_SIZE];
    int n, key, i, j, temp;
    char choice;
    srand(time(NULL));

    do {
        printf("Enter the size of the array (max %d): ", MAX_SIZE);
        scanf("%d", &n);
        if (n <= 0 || n > MAX_SIZE) {
            printf("Invalid size. Please try again.\n");
        }
    } while (n <= 0 || n > MAX_SIZE);

    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the key to search for: ");
    scanf("%d", &key);

    int index = -1; // initialize index to -1 (not found)

    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Key not found.\n");
    } else {
        printf("Key found at index %d.\n", index);
    }

    do {
        printf("Do you want to search again? (y/n): ");
        scanf(" %c", &choice);
        if (choice!= 'y' && choice!= 'n') {
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 'y' && choice!= 'n');

    if (choice == 'y') {
        main();
    } else {
        return 0;
    }
}