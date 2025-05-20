//FormAI DATASET v1.0 Category: Data recovery tool ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int index;
    char data[100];
} Entry;

void writeData(FILE *fp) {
    Entry entry;
    printf("Enter index: ");
    scanf("%d", &entry.index);
    printf("Enter data: ");
    scanf("%s", entry.data);
    fseek(fp, entry.index * sizeof(Entry), SEEK_SET);
    fwrite(&entry, sizeof(Entry), 1, fp);
}

void readData(FILE *fp) {
    int index;
    Entry entry;
    printf("Enter index: ");
    scanf("%d", &index);
    fseek(fp, index * sizeof(Entry), SEEK_SET);
    fread(&entry, sizeof(Entry), 1, fp);
    printf("Index: %d, Data: %s\n", entry.index, entry.data);
}

void removeData(FILE *fp) {
    int index;
    printf("Enter index: ");
    scanf("%d", &index);
    fseek(fp, index * sizeof(Entry), SEEK_SET);
    Entry entry = {0, ""};
    fwrite(&entry, sizeof(Entry), 1, fp);
}

int main() {
    FILE *fp = fopen("data.bin", "rb+");
    if (fp == NULL) {
        fp = fopen("data.bin", "wb+");
        Entry entry = {0, ""};
        for (int i = 0; i < 100; i++) {
            fwrite(&entry, sizeof(Entry), 1, fp);
        }
    }

    int choice;
    do {
        printf("\nChoose an option:\n");
        printf("1. Write data\n");
        printf("2. Read data\n");
        printf("3. Remove data\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                writeData(fp);
                break;
            case 2:
                readData(fp);
                break;
            case 3:
                removeData(fp);
                break;
            case 4:
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
    } while (choice != 4);

    fclose(fp);

    return 0;
}