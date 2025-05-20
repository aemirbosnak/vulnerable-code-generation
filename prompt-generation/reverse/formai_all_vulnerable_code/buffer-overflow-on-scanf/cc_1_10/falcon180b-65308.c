//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 1000

typedef struct {
    char date[20];
    char entry[MAX_ENTRY_LENGTH];
} Entry;

int main() {
    FILE *fp;
    char filename[50];
    int count = 0;
    Entry entries[MAX_ENTRIES];

    printf("Enter file name: ");
    scanf("%s", filename);

    fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Error: file not found.\n");
        exit(1);
    }

    rewind(fp);

    while (fgets(entries[count].date, sizeof(entries[count].date), fp)!= NULL) {
        count++;
    }

    fclose(fp);

    fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Error: file not found.\n");
        exit(1);
    }

    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(entries[count].date, sizeof(entries[count].date), "%Y-%m-%d %H:%M:%S", t);

    printf("Enter entry: ");
    fgets(entries[count].entry, MAX_ENTRY_LENGTH, stdin);

    fprintf(fp, "%s\n", entries[count].entry);

    fclose(fp);

    return 0;
}