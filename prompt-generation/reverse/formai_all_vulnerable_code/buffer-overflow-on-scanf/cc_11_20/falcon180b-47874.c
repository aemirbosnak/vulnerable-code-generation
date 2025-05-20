//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main() {
    int i, j, n, m, sum, choice, flag = 0;
    float avg, num, median, mode[10], freq[10] = {0};
    char ch;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d integers:\n", n);

    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter your choice:\n");
    printf("1. Sum\n");
    printf("2. Average\n");
    printf("3. Median\n");
    printf("4. Mode\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            sum = 0;
            for(i = 0; i < n; i++) {
                sum += arr[i];
            }
            printf("The sum of the array is: %d\n", sum);
            break;
        case 2:
            avg = 0;
            for(i = 0; i < n; i++) {
                avg += arr[i];
            }
            avg = avg / n;
            printf("The average of the array is: %.2f\n", avg);
            break;
        case 3:
            for(i = 0; i < n; i++) {
                if(arr[i] > median) {
                    median++;
                }
            }
            printf("The median of the array is: %d\n", median);
            break;
        case 4:
            for(i = 0; i < n; i++) {
                freq[arr[i]]++;
            }
            for(i = 0; i < n; i++) {
                if(freq[arr[i]] > mode[0]) {
                    mode[0] = arr[i];
                }
            }
            printf("The mode of the array is: %d\n", mode[0]);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}