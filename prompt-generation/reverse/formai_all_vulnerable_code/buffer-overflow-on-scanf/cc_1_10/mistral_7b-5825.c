//MISTRAL-7B DATASET v1.0 Category: Arithmetic ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_NUM 100
#define SIZEOF_NUM 10

int main() {
    int a[MAX_NUM];
    int i, j, temp;
    char filename[SIZEOF_NUM];

    printf("Enter %d numbers:\n", MAX_NUM);
    for (i = 0; i < MAX_NUM; i++) {
        scanf("%d", &a[i]);
    }

    printf("Before sorting:\n");
    for (i = 0; i < MAX_NUM; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    for (i = 0; i < MAX_NUM - 1; i++) {
        for (j = 0; j < MAX_NUM - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    printf("After sorting:\n");
    for (i = 0; i < MAX_NUM; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    sprintf(filename, "numbers.txt");
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd < 0) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    for (i = 0; i < MAX_NUM; i++) {
        if (write(fd, &a[i], sizeof(int)) < 0) {
            perror("Error writing to file");
            exit(EXIT_FAILURE);
        }
    }

    close(fd);

    printf("Numbers have been saved to %s file.\n", filename);

    return 0;
}