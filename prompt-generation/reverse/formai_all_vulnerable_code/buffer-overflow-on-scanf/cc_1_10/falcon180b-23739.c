//Falcon-180B DATASET v1.0 Category: File handling ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

struct entry {
    char name[MAX_LINE_LENGTH];
    char value[MAX_LINE_LENGTH];
};

int compare_entries(const void *a, const void *b) {
    struct entry *entry1 = (struct entry *)a;
    struct entry *entry2 = (struct entry *)b;

    return strcmp(entry1->name, entry2->name);
}

int main() {
    FILE *file;
    char filename[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    char delimiter = '=';
    char *token;
    struct entry entries[100];
    int num_entries = 0;

    printf("Enter the name of the input file: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        token = strtok(line, &delimiter);
        strcpy(entries[num_entries].name, token);

        token = strtok(NULL, &delimiter);
        strcpy(entries[num_entries].value, token);

        num_entries++;
    }

    fclose(file);

    qsort(entries, num_entries, sizeof(struct entry), compare_entries);

    printf("Sorted entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s = %s\n", entries[i].name, entries[i].value);
    }

    return 0;
}