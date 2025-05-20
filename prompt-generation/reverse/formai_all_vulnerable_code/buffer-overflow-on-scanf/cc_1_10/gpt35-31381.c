//FormAI DATASET v1.0 Category: Digital Diary ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_ENTRY_SIZE 500
#define MAX_TITLE_SIZE 50
#define MAX_ENTRIES 10

struct Entry {
    char title[MAX_TITLE_SIZE];
    char content[MAX_ENTRY_SIZE];
    char date[30];
};

typedef struct Entry Entry;

int num_entries = 0;
Entry entries[MAX_ENTRIES];

void display_menu(void);
void add_entry(void);
void show_entries(void);
void search_entries(void);
bool is_duplicate(char *);
char *get_user_input(const char *);
bool ask_to_continue(char *);

int main(void) {
    display_menu();

    return 0;
}

void display_menu(void) {
    while (true) {
        printf("**********DIGITAL DIARY**********\n"
               "1) Add an Entry\n"
               "2) Show Entries\n"
               "3) Search Entries\n"
               "4) Exit\n"
               "Choose an option (1-4): ");

        char input = getchar();
        fflush(stdin);

        switch (input) {
            case '1':
                add_entry();
                break;
            case '2':
                show_entries();
                break;
            case '3':
                search_entries();
                break;
            case '4':
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid option selected. Try again!\n");
                break;
        }
    }
}

void add_entry(void) {
    if (num_entries >= MAX_ENTRIES) {
        printf("Sorry, you cannot add more than %d entries!\n", MAX_ENTRIES);
        return;
    }

    char *title = get_user_input("Enter the title of the entry:");
    if (is_duplicate(title)) {
        printf("An entry with the title '%s' already exists!\n", title);
        return;
    }

    char *content = get_user_input("Enter the content of the entry:");
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char s[30];
    strftime(s, sizeof(s), "%c", tm);

    Entry new_entry;
    strcpy(new_entry.title, title);
    strcpy(new_entry.content, content);
    strcpy(new_entry.date, s);

    entries[num_entries++] = new_entry;

    free(title);
    free(content);

    printf("'%s' entry added successfully.\n", new_entry.title);
    ask_to_continue("Add another entry? (y/n):") ? add_entry() : display_menu();
}

void show_entries(void) {
    if (num_entries == 0) {
        printf("Sorry, there are no entries to display.\n");
        return;
    }

    printf("#\tEntry Title\tDate\t\tContent\n");
    printf("--------------------------------------------------------------\n");
    for (int i = 0; i < num_entries; i++) {
        printf("%d\t%s\t%s\t\t%s\n", i + 1, entries[i].title, entries[i].date, entries[i].content);
    }
    ask_to_continue("Show entries again? (y/n):") ? show_entries() : display_menu();
}

void search_entries(void) {
    if (num_entries == 0) {
        printf("Sorry, there are no entries to search.\n");
        return;
    }

    char *query = get_user_input("Enter a search query:");
    bool found = false;
    printf("#\tEntry Title\tDate\t\tContent\n");
    printf("--------------------------------------------------------------\n");
    for (int i = 0; i < num_entries; i++) {
        if (strstr(entries[i].title, query) || strstr(entries[i].content, query)) {
            printf("%d\t%s\t%s\t\t%s\n", i + 1, entries[i].title, entries[i].date, entries[i].content);
            found = true;
        }
    }

    if (!found) {
        printf("No entries found containing '%s'.\n", query);
    }
    free(query);

    ask_to_continue("Search for another query?(y/n): ")? search_entries(): display_menu();
}

bool ask_to_continue(char *prompt) {
    char choice = 'n';
    printf("%s", prompt);
    scanf("%c", &choice);
    fflush(stdin);

    if (tolower(choice) == 'y') {
        return true;
    }
    return false;
}


bool is_duplicate(char *title) {
    for (int i = 0; i < num_entries; i++) {
        if (strcmp(entries[i].title, title) == 0) {
            return true;
        }
    }
    return false;
}

char *get_user_input(const char *prompt) {
    char *input = (char *) malloc(sizeof(char) * MAX_ENTRY_SIZE);
    printf("%s\n", prompt);
    fgets(input, MAX_ENTRY_SIZE, stdin);
    input[strcspn(input, "\n")] = 0;
    return input;
}