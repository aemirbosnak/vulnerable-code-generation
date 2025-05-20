//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME_LENGTH 100
#define MAX_XML_LENGTH 1000

typedef struct Tag {
    char name[MAX_TAG_NAME_LENGTH];
    struct Tag *next;
} Tag;

// Function prototypes
Tag* createTag(const char *name);
void freeTags(Tag *head);
void parseXML(const char *xmlString);
void printTags(Tag *head);

int main() {
    char xmlInput[MAX_XML_LENGTH];

    printf("Enter an XML string: ");
    fgets(xmlInput, sizeof(xmlInput), stdin);

    // Remove trailing newline if exists
    size_t len = strlen(xmlInput);
    if (len > 0 && xmlInput[len - 1] == '\n') {
        xmlInput[len - 1] = '\0';
    }

    parseXML(xmlInput);

    return 0;
}

Tag* createTag(const char *name) {
    Tag *newTag = (Tag*)malloc(sizeof(Tag));
    if (newTag == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newTag->name, name, MAX_TAG_NAME_LENGTH - 1);
    newTag->name[MAX_TAG_NAME_LENGTH - 1] = '\0'; // Ensure null-termination
    newTag->next = NULL;
    return newTag;
}

void freeTags(Tag *head) {
    Tag *current = head;
    Tag *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

void parseXML(const char *xmlString) {
    Tag *head = NULL;
    Tag *tail = NULL;

    const char *start = xmlString;
    while (*start) {
        // Find the start of a tag
        if (*start == '<') {
            const char *end = strchr(start, '>');
            if (!end) {
                fprintf(stderr, "Error: Mismatched tag.\n");
                freeTags(head);
                return;
            }

            // Allocate buffer for tag name and extract it
            char tagName[MAX_TAG_NAME_LENGTH] = {0};
            int len = end - start - 1; // Length of the tag name
            if (len >= MAX_TAG_NAME_LENGTH) {
                fprintf(stderr, "Error: Tag name too long.\n");
                freeTags(head);
                return;
            }

            // Check for closing tags
            if (*(start + 1) == '/') {
                // Handle closing tag
                strncpy(tagName, start + 2, len - 1); // Skip </
                tagName[len - 3] = '\0'; // Null-terminate the string
                printf("Closing Tag: %s\n", tagName);
            } else {
                // Handle opening tag
                strncpy(tagName, start + 1, len); // Skip <
                tagName[len - 1] = '\0'; // Null-terminate the string

                printf("Opening Tag: %s\n", tagName);

                // Create a new Tag node
                Tag *newTag = createTag(tagName);
                
                // Add tag to the list
                if (head == NULL) {
                    head = newTag;
                } else {
                    tail->next = newTag;
                }
                tail = newTag;
            }
            start = end + 1; // Move to the character after the closing '>'
        } else {
            start++;
        }
    }

    // Printing all collected tags
    printTags(head);
    freeTags(head);
}

void printTags(Tag *head) {
    printf("Parsed Tags:\n");
    Tag *current = head;
    while (current != NULL) {
        printf("Tag: %s\n", current->name);
        current = current->next;
    }
}