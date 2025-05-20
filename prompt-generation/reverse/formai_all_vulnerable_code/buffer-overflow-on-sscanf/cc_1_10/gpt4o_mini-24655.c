//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct XMLNode
{
    char *name;
    char *value;
    struct XMLNode *next; // For siblings
    struct XMLNode *children; // For children nodes
} XMLNode;

XMLNode* createNode(const char *name, const char *value)
{
    XMLNode* node = (XMLNode *)malloc(sizeof(XMLNode));
    node->name = strdup(name);
    node->value = value ? strdup(value) : NULL;
    node->next = NULL;
    node->children = NULL;
    return node;
}

void addChild(XMLNode* parent, XMLNode* child)
{
    if (!parent->children)
    {
        parent->children = child;
    }
    else
    {
        XMLNode* temp = parent->children;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = child;
    }
}

void freeNode(XMLNode* node)
{
    if (node)
    {
        free(node->name);
        if (node->value)
            free(node->value);
        freeNode(node->children);
        freeNode(node->next);
        free(node);
    }
}

void printXML(XMLNode* node, int depth)
{
    if (!node) return;
    
    for (int i = 0; i < depth; i++)
        printf("    "); // Indentation for each depth

    printf("<%s>", node->name);
    if (node->value)
        printf("%s", node->value);

    if (node->children)
    {
        printf("\n");
        printXML(node->children, depth + 1);
        for (int i = 0; i < depth; i++)
            printf("    "); // Indentation for closing tag
    }

    printf("</%s>\n", node->name);
    printXML(node->next, depth);
}

XMLNode* parseXML(const char *xml)
{
    XMLNode* root = NULL;
    XMLNode* current = NULL;
    char tag[256], value[256];
    const char *p = xml;

    while (*p)
    {
        if (*p == '<')
        {
            if (*(p + 1) == '/')
            {
                p += 2; // Move past "</"
                sscanf(p, "%[^>]", tag);
                while (*p && *p != '>') p++;
                p++; // Move past '>'
            }
            else
            {
                p++; // Move past '<'
                sscanf(p, "%[^>]", tag);
                XMLNode *newNode = createNode(tag, NULL);

                if (!root)
                {
                    root = newNode; // Set root
                }

                if (current)
                {
                    addChild(current, newNode); // Add new child to current
                }

                current = newNode; // Set current as newNode
                while (*p && *p != '>') p++;
                p++; // Move past '>'
            }
        }
        else
        {
            sscanf(p, "%[^<]", value);
            if (current)
            {
                current->value = strdup(value); // Set value to current node
            }
            while (*p && *p != '<') p++;
        }
    }
    return root;
}

int main()
{
    const char *sampleXML = "<book><title>XML Parser</title><author>John Doe</author></book>";
    XMLNode *parsedXML = parseXML(sampleXML);
    printXML(parsedXML, 0);
    freeNode(parsedXML); // Clean up memory
    return 0;
}