//FormAI DATASET v1.0 Category: Database Indexing System ; Style: imaginative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct index {
    char key[50];
    int offset;
}index_table[100];

int num_index = 0;
FILE *fp;

void insert_index(char key[], int offset) {
    if(num_index < 100) {
        strcpy(index_table[num_index].key, key);
        index_table[num_index].offset = offset;
        num_index++;
    }
    else {
        printf("Maximum index limit reached.\n");
    }
}

void search_index(char key[]) {
    int i, offset = -1;
    for(i = 0; i < num_index; i++) {
        if(strcmp(key, index_table[i].key) == 0) {
            offset = index_table[i].offset;
            break;
        }
    }
    if(offset != -1) {
        fseek(fp, offset, SEEK_SET);
        char buffer[100];
        fgets(buffer, 100, fp);
        printf("Record found: %s\n", buffer);
    }
    else {
        printf("Record not found.\n");
    }
}

int main() {
    fp = fopen("data.txt", "r");
    if(fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    char buffer[100];
    int offset = 0;
    while(fgets(buffer, 100, fp) != NULL) {
        char key[50];
        sscanf(buffer, "%s", key);
        insert_index(key, offset);
        offset = ftell(fp);
    }

    char search_term[50];
    printf("Enter search term: ");
    scanf("%s", search_term);
    search_index(search_term);

    fclose(fp);
    return 0;
}