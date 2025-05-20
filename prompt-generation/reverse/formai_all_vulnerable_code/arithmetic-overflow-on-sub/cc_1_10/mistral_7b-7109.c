//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_STRINGS 100
#define MAX_LENGTH 50

typedef struct {
    char str[MAX_LENGTH + 1];
    int length;
} String;

void swapStrings(String *a, String *b) {
    String temp = *a;
    *a = *b;
    *b = temp;
}

bool isSorted(String arr[], int n) {
    int i;
    for (i = 0; i < n - 1; i++) {
        if (strcmp(arr[i].str, arr[i + 1].str) > 0) {
            return false;
        }
    }
    return true;
}

void LoveSort(String arr[], int n) {
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(arr[j].str, arr[j + 1].str) > 0) {
                swapStrings(&arr[j], &arr[j + 1]);
                swapped = true;
            }
            printf("\033[2J"); // Clear the console screen
            printf("\033[%d;%dH", 1 + i * 2, j * 2); // Move cursor to the desired position
            printf("❤");
            fflush(stdout); // Flush the output buffer to display the heart immediately
            usleep(100000); // Wait for 100ms to create a delay between hearts
        }
        if (!swapped) {
            break;
        }
    }
}

int main() {
    String arr[MAX_STRINGS];
    int n, i;
    printf("Enter the number of strings: ");
    scanf("%d", &n);
    printf("\nEnter %d strings:\n", n);

    for (i = 0; i < n; i++) {
        fgets(arr[i].str, sizeof(arr[i].str), stdin);
        arr[i].length = strlen(arr[i].str);
        if (arr[i].length > MAX_LENGTH) {
            arr[i].length--;
            arr[i].str[arr[i].length] = '\0';
        }
    }

    LoveSort(arr, n);

    printf("\nSorted strings:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", arr[i].str);
    }

    return 0;
}