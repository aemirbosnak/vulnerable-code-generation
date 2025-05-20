//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct {
    char data[MAX_SIZE];
    int size;
} String;

// Function to initialize a string
void init(String* str) {
    str->size = 0;
    str->data[str->size] = '\0';
}

// Function to concatenate two strings
void concat(String* str1, String* str2) {
    int len1 = str1->size;
    int len2 = str2->size;
    int new_size = len1 + len2 + 1;

    if (new_size > MAX_SIZE) {
        printf("Error: String too long\n");
        exit(1);
    }

    strcat(str1->data, str2->data);
    str1->size = new_size;
}

// Function to compare two strings
int compare(String* str1, String* str2) {
    int len1 = str1->size;
    int len2 = str2->size;

    if (len1!= len2) {
        return len1 - len2;
    }

    return strcmp(str1->data, str2->data);
}

// Function to search for a string in a sorted array of strings
int binary_search(String* arr, int n, String* target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int cmp = compare(arr + mid, target);

        if (cmp == 0) {
            return mid;
        } else if (cmp < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    String arr[MAX_SIZE];
    int n = 0;
    String target;

    init(&arr[n]);
    printf("Enter string 1: ");
    scanf("%s", arr[n].data);
    n++;

    while (scanf("%s", arr[n].data)!= EOF) {
        n++;
    }

    init(&target);
    printf("Enter target string: ");
    scanf("%s", target.data);

    int index = binary_search(arr, n, &target);

    if (index == -1) {
        printf("Target string not found\n");
    } else {
        printf("Target string found at index %d\n", index);
    }

    return 0;
}