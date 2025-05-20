//Falcon-180B DATASET v1.0 Category: Intrusion detection system ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 100

typedef struct {
    char *key;
    int value;
} Entry;

Entry entries[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char *key, int value) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Error: Maximum number of entries reached.\n");
        return;
    }

    entries[num_entries].key = strdup(key);
    entries[num_entries].value = value;

    num_entries++;
}

int get_value(char *key) {
    int i;

    for (i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].key, key) == 0) {
            return entries[i].value;
        }
    }

    return -1;
}

int main() {
    add_entry("test", 1);
    add_entry("foo", 2);
    add_entry("bar", 3);

    printf("Value for test: %d\n", get_value("test"));
    printf("Value for foo: %d\n", get_value("foo"));
    printf("Value for bar: %d\n", get_value("bar"));

    return 0;
}