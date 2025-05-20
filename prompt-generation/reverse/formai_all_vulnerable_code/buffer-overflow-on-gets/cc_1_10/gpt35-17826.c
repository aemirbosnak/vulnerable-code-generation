//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node {
   char tagName[20];
   char attributes[20];
   char value[20];
   struct Node *child;
   struct Node *sibling;
};

// function declarations
struct Node* createNode(char [], char [], char []);
void parseXML(char []);
void printTree(struct Node *);

int main() {
   char xml[500];
   printf("Enter the XML as a string: ");
   gets(xml);
   parseXML(xml);
   return 0;
}

// function to create a new node in the tree
struct Node* createNode(char tagName[], char attributes[], char value[]) {
   struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
   strcpy(newNode->tagName, tagName);
   strcpy(newNode->attributes, attributes);
   strcpy(newNode->value, value);
   newNode->child = NULL;
   newNode->sibling = NULL;
   return newNode;
}

// function to parse and build the XML tree
void parseXML(char xml[]) {
   int i = 0;
   struct Node *root = NULL, *current = NULL;
   while (xml[i]) {
      if (xml[i] == '<') {
         char tagName[20], attributes[20], value[20];
         int j = 0;
         i++;
         // get the tag name
         while (xml[i] != ' ' && xml[i] != '>') {
            tagName[j] = xml[i];
            j++;
            i++;
         }
         tagName[j] = '\0';
         // get the attributes
         j = 0;
         while (xml[i] != '>') {
            if (xml[i] != ' ') {
               attributes[j] = xml[i];
               j++;
            }
            i++;
         }
         attributes[j] = '\0';
         // get the value
         j = 0;
         i++;
         while (xml[i] != '<') {
            value[j] = xml[i];
            j++;
            i++;
         }
         value[j] = '\0';
         // create new node
         struct Node *newNode = createNode(tagName, attributes, value);
         // add new node to the tree
         if (root == NULL) {
            root = newNode;
            current = root;
         } else {
            if (current->child == NULL) {
               current->child = newNode;
            } else {
               current = current->child;
               while (current->sibling != NULL) {
                  current = current->sibling;
               }
               current->sibling = newNode;
            }
         }
      }
      i++;
   }
   // print the XML tree
   printTree(root);
}

// function to print the XML tree
void printTree(struct Node *root) {
   if (root == NULL) {
      return;
   }
   printf("<%s %s>", root->tagName, root->attributes);
   if (strlen(root->value) > 0) {
      printf("%s", root->value);
   }
   if (root->child != NULL) {
      printf("\n");
      printTree(root->child);
   }
   printf("</%s>\n", root->tagName);
   if (root->sibling != NULL) {
      printTree(root->sibling);
   }
}