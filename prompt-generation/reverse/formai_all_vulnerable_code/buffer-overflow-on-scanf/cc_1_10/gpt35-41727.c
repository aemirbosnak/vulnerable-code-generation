//FormAI DATASET v1.0 Category: Log analysis ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LEN 100

struct entry {
    char filename[MAX_LEN];
    int line_no;
    char message[MAX_LEN];
};

void print_menu(){
    printf("1. Add entry\n");
    printf("2. Display all entries\n");
    printf("3. Search by file name\n");
    printf("4. Search by line number\n");
    printf("5. Exit\n");
}

void add_entry(struct entry *logbook, int *total_entries){
    if (*total_entries == MAX_LINES){
        printf("Log book is full\n");
        return;
    }
    struct entry new_entry;
    printf("Enter filename: ");
    scanf("%s", new_entry.filename);
    printf("Enter line number: ");
    scanf("%d", &new_entry.line_no);
    printf("Enter message: ");
    scanf("%s", new_entry.message);
    logbook[*total_entries] = new_entry;
    (*total_entries)++;
}

void display_entries(struct entry *logbook, int total_entries){
    printf("%6s %20s %10s %40s\n", "Index", "Filename", "Line no.", "Message");
    for (int i = 0; i < total_entries; i++){
        printf("%6d %20s %10d %40s\n", i, logbook[i].filename, logbook[i].line_no, logbook[i].message);
    }
}

void search_by_filename(struct entry *logbook, int total_entries, char *filename){
    int num_matches = 0;
    printf("%6s %20s %10s %40s\n", "Index", "Filename", "Line no.", "Message");
    for (int i = 0; i < total_entries; i++){
        if (strcmp(logbook[i].filename, filename) == 0){
            printf("%6d %20s %10d %40s\n", i, logbook[i].filename, logbook[i].line_no, logbook[i].message);
            num_matches++;
        }
    }
    if (num_matches == 0){
        printf("No matches found\n");
    }
}

void search_by_line_no(struct entry *logbook, int total_entries, int line_no){
    int num_matches = 0;
    printf("%6s %20s %10s %40s\n", "Index", "Filename", "Line no.", "Message");
    for (int i = 0; i < total_entries; i++){
        if (logbook[i].line_no == line_no){
            printf("%6d %20s %10d %40s\n", i, logbook[i].filename, logbook[i].line_no, logbook[i].message);
            num_matches++;
        }
    }
    if (num_matches == 0){
        printf("No matches found\n");
    }
}

void recursive_logbook(struct entry *logbook, int *total_entries){
    print_menu();
    int choice;
    scanf("%d", &choice);
    switch(choice){
        case 1: add_entry(logbook, total_entries);
                break;
        case 2: display_entries(logbook, *total_entries);
                break;
        case 3: {
                    char filename[MAX_LEN];
                    printf("Enter filename: ");
                    scanf("%s", filename);
                    search_by_filename(logbook, *total_entries, filename);
                    break;
                }
        case 4: {
                    int line_no;
                    printf("Enter line number: ");
                    scanf("%d", &line_no);
                    search_by_line_no(logbook, *total_entries, line_no);
                    break;
                }
        case 5: return;
        default: printf("Invalid choice\n");
                 break;
    }
    recursive_logbook(logbook, total_entries);
}

int main(){
    struct entry logbook[MAX_LINES];
    int total_entries = 0;
    recursive_logbook(logbook, &total_entries);
    return 0;
}