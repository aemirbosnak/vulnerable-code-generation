//FormAI DATASET v1.0 Category: Database Indexing System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Structure definition for our database entries. */
struct Entry {
    int id;
    char name[50];
    char address[100];
    float salary;
};

/* Function to print a single entry in the database. */
void printEntry(struct Entry e) {
    printf("ID: %d\n", e.id);
    printf("Name: %s\n", e.name);
    printf("Address: %s\n", e.address);
    printf("Salary: %.2f\n", e.salary);
}

/* Struct for our index nodes. */
struct IndexNode {
    int id;
    int offset;
};

/* Struct for our index. */
struct Index {
    int num_entries;
    struct IndexNode *nodes;
};

/* Function to print an entire index. */
void printIndex(struct Index index) {
    printf("Index:\n");
    for (int i = 0; i < index.num_entries; i++) {
        printf("[%d]: %d\n", i, index.nodes[i].id);
    }
}

/* Function to read entries from a file and build a database and index from them. */
struct Index readFromFile(char *filename, struct Entry **db_ptr) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    /* First read in the number of entries. */
    int num_entries;
    fscanf(fp, "%d", &num_entries);

    /* Allocate space for the entries and our index nodes. */
    struct Entry *db = malloc(num_entries * sizeof(struct Entry));
    struct IndexNode *nodes = malloc(num_entries * sizeof(struct IndexNode));

    /* Read in each entry and populate the database and index. */
    for (int i = 0; i < num_entries; i++) {
        nodes[i].offset = ftell(fp);
        fscanf(fp, "%d", &db[i].id);
        fgets(db[i].name, 50, fp);
        db[i].name[strcspn(db[i].name, "\n")] = '\0'; /* Remove the newline character. */
        fgets(db[i].address, 100, fp);
        db[i].address[strcspn(db[i].address, "\n")] = '\0'; /* Remove the newline character. */
        fscanf(fp, "%f", &db[i].salary);
        nodes[i].id = db[i].id;
    }

    fclose(fp);

    /* Sort the index nodes using bubble sort. */
    for (int i = 0; i < num_entries - 1; i++) {
        for (int j = 0; j < num_entries - i - 1; j++) {
            if (nodes[j].id > nodes[j+1].id) {
                struct IndexNode temp = nodes[j];
                nodes[j] = nodes[j+1];
                nodes[j+1] = temp;
            }
        }
    }

    /* Populate our index struct and return it, along with the database. */
    struct Index index;
    index.num_entries = num_entries;
    index.nodes = nodes;
    *db_ptr = db;

    return index;
}

/* Function to search for an entry in the database given its ID. */
void searchDatabase(int id, struct Index index, struct Entry *db) {
    /* Binary search for the index node with the specified ID. */
    int left = 0, right = index.num_entries - 1, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (index.nodes[mid].id == id) {
            /* We've found the index node, seek to the corresponding entry in the file and print it. */
            fseek(stdin, index.nodes[mid].offset, SEEK_SET);
            struct Entry e;
            fscanf(stdin, "%d", &e.id);
            fgets(e.name, 50, stdin);
            fgets(e.address, 100, stdin);
            fscanf(stdin, "%f", &e.salary);
            printEntry(e);
            return;
        } else if (index.nodes[mid].id < id) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    printf("Error: entry with ID %d not found.\n", id);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    struct Entry *db;
    struct Index index = readFromFile(argv[1], &db);
    printf("Database:\n");
    for (int i = 0; i < index.num_entries; i++) {
        printEntry(db[i]);
        printf("\n");
    }
    printIndex(index);

    /* Example searches. */
    searchDatabase(3, index, db);
    searchDatabase(7, index, db);
    searchDatabase(12, index, db);

    free(db);
    free(index.nodes);

    printf("Finished.\n");
    return 0;
}