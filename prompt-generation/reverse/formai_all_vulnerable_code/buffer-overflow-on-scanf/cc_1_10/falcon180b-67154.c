//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <stdarg.h>
#include <limits.h>

#define MAX_ENTRIES 100
#define MAX_ENTRY_LENGTH 100

typedef struct {
    char category[MAX_ENTRY_LENGTH];
    double value;
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* category, double value) {
    if (num_entries >= MAX_ENTRIES) {
        fprintf(stderr, "Error: maximum number of entries reached.\n");
        return;
    }

    strncpy(entries[num_entries].category, category, MAX_ENTRY_LENGTH);
    entries[num_entries].value = value;
    num_entries++;
}

void print_entries() {
    printf("Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%s: %.2f\n", entries[i].category, entries[i].value);
    }
}

void clear_entries() {
    num_entries = 0;
}

int main() {
    char input[MAX_ENTRY_LENGTH];
    while (1) {
        printf("Enter category (or 'print' to view entries, 'clear' to reset):\n");
        scanf("%s", input);

        if (!strcmp(input, "print")) {
            print_entries();
        } else if (!strcmp(input, "clear")) {
            clear_entries();
        } else {
            printf("Enter value:\n");
            scanf("%lf", &entries[num_entries].value);
            strncpy(entries[num_entries].category, input, MAX_ENTRY_LENGTH);
            num_entries++;
        }
    }

    return 0;
}