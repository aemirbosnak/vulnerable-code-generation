//FormAI DATASET v1.0 Category: Database querying ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 20
#define MAX_RECORDS 100

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    int age;
    char gender;
} Record;

int main() {

    FILE *file_ptr;
    Record records[MAX_RECORDS];
    char user_name[MAX_NAME_LEN];

    // Open the database file
    file_ptr = fopen("database.dat", "rb");
    if (file_ptr == NULL) {
        printf("Error: Unable to open database file");
        return -1;
    }

    // Read all records from the database file into memory
    int num_records = 0;
    while (fread(&records[num_records], sizeof(Record), 1, file_ptr) == 1) {
        num_records++;
    }

    // Prompt the user for a name to search for
    printf("Enter name to query: ");
    scanf("%s", user_name);

    // Search for records with matching name
    int match_count = 0;
    for (int i = 0; i < num_records; i++) {
        if (strcmp(records[i].name, user_name) == 0) {
            match_count++;
            printf("Record #%d:\n", i+1);
            printf("\tID: %d\n", records[i].id);
            printf("\tName: %s\n", records[i].name);
            printf("\tAge: %d\n", records[i].age);
            printf("\tGender: %c\n", records[i].gender);
        }
    }

    // Display number of matches found
    if (match_count == 0) {
        printf("No matches found.\n");
    } else {
        printf("%d matches found.\n", match_count);
    }

    // Close the database file
    fclose(file_ptr);

    return 0;
}