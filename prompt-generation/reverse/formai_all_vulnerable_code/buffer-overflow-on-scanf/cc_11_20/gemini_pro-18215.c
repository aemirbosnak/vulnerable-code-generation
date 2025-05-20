//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, j, k, l, count = 0, arr[100], guess[100], flag = 0;
    char ch;
    srand(time(NULL));
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1;
    }
    printf("The elements are: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Enter the elements to be guessed: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &guess[i]);
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (arr[i] == guess[j]) {
                count++;
                arr[i] = -1;
                guess[j] = -1;
            }
        }
    }
    for (i = 0; i < n; i++) {
        if (arr[i] != -1) {
            flag = 1;
            break;
        }
    }
    for (i = 0; i < n; i++) {
        if (guess[i] != -1) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
        printf("You won!\n");
    } else {
        printf("You lost!\n");
    }
    printf("Do you want to play again? (y/n): ");
    scanf(" %c", &ch);
    if (ch == 'y') {
        main();
    } else {
        printf("Thank you for playing!\n");
    }
    return 0;
}