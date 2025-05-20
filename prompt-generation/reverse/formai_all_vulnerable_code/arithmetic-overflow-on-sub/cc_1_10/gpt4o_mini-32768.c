//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

#define MAX 100

// Function prototypes
void exchange(int *x, int *y);
void bubbleSort(char arr[][MAX], int n);
void printArray(char arr[][MAX], int n);

// A tale of two lovers, their hearts entwined like intertwined arrays
// Where sorting their passions would lead to fated matches

int main() {
    char arr[MAX][MAX];
    int n;

    printf("Enter the number of love letters (up to %d): ", MAX);
    scanf("%d", &n);
    getchar(); // to consume the newline

    // Collecting love letters worthy of Shakespeare
    printf("Enter the love letters:\n");
    for(int i = 0; i < n; i++) {
        fgets(arr[i], MAX, stdin);
        arr[i][strcspn(arr[i], "\n")] = 0; // Remove trailing newline
    }

    // Sorting the love letters based on their dear words
    bubbleSort(arr, n);

    // Once sorted, they would shine, like stars in the twilight sky
    printf("\nThe sorted love letters are:\n");
    printArray(arr, n);

    return 0;
}

// Beauty in simplicity, to exchange the strings of love
void exchange(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// To sort the love letters using a bubble, like fate's gentle touch
void bubbleSort(char arr[][MAX], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            // Comparing the hearts' verse, sorting by their lyrical grace
            if(strcmp(arr[j], arr[j + 1]) > 0) {
                // Lending a hand to the querulous letters
                char temp[MAX];
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }
}

// To present the hearts' confessions, unveiled for all to behold
void printArray(char arr[][MAX], int n) {
    for(int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }
}