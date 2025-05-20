//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n, i, j, k, l, m, count = 0, flag = 0;
    int arr[100][100];
    int sum = 0;
    int prod = 1;
    int min = 1000, max = -1000;
    int avg;
    char ch;
    FILE *fp;
    struct tm *tm;
    time_t now;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    srand(time(0));

    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            arr[i][j] = rand()%100;
        }
    }

    printf("\nEnter the element to be searched: ");
    scanf("%d", &ch);

    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(arr[i][j] == ch) {
                count++;
                flag = 1;
                break;
            }
        }
    }

    if(flag == 0) {
        printf("\nElement not found in the array!");
    } else {
        printf("\nElement found %d times in the array!", count);
    }

    printf("\nDo you want to save the array in a file? (y/n): ");
    scanf(" %c", &ch);

    if(ch == 'y' || ch == 'Y') {
        fp = fopen("array.txt", "w");

        if(fp == NULL) {
            printf("\nError in creating file!");
        } else {
            for(i=0; i<n; i++) {
                for(j=0; j<n; j++) {
                    fprintf(fp, "%d ", arr[i][j]);
                }
                fprintf(fp, "\n");
            }

            fclose(fp);
            printf("\nArray saved in file successfully!");
        }
    }

    return 0;
}