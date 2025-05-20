//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define a struct for XML nodes */
struct xml_node {
    char tag_name[50];
    char attribute_name[50];
    char attribute_value[50];
    struct xml_node *child;
    struct xml_node *sibling;
};

/* Function to create a new XML node */
struct xml_node *new_xml_node(char *tag_name, char *attribute_name, char *attribute_value) {
    /* Allocate memory for the node */
    struct xml_node *node = malloc(sizeof(struct xml_node));
    
    /* Set the tag name */
    strcpy(node->tag_name, tag_name);
    
    /* Set the attribute name and value */
    strcpy(node->attribute_name, attribute_name);
    strcpy(node->attribute_value, attribute_value);
    
    /* Set the child and sibling pointers to NULL */
    node->child = NULL;
    node->sibling = NULL;
    
    return node;
}

/* Recursive function to parse XML */
struct xml_node *parse_xml(char *xml, int *index) {
    /* Allocate memory for the new node */
    struct xml_node *node = NULL;
    
    /* Variables to store the tag name and attribute */
    char tag_name[50] = "";
    char attribute_name[50] = "";
    char attribute_value[50] = "";

    /* Get the length of the XML */
    int xml_length = strlen(xml);
    
    /* Loop through the XML, parsing each node */
    while (*index < xml_length) {
        /* Check for the start of a new node */
        if (xml[*index] == '<') {
            /* Ignore any whitespace */
            while (xml[*index] && xml[*index] != '<' && xml[*index] != '>') {
                (*index)++;
            }
            
            /* Check for the end of the current node */
            if (xml[*index] == '>') {
                /* increment the index to the start of the node content */
                (*index)++;
                
                /* Create the new node */
                node = new_xml_node(tag_name, attribute_name, attribute_value);
                
                /* Parse any child nodes */
                node->child = parse_xml(xml, index);
                
                /* Check for the end of the current tag */
                if (xml[*index] == '<' && xml[(*index)+1] == '/') {
                    (*index) += 2;
                    
                    /* Get the tag name */
                    int i = 0;
                    while (xml[*index+i] && xml[*index+i] != '>') {
                        tag_name[i] = xml[*index+i];
                        i++;
                    }
                    
                    /* Move the index past the end of the tag */
                    *index += i + 1;
                    
                    /* Check that the current tag matches the expected tag */
                    if (strlen(tag_name) && strcmp(tag_name, node->tag_name)) {
                        printf("Error parsing XML at index %d, expected tag '%s', but found '%s'\n", *index, node->tag_name, tag_name);
                        exit(EXIT_FAILURE);
                    }
                    
                    /* Return the current node */
                    return node;
                }
            }
            /* Check for the start of a new tag */
            else if (xml[*index] == '<' && xml[(*index)+1] != '/') {
                /* Move past the start tag */
                (*index)++;
                
                /* Get the tag name */
                int i = 0;
                while (xml[*index+i] && xml[*index+i] != ' ' && xml[*index+i] != '>') {
                    tag_name[i] = xml[*index+i];
                    i++;
                }
                
                /* Move the index past the tag name */
                *index += i;
                
                /* Parse any attributes */
                while (xml[*index] && xml[*index] != '>') {
                    /* Ignore any whitespace */
                    while (xml[*index] && xml[*index] != '=' && xml[*index] != '>') {
                        (*index)++;
                    }
                    
                    /* Move past the '=' character */
                    if (xml[*index] == '=') {
                        (*index)++;
                        
                        /* Get the attribute name */
                        i = 0;
                        while (xml[*index+i] && xml[*index+i] != ' ' && xml[*index+i] != '=' && xml[*index+i] != '>') {
                            attribute_name[i] = xml[*index+i];
                            i++;
                        }
                        
                        /* Move past the attribute name */
                        *index += i;
                        
                        /* Get the attribute value */
                        i = 0;
                        while (xml[*index+i] && xml[*index+i] != '"' && xml[*index+i] != '\'') {
                            i++;
                        }
                        
                        /* Move past the opening quote character */
                        if (xml[*index+i] == '"' || xml[*index+i] == '\'') {
                            (*index) += i + 1;
                            
                            /* Get the attribute value */
                            i = 0;
                            while (xml[*index+i] && xml[*index+i] != '"' && xml[*index+i] != '\'') {
                                attribute_value[i] = xml[*index+i];
                                i++;
                            }
                            
                            /* Move past the closing quote character */
                            if (xml[*index+i] == '"' || xml[*index+i] == '\'') {
                                *index += i + 1;
                            }
                        }
                        
                        /* Create the new node */
                        node = new_xml_node(tag_name, attribute_name, attribute_value);
                    }
                }
                
                /* Parse any child nodes */
                node->child = parse_xml(xml, index);
                
                /* Check for the end of the current tag */
                if (xml[*index] == '<' && xml[(*index)+1] == '/') {
                    (*index) += 2;
                    
                    /* Get the tag name */
                    int i = 0;
                    while (xml[*index+i] && xml[*index+i] != '>') {
                        tag_name[i] = xml[*index+i];
                        i++;
                    }
                    
                    /* Move the index past the end of the tag */
                    *index += i + 1;
                    
                    /* Check that the current tag matches the expected tag */
                    if (strlen(tag_name) && strcmp(tag_name, node->tag_name)) {
                        printf("Error parsing XML at index %d, expected tag '%s', but found '%s'\n", *index, node->tag_name, tag_name);
                        exit(EXIT_FAILURE);
                    }
                    
                    /* Return the current node */
                    return node;
                }
            }
            /* Error parsing XML */
            else {
                printf("Error parsing XML at index %d\n", *index);
                exit(EXIT_FAILURE);
            }
        }
        /* Add any text content to the current node */
        else if (node) {
            /* Allocate memory for the text content */
            int length = 0;
            char *text = malloc(sizeof(char) * (xml_length - *index - 1));
            
            /* Copy the text content */
            while (xml[*index] && xml[*index] != '<') {
                text[length++] = xml[(*index)++];
            }
            
            /* Null-terminate the text */
            text[length] = '\0';
            
            /* Add the text content to the current node */
            if (length) {
                node->child = new_xml_node("", "", "");
                node->child->sibling = new_xml_node(text, "", "");
            }
            
            /* Free the memory used for the text content */
            free(text);
        }
        /* Increment the index */
        else {
            (*index)++;
        }
    }
    
    /* Return the current node */
    return node;
}

/* Function to print the XML tree */
void print_xml_tree(struct xml_node *node, int indent) {
    /* Print the tag name and attribute */
    for (int i = 0; i < indent; i++) {
        printf(" ");
    }
    
    printf("<%s", node->tag_name);
    
    if (strlen(node->attribute_name)) {
        printf(" %s=\"%s\"", node->attribute_name, node->attribute_value);
    }
    
    printf(">\n");
    
    /* Print the child nodes */
    if (node->child) {
        print_xml_tree(node->child, indent+2);
    }
    
    /* Print the sibling nodes */
    if (node->sibling) {
        print_xml_tree(node->sibling, indent);
    }
    
    /* Print the end tag */
    for (int i = 0; i < indent; i++) {
        printf(" ");
    }
    
    printf("</%s>\n", node->tag_name);
}

/* Main function */
int main() {
    /* XML string to parse */
    char *xml = "<html>\n  <head>\n    <title>Example</title>\n  </head>\n  <body>\n    <h1>Example</h1>\n    <p>This is an example of an XML document.</p>\n    <ul>\n      <li>Item 1</li>\n      <li>Item 2</li>\n    </ul>\n  </body>\n</html>\n";
    
    /* Index for parsing the XML */
    int index = 0;
    
    /* Parse the XML */
    struct xml_node *xml_tree = parse_xml(xml, &index);
    
    /* Print the XML tree */
    print_xml_tree(xml_tree, 0);
    
    /* Free the memory used for the XML tree */
    free(xml_tree);
    
    return 0;
}