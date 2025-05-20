//FormAI DATASET v1.0 Category: File handling ; Style: random
#include <stdio.h>
#include <stdlib.h>

int main() {
    // create file pointer and open file for writing
    FILE *file;
    file = fopen("data.txt", "w");

    // check if file is successfully opened
    if (file == NULL) {
        printf("Unable to open file\n");
        exit(1);
    }

    // ask user for input data
    int n;
    printf("How many numbers do you want to write into the file?\n");
    scanf("%d", &n);

    // write integers into file
    printf("Enter %d integers separated by spaces:\n", n);
    int i, num;
    for (i = 0; i < n; i++) {
        scanf("%d", &num);
        fprintf(file, "%d ", num);
    }

    // close file
    fclose(file);

    // open file for reading
    file = fopen("data.txt", "r");

    // check if file is successfully opened
    if (file == NULL) {
        printf("Unable to open file\n");
        exit(1);
    }

    // read integers from file and find their sum
    int sum = 0;
    while (!feof(file)) {
        fscanf(file, "%d", &num);
        sum += num;
    }

    // close file
    fclose(file);

    // print sum of integers
    printf("Sum of %d integers in file is %d\n", n, sum);

    return 0;
}