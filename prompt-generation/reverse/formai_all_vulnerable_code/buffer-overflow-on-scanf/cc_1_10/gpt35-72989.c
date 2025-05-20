//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000
#define MAX_LEVELS 50

typedef struct {
    char name[MAX_LENGTH];
    char value[MAX_LENGTH];
} attribute;

typedef struct {
    int level;
    char name[MAX_LENGTH];
    attribute attributes[MAX_LEVELS];
    int num_attributes;
} element;

element stack[MAX_LEVELS];
int top = -1;

void push(element e) {
  top++;
  stack[top] = e;
}

void pop() {
  top--;
}

void parseXML(char *filename) {
  FILE *fp;
  char line[MAX_LENGTH];
  element current_element;

  fp = fopen(filename, "r");
  if (fp == NULL) {
    printf("Error opening file: %s\n", filename);
    exit(1);
  }
  
  while(fgets(line, MAX_LENGTH, fp)) {
    char *token;
    int num_tokens = 0;
    const char *delimiter = " <>\n";
    token = strtok(line, delimiter);
    while(token != NULL) {
      current_element.level = top+1;
      if (num_tokens == 0 && token[0] == '/') {
        // End element
        current_element = stack[top];
        if (strcmp(current_element.name, &token[1]) != 0) {
          printf("Error: Mismatched end tag for %s\n", current_element.name);
          exit(1);
        } else {
          pop();
        }
      } else if (num_tokens == 0 && token[0] != '/') {
        // Start element
        strcpy(current_element.name, token);
        current_element.num_attributes = 0;
        push(current_element);
      } else if (num_tokens == 2 && token[0] == '=') {
        // Attribute name-value pair
        strcpy(current_element.attributes[current_element.num_attributes].name, &line[token-line+1]);
        current_element.attributes[current_element.num_attributes].name[strlen(current_element.attributes[current_element.num_attributes].name)-1] = '\0';
        strcpy(current_element.attributes[current_element.num_attributes].value, token+1);
        current_element.attributes[current_element.num_attributes].value[strlen(current_element.attributes[current_element.num_attributes].value)-1] = '\0';
        current_element.num_attributes++;
      }
      token = strtok(NULL, delimiter);
      num_tokens++;
    }
    
    if (current_element.level > stack[top].level) {
      printf("Error: Missing end tag for %s\n", stack[top].name);
      exit(1);
    }
  }
  
  fclose(fp);
}

int main() {
  element root_element;
  char filename[MAX_LENGTH];

  printf("Enter filename: ");
  scanf("%s", filename);

  root_element.level = 0;
  strcpy(root_element.name, "root");
  root_element.num_attributes = 0;
  push(root_element);

  parseXML(filename);

  printf("XML parsed successfully!\n");

  return 0;
}