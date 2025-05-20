//Falcon-180B DATASET v1.0 Category: Data mining ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

typedef struct {
    int id;
    char name[50];
    int age;
    char gender[10];
    float income;
} Record;

Record dataset[MAX_ROWS];
int num_rows = 0;
int num_cols = 4;

void load_data() {
    FILE *fp;
    fp = fopen("data.csv", "r");

    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        exit(1);
    }

    fscanf(fp, "%d,%s,%d,%s,%f\n", &dataset[0].id, dataset[0].name, &dataset[0].age, dataset[0].gender, &dataset[0].income);

    while (fscanf(fp, "%d,%s,%d,%s,%f\n", &dataset[num_rows].id, dataset[num_rows].name, &dataset[num_rows].age, dataset[num_rows].gender, &dataset[num_rows].income)!= EOF) {
        num_rows++;
    }

    fclose(fp);
}

void display_data() {
    int i, j;

    for (i = 0; i < num_rows; i++) {
        for (j = 0; j < num_cols; j++) {
            printf("%d ", dataset[i].id);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    load_data();
    display_data();

    return 0;
}