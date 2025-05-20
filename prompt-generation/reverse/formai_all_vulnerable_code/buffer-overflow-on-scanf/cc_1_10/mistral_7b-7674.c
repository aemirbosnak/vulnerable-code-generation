//MISTRAL-7B DATASET v1.0 Category: Digital Diary ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ENTRIES 50
#define ENTRY_LEN 200

typedef struct {
    time_t date;
    char description[ENTRY_LEN];
} Entry;

Entry diary[MAX_ENTRIES];
int num_entries = 0;

int is_valid_date(int day, int month, int year) {
    int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month < 1 || month > 12 || year < 1) {
        return 0;
    }

    if (month == 2 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)) {
        months[1] = 29;
    }

    return day <= months[month - 1];
}

void add_entry(const char *description) {
    time_t now = time(NULL);
    int day, month, year;

    sscanf(ctime(&now), "%d-%d-%d %*s%*s%*s%*s", &year, &month, &day);

    if (!is_valid_date(day, month, year)) {
        printf("Invalid date.\n");
        return;
    }

    if (num_entries >= MAX_ENTRIES) {
        printf("Diary is full.\n");
        return;
    }

    diary[num_entries].date = now;
    strcpy(diary[num_entries].description, description);
    num_entries++;
}

void view_entry(int index) {
    if (index < 0 || index >= num_entries) {
        printf("Invalid index.\n");
        return;
    }

    struct tm *ptm = localtime(&diary[index].date);
    printf("%.2d-%d-%d %2d:%2d:%2d: %s\n", ptm->tm_mon + 1, ptm->tm_mday, ptm->tm_year + 1900, ptm->tm_hour, ptm->tm_min, ptm->tm_sec, diary[index].description);
}

void delete_entry(int index) {
    if (index < 0 || index >= num_entries) {
        printf("Invalid index.\n");
        return;
    }

    for (int i = index; i < num_entries - 1; i++) {
        diary[i] = diary[i + 1];
    }
    num_entries--;
}

void search_diary(const char *query) {
    for (int i = 0; i < num_entries; i++) {
        if (strstr(diary[i].description, query) != NULL) {
            view_entry(i);
            break;
        }
    }
}

int main() {
    char command[20];
    int index;

    while (1) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            char description[ENTRY_LEN];
            printf("Description: ");
            scanf("%s", description);
            add_entry(description);
        } else if (strcmp(command, "view") == 0) {
            if (num_entries == 0) {
                printf("Diary is empty.\n");
            } else {
                printf("Current entry: ");
                view_entry(num_entries - 1);
            }
        } else if (strcmp(command, "delete") == 0) {
            if (num_entries == 0) {
                printf("Diary is empty.\n");
            } else {
                printf("Index: ");
                scanf("%d", &index);
                delete_entry(index);
            }
        } else if (strcmp(command, "search") == 0) {
            char query[ENTRY_LEN];
            printf("Query: ");
            scanf("%s", query);
            search_diary(query);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}