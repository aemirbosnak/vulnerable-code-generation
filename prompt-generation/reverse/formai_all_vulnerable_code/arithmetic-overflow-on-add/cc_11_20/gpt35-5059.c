//FormAI DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: portable
#include <stdio.h>

int main() {
    
    int n, first = 0, second = 1, next, i;
    
    printf("Enter the number of terms in Fibonacci sequence: ");
    scanf("%d", &n);
    
    printf("Fibonacci Series:\n");
    
    for(i = 0; i < n; i++) {
        if(i <= 1)
            next = i;
        else {
            next = first + second;
            first = second;
            second = next;
        }
        printf("%d ", next);
    }
    
    printf("\n\n");
    
    int height = n + 2;
    int width = (n * 2) + 2;
    
    char sequence[height][width];
    
    for(i = 0; i < height; i++)
        for(int j = 0; j < width; j++)
            sequence[i][j] = ' ';
    
    for(i = 0; i < n; i++) {
        if(i == 0) {
            sequence[1][n+1] = '0';
            continue;
        } else if(i == 1) {
            sequence[n][n+1] = '1';
            continue;
        }
        
        next = first + second;
        first = second;
        second = next;
        
        int length = sprintf(sequence[0], "%d", next);
        int start = (width - length) / 2;
        
        for(int j = 0; j < length; j++)
            sequence[i+1][start+j] = sequence[0][j];
    }
    
    for(i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            printf("%c", sequence[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}