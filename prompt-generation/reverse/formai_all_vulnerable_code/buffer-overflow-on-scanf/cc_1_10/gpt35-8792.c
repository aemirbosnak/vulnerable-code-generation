//FormAI DATASET v1.0 Category: Database Indexing System ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student {
    char name[20];
    int roll;
    float marks;
};

struct index {
    int roll;
    int pos;
};

int main() {
    int n, i, j;
    FILE *fp, *fptr;
    struct student s;
    struct index idx[10], t;

    fp = fopen("students.dat", "wb");
    if (fp == NULL) {
        printf("Error opening file!!\n");
        exit(1);
    }

    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("Enter details of students -\n");
    for (i = 0; i < n; i++) {
        printf("Name: ");
        scanf("%s", s.name);
        printf("Roll: ");
        scanf("%d", &s.roll);
        printf("Marks: ");
        scanf("%f", &s.marks);

        fwrite(&s, sizeof(struct student), 1, fp);
        idx[i].roll = s.roll;
        idx[i].pos = i;
    }

    fclose(fp);

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (idx[i].roll > idx[j].roll) {
                t = idx[i];
                idx[i] = idx[j];
                idx[j] = t;
            }
        }
    }

    fptr = fopen("index.dat", "wb");
    if (fptr == NULL) {
        printf("Error opening file!!\n");
        exit(1);
    }

    fwrite(&idx, sizeof(struct index), n, fptr);
    fclose(fptr);
    printf("Index file created successfully!!\n");

    return 0;
}