//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int a, b, c;
    char op;
    int result;
    int count = 0;
    int flag = 0;
    int max_count = 10;
    int min_count = 5;
    int difficulty = rand() % (max_count - min_count + 1) + min_count;
    int arr[difficulty];
    for (int i = 0; i < difficulty; i++) {
        a = rand() % 100;
        b = rand() % 100;
        c = rand() % 100;
        op = rand() % 4;
        switch (op) {
            case 0:
                result = a + b;
                break;
            case 1:
                result = a - b;
                break;
            case 2:
                result = a * b;
                break;
            case 3:
                if (b == 0) {
                    result = 0;
                } else {
                    result = a / b;
                }
                break;
        }
        arr[i] = result;
    }
    printf("Welcome to the Arithmetic Challenge!\n");
    for (int i = 0; i < difficulty; i++) {
        printf("%d + %d = ", arr[i], rand() % 100);
        scanf("%d", &result);
        if (result == arr[i]) {
            count++;
        }
    }
    if (count == difficulty) {
        printf("\nCongratulations! You have completed the challenge with a perfect score!\n");
    } else {
        printf("\nSorry, you have not completed the challenge with a perfect score.\n");
    }
    return 0;
}