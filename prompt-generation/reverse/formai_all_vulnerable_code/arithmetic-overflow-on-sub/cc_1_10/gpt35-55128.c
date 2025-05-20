//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: curious
#include<stdio.h>
#include<string.h>

#define MAX_TAG_LEN 100
#define MAX_TAG_ATTR_LEN 100
#define MAX_TAG_ATTR_VAL_LEN 100
#define MAX_DATA_LEN 1000

typedef struct {
    char tag_name[MAX_TAG_LEN];
    char attributes[MAX_TAG_ATTR_LEN][MAX_TAG_ATTR_VAL_LEN];
    int num_attributes;
    char data[MAX_DATA_LEN];
    struct element *child;
    struct element *sibling;
} element;

char* parse_attribute(char* buffer, char* attr) {
    int pos = 0;
    while(*buffer != '=') {
        attr[pos++] = *buffer;
        buffer++;
    }
    attr[pos] = '\0';
    buffer++;
    pos = 0;
    char* val = (char*)malloc(MAX_TAG_ATTR_VAL_LEN*sizeof(char));
    while(*buffer != '\"') {
        buffer++;
    }
    buffer++;
    while(*buffer != '\"') {
        val[pos++] = *buffer;
        buffer++;
    }
    val[pos] = '\0';
    return val;
}

element* parse_xml(char* buffer) {
    element* root = NULL;
    element* current = NULL;
    char tag[MAX_TAG_LEN], data[MAX_DATA_LEN];
    char attr[MAX_TAG_ATTR_LEN], attr_val[MAX_TAG_ATTR_VAL_LEN];
    int pos = 0, data_pos = 0;
    while(*buffer != '\0') {
        if(*buffer == '<') {
            buffer++;
            if(*buffer == '/') {
                buffer++;
                pos = 0;
                while(*buffer != '>') {
                    tag[pos++] = *buffer;
                    buffer++;
                }
                tag[pos] = '\0';
                if(strcmp(tag, current->tag_name) != 0) {
                    printf("Error: Mismatched tags!");
                    return NULL;
                } else {
                    current = current->sibling;
                }
                buffer++;
            } else {
                if(root == NULL) {
                    root = (element*)malloc(sizeof(element));
                    current = root;
                } else {
                    current->child = (element*)malloc(sizeof(element));
                    current = current->child;
                }
                pos = 0;
                while(*buffer != ' ' && *buffer != '>') {
                    tag[pos++] = *buffer;
                    buffer++;
                }
                tag[pos] = '\0';
                strcpy(current->tag_name, tag);
                current->num_attributes = 0;
                while(*buffer != '>') {
                    buffer++;
                    pos = 0;
                    while(*buffer != '=' && *buffer != '>') {
                        attr[pos++] = *buffer;
                        buffer++;
                    }
                    attr[pos] = '\0';
                    if(*buffer == '=') {
                        buffer++;
                        current->num_attributes++;
                        strcpy(current->attributes[current->num_attributes - 1], attr);
                        char* val = parse_attribute(buffer, attr_val);
                        strcpy(current->attributes[current->num_attributes - 1], val);
                    }
                }
                buffer++;
            }
        } else if(*buffer == '>') {
            buffer++;
            data_pos = 0;
            while(*buffer != '<') {
                data[data_pos++] = *buffer;
                buffer++;
            }
            data[data_pos] = '\0';
            strcpy(current->data, data);
            buffer++;
        } else {
            buffer++;
        }
    }
    return root;
}

int main() {
    char buffer[] = "<bookstore>\n"
        "  <book category=\"COOKING\">\n"
        "    <title lang=\"en\">Everyday Italian</title>\n"
        "    <author>Giada De Laurentiis</author>\n"
        "    <year>2005</year>\n"
        "    <price>30.00</price>\n"
        "  </book>\n"
        "  <book category=\"CHILDREN\">\n"
        "    <title lang=\"en\">Harry Potter</title>\n"
        "    <author>J K. Rowling</author>\n"
        "    <year>2005</year>\n"
        "    <price>29.99</price>\n"
        "  </book>\n"
        "</bookstore>";
    element* root = parse_xml(buffer);
    element* current = root->child;
    while(current != NULL) {
        printf("Tag: %s\n", current->tag_name);
        for(int i=0; i<current->num_attributes; i++) {
            printf("Attribute %d: %s=%s\n", i+1, current->attributes[i], current->attributes[i+1]);
            i++;
        }
        printf("Data: %s\n", current->data);
        current = current->sibling;
    }
    return 0;
}