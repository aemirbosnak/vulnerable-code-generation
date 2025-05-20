//Falcon2-11B DATASET v1.0 Category: Mailing list manager ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIST_SIZE 1000
#define MAX_SUBSCRIBERS_PER_LIST 50

typedef struct list {
    char* name;
    int size;
    int subscribers_count;
    char** subscribers;
} List;

List* create_list(char* name) {
    List* new_list = (List*)malloc(sizeof(List));
    if (new_list == NULL) {
        fprintf(stderr, "Error: Could not allocate memory.\n");
        return NULL;
    }

    new_list->name = strdup(name);
    new_list->size = 0;
    new_list->subscribers_count = 0;
    new_list->subscribers = NULL;

    return new_list;
}

void add_subscriber_to_list(List* list, char* email) {
    if (list->subscribers_count >= MAX_SUBSCRIBERS_PER_LIST) {
        fprintf(stderr, "Error: List is full.\n");
        return;
    }

    list->subscribers_count++;
    list->subscribers = (char**)realloc(list->subscribers, sizeof(char*) * (list->subscribers_count + 1));
    list->subscribers[list->subscribers_count - 1] = strdup(email);
}

void remove_subscriber_from_list(List* list, char* email) {
    int i;
    for (i = 0; i < list->subscribers_count; i++) {
        if (strcmp(list->subscribers[i], email) == 0) {
            free(list->subscribers[i]);
            list->subscribers[i] = NULL;
            list->subscribers_count--;
            break;
        }
    }
}

void print_list_contents(List* list) {
    int i;
    printf("%s:\n", list->name);
    printf("Subscribers:\n");
    for (i = 0; i < list->subscribers_count; i++) {
        printf("  %s\n", list->subscribers[i]);
    }
}

int main() {
    List* list1 = create_list("list1");
    add_subscriber_to_list(list1, "subscriber1@example.com");
    add_subscriber_to_list(list1, "subscriber2@example.com");
    print_list_contents(list1);

    remove_subscriber_from_list(list1, "subscriber2@example.com");
    print_list_contents(list1);

    free(list1);
    return 0;
}