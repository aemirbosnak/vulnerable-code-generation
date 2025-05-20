//FormAI DATASET v1.0 Category: System boot optimizer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void delay(int);

int main()
{
    int i, j, temp, n;
    float time_taken;
    clock_t start, end;

    printf("\n--------System Boot Optimizer--------\n");
    printf("Enter the number of files to remove: ");
    scanf("%d", &n);

    int *files = (int*) malloc(n * sizeof(int));
    if (files == NULL) {
        printf("Memory allocation failed!");
        exit(1);
    }

    for (i = 0; i < n; i++) {
        printf("Enter file size in KB to remove: ");
        scanf("%d", &files[i]);
    }

    start = clock(); // start the clock

    // bubble sort
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (files[j] > files[j+1]) {
                temp = files[j];
                files[j] = files[j+1];
                files[j+1] = temp;
            }
        }
    }

    printf("\nRemoving files of sizes: ");
    for (i = 0; i < n; i++) {
        printf("%d KB ", files[i]);
        delay(1000);
    }

    free(files);

    end = clock(); // end the clock
    time_taken = ((float) end - start) / CLOCKS_PER_SEC;

    printf("\n\nTime taken to optimize: %.2f seconds", time_taken);

    return 0;
}

void delay(int milliseconds)
{
    clock_t start_time = clock();
    while (clock() < start_time + milliseconds);
}