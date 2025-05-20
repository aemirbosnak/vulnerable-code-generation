//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50
#define MAX_AGE 120

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} Person;

int main() {
    FILE *dbFile;
    Person db[MAX_ENTRIES];
    int numEntries = 0;

    // Open the database file
    dbFile = fopen("database.txt", "r");
    if (dbFile == NULL) {
        printf("Error opening database file.\n");
        return 1;
    }

    // Read in the database entries
    while (fscanf(dbFile, "%s %d\n", db[numEntries].name, &db[numEntries].age)!= EOF) {
        numEntries++;
    }
    fclose(dbFile);

    // Sort the database by age
    for (int i = 0; i < numEntries - 1; i++) {
        for (int j = i + 1; j < numEntries; j++) {
            if (db[i].age > db[j].age) {
                Person temp = db[i];
                db[i] = db[j];
                db[j] = temp;
            }
        }
    }

    // Print the sorted database
    printf("Sorted database:\n");
    for (int i = 0; i < numEntries; i++) {
        printf("%s %d\n", db[i].name, db[i].age);
    }

    // Close the database file
    fclose(dbFile);

    return 0;
}