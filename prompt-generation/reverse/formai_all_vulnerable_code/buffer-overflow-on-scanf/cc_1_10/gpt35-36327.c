//FormAI DATASET v1.0 Category: Database Indexing System ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_RECORDS 1000

struct Record {
    int id;
    char name[50];
    char email[50];
    char phone[20];
};

struct Index {
    int id;
    int offset;
};

void write_record(FILE *fp, struct Record *record);
void read_record(FILE *fp, struct Record *record);
void write_index(FILE *fp, struct Index *index);
void read_index(FILE *fp, struct Index *index);
void print_record(struct Record *record);
void print_index(struct Index *index);
void print_records(FILE *fp);
void print_indexes(FILE *fp);
void search_by_id(int id, FILE *fp);

int main() {
    FILE *data_file = fopen("data.dat", "w+b");
    FILE *index_file = fopen("index.dat", "w+b");
    struct Record records[MAX_RECORDS];
    int num_records = 0;
    int i, j;
    struct Index index;
    int unique = 1;
    int offset;

    printf("Welcome to the Unique Database Indexing System!\n");

    // Ask the user to enter records until they are done
    do {
        printf("Enter record #%d:\n", num_records + 1);
        fflush(stdin);
        printf("ID: ");
        scanf("%d", &records[num_records].id);
        // Check if ID is already in use
        rewind(index_file);
        while (fread(&index, sizeof(struct Index), 1, index_file)) {
            if (index.id == records[num_records].id) {
                printf("That ID is already in use!\n");
                unique = 0;
                break;
            }
        }
        if (unique) {
            printf("Name: ");
            scanf("%s", records[num_records].name);
            printf("Email: ");
            scanf("%s", records[num_records].email);
            printf("Phone: ");
            scanf("%s", records[num_records].phone);
            write_record(data_file, &records[num_records]);
            // Create an index for the new record
            index.id = records[num_records].id;
            index.offset = ftell(data_file) - sizeof(struct Record);
            write_index(index_file, &index);
            num_records++;
        }
        unique = 1; // Reset flag for next loop
    } while (num_records < MAX_RECORDS && getchar() != 'q');

    // Print the records and indexes
    printf("All records:\n");
    print_records(data_file);
    printf("All indexes:\n");
    print_indexes(index_file);

    // Search for a record by ID
    printf("Enter an ID to search for (0 to quit): ");
    scanf("%d", &i);
    while (i != 0) {
        search_by_id(i, data_file);
        printf("Enter another ID to search for (0 to quit): ");
        scanf("%d", &i);
    }

    // Clean up and exit
    fclose(data_file);
    fclose(index_file);
    return 0;
}

void write_record(FILE *fp, struct Record *record) {
    fwrite(record, sizeof(struct Record), 1, fp);
}

void read_record(FILE *fp, struct Record *record) {
    fread(record, sizeof(struct Record), 1, fp);
}

void write_index(FILE *fp, struct Index *index) {
    fwrite(index, sizeof(struct Index), 1, fp);
}

void read_index(FILE *fp, struct Index *index) {
    fread(index, sizeof(struct Index), 1, fp);
}

void print_record(struct Record *record) {
    printf("%d\t%s\t%s\t%s\n", record->id, record->name, record->email, record->phone);
}

void print_index(struct Index *index) {
    printf("%d\t%d\n", index->id, index->offset);
}

void print_records(FILE *fp) {
    struct Record record;
    rewind(fp);
    while (fread(&record, sizeof(struct Record), 1, fp)) {
        print_record(&record);
    }
}

void print_indexes(FILE *fp) {
    struct Index index;
    rewind(fp);
    while (fread(&index, sizeof(struct Index), 1, fp)) {
        print_index(&index);
    }
}

void search_by_id(int id, FILE *fp) {
    struct Index index;
    struct Record record;
    rewind(fp);
    // Look up the index for the ID
    while (fread(&index, sizeof(struct Index), 1, fp)) {
        if (index.id == id) {
            // Read the corresponding record
            fseek(fp, index.offset, SEEK_SET);
            read_record(fp, &record);
            // Print the record
            printf("Record found!\n");
            print_record(&record);
            return;
        }
    }
    // ID not found
    printf("Record not found.\n");
}