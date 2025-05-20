//FormAI DATASET v1.0 Category: Online Examination System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, q, ans, count = 0;
    srand(time(NULL));
    
    printf("Enter the number of questions: ");
    scanf("%d", &n);
    printf("\n");
    
    for (int i = 1; i <= n; i++) {
        int a = rand() % 10;
        int b = rand() % 10;
        int op = rand() % 4;
        
        printf("%d) ", i);
        
        if (op == 0) {
            printf("%d + %d = ", a, b);
            q = a + b;
        }
        else if (op == 1) {
            printf("%d - %d = ", a, b);
            q = a - b;
        }
        else if (op == 2) {
            printf("%d * %d = ", a, b);
            q = a * b;
        }
        else {
            printf("%d / %d = ", a, b);
            q = a / b;
        }
        
        scanf("%d", &ans);
        
        if (ans == q) {
            printf("Correct!\n");
            count++;
        }
        else {
            printf("Incorrect. The answer is %d.\n", q);
        }
    }
    
    printf("\nYou scored %d out of %d.\n", count, n);
    
    return 0;
}