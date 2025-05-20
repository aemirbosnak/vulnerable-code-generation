#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 10

typedef struct {
    char title[100];
    char content[500];
} DiaryEntry;

int main() {
    DiaryEntry diary[MAX_ENTRIES];
    int num_entries = 0;

    char title[100];
    char content[500];

    while (num_entries < MAX_ENTRIES) {
        printf("Enter title: ");
        scanf("%s", title);
        printf("Enter content: ");
        scanf("%s", content);

        strcpy(diary[num_entries].title, title);
        strcpy(diary[num_entries].content, content);

        num_entries++;
    }

    printf("\nDiary Entries:\n");
    for (int i = 0; i < num_entries; i++) {
        printf("\nTitle: %s\nContent: %s\n", diary[i].title, diary[i].content);
    }

    return 0;
}
