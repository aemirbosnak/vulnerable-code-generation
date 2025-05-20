//FormAI DATASET v1.0 Category: Scientific ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    int n, i, j, k, l, m, sum, count;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    // generate array with random integers
    srand(time(NULL));
    for(i = 0; i < n; i++) {
        arr[i] = rand() % 100;
        printf("%d ", arr[i]);
    }

    // find prime numbers in array
    printf("\nPrime numbers in array: ");
    count = 0;
    for(i = 0; i < n; i++) {
        sum = 0;
        for(j = 2; j <= arr[i]/2; j++) {
            if(arr[i] % j == 0) {
                sum++;
                break;
            }
        }
        if(sum == 0 && arr[i] != 1) {
            printf("%d ", arr[i]);
            count++;
        }
    }
    if(count == 0) {
        printf("No prime numbers found!");
    }

    // find squares of even numbers in array
    printf("\nSquares of even numbers in array: ");
    count = 0;
    for(i = 0; i < n; i++) {
        if(arr[i] % 2 == 0) {
            printf("%d ", pow(arr[i], 2));
            count++;
        }
    }
    if(count == 0) {
        printf("No even numbers found!");
    }

    // find palindrome numbers in array
    printf("\nPalindrome numbers in array: ");
    count = 0;
    for(i = 0; i < n; i++) {
        int num = arr[i];
        int rev = 0;
        while(num != 0) {
            int rem = num % 10;
            rev = (rev*10) + rem;
            num /= 10;
        }
        if(rev == arr[i]) {
            printf("%d ", arr[i]);
            count++;
        }
    }
    if(count == 0) {
        printf("No palindrome numbers found!");
    }

    // find smallest and largest numbers in array
    int smallest = arr[0];
    int largest = arr[0];
    for(i = 1; i < n; i++) {
        if(arr[i] < smallest)
            smallest = arr[i];
        if(arr[i] > largest)
            largest = arr[i];
    }
    printf("\nSmallest number in array: %d", smallest);
    printf("\nLargest number in array: %d", largest);

    // sort array in ascending order
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("\nArray in ascending order: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // reverse array
    j = n-1;
    for(i = 0; i < j; i++) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        j--;
    }
    printf("\nReversed array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // find frequency of each element in array
    printf("\nFrequency of each element in array:");
    for(i = 0; i < n; i++) {
        count = 1;
        for(j = i+1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
                for(k = j; k < n-1; k++) {
                    arr[k] = arr[k+1];
                }
                n--;
                j--;
            }
        }
        printf("\n%d occurs %d times", arr[i], count);
    }

    // find missing numbers in array
    int missing[100], index = 0;
    for(i = smallest+1; i < largest; i++) {
        sum = 0;
        for(j = 0; j < n; j++) {
            if(i == arr[j]) {
                sum++;
                break;
            }
        }
        if(sum == 0) {
            missing[index] = i;
            index++;
        }
    }
    printf("\nMissing number(s) in array: ");
    if(index == 0) {
        printf("None");
    }
    else {
        for(i = 0; i < index; i++) {
            printf("%d ", missing[i]);
        }
    }

    return 0;
}