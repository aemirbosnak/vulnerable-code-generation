//Code Llama-13B DATASET v1.0 Category: Digital Diary ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_ENTRIES 100

typedef struct {
    char title[100];
    char content[1000];
    time_t date;
} entry_t;

void write_entry(char* title, char* content) {
    entry_t entry;
    strcpy(entry.title, title);
    strcpy(entry.content, content);
    entry.date = time(NULL);
    FILE* fp = fopen("diary.dat", "ab");
    fwrite(&entry, sizeof(entry_t), 1, fp);
    fclose(fp);
}

void read_entry(int index, char* title, char* content) {
    FILE* fp = fopen("diary.dat", "rb");
    if (fp == NULL) {
        printf("Error opening file\n");
        return;
    }
    fseek(fp, index * sizeof(entry_t), SEEK_SET);
    entry_t entry;
    fread(&entry, sizeof(entry_t), 1, fp);
    strcpy(title, entry.title);
    strcpy(content, entry.content);
    fclose(fp);
}

void print_entry(int index) {
    char title[100];
    char content[1000];
    read_entry(index, title, content);
    printf("%s - %s\n", title, content);
}

void print_all_entries() {
    int i;
    for (i = 0; i < MAX_ENTRIES; i++) {
        print_entry(i);
    }
}

int main() {
    char title[100];
    char content[1000];
    printf("Enter title: ");
    scanf("%s", title);
    printf("Enter content: ");
    scanf("%s", content);
    write_entry(title, content);
    print_all_entries();
    return 0;
}