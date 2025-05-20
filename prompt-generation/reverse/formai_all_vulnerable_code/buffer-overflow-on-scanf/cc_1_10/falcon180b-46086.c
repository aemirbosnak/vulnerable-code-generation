//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA_SIZE 100
#define MAX_INDEX_SIZE 26
#define MAX_KEY_SIZE 10

typedef struct {
    char data[MAX_DATA_SIZE];
    char index[MAX_INDEX_SIZE];
} Record;

void create_index(Record records[], int num_records) {
    int i, j;
    char key[MAX_KEY_SIZE];
    for (i = 0; i < num_records; i++) {
        strcpy(key, records[i].index);
        for (j = 0; j < strlen(key); j++) {
            key[j] = tolower(key[j]);
        }
        int index = key[0] - 'a';
        records[i].index[0] = index + 'a';
        records[i].index[1] = '\0';
    }
}

void search_index(Record records[], int num_records, char search_key[]) {
    int i, j;
    char key[MAX_KEY_SIZE];
    for (i = 0; i < num_records; i++) {
        strcpy(key, records[i].index);
        for (j = 0; j < strlen(key); j++) {
            key[j] = tolower(key[j]);
        }
        if (strcmp(key, search_key) == 0) {
            printf("Record found: %s\n", records[i].data);
        }
    }
}

int main() {
    Record records[10];
    int num_records = 0;
    char choice;
    do {
        printf("\n\nWelcome to the Romantic C Database Indexing System!\n");
        printf("Please choose an option:\n");
        printf("1. Add a record\n");
        printf("2. Search for a record\n");
        printf("3. Exit\n");
        scanf("%c", &choice);
        switch (choice) {
            case '1':
                if (num_records >= 10) {
                    printf("Sorry, the database is full.\n");
                } else {
                    printf("Enter the record:\n");
                    scanf("%s", records[num_records].data);
                    strcpy(records[num_records].index, "");
                    num_records++;
                }
                break;
            case '2':
                printf("Enter the search key:\n");
                scanf("%s", records[0].index);
                create_index(records, num_records);
                search_index(records, num_records, records[0].index);
                break;
            case '3':
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= '3');
    return 0;
}