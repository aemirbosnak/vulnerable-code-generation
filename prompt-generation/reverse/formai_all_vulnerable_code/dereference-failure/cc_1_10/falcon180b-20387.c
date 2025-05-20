//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 1000

typedef struct element {
    char *name;
    char *value;
    struct element *next;
} element;

typedef struct {
    element *head;
    int count;
} element_list;

element_list *create_element_list() {
    element_list *list = (element_list *)malloc(sizeof(element_list));
    if (list == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }
    list->head = NULL;
    list->count = 0;
    return list;
}

void destroy_element_list(element_list *list) {
    element *elem = list->head;
    while (elem!= NULL) {
        element *next = elem->next;
        free(elem->name);
        free(elem->value);
        free(elem);
        elem = next;
    }
    free(list);
}

element *find_element(element_list *list, char *name) {
    element *elem = list->head;
    while (elem!= NULL) {
        if (strcmp(elem->name, name) == 0) {
            return elem;
        }
        elem = elem->next;
    }
    return NULL;
}

void add_element(element_list *list, char *name, char *value) {
    element *elem = find_element(list, name);
    if (elem!= NULL) {
        free(elem->value);
        elem->value = strdup(value);
    } else {
        elem = (element *)malloc(sizeof(element));
        if (elem == NULL) {
            printf("Error: Out of memory\n");
            exit(1);
        }
        elem->name = strdup(name);
        elem->value = strdup(value);
        elem->next = NULL;
        if (list->head == NULL) {
            list->head = elem;
        } else {
            element *last = list->head;
            while (last->next!= NULL) {
                last = last->next;
            }
            last->next = elem;
        }
        list->count++;
    }
}

void print_element_list(element_list *list) {
    element *elem = list->head;
    while (elem!= NULL) {
        printf("%s=%s\n", elem->name, elem->value);
        elem = elem->next;
    }
}

int main() {
    FILE *fp;
    char line[MAX_ELEMENTS];
    element_list *list = create_element_list();

    fp = fopen("example.xml", "r");
    if (fp == NULL) {
        printf("Error: Cannot open file\n");
        exit(1);
    }

    while (fgets(line, MAX_ELEMENTS, fp)!= NULL) {
        int len = strlen(line);
        if (line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }
        char *pos = strchr(line, '=');
        if (pos!= NULL) {
            *pos = '\0';
            char *name = line;
            char *value = pos + 1;
            add_element(list, name, value);
        }
    }

    fclose(fp);

    print_element_list(list);

    destroy_element_list(list);

    return 0;
}