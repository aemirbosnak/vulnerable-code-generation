//MISTRAL-7B DATASET v1.0 Category: Sorting ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAX_LINE_LENGTH 1024
#define ARRAY_SIZE 10

void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[ARRAY_SIZE] = {0};
    int fd;
    char filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    fd = open(filename, O_RDONLY);

    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    int i = 0;
    while (fgets(line, MAX_LINE_LENGTH, fd) != NULL) {
        sscanf(line, "%d", &arr[i]);
        i++;
    }

    close(fd);

    printf("Unsorted array:\n");
    print_array(arr, i);

    for (int j = 0; j < i; j++) {
        for (int k = 0; k < i - 1; k++) {
            if (arr[k] > arr[k + 1]) {
                int temp = arr[k];
                arr[k] = arr[k + 1];
                arr[k + 1] = temp;
            }
        }
    }

    printf("Sorted array:\n");
    print_array(arr, i);

    return 0;
}