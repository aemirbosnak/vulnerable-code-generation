//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_SIZE 100
#define FILE_NAME "numbers.txt"

int main() {
    int i, j, temp;
    int array[MAX_SIZE];
    FILE *fp;

    printf("\n\t*****************************************\n");
    printf("\t* Welcome to the Retro Sorting Program!   *\n");
    printf("\t* This program sorts numbers from a file  *\n");
    printf("\t* using bubble sort algorithm.           *\n");
    printf("\t*****************************************\n\n");

    // Open the file and read numbers into array
    fp = fopen(FILE_NAME, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < MAX_SIZE && fscanf(fp, "%d", &array[i]) != EOF; i++);
    fclose(fp);

    // Bubble sort algorithm
    for (i = 0; i < MAX_SIZE - 1; i++) {
        for (j = 0; j < MAX_SIZE - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }

    // Print sorted numbers
    printf("\n\tSorted numbers:\n");
    for (i = 0; i < MAX_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}