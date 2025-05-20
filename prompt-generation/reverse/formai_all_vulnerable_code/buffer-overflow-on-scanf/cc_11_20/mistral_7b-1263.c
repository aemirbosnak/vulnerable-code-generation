//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAX_SIZE 100
#define GRATITUDE_SIZE 50

int main() {
    int i, j, temp;
    int arr[MAX_SIZE];
    char gratitude[GRATITUDE_SIZE][100];

    printf("Hello! I'm a C sorting program, and I'm grateful for your attention.\n");
    printf("I'd be happy to sort an array of integers for you using the Bubble Sort algorithm.\n");
    printf("Please enter %d integers to be sorted:\n", MAX_SIZE);

    for (int k = 0; k < MAX_SIZE; k++) {
        scanf("%d", &arr[k]);
        fflush(stdin);
    }

    for (i = 0; i < MAX_SIZE - 1; i++) {
        for (j = 0; j < MAX_SIZE - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("\nThank you for letting me sort your integers! Here is the sorted array:\n");
    for (i = 0; i < MAX_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("\nNow, let me express my gratitude in a creative way:\n");
    for (int m = 0; m < GRATITUDE_SIZE; m++) {
        int r = rand() % 5;
        switch (r) {
            case 0:
                strcpy(gratitude[m], "I'm grateful for your patience, for giving me the chance to serve you.");
                break;
            case 1:
                strcpy(gratitude[m], "I'm thankful for your trust in my abilities to sort your numbers.");
                break;
            case 2:
                strcpy(gratitude[m], "I'm grateful for the opportunity to write a C program that sorts integers.");
                break;
            case 3:
                strcpy(gratitude[m], "I'm thankful for your presence as I continue my journey to learn and grow.");
                break;
            case 4:
                strcpy(gratitude[m], "I'm grateful for the chance to bring a smile to your face with some code.");
                break;
        }
        printf("%s\n", gratitude[m]);
    }

    return 0;
}