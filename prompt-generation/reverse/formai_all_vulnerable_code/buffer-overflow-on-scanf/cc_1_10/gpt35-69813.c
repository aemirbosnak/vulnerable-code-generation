//FormAI DATASET v1.0 Category: Database Indexing System ; Style: calm
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Record {
    char name[50];
    int age;
    long int ID_number;
};

struct Index {
    long int ID_number;
    int pointer;
};

void sort(struct Index index[], int n) {
    int i, j;
    struct Index temp;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (index[i].ID_number > index[j].ID_number) {
                temp = index[i];
                index[i] = index[j];
                index[j] = temp;
            }
        }
    }
}

int main() {
    FILE *fp;
    int i, n = 3;
    struct Record record[n];
    struct Index index[n];
    fp = fopen("index.dat", "wb");
    if(fp==NULL) {
        puts("Unable to create file");
        exit(1);
    }
    for (i = 0; i < n; i++) {
        printf("Record %d:\n", i + 1);
        printf("Enter name: ");
        scanf("%s", record[i].name);
        printf("Enter age: ");
        scanf("%d", &record[i].age);
        printf("Enter ID number: ");
        scanf("%ld", &record[i].ID_number);
        index[i].ID_number = record[i].ID_number;
        index[i].pointer = i;
    }
    sort(index, n);
    fwrite(&index, sizeof(struct Index), n, fp);
    fclose(fp);
    fp = fopen("index.dat", "rb");
    if(fp==NULL) {
        puts("Unable to open file");
        exit(1);
    }
    printf("\nIndex\tName\t\tAge\tID Number\n");
    printf("-------------------------------------------\n");
    for (i = 0; i < n; i++) {
        fseek(fp, index[i].pointer * sizeof(struct Record), SEEK_SET);
        fread(&record[i], sizeof(struct Record), 1, fp);
        printf("%ld\t%-16s%d\t%ld\n", index[i].ID_number, record[i].name, record[i].age, record[i].ID_number);
    }
    fclose(fp);
    return 0;
}