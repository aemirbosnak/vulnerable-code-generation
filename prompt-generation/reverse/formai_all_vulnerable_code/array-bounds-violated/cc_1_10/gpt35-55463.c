//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENT_SIZE 100
#define MAX_ATTRIBUTE_SIZE 30

// struct to represent an XML element
typedef struct xml_element {
    char name[MAX_ELEMENT_SIZE];    // name of the element
    char content[MAX_ELEMENT_SIZE]; // content of the element
    struct xml_element* parent;     // pointer to parent element (NULL if root)
    struct xml_element* children;   // pointer to first child element (NULL if leaf)
    struct xml_attribute* attributes; // pointer to first attribute (NULL if none)
    struct xml_element* next;       // pointer to next sibling element (NULL if last)
} xml_element;

// struct to represent an XML attribute
typedef struct xml_attribute {
    char name[MAX_ATTRIBUTE_SIZE];  // name of the attribute
    char value[MAX_ATTRIBUTE_SIZE]; // value of the attribute
    struct xml_attribute* next;     // pointer to next attribute (NULL if last)
} xml_attribute;

// function to parse an XML file and create a tree of elements
xml_element* parse_xml_file(char* filename) {
    FILE* file = fopen(filename, "r");    // open file for reading
    if (!file) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }
    xml_element* root = NULL;             // pointer to root element (the first element in the file)
    xml_element* current = NULL;          // pointer to the current element being processed
    xml_element* last_parent = NULL;      // pointer to the most recent parent element
    xml_attribute* last_attribute = NULL; // pointer to the most recent attribute
    char buffer[MAX_ELEMENT_SIZE];        // buffer to hold element and attribute names and values
    char c;                               // variable to hold current character being read from file
    int i;                                // loop counter
    int inside_tag = 0;                   // flag to indicate whether we are inside an element tag
    int inside_comment = 0;               // flag to indicate whether we are inside a comment

    while ((c = fgetc(file)) != EOF) {
        if (inside_comment) { // skip characters until end of comment tag is found
            if (c == '-' && fgetc(file) == '-' && fgetc(file) == '>') {
                inside_comment = 0;
            }
            continue;
        }
        if (c == '<') {
            if (fgetc(file) == '!') { // handle comment tags
                if (fgetc(file) == '-' && fgetc(file) == '-') {
                    inside_comment = 1;
                }
                continue;
            }
            ungetc(c, file); // put the '<' back to parse the next element
            fgets(buffer, MAX_ELEMENT_SIZE, file); // get the element name (assumed to be on the same line as the opening tag)
            buffer[strlen(buffer)-1] = '\0'; // remove newline character
            if (buffer[0] == '/') { // this is a closing tag
                current = current->parent;
                continue;
            }
            xml_element* new_element = malloc(sizeof(xml_element));
            strcpy(new_element->name, buffer);
            new_element->content[0] = '\0';
            new_element->parent = current;
            new_element->children = NULL;
            new_element->attributes = NULL;
            new_element->next = NULL;
            if (!root) { // this is the first element, so it is the root
                root = new_element;
                current = root;
                last_parent = root;
            } else { // this is a child or sibling element
                char next_char = fgetc(file);
                if (next_char == '/') { // this is a self-closing tag
                    current->next = new_element;
                    current = current->next;
                } else {
                    ungetc(next_char, file); // put the next character back to parse the element contents
                    if (!current->children) { // this is the first child element of the current parent
                        current->children = new_element;
                        current = current->children;
                    } else { // this is a new sibling element
                        current->next = new_element;
                        current = current->next;
                    }
                }
            }
            inside_tag = 1;
        } else if (c == '>') {
            if (inside_tag) { // ignore '>' characters inside the element content
                inside_tag = 0;
            } else { // parse the element content (text between opening and closing tags)
                fgets(buffer, MAX_ELEMENT_SIZE, file);
                buffer[strlen(buffer)-1] = '\0'; // remove newline character
                strcpy(current->content, buffer);
            }
        } else if (c == '=') { // parse an attribute (name=value)
            fgets(buffer, MAX_ATTRIBUTE_SIZE, file);
            buffer[strlen(buffer)-1] = '\0'; // remove newline character
            xml_attribute* new_attribute = malloc(sizeof(xml_attribute));
            strcpy(new_attribute->name, buffer);
            fgets(buffer, MAX_ATTRIBUTE_SIZE, file);
            buffer[strlen(buffer)-1] = '\0'; // remove newline character
            strcpy(new_attribute->value, buffer);
            new_attribute->next = NULL;
            if (!current->attributes) {
                current->attributes = new_attribute;
                last_attribute = current->attributes;
            } else {
                last_attribute->next = new_attribute;
                last_attribute = last_attribute->next;
            }
        }
    }
    fclose(file); // close the file
    return root;  // return the root element of the tree
}

// function to print an XML element and its descendants recursively
void print_element(xml_element* element, int indent) {
    int i;
    for (i = 0; i < indent; i++) {
        printf(" "); // print indentation spaces
    }
    printf("<%s", element->name); // print opening tag
    xml_attribute* attribute = element->attributes;
    while (attribute) { // print attributes
        printf(" %s=\"%s\"", attribute->name, attribute->value);
        attribute = attribute->next;
    }
    printf(">\n"); // close the opening tag and start a new line
    if (element->content[0] != '\0') { // print element content (if any)
        for (i = 0; i < indent+2; i++) {
            printf(" "); // print indentation spaces
        }
        printf("%s\n", element->content);
    }
    xml_element* child = element->children;
    while (child) { // recursively call print_element for all child elements
        print_element(child, indent+2);
        child = child->next;
    }
    for (i = 0; i < indent; i++) {
        printf(" "); // print indentation spaces
    }
    printf("</%s>\n", element->name); // print closing tag and start a new line
}

int main() {
    xml_element* root = parse_xml_file("example.xml");
    if (!root) {
        return 1; // error parsing XML file
    }
    print_element(root, 0);
    return 0;
}