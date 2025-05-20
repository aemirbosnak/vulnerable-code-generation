//FormAI DATASET v1.0 Category: Database Indexing System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

struct Person {
    char name[30];
    int age;
    long id;
};

struct Index {
    long id;
    long position;
};

int main(void) {
    FILE *database = fopen("people.db", "rb");
    if (!database) {
        fprintf(stderr, "Error: Failed to open database file.\n");
        return 1;
    }

    fseek(database, 0, SEEK_END);
    long fileSize = ftell(database);
    int numPeople = fileSize / sizeof(struct Person);
    rewind(database);

    struct Index *index = malloc(numPeople * sizeof(struct Index));
    if (!index) {
        fprintf(stderr, "Error: Failed to allocate index.\n");
        fclose(database);
        return 1;
    }

    for (int i = 0; i < numPeople; i++) {
        struct Person person;
        fread(&person, sizeof(struct Person), 1, database);

        index[i].id = person.id;
        index[i].position = ftell(database) - sizeof(struct Person);
    }

    printf("%d people found in database.\n", numPeople);

    int continueSearch = 1;
    while (continueSearch) {
        long searchId;
        printf("\nEnter ID to search (0 to quit): ");
        scanf("%ld", &searchId);

        if (searchId == 0) {
            continueSearch = 0;
        } else {
            int found = 0;
            int low = 0;
            int high = numPeople - 1;
            int mid;

            while (low <= high) {
                mid = (low + high) / 2;
                if (index[mid].id == searchId) {
                    found = 1;
                    break;
                } else if (index[mid].id < searchId) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            if (found) {
                struct Person person;
                fseek(database, index[mid].position, SEEK_SET);
                fread(&person, sizeof(struct Person), 1, database);
                printf("Name: %s\nAge: %d\nID: %ld\n", person.name, person.age, person.id);
            } else {
                printf("Person not found.\n");
            }
        }
    }

    fclose(database);
    free(index);

    return 0;
}