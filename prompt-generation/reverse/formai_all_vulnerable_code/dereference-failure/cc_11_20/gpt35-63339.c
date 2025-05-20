//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_LEN 50
#define MAX_ATTR_LEN 30
#define MAX_ATTR_VAL 100

typedef struct {
  char tag[MAX_TAG_LEN + 1];
  char attr[MAX_ATTR_LEN + 1];
  char val[MAX_ATTR_VAL + 1];
} xml_element;

// Function to parse an XML file and return an array of xml_elements
xml_element* parse_xml(char* str, int* count) {
  xml_element* elements = NULL;
  int size = 0;
  
  // Loop through the string and extract elements and attributes
  char* p = str;
  while (*p != '\0') {
    xml_element el;
    memset(&el, 0, sizeof(el));
    
    // Find opening tag
    while (*p != '<') {
      p++;
    }
    p++;
    
    // Find tag name
    int i = 0;
    while (*p != ' ' && *p != '>') {
      el.tag[i++] = *p++;
      if (i == MAX_TAG_LEN) {
        printf("ERROR: tag name too long\n");
        return NULL;
      }
    }
    el.tag[i] = '\0';
    
    // Find attributes
    while (*p != '>') {
      if (*p == ' ') {
        p++;
        int j = 0;
        while (*p != '=' && *p != '>' && j < MAX_ATTR_LEN) {
          el.attr[j++] = *p++;
        }
        el.attr[j] = '\0';
        if (*p == '=') {
          p++;
          if (*p == '\"' || *p == '\'') {
            char quote = *p++;
            int k = 0;
            while (*p != quote && k < MAX_ATTR_VAL) {
              el.val[k++] = *p++;
            }
            el.val[k] = '\0';
            if (*p != quote) {
              printf("ERROR: attribute value not terminated with %c\n", quote);
              return NULL;
            }
          } else {
            printf("ERROR: expected quote after =\n");
            return NULL;
          }
        }
      } else {
        p++;
      }
    }
    
    // Add element to array
    size++;
    elements = realloc(elements, sizeof(xml_element) * size);
    if (elements == NULL) {
      printf("ERROR: memory allocation failed\n");
      return NULL;
    }
    memcpy(&elements[size - 1], &el, sizeof(el));
    
    // Move to next element
    p++;
  }
  
  // Set count and return array
  if (count != NULL) {
    *count = size;
  }
  return elements;
}

int main() {
  // Example XML string
  char* xml = "<book title=\"The Great Gatsby\"><author>F. Scott Fitzgerald</author><price>12.99</price></book>";
  
  // Parse XML string and print out elements
  int count;
  xml_element* elements = parse_xml(xml, &count);
  if (elements == NULL) {
    printf("ERROR: parsing XML\n");
    return 1;
  }
  printf("Parsed %d element(s):\n", count);
  for (int i = 0; i < count; i++) {
    printf("  <%s", elements[i].tag);
    if (strlen(elements[i].attr) > 0) {
      printf(" %s=\"%s\"", elements[i].attr, elements[i].val);
    }
    printf(">\n");
  }
  
  // Free memory and return
  free(elements);
  return 0;
}