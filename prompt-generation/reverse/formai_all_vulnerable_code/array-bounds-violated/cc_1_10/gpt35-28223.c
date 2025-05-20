//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct xml_node{
    char tag[50];
    char value[50];
    struct xml_node* child;
    struct xml_node* sibling;
} xml_node;

void parse_element(xml_node* node, char* element){
    char* start = strchr(element, '<');
    char* end = strchr(element, '>');

    if(start && end){
        // Extract tag and value
        int tag_len = end - start - 1;
        char tag[tag_len];
        strncpy(tag, start+1, tag_len);
        tag[tag_len] = '\0';
        
        if(*(end-1) == '/'){ // self-closing tag
            xml_node* child = (xml_node*) malloc(sizeof(xml_node));
            strncpy(child->tag, tag, tag_len);
            child->tag[tag_len] = '\0';
            child->value[0] = '\0';
            child->child = NULL;
            child->sibling = NULL;

            node->child = child;
            return;
        }

        int val_len = strlen(element) - (tag_len + 3) - 1;
        char val[val_len];   
        strncpy(val, end+1, val_len);
        val[val_len] = '\0';

        // Create child node
        xml_node* child = (xml_node*) malloc(sizeof(xml_node));
        strncpy(child->tag, tag, tag_len);
        child->tag[tag_len] = '\0';
        strncpy(child->value, val, val_len);
        child->value[val_len] = '\0';
        child->child = NULL;
        child->sibling = NULL;

        // Add child to parent
        if(!node->child){
            node->child = child;
        } else {
            xml_node* sibling = node->child;
            while(sibling->sibling){
                sibling = sibling->sibling;
            }
            sibling->sibling = child;
        }

        // Recursively parse child elements
        char* sub_element = strchr(val, '<');
        while(sub_element){
            xml_node* sub_child = (xml_node*) malloc(sizeof(xml_node));
            sub_child->tag[0] = '\0';
            sub_child->value[0] = '\0';
            sub_child->child = NULL;
            sub_child->sibling = NULL;

            parse_element(sub_child, sub_element);

            if(!child->child){
                child->child = sub_child;
            } else {
                xml_node* sub_sibling = child->child;
                while(sub_sibling->sibling){
                    sub_sibling = sub_sibling->sibling;
                }
                sub_sibling->sibling = sub_child;
            }

            sub_element = strchr(sub_element+1, '<');
        }
    }
}

void print_tree(xml_node* node, int depth){
    if(!node){
        return;
    }

    for(int i=0; i<depth; i++){
        printf("  ");
    }
    printf("%s:%s\n", node->tag, node->value);

    print_tree(node->child, depth+1);
    print_tree(node->sibling, depth);
}

int main(){
    char* xml = "<people><person name=\"Alice\">Hello</person><person name=\"Bob\"><age>25</age></person></people>";

    xml_node root;
    root.tag[0] = '\0';
    root.value[0] = '\0';
    root.child = NULL;
    root.sibling = NULL;

    parse_element(&root, xml);

    print_tree(&root, 0);

    return 0;
}