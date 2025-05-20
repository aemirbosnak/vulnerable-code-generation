//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/* XML element struct */
typedef struct xml_element {
    char * tag;  /* element tag */
    char * value;  /* element value */
    struct xml_element * children;  /* child elements */
    struct xml_element * next;  /* next sibling element */
} xml_element;

/* Error handling function for memory allocation */
void die(char * message) {
    if (errno) {
        perror(message);
    } else {
        printf("Error: %s\n", message);
    }
    exit(1);
}

/* XML parser function */
xml_element * parse_xml(char * filename) {
    FILE * fp;
    char ch;
    char * buffer = NULL;
    size_t bufsize = 0;
    ssize_t len;
    xml_element * root = NULL;
    xml_element * current = NULL;
    xml_element * parent = NULL;
    
    /* Open file for reading */
    fp = fopen(filename, "r");
    if (fp == NULL) {
        die("Failed to open file");
    }
    
    /* Read file line by line */
    while ((len = getline(&buffer, &bufsize, fp)) != -1) {
        /* Ignore blank lines */
        if (len == 1 && buffer[0] == '\n') {
            continue;
        }
        
        /* Parse element */
        if (buffer[0] == '<') {
            /* Create new element */
            xml_element * element = malloc(sizeof(xml_element));
            if (element == NULL) {
                die("Failed to allocate memory");
            }
            element->tag = buffer + 1;
            element->value = NULL;
            element->children = NULL;
            element->next = NULL;
            
            /* Determine element type */
            if (buffer[1] == '/') {
                /* Closing element */
                element->tag = buffer + 2;
                current = parent;
                parent = current ? current->children : NULL;
                if (current) {
                    /* Add element to parent */
                    if (parent) {
                        while (parent->next) {
                            parent = parent->next;
                        }
                        parent->next = element;
                    } else {
                        current->children = element;
                    }
                } else if (!root) {
                    /* Set root if first element */
                    root = element;
                }
            } else if (buffer[len - 2] == '/') {
                /* Self-closing element */
                element->tag[len - 3] = '\0';
                if (current) {
                    /* Add element to parent */
                    if (parent) {
                        while (parent->next) {
                            parent = parent->next;
                        }
                        parent->next = element;
                    } else {
                        current->children = element;
                    }
                } else if (!root) {
                    /* Set root if first element */
                    root = element;
                }
            } else {
                /* Opening element */
                element->tag[len - 2] = '\0';
                parent = current;
                current = element;
                if (parent) {
                    /* Add child element */
                    if (parent->children) {
                        xml_element * child = parent->children;
                        while (child->next) {
                            child = child->next;
                        }
                        child->next = element;
                    } else {
                        parent->children = element;
                    }
                }
            }
        } else {
            /* Add value to current element */
            if (current && buffer[0] != '\n') {
                char * value = malloc(len + 1);
                if (value == NULL) {
                    die("Failed to allocate memory");
                }
                strncpy(value, buffer, len);
                value[len - 1] = '\0';
                if (current->value) {
                    /* Append to existing value */
                    current->value = realloc(current->value, strlen(current->value) + len + 1);
                    if (current->value == NULL) {
                        die("Failed to allocate memory");
                    }
                    strcat(current->value, value);
                } else {
                    /* Set value if first line */
                    current->value = value;
                }
            }
        }
    }
    
    /* Close file and free memory */
    fclose(fp);
    if (buffer) {
        free(buffer);
    }
    
    return root;
}

/* Main function */
int main() {
    xml_element * root = parse_xml("data.xml");
    xml_element * element = root;
    while (element) {
        printf("Element: <%s>\n", element->tag);
        if (element->value) {
            printf("Value: %s\n", element->value);
        }
        if (element->children) {
            printf("Children:\n");
            xml_element * child = element->children;
            while (child) {
                printf("  <%s>\n", child->tag);
                child = child->next;
            }
        }
        printf("\n");
        element = element->next;
    }
    return 0;
}