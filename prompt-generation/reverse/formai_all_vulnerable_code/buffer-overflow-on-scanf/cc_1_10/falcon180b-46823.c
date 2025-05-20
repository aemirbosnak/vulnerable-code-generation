//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 1000

typedef struct {
    char date[20];
    char entry[500];
} diary_entry;

int main() {
    FILE *diary_file;
    char filename[20];
    int num_entries = 0;
    diary_entry diary[MAX_ENTRIES];

    printf("Welcome to your digital diary!\n");
    printf("Please enter a filename (without extension): ");
    scanf("%s", filename);

    strcat(filename, ".txt");

    diary_file = fopen(filename, "a");

    if (diary_file == NULL) {
        printf("Error creating file.\n");
        exit(1);
    }

    while (num_entries < MAX_ENTRIES) {
        printf("\n");
        printf("Date (YYYY-MM-DD): ");
        scanf("%s", diary[num_entries].date);

        printf("Entry:\n");
        fgets(diary[num_entries].entry, 500, stdin);

        fprintf(diary_file, "%s\n%s\n", diary[num_entries].date, diary[num_entries].entry);
        num_entries++;
    }

    fclose(diary_file);

    printf("\nYour diary has been saved.\n");

    return 0;
}