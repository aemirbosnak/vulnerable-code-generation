//MISTRAL-7B DATASET v1.0 Category: Database simulation ; Style: medieval
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_RECORDS 10
#define RECORD_SIZE 100

typedef struct {
    char name[50];
    char occupation[50];
} Record;

Record scroll[MAX_RECORDS];
int current_position = 0;

void print_scroll() {
    printf("\n-------- The Scroll of Knowledge --------\n");
    for (int i = 0; i < current_position; i++) {
        printf("\n%s, %s", scroll[i].name, scroll[i].occupation);
    }
}

void add_record(const char* name, const char* occupation) {
    if (current_position >= MAX_RECORDS) {
        printf("\n------ Error: Scroll is full! -------\n");
        return;
    }
    strcpy(scroll[current_position].name, name);
    strcpy(scroll[current_position].occupation, occupation);
    current_position++;
}

void delete_record(int index) {
    if (index < 0 || index >= current_position) {
        printf("\n------ Error: Record not found! -------\n");
        return;
    }
    for (int i = index; i < current_position; i++) {
        scroll[i] = scroll[i+1];
    }
    current_position--;
}

void search_record(const char* keyword) {
    for (int i = 0; i < current_position; i++) {
        if (strstr(scroll[i].name, keyword) != NULL) {
            printf("\nRecord found: %s, %s\n", scroll[i].name, scroll[i].occupation);
            return;
        }
    }
    printf("\n------ Error: Record not found! -------\n");
}

int main() {
    char command[20];
    char name[50];
    char occupation[50];
    int index;

    while (1) {
        printf("\n------ Welcome, noble! What's your command? ------\n");
        scanf("%s", command);

        if (strcmp(command, "ADD") == 0) {
            printf("\n------ Enter name: ------\n");
            scanf("%s", name);
            printf("\n------ Enter occupation: ------\n");
            scanf("%s", occupation);
            add_record(name, occupation);
        } else if (strcmp(command, "DELETE") == 0) {
            printf("\n------ Enter index: ------\n");
            scanf("%d", &index);
            delete_record(index);
        } else if (strcmp(command, "SEARCH") == 0) {
            printf("\n------ Enter keyword: ------\n");
            scanf("%s", name);
            search_record(name);
        } else if (strcmp(command, "DISPLAY") == 0) {
            print_scroll();
        } else if (strcmp(command, "QUIT") == 0) {
            break;
        } else {
            printf("\n------ Unknown command! ------\n");
        }
    }

    return 0;
}