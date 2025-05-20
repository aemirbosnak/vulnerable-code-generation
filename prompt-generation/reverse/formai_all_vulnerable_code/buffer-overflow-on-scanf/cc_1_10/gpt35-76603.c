//FormAI DATASET v1.0 Category: Database Indexing System ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000000

struct Record {
    char name[50];
    char address[100];
    int age;
};

struct Index {
    char key[50];
    int offset;
};

int compare(const void *a, const void *b) {
    return strcmp(((struct Index*)a)->key, ((struct Index*)b)->key);
}

int main() {

    struct Record records[MAX_RECORDS];
    struct Index index[MAX_RECORDS];

    FILE *fp = fopen("records.dat", "rb");

    if (fp == NULL) {
        printf("Unable to open file records.dat\n");
        exit(EXIT_FAILURE);
    }

    int count = 0;
    int offset = 0;

    while (fread(&records[count], sizeof(struct Record), 1, fp)) {
        strcpy(index[count].key, records[count].name);
        index[count].offset = offset;
        count++;
        offset = ftell(fp);
    }

    fclose(fp);

    qsort(index, count, sizeof(struct Index), compare);

    // Binary search implementation
    char search_key[50];
    printf("Enter name to search: ");
    scanf("%s", search_key);

    int s = 0;
    int e = count - 1;
    int mid = 0;

    while (s <= e) {
        mid = (s + e) / 2;
        if (strcmp(search_key, index[mid].key) == 0) {
            printf("Name found at offset: %d\n", index[mid].offset);
            break;
        } else if (strcmp(search_key, index[mid].key) > 0) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }

    if (s > e) {
        printf("Name not found.\n");
    }

    return 0;
}