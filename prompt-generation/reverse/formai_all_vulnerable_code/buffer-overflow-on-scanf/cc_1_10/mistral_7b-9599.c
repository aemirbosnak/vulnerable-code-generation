//MISTRAL-7B DATASET v1.0 Category: Data mining ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int longestSequence(int arr[], int start, int len, int *maxLen);

int main() {
    int arr[MAX_SIZE], i, len;
    int maxLen = 0;

    printf("Enter the number of elements: ");
    scanf("%d", &len);

    printf("Enter %d integers: ", len);
    for(i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
    }

    printf("The longest consecutive sequence has a length of %d.\n", longestSequence(arr, 0, len, &maxLen));

    return 0;
}

int longestSequence(int arr[], int start, int len, int *maxLen) {
    int i, currLen = 1;

    if(len <= 0) {
        return 0;
    }

    if(start + 1 < len && arr[start] + 1 == arr[start + 1]) {
        currLen++;
        return longestSequence(arr, start + 1, len - 1, maxLen) + currLen;
    } else {
        *maxLen = (currLen > *maxLen) ? currLen : *maxLen;
        currLen = 1;
    }

    for(i = start + 1; i < len; i++) {
        if(arr[i] == arr[i - 1] + 1) {
            currLen++;
        } else {
            *maxLen = (currLen > *maxLen) ? currLen : *maxLen;
            currLen = 1;
        }
    }

    *maxLen = (currLen > *maxLen) ? currLen : *maxLen;

    return *maxLen;
}