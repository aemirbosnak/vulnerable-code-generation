//FormAI DATASET v1.0 Category: Database Indexing System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000
#define MAX_NAME_LEN 50
#define MAX_EMAIL_LEN 100

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    char email[MAX_EMAIL_LEN];
} Record;

typedef struct {
    int key;
    int record_id;
} Index;

int compare_index(const void *a, const void *b) {
    return ((Index*)a)->key - ((Index*)b)->key;
}

int main() {
    Record records[MAX_RECORDS];
    Index index[MAX_RECORDS];
    int num_records = 0;
    
    // read records from input file
    FILE *input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }
    while (fscanf(input_file, "%d %s %s", &records[num_records].id, records[num_records].name, records[num_records].email) == 3) {
        index[num_records].key = records[num_records].id;
        index[num_records].record_id = num_records;
        num_records++;
    }
    fclose(input_file);
    
    // sort index
    qsort(index, num_records, sizeof(Index), compare_index);
    
    // search for records
    int search_id;
    printf("Enter an id to search for: ");
    scanf("%d", &search_id);
    int low = 0, high = num_records-1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (index[mid].key == search_id) {
            printf("Record found:\n");
            printf("id: %d\n", records[index[mid].record_id].id);
            printf("name: %s\n", records[index[mid].record_id].name);
            printf("email: %s\n", records[index[mid].record_id].email);
            return 0;
        } else if (index[mid].key < search_id) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("Record not found.\n");
    return 0;
}