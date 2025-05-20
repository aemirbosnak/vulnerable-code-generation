//Falcon-180B DATASET v1.0 Category: Pattern printing ; Style: Dennis Ritchie
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
 
int main() {
    int n, i, j, k, l, m;
    time_t t;
    struct tm *tm;
    char *pattern;
    int *arr;
    int count = 0;
    int max = 0;
 
    srand(time(NULL));
    n = rand() % 10 + 1;
 
    arr = (int *)malloc(n*sizeof(int));
 
    for(i=0;i<n;i++) {
        arr[i] = rand() % 100;
    }
 
    printf("Enter the number of rows: ");
    scanf("%d", &m);
 
    printf("Enter the pattern:\n");
    scanf("%s", &pattern);
 
    for(i=0;i<m;i++) {
        for(j=0;j<n;j++) {
            if(pattern[i] == '*') {
                printf("%d ", arr[j]);
            }
            else if(pattern[i] == 'S') {
                if(arr[j] > max) {
                    max = arr[j];
                }
            }
            else if(pattern[i] == 'L') {
                if(arr[j] < max) {
                    printf("%d ", arr[j]);
                }
            }
            else if(pattern[i] == 'A') {
                if(arr[j] % 2 == 0) {
                    printf("%d ", arr[j]);
                }
            }
            else if(pattern[i] == 'O') {
                if(arr[j] % 2!= 0) {
                    printf("%d ", arr[j]);
                }
            }
            else if(pattern[i] == 'R') {
                if(arr[j] % 3 == 0) {
                    printf("%d ", arr[j]);
                }
            }
        }
        printf("\n");
    }
 
    free(arr);
    return 0;
}