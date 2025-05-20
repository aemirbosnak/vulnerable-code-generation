//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct record {
    int id;
    char name[20];
    int age;
    float score;
};

struct index {
    int id;
    long offset;
};

void create_db(FILE *fp) {
    struct record r1 = { 1, "John", 25, 80.5 };
    struct record r2 = { 2, "Mary", 30, 90.3 };
    struct record r3 = { 3, "Bob", 20, 75.4 };
    fwrite(&r1, sizeof(struct record), 1, fp);
    fwrite(&r2, sizeof(struct record), 1, fp);
    fwrite(&r3, sizeof(struct record), 1, fp);
}

void create_index(FILE *fp, FILE *ip) {
    struct index idx;
    struct record rec;
    int i = 0;
    while (fread(&rec, sizeof(struct record), 1, fp)) {
        idx.id = rec.id;
        idx.offset = sizeof(struct record) * i++;
        fwrite(&idx, sizeof(struct index), 1, ip);
    }
}

void search_db(FILE *fp, FILE *ip, int id) {
    struct index idx;
    struct record rec;
    int found = 0;
    rewind(ip);
    while (fread(&idx, sizeof(struct index), 1, ip)) {
        if (idx.id == id) {
            found = 1;
            fseek(fp, idx.offset, SEEK_SET);
            fread(&rec, sizeof(struct record), 1, fp);
            printf("ID: %d, Name: %s, Age: %d, Score: %.2f\n", rec.id, rec.name, rec.age, rec.score);
            break;
        }
    }
    if (!found) printf("Record with ID %d not found!\n", id);
}

int main() {
    FILE *data_file = fopen("data.bin", "wb+");
    if (data_file == NULL) {
        perror("Could not open data file");
        exit(EXIT_FAILURE);
    }
    create_db(data_file);
    fclose(data_file);

    FILE *index_file = fopen("index.bin", "wb+");
    if (index_file == NULL) {
        perror("Could not open index file");
        exit(EXIT_FAILURE);
    }
    create_index(data_file, index_file);
    fclose(index_file);

    int search_id;
    printf("Enter ID to search: ");
    scanf("%d", &search_id);

    data_file = fopen("data.bin", "rb");
    index_file = fopen("index.bin", "rb");

    if (data_file == NULL || index_file == NULL) {
        perror("Could not open data or index file for reading");
        exit(EXIT_FAILURE);
    }
    search_db(data_file, index_file, search_id);

    fclose(data_file);
    fclose(index_file);

    return EXIT_SUCCESS;
}