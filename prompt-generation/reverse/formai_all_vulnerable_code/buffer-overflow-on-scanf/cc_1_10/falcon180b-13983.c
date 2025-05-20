//Falcon-180B DATASET v1.0 Category: File handling ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

struct data {
    char filename[MAX_LINE_LENGTH];
    int length;
    char data[MAX_LINE_LENGTH];
};

void read_file(struct data *entry, FILE *file) {
    char line[MAX_LINE_LENGTH];
    int i = 0;

    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        strcat(entry->data, line);
        entry->length += strlen(line);
        i++;
    }
}

void write_file(struct data *entry, FILE *file) {
    fprintf(file, "%s", entry->data);
}

int main() {
    FILE *file1, *file2;
    char choice;
    struct data entry;

    printf("Enter the name of the file to read: ");
    scanf("%s", entry.filename);

    file1 = fopen(entry.filename, "r");

    if (file1 == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    read_file(&entry, file1);

    printf("\nEnter the name of the file to write: ");
    scanf("%s", entry.filename);

    file2 = fopen(entry.filename, "w");

    if (file2 == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    write_file(&entry, file2);

    printf("\nFile written successfully.\n");

    fclose(file1);
    fclose(file2);

    return 0;
}