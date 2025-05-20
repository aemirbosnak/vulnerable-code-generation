//FormAI DATASET v1.0 Category: Digital Diary ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

struct diary_entry {
    char date[20];
    char time[20];
    char content[1000];
};

/* Function to display the menu */
void display_menu() {
    printf("\nDigital Diary\n");
    printf("-----------------------------------\n");
    printf("1. Add new entry\n");
    printf("2. View diary entries\n");
    printf("3. Search entries\n");
    printf("4. Delete entry\n");
    printf("5. Exit\n");
    printf("-----------------------------------\n");
}

/* Function to validate date and time*/
int validate(char *date, char *time) {
    if (strlen(date) != 10 || strlen(time) != 5) {
        return 0;
    }
    for (int i = 0; i < 10; i++) {
        if (i == 2 || i == 5) {
            continue;
        }
        if (!isdigit(date[i])) {
            return 0;
        }
    }
    for (int i = 0; i < 5; i++) {
        if (i == 2) {
            continue;
        }
        if (!isdigit(time[i])) {
            return 0;
        }
    }
    return 1;
}

/* Function to add new entry */
void add_entry(struct diary_entry *entry, int *count) {
    printf("\nEnter the date (dd/mm/yyyy): ");
    scanf("%s", entry[*count].date);
    printf("Enter the time (hh:mm): ");
    scanf("%s", entry[*count].time);
    printf("Enter your diary entry:\n");
    scanf(" %[^\n]s", entry[*count].content);
    if (validate(entry[*count].date, entry[*count].time) == 0) {
        printf("\nInvalid date or time! Entry not added.\n");
    } else {
        (*count)++;
        printf("\nEntry added successfully!\n");
    }
}

/* Function to view diary entries */
void view_entries(struct diary_entry *entry, int count) {
    if (count == 0) {
        printf("\nNo entries to display!\n");
    } else {
        printf("\nDiary Entries\n");
        printf("-----------------------------------\n");
        for (int i = 0; i < count; i++) {
            printf("Entry %d:\n", i + 1);
            printf("%s %s\n", entry[i].date, entry[i].time);
            printf("%s\n", entry[i].content);
            printf("-----------------------------------\n");
        }
    }
}

/* Function to search for a specific entry */
void search_entries(struct diary_entry *entry, int count) {
    if (count == 0) {
        printf("\nNo entries to search!\n");
    } else {
        int flag = 0;
        char search_term[1000];
        printf("\nEnter search term: ");
        scanf(" %[^\n]s", search_term);
        for (int i = 0; i < count; i++) {
            char *ptr = strstr(entry[i].content, search_term);
            if (ptr != NULL) {
                printf("\nMatch found in entry %d!\n", i + 1);
                printf("%s %s\n", entry[i].date, entry[i].time);
                printf("%s\n", entry[i].content);
                flag = 1;
            }
        }
        if (flag == 0) {
            printf("\nNo matches found!\n");
        }
    }
}

/* Function to delete an entry */
void delete_entry(struct diary_entry *entry, int *count) {
    if (*count == 0) {
        printf("\nNo entries to delete!\n");
    } else {
        int index;
        printf("\nEnter the index of the entry to be deleted: ");
        scanf("%d", &index);
        if (index > *count || index < 1) {
            printf("\nInvalid index! Deletion failed.\n");
        } else {
            for (int i = index - 1; i < *count - 1; i++) {
                entry[i] = entry[i + 1];
            }
            (*count)--;
            printf("\nDeletion successful.\n");
        }
    }
}

int main() {
    int choice, count = 0;
    struct diary_entry *entry = (struct diary_entry*) malloc(sizeof(struct diary_entry));
    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_entry(entry, &count);
                break;
            case 2:
                view_entries(entry, count);
                break;
            case 3:
                search_entries(entry, count);
                break;
            case 4:
                delete_entry(entry, &count);
                break;
            case 5:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Please choose again.\n");
        }
    } while (choice != 5);
    free(entry);
    return 0;
}