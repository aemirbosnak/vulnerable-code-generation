//FormAI DATASET v1.0 Category: Database Indexing System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int key;
    char name[30];
    float score;
} Student;

typedef struct {
    int key;
    long offset;
} Index;

int main() {
    FILE *fp = fopen("students.dat", "rb");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    int n = 0;
    Student s;
    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        n++;
    }
    printf("Number of students: %d\n", n);

    Index *index = malloc(n * sizeof(Index));

    rewind(fp);
    n = 0;
    while (fread(&s, sizeof(Student), 1, fp) == 1) {
        index[n].key = s.key;
        index[n].offset = ftell(fp) - sizeof(Student);
        n++;
    }

    fclose(fp);

    // sort index by key using bubble sort
    for (int i = 0; i < n; i++) {
        for (int j = n-1; j > i; j--) {
            if (index[j].key < index[j-1].key) {
                // swap
                Index temp = index[j];
                index[j] = index[j-1];
                index[j-1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("Key: %d, Offset: %ld\n", index[i].key, index[i].offset);
    }

    // search for a student by key
    int key;
    printf("Enter key to search for: ");
    scanf("%d", &key);

    int lo = 0, hi = n-1, mid;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (index[mid].key == key) {
            break;
        } else if (index[mid].key < key) {
            lo = mid+1;
        } else {
            hi = mid-1;
        }
    }

    if (lo <= hi) {
        fp = fopen("students.dat", "rb");
        fseek(fp, index[mid].offset, SEEK_SET);
        fread(&s, sizeof(Student), 1, fp);
        fclose(fp);
        printf("Name: %s, Score: %.2f\n", s.name, s.score);
    } else {
        printf("Student not found.\n");
    }

    free(index);
    return 0;
}