//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME_LEN 256
#define MAX_ATTR_NAME_LEN 256
#define MAX_ATTR_VALUE_LEN 256
#define MAX_ELEM_DATA_LEN 1024

typedef struct attribute {
    char name[MAX_ATTR_NAME_LEN];
    char value[MAX_ATTR_VALUE_LEN];
} attribute_t;

typedef struct element {
    char name[MAX_TAG_NAME_LEN];
    attribute_t attrs[MAX_ATTR_NAME_LEN];
    char data[MAX_ELEM_DATA_LEN];
    struct element *children;
    struct element *next;
} element_t;

void parse_element(element_t *elem, char *xml_str) {
    char *start = xml_str;
    char *end;

    // get tag name
    start = strchr(start, '<');
    end = strchr(start, '>');
    int name_len = end - start - 1;
    strncpy(elem->name, start + 1, name_len);
    elem->name[name_len] = '\0';

    // get attributes
    start = end + 1;
    while (*start != '>') {
        char attr_name[MAX_ATTR_NAME_LEN], attr_value[MAX_ATTR_VALUE_LEN];
        sscanf(start, "%s=\"%[^\"]\"", attr_name, attr_value);
        strncpy(elem->attrs->name, attr_name, strlen(attr_name) + 1);
        strncpy(elem->attrs->value, attr_value, strlen(attr_value) + 1);
        start = strchr(start, '\"') + 1;
    }

    // get element data
    start = strchr(start, '>') + 1;
    end = strstr(start, "</");
    int data_len = end - start;
    strncpy(elem->data, start, data_len);
    elem->data[data_len] = '\0';

    // get child elements
    start = end;
    while (*start != '\0') {
        if (strncmp(start, "</", 2) == 0) break;
        element_t *child = (element_t *)malloc(sizeof(element_t));
        elem->children = child;
        parse_element(child, start);
        start = strchr(start, '<');
    }

    // get next element
    end = strstr(start, "</");
    if (end != NULL) {
        element_t *next = (element_t *)malloc(sizeof(element_t));
        elem->next = next;
        parse_element(next, end);
    }
}

int main() {
    char xml_str[] = "<bookstore>\n"
                     "  <book category=\"cooking\">\n"
                     "    <title lang=\"en\">Everyday Italian</title>\n"
                     "    <author>Giada De Laurentiis</author>\n"
                     "    <year>2005</year>\n"
                     "    <price>30.00</price>\n"
                     "  </book>\n"
                     "  <book category=\"children\">\n"
                     "    <title lang=\"en\">Harry Potter</title>\n"
                     "    <author>J.K. Rowling</author>\n"
                     "    <year>2005</year>\n"
                     "    <price>29.99</price>\n"
                     "  </book>\n"
                     "</bookstore>";
    
    element_t *root = (element_t *)malloc(sizeof(element_t));
    parse_element(root, xml_str);

    // print out the bookstore element and its children elements
    printf("Element: %s\n", root->name);
    element_t *child = root->children;
    while (child != NULL) {
        printf("\tElement: %s\n", child->name);
        printf("\t\tTitle: %s\n", child->children->data);
        printf("\t\tAuthor: %s\n", child->children->next->data);
        printf("\t\tYear: %s\n", child->children->next->next->data);
        printf("\t\tPrice: %s\n", child->children->next->next->next->data);
        child = child->next;
    }

    // free memory
    free(root);
    return 0; 
}