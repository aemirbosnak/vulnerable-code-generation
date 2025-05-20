//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1024
#define MAX_KEY_VALUE_PAIRS 100

typedef struct {
    char* key;
    char* value;
} KeyValuePair;

char* extract_key_value(char* line) {
    char* key = NULL;
    char* value = NULL;
    char* token = strtok(line, "=");
    if(token!= NULL) {
        key = strdup(token);
        value = strdup(strtok(NULL, " "));
    }
    return key;
}

int main() {
    FILE* fp;
    char line[MAX_LINE];
    int num_key_value_pairs = 0;
    KeyValuePair key_value_pairs[MAX_KEY_VALUE_PAIRS];

    fp = fopen("metadata.txt", "r");
    if(fp == NULL) {
        printf("Error: could not open metadata file.\n");
        exit(1);
    }

    while(fgets(line, MAX_LINE, fp)!= NULL) {
        char* key = extract_key_value(line);
        if(key!= NULL) {
            if(num_key_value_pairs >= MAX_KEY_VALUE_PAIRS) {
                printf("Error: maximum number of key-value pairs reached.\n");
                exit(1);
            }
            key_value_pairs[num_key_value_pairs].key = key;
            key_value_pairs[num_key_value_pairs].value = strdup(line);
            num_key_value_pairs++;
        }
    }

    fclose(fp);

    printf("Metadata:\n");
    for(int i = 0; i < num_key_value_pairs; i++) {
        printf("%s: %s\n", key_value_pairs[i].key, key_value_pairs[i].value);
    }

    return 0;
}