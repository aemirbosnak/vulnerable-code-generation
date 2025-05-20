//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

int strCmp(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int minLen = len1 < len2? len1 : len2;
    int result = 0;
    for (int i = 0; i < minLen; i++) {
        if (s1[i]!= s2[i]) {
            result = s1[i] - s2[i];
            break;
        }
    }
    return result;
}

void strSwap(char* s1, char* s2) {
    char temp[MAX_STRING_LENGTH];
    strcpy(temp, s1);
    strcpy(s1, s2);
    strcpy(s2, temp);
}

void bubbleSort(char* arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strCmp(arr[j], arr[j + 1]) > 0) {
                strSwap(arr[j], arr[j + 1]);
            }
        }
    }
}

void search(char* arr[], int n, char* searchKey) {
    bubbleSort(arr, n);
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cmp = strCmp(arr[mid], searchKey);
        if (cmp == 0) {
            printf("Search Key found at index %d\n", mid);
            return;
        } else if (cmp > 0) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    printf("Search Key not found\n");
}

int main() {
    char arr[MAX_STRING_LENGTH][MAX_STRING_LENGTH];
    int n;
    printf("Enter number of elements to be sorted: ");
    scanf("%d", &n);
    printf("Enter elements to be sorted:\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i]);
    }
    char searchKey[MAX_STRING_LENGTH];
    printf("Enter search key: ");
    scanf("%s", searchKey);
    search(arr, n, searchKey);
    return 0;
}