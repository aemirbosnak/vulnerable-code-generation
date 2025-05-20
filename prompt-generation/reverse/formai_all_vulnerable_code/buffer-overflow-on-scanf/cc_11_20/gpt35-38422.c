//FormAI DATASET v1.0 Category: Movie Rating System ; Style: statistical
#include <stdio.h>

int main() {
    int rating, count = 0;
    int sum = 0;
    float average;

    printf("=== C Movie Rating System ===\n");
    printf("Enter rating from 1 to 10. Enter -1 to stop.\n");

    do {
        printf("Enter rating: ");
        scanf("%d", &rating);

        if (rating >= 1 && rating <= 10) {
            sum += rating;
            count++;
        } else if (rating != -1) {
            printf("Invalid rating entered. Please enter a rating from 1 to 10 or -1 to stop.\n");
        }
    } while (rating != -1);

    if (count == 0) {
        printf("==============================\n");
        printf("No ratings entered. Thank you for using C Movie Rating System.\n");
        printf("==============================\n");
        return 0;
    }

    average = (float) sum / count;
    printf("==============================\n");
    printf("Summary:\n");
    printf("Number of ratings entered: %d\n", count);
    printf("Average rating: %.2f\n", average);

    printf("Histogram:\n");
    printf("1-2: ");
    for (int i = 0; i < sum / 10; i++) {
        printf("*");
    }
    printf("\n");

    printf("3-4: ");
    for (int i = 0; i < sum % 10; i++) {
        printf("*");
    }
    printf("\n");

    printf("5-6: ");
    for (int i = 0; i < (10 - sum % 10); i++) {
        printf("*");
    }
    printf("\n");

    printf("7-8: ");
    for (int i = 0; i < sum / 10; i++) {
        printf("*");
    }
    printf("\n");

    printf("9-10: ");
    for (int i = 0; i < sum % 10; i++) {
        printf("*");
    }
    printf("\n");

    printf("==============================\n");
    printf("Thank you for using C Movie Rating System.\n");
    printf("==============================\n");

    return 0;
}