//FormAI DATASET v1.0 Category: Database Indexing System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* structure for the student record */
struct student {
    int roll;
    char name[20];
    int marks;
};

/* structure for the index record */
struct index {
    int roll;
    int pos;
};

/* function to generate the index record */
void generateIndex(FILE *fdata, FILE *findex) {
    int count = 0;
    long int offset = 0;
    struct student s;
    struct index i;
    fread(&s, sizeof(struct student), 1, fdata);
    while (!feof(fdata)) {
        i.roll = s.roll;
        i.pos = offset;
        fwrite(&i, sizeof(struct index), 1, findex);
        offset = ftell(fdata);
        fread(&s, sizeof(struct student), 1, fdata);
        count++;
    }
    printf("Generated Index for %d Records\n", count);
}

/* function to search for a record using index */
void searchRecord(FILE *fdata, FILE *findex) {
    int count = 0;
    int roll;
    struct student s;
    struct index i;
    printf("Enter Roll Number : ");
    scanf("%d", &roll);
    fseek(findex, 0, SEEK_SET);
    fread(&i, sizeof(struct index), 1, findex);
    while (!feof(findex)) {
        if (i.roll == roll) {
            fseek(fdata, i.pos, SEEK_SET);
            fread(&s, sizeof(struct student), 1, fdata);
            printf("Roll Number : %d\n", s.roll);
            printf("Name : %s\n", s.name);
            printf("Marks : %d\n", s.marks);
            count++;
        }
        fread(&i, sizeof(struct index), 1, findex);
    }
    if (count == 0) {
        printf("Record not found\n");
    }
}

int main() {
    FILE *fdata;
    FILE *findex;
    int choice;
    fdata = fopen("student.dat", "rb");
    if (fdata == NULL) {
        printf("Error : Could not Open File\n");
        return 1;
    }
    findex = fopen("student.idx", "wb");
    if (findex == NULL) {
        printf("Error : Could not Open File\n");
        fclose(fdata);
        return 1;
    }
    generateIndex(fdata, findex);
    fclose(fdata);
    fclose(findex);
    findex = fopen("student.idx", "rb");
    if (findex == NULL) {
        printf("Error : Could not Open File\n");
        return 1;
    }
    do {
        printf("\n");
        printf("1. Search\n");
        printf("2. Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                fdata = fopen("student.dat", "rb");
                if (fdata == NULL) {
                    printf("Error : Could not Open File\n");
                    return 1;
                }
                searchRecord(fdata, findex);
                fclose(fdata);
                break;
            case 2:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid Choice\n");
                break;
        }
    } while (choice != 2);
    fclose(findex);
    return 0;
}