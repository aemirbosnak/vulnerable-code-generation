//Falcon-180B DATASET v1.0 Category: File handling ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 100

typedef struct {
    char name[MAX_SIZE];
    int roll_no;
    float marks;
} student;

int main() {
    FILE *fp;
    student s;
    int choice;
    char filename[50];

    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File not found\n");
        exit(1);
    }

    printf("1. Read file\n2. Write to file\n3. Append to file\n4. Exit\n");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            while(fscanf(fp, "%s %d %f", s.name, &s.roll_no, &s.marks)!= EOF) {
                printf("%s %d %f\n", s.name, s.roll_no, s.marks);
            }
            break;
        case 2:
            printf("Enter data to write: ");
            scanf("%s %d %f", s.name, &s.roll_no, &s.marks);
            fprintf(fp, "%s %d %f\n", s.name, s.roll_no, s.marks);
            break;
        case 3:
            printf("Enter data to append: ");
            scanf("%s %d %f", s.name, &s.roll_no, &s.marks);
            fprintf(fp, "%s %d %f\n", s.name, s.roll_no, s.marks);
            break;
        case 4:
            fclose(fp);
            exit(0);
        default:
            printf("Invalid choice\n");
    }

    return 0;
}