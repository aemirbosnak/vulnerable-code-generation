//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

int main() {
    int n, i, j, max_sum = 0;
    int arr[MAX];
    int sum = 0;
    int coin[MAX];
    int m = 0;
    int S[MAX];
    int index = 0;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the values of items: ");
    for(i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the number of coins: ");
    scanf("%d", &m);

    printf("Enter the values of coins: ");
    for(i=0; i<m; i++) {
        scanf("%d", &coin[i]);
    }

    printf("Enter the number of items to be selected: ");
    scanf("%d", &n);

    S[0] = 0;
    for(i=1; i<=n; i++) {
        sum = 0;
        for(j=0; j<m; j++) {
            if(arr[i-1] <= coin[j]) {
                sum += coin[j];
            }
        }
        if(sum > 0) {
            S[index++] = sum;
        }
    }

    printf("The possible sums are: ");
    for(i=0; i<index; i++) {
        printf("%d ", S[i]);
    }

    return 0;
}