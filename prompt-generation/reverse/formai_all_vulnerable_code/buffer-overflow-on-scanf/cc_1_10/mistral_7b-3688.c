//MISTRAL-7B DATASET v1.0 Category: Phone Book ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_NAME_LEN 50
#define MAX_NUM_LEN 20
#define MAX_ENTRIES 100

typedef struct {
    char name[MAX_NAME_LEN];
    char number[MAX_NUM_LEN];
} Entry;

void normalizeName(char *name) {
    int i, j;
    for (i = 0; name[i] != '\0'; i++) {
        name[i] = tolower(name[i]);
        for (j = i + 1; name[j] != '\0'; j++) {
            if (name[i] == 'a' && (name[i + 1] == 'e' || name[i + 1] == 'i' || name[i + 1] == 'o' || name[i + 1] == 'u')) {
                name[i] = '\0';
                for (; j < strlen(name + i) + i; j++) {
                    name[j - i] = name[j];
                }
                i--;
                break;
            }
        }
    }
}

int hashFunction(char *name) {
    int hash = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        hash += name[i];
    }
    hash = fabs(sin(M_PI * hash / 100.0));
    hash = (int)(hash * 100.0) % MAX_ENTRIES;
    return hash;
}

int compareEntries(const void *a, const void *b) {
    Entry *entryA = (Entry *)a;
    Entry *entryB = (Entry *)b;
    return strcmp(entryA->name, entryB->name);
}

int main() {
    Entry phoneBook[MAX_ENTRIES];
    int numEntries = 0;

    while (numEntries < MAX_ENTRIES && scanf("%s%s", phoneBook[numEntries].name, phoneBook[numEntries].number) == 2) {
        normalizeName(phoneBook[numEntries].name);
        numEntries++;
    }

    qsort(phoneBook, numEntries, sizeof(Entry), compareEntries);

    int searchNameLen;
    char searchName[MAX_NAME_LEN];

    while (1) {
        printf("\nEnter name to search for (type 'exit' to quit): ");
        scanf("%s", searchName);

        if (strcmp(searchName, "exit") == 0) {
            break;
        }

        searchNameLen = strlen(searchName);
        if (searchNameLen > MAX_NAME_LEN) {
            printf("Name too long. Please try again.\n");
            continue;
        }

        normalizeName(searchName);

        int index = -1;

        for (int i = 0; i < numEntries; i++) {
            if (strcmp(phoneBook[i].name, searchName) == 0) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            printf("Name not found in phone book.\n");
        } else {
            printf("Number for %s: %s\n", searchName, phoneBook[index].number);
        }
    }

    return 0;
}