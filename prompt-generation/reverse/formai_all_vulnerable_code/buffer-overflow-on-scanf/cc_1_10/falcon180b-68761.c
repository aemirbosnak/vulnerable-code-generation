//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_LEN 255
#define MAX_DATA_LEN 1024
#define MAX_INDEXES 10

typedef struct {
    char key[MAX_KEY_LEN];
    char data[MAX_DATA_LEN];
} Record;

typedef struct {
    char name[MAX_KEY_LEN];
    int (*compare)(const char *key1, const char *key2);
} Index;

int str_compare(const char *key1, const char *key2) {
    return strcmp(key1, key2);
}

int main() {
    Record records[MAX_INDEXES];
    Index indexes[MAX_INDEXES];
    int num_records = 0;
    int num_indexes = 0;

    int choice;
    while(1) {
        printf("1. Add Record\n2. Add Index\n3. Search\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(num_records >= MAX_INDEXES) {
                    printf("Maximum number of records reached.\n");
                    break;
                }
                printf("Enter key: ");
                scanf("%s", records[num_records].key);
                printf("Enter data: ");
                scanf("%s", records[num_records].data);
                num_records++;
                break;
            case 2:
                if(num_indexes >= MAX_INDEXES) {
                    printf("Maximum number of indexes reached.\n");
                    break;
                }
                printf("Enter index name: ");
                scanf("%s", indexes[num_indexes].name);
                indexes[num_indexes].compare = str_compare;
                num_indexes++;
                break;
            case 3:
                printf("Enter search key: ");
                scanf("%s", indexes[0].name);
                for(int i=0; i<num_records; i++) {
                    if(indexes[0].compare(records[i].key, indexes[0].name) == 0) {
                        printf("Record found:\nKey: %s\nData: %s\n", records[i].key, records[i].data);
                    }
                }
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}