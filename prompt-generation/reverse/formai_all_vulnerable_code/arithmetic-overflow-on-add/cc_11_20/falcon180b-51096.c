//Falcon-180B DATASET v1.0 Category: File handling ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000000

typedef struct {
    int num;
    int count;
} num_count;

int main() {
    FILE *fp;
    int i, j, num, count = 0;
    num_count arr[MAX_SIZE];
    char filename[20];
    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);
    sprintf(filename, "stats_%d%02d%02d%02d%02d%02d.txt", tm_now->tm_year + 1900, tm_now->tm_mon + 1, tm_now->tm_mday, tm_now->tm_hour, tm_now->tm_min, tm_now->tm_sec);
    fp = fopen(filename, "w");

    if (fp == NULL) {
        printf("Error: could not create file.\n");
        exit(1);
    }

    for (i = 0; i < MAX_SIZE; i++) {
        arr[i].num = -1;
        arr[i].count = 0;
    }

    srand(time(NULL));
    for (i = 0; i < 100000; i++) {
        num = rand() % 1000;
        for (j = 0; j < MAX_SIZE; j++) {
            if (arr[j].num == num) {
                arr[j].count++;
                break;
            }
        }
        if (j == MAX_SIZE) {
            for (j = 0; j < MAX_SIZE; j++) {
                if (arr[j].num == -1) {
                    arr[j].num = num;
                    arr[j].count = 1;
                    break;
                }
            }
        }
    }

    fprintf(fp, "Number\tCount\n");
    for (i = 0; i < MAX_SIZE; i++) {
        if (arr[i].num!= -1) {
            fprintf(fp, "%d\t%d\n", arr[i].num, arr[i].count);
        }
    }

    fclose(fp);

    return 0;
}