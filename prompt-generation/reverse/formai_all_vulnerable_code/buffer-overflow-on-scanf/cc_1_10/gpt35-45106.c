//FormAI DATASET v1.0 Category: Pattern printing ; Style: shape shifting
#include <stdio.h>

void pattern1(int n) {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d ", i);
        }
        printf("\n");
    }
}

void pattern2(int n) {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            printf("%c ", 64+i);
        }
        printf("\n");
    }
}

void pattern3(int n) {
    int i, j;
    for (i = n; i > 0; i--) {
        for (j = i; j > 0; j--) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

void pattern4(int n) {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = n; j > 0; j--) {
            if (j > i) {
                printf("  ");
            } else {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

int main() {
    int choice, n;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    do {
        printf("\nWhich pattern do you want to print?\n");
        printf("1. Pattern 1\n");
        printf("2. Pattern 2\n");
        printf("3. Pattern 3\n");
        printf("4. Pattern 4\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 0:
                break;
            case 1:
                pattern1(n);
                break;
            case 2:
                pattern2(n);
                break;
            case 3:
                pattern3(n);
                break;
            case 4:
                pattern4(n);
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);
    return 0;
}