//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ELEM 5
#define FILENAME "numbers.txt"

typedef struct {
    int num;
    char name[20];
} Person;

int main(void) {
    FILE *fp;
    Person people[NUM_ELEM];
    int i, num_read;

    fp = fopen(FILENAME, "r");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open %s\n", FILENAME);
        exit(1);
    }

    for (i = 0; i < NUM_ELEM; i++) {
        fscanf(fp, "%s %d", people[i].name, &people[i].num);
        if (feof(fp)) break;
    }

    fclose(fp);

    printf("Contents of %s:\n", FILENAME);
    for (i = 0; i < NUM_ELEM; i++) {
        printf("%s: %d\n", people[i].name, people[i].num);
    }

    printf("\nLet's reverse the numbers and save it to another file.\n");

    fp = fopen("reversed_numbers.txt", "w");
    for (i = NUM_ELEM - 1; i >= 0; i--) {
        fprintf(fp, "%d ", people[i].num);
    }
    fclose(fp);

    printf("\nFile reversed_numbers.txt created.\n");

    printf("\nNow, let's read the reversed numbers and print them.\n");

    fp = fopen("reversed_numbers.txt", "r");
    char line[100];
    int reversed_num;

    while (fgets(line, sizeof(line), fp) != NULL) {
        sscanf(line, "%d", &reversed_num);
        printf("%d ", reversed_num);
    }

    fclose(fp);

    printf("\nDone!\n");

    return 0;
}