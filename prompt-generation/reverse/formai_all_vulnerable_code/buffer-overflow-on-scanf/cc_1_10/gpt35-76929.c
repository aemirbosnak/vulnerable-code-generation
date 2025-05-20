//FormAI DATASET v1.0 Category: Database Indexing System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

struct record {
    int key;
    char data[MAX];
};

struct index {
    int key;
    int offset;
    int valid;
};

struct index index_array[MAX];

int num_records = 0;

void add_record() {
    struct record rec;
    printf("\nEnter key and data: ");
    scanf("%d %s", &rec.key, rec.data);
    FILE *fp = fopen("data.dat", "ab");
    long int offset = ftell(fp);
    fwrite(&rec, sizeof(struct record), 1, fp);
    fclose(fp);
    index_array[num_records].key = rec.key;
    index_array[num_records].offset = offset;
    index_array[num_records].valid = 1;
    num_records++;
}

void delete_record() {
    int key, i, j;
    printf("\nEnter key of record to delete: ");
    scanf("%d", &key);
    for (i = 0; i < num_records; i++) {
        if (index_array[i].key == key && index_array[i].valid) {
            index_array[i].valid = 0;
            for (j = i; j < num_records - 1; j++) {
                index_array[j] = index_array[j + 1];
            }
            num_records--;
            return;
        }
    }
    printf("\nRecord not found!\n");
}

void search_record() {
    int key, i;
    FILE *fp = fopen("data.dat", "rb");
    printf("\nEnter key of record to search: ");
    scanf("%d", &key);
    for (i = 0; i < num_records; i++) {
        if (index_array[i].key == key && index_array[i].valid) {
            struct record rec;
            fseek(fp, index_array[i].offset, SEEK_SET);
            fread(&rec, sizeof(struct record), 1, fp);
            printf("\n%s\n", rec.data);
            fclose(fp);
            return;
        }
    }
    printf("\nRecord not found!\n");
    fclose(fp);
}

void display_records() {
    int i;
    FILE *fp = fopen("data.dat", "rb");
    for (i = 0; i < num_records; i++) {
        if (index_array[i].valid) {
            struct record rec;
            fseek(fp, index_array[i].offset, SEEK_SET);
            fread(&rec, sizeof(struct record), 1, fp);
            printf("%d %s\n", rec.key, rec.data);
        }
    }
    fclose(fp);
}

int menu() {
    int choice;
    printf("\n1. Add record\n");
    printf("2. Delete record\n");
    printf("3. Search record\n");
    printf("4. Display records\n");
    printf("5. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    int choice;
    while ((choice = menu()) != 5) {
        switch (choice) {
            case 1:
                add_record();
                break;
            case 2:
                delete_record();
                break;
            case 3:
                search_record();
                break;
            case 4:
                display_records();
                break;
            default:
                printf("\nInvalid choice!\n");
                break;
        }
    }
    return 0;
}