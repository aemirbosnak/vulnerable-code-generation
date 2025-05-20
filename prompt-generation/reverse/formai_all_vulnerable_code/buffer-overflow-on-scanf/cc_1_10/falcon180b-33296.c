//Falcon-180B DATASET v1.0 Category: Fitness Tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 50

typedef struct {
    char entry[MAX_ENTRY_LENGTH];
    int count;
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

int add_entry(char* str) {
    for(int i=0; i<num_entries; i++) {
        if(strcmp(entries[i].entry, str) == 0) {
            entries[i].count++;
            return i;
        }
    }
    if(num_entries >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return -1;
    }
    strcpy(entries[num_entries].entry, str);
    entries[num_entries].count = 1;
    num_entries++;
    return num_entries-1;
}

void print_entries() {
    for(int i=0; i<num_entries; i++) {
        printf("%d. %s (%d)\n", i+1, entries[i].entry, entries[i].count);
    }
}

int main() {
    char input[MAX_ENTRY_LENGTH];
    while(1) {
        printf("Enter a fitness activity: ");
        scanf("%s", input);
        int index = add_entry(input);
        if(index == -1) {
            break;
        }
        printf("Added '%s' to fitness tracker.\n", input);
    }
    print_entries();
    return 0;
}