//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 100
#define MAX_RECORD_SIZE 1000

typedef struct {
    char key[MAX_KEY_SIZE];
    int record_size;
    char record[MAX_RECORD_SIZE];
} DatabaseRecord;

int main() {
    DatabaseRecord database[100];
    int num_records = 0;
    char input_key[MAX_KEY_SIZE];
    char input_record[MAX_RECORD_SIZE];
    int input_record_size;
    int i;

    printf("Enter records (key, record):\n");

    while (1) {
        scanf("%s", input_key);
        scanf("%d", &input_record_size);
        scanf("%[^\n]", input_record);

        if (input_record_size > MAX_RECORD_SIZE) {
            printf("Record too large.\n");
            continue;
        }

        for (i = 0; i < num_records; i++) {
            if (strcmp(database[i].key, input_key) == 0) {
                printf("Record already exists.\n");
                break;
            }
        }

        if (i == num_records) {
            strcpy(database[num_records].key, input_key);
            strncpy(database[num_records].record, input_record, input_record_size);
            database[num_records].record_size = input_record_size;
            num_records++;
        }
    }

    printf("Enter search key:\n");
    scanf("%s", input_key);

    for (i = 0; i < num_records; i++) {
        if (strcmp(database[i].key, input_key) == 0) {
            printf("Record found:\n");
            printf("Key: %s\n", database[i].key);
            printf("Record:\n%s\n", database[i].record);
            break;
        }
    }

    return 0;
}