//GPT-4o-mini DATASET v1.0 Category: Pattern printing ; Style: Ken Thompson
#include <stdio.h>

void print_hollow_square(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void print_right_angle_triangle(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void print_pyramid(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = i; j < n; j++) {
            printf(" ");
        }
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
}

void print_diamond(int n) {
    print_pyramid(n);
    for (int i = n - 1; i >= 1; i--) {
        for (int j = n; j > i; j--) {
            printf(" ");
        }
        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
}

void print_number_pyramid(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = i; j < n; j++) {
            printf(" ");
        }
        for (int j = 1; j <= i; j++) {
            printf("%d ", j);
        }
        printf("\n");
    }
}

void print_floyds_triangle(int n) {
    int num = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", num);
            num++;
        }
        printf("\n");
    }
}

void print_triangle_with_spaces(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for (int j = 1; j <= (2 * i - 1); j++) {
            if(j % 2 == 0){
                printf(" ");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}

int main() {
    int choice, n;
    printf("Choose a pattern to print:\n");
    printf("1. Hollow Square\n2. Right Angle Triangle\n3. Pyramid\n4. Diamond\n5. Number Pyramid\n6. Floyd's Triangle\n7. Triangle with Spaces\n");
    printf("Enter your choice (1-7): ");
    scanf("%d", &choice);
    printf("Enter the size (n): ");
    scanf("%d", &n);

    switch (choice) {
        case 1:
            print_hollow_square(n);
            break;
        case 2:
            print_right_angle_triangle(n);
            break;
        case 3:
            print_pyramid(n);
            break;
        case 4:
            print_diamond(n);
            break;
        case 5:
            print_number_pyramid(n);
            break;
        case 6:
            print_floyds_triangle(n);
            break;
        case 7:
            print_triangle_with_spaces(n);
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}