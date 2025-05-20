//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: romantic
#include <stdio.h>
#include <string.h>

void swap(char *xp, char *yp) {
    char temp[100];
    strcpy(temp, xp);
    strcpy(xp, yp);
    strcpy(yp, temp);
}

void bubbleSort(char arr[][100], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (strcmp(arr[j], arr[j+1]) > 0) {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void printArray(char arr[][100], int size) {
    for (int i=0; i < size; i++)
        printf("%s\n", arr[i]);
}

void loveLettersSort() {
    char loveLetters[10][100];
    int n;

    printf("Dearest, how many love letters do we have to sort? (Max 10): ");
    scanf("%d", &n);

    if (n > 10) {
        printf("Oh dear! We cannot handle more than 10 love letters.\n");
        return;
    }

    getchar(); // to consume leftover newline
    printf("Please, share your heartfelt letters:\n");

    for (int i = 0; i < n; i++) {
        printf("Enter love letter %d: ", i + 1);
        fgets(loveLetters[i], sizeof(loveLetters[i]), stdin);
        loveLetters[i][strcspn(loveLetters[i], "\n")] = 0; // remove newline
    }

    printf("\nBefore sorting:\n");
    printArray(loveLetters, n);

    printf("\nIn the embrace of love, let us sort these letters...\n");
    bubbleSort(loveLetters, n);

    printf("\nAfter sorting, our sweet love letters are:\n");
    printArray(loveLetters, n);
}

int main() {
    printf("Welcome, dear heart, to the Romance Sorting Program!\n");
    loveLettersSort();
    return 0;
}