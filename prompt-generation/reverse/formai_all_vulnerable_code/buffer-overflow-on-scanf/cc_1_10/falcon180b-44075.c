//Falcon-180B DATASET v1.0 Category: Digital Diary ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_ENTRIES 1000
#define MAX_ENTRY_LENGTH 1000

struct entry {
    char date[20];
    char time[20];
    char content[MAX_ENTRY_LENGTH];
};

struct entry diary[MAX_ENTRIES];
int num_entries = 0;

void add_entry(char* date, char* time, char* content) {
    struct entry new_entry;
    strcpy(new_entry.date, date);
    strcpy(new_entry.time, time);
    strcpy(new_entry.content, content);
    diary[num_entries++] = new_entry;
}

void print_entry(int index) {
    printf("%s %s\n%s\n", diary[index].date, diary[index].time, diary[index].content);
}

int main() {
    srand(time(NULL));
    int choice;
    char date[20];
    char time[20];
    char content[MAX_ENTRY_LENGTH];

    do {
        printf("Digital Diary\n");
        printf("1. Add Entry\n2. Print Entry\n3. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter Date (YYYY-MM-DD): ");
                scanf("%s", date);
                printf("Enter Time (HH:MM:SS): ");
                scanf("%s", time);
                printf("Enter Content:\n");
                fgets(content, MAX_ENTRY_LENGTH, stdin);
                content[strcspn(content, "\n")] = '\0'; // remove newline character
                add_entry(date, time, content);
                printf("Entry added.\n");
                break;
            case 2:
                printf("Enter Index of Entry to Print: ");
                scanf("%d", &index);
                if(index >= 0 && index < num_entries) {
                    print_entry(index);
                } else {
                    printf("Invalid Index.\n");
                }
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Choice.\n");
        }

    } while(choice!= 3);

    return 0;
}