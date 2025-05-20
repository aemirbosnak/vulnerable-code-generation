//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct record {
    char name[50];
    int id;
};

// Function to compare two records by ID
int compare_records(const void *a, const void *b) {
    struct record *r1 = (struct record *) a;
    struct record *r2 = (struct record *) b;
    return r1->id - r2->id;
}

int main() {
    struct record database[100];
    int num_records = 0;

    // Romeo enters a record into the database
    printf("Oh sweet database, let me add my record:\n");
    printf("Enter name: ");
    scanf("%s", database[num_records].name);
    printf("Enter ID: ");
    scanf("%d", &database[num_records].id);
    num_records++;

    // Juliet enters a record into the database
    printf("Ah, beloved database, I'll add a record too:\n");
    printf("Enter name: ");
    scanf("%s", database[num_records].name);
    printf("Enter ID: ");
    scanf("%d", &database[num_records].id);
    num_records++;

    // Romeo and Juliet sort the database by ID
    printf("Oh dear database, let us sort you out:\n");
    qsort(database, num_records, sizeof(struct record), compare_records);

    // Romeo and Juliet search the database for a record
    printf("Database of my heart, please tell me,\n");
    printf("Do you contain a record with ID of: ");
    int search_id;
    scanf("%d", &search_id);
    struct record *result = bsearch(&search_id, database, num_records, sizeof(struct record), compare_records);
    if (result != NULL) {
        printf("Yes, dear database, it contains: %s, %d\n", result->name, result->id);
    } else {
        printf("Alas, database, it does not contain such a record!\n");
    }
    
    // Juliet deletes a record from the database
    printf("Oh, fair database, I must remove a record:\n");
    printf("Enter the ID of the record to be removed: ");
    int delete_id;
    scanf("%d", &delete_id);
    for (int i = 0; i < num_records; i++) {
        if (database[i].id == delete_id) {
            // Shift all subsequent records back 1 position
            for (int j = i; j < num_records - 1; j++) {
                database[j] = database[j+1];
            }
            num_records--;
            printf("Hark, fair database, the record has been removed!\n");
            break;
        }
    }

    return 0;
}